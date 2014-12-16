/*
 * (C) Copyright 1996-2014 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include <limits>
#include <cassert>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <memory>
#include <iostream>

#include "eckit/exception/Exceptions.h"
#include "eckit/config/Resource.h"
#include "eckit/runtime/Context.h"
#include "eckit/runtime/Tool.h"
#include "eckit/filesystem/LocalPathName.h"

#include "atlas/atlas.h"

//------------------------------------------------------------------------------------------------------

using namespace eckit;
using namespace atlas;

//------------------------------------------------------------------------------------------------------

class gmsh_extract : public eckit::Tool {

  virtual void run();

public:

	gmsh_extract(int argc,char **argv): eckit::Tool(argc,argv)
	{
		do_run = true;

		bool help = Resource< bool >("-h",false);

		std::string help_str =
				"NAME\n"
				"       gmsh_extract - extract fields from gmsh files\n"
				"\n"
				"SYNOPSIS\n"
				"       gmsh_extract [OPTION]... -i SOURCE\n"
				"\n"
				"DESCRIPTION\n"
				"       Extract fields from SOURCE depending on OPTION\n"
				"\n"
				"       -i     (Required) space-separated list of gmsh files to process\n"
				"\n"
				"       -f     (Optional) comma-separated list of field names\n"
				"              If not present, all fields will be extracted\n"
				"\n"
				"       -l     (Optional) comma-separated list of levels\n"
				"              If not present, all levels will be extracted\n"
				"\n"
				"       -o     (Optional) newly created output file\n"
				"              If not present, the output will go to stdout\n"
				"\n"
				"EXAMPLES\n"
				"       gmsh_extract -f theta,VelocityZ -l 0,3 -i data/fields*.msh -o extracted.msh\n"
				"              # create/overwrite file extracted.msh\n"
				"\n"
				"       gmsh_extract -f theta,VelocityZ -l 0,3 -i data/fields*.msh >  extracted.msh\n"
				"              # create/overwrite file extracted.msh\n"
				"\n"
				"       gmsh_extract -f theta,VelocityZ -l 0,3 -i data/fields*.msh >> extracted.msh\n"
				"              # append to file extracted.msh\n"
				"\n"
				"AUTHOR\n"
				"       Written by Willem Deconinck.\n"
				"\n"
				"ECMWF                        October 2014"
				;

		if( help )
		{
			std::cout << help_str << std::endl;
			do_run = false;
			return;
		}


		fields = Resource< std::vector<std::string> >("-f",std::vector<std::string>());
		levels = Resource< std::vector<long> >("-l",std::vector<long>());
		out_filename = Resource< std::string >("-o",std::string(""));

		// Parse in_files manually, as Resource does not allow space separated file list,
		// as a wildcard would return
		//in_files = Resource< std::vector<std::string> >("-i",std::vector<std::string>());

		for( int i=0; i<argc; ++i )
		{
			if( std::string(argv[i]) == "-i" )
			{
				for( int j=i+1; j<argc; ++j )
				{
					std::string in_file(argv[j]);
					if( in_file[0] == '-' ) break;
					in_files.push_back(in_file);
				}
			}
		}

		if( in_files.empty() )
			throw UserError(Here(),"missing input filename, parameter -i\n"+help_str);

	}

private:

	std::vector<std::string> fields;
	std::vector<long> levels;
  std::vector<std::string> in_files;
	std::string out_filename;
	bool do_run;
};

//------------------------------------------------------------------------------------------------------

void gmsh_extract::run()
{
	if( !do_run ) return;
	atlas_init(Context::instance().argc(),Context::instance().argvs());
	Log::debug() << "Command line:" << std::endl;
	for( int i=0; i< Context::instance().argc(); ++i)
		Log::debug() << Context::instance().argv(i) << std::endl;
	Log::debug() << Translator<std::vector<std::string>,std::string>()(in_files) << std::endl;

	std::ofstream out_file;
	if( !out_filename.empty() )
	{
		out_file.open( out_filename.c_str() , std::ios::out | std::ios::binary );
		if( !out_file.is_open() )
			throw eckit::CantOpenFile(out_filename);
	}

	std::ostream& out = out_filename.empty() ? std::cout : out_file;

	for (int i=0; i<in_files.size(); ++i)
	{
		LocalPathName gmsh_file(in_files[i]);
		Log::debug() << "Processing " << gmsh_file << std::endl;
		std::set<std::string> search_fields;
		std::set<int> search_levels;
		search_fields.insert(fields.begin(),fields.end());
		search_levels.insert(levels.begin(),levels.end());

		std::ifstream in_file;
		in_file.open( gmsh_file.c_str() , std::ios::in | std::ios::binary );
		if( !in_file.is_open() )
			throw eckit::CantOpenFile(gmsh_file);

		std::string line;
		std::string ctxt = "";
		while (true)
		{
			std::getline(in_file,line);
			if( in_file.eof() ) break;
			if( line == "$MeshFormat" )
			{
				out<< line << "\n";
				std::getline(in_file,line);    out<< line << "\n";
				std::getline(in_file,line);    out<< line << "\n";
				std::getline(in_file,line);
			}
			if( line == "$NodeData" )        ctxt = "NodeData";
			if( line == "$ElementData")      ctxt = "ElementData";
			if( line == "$ElementNodeData")  ctxt = "ElementNodeData";

			if( !ctxt.empty() )
			{
				std::string end_ctxt = "$End"+ctxt;
				std::getline(in_file,line); // useless line
				std::getline(in_file,line); // field name
				std::string field_name_read;
				std::string field_name;
				int lev(-1);
				bool extract = false;

				field_name_read.assign(line,1,line.size()-2);
				field_name = field_name_read;
				Log::debug(2) << "Found field " << field_name << std::endl;
				if( field_name[field_name.size()-1] == ']' )
				{
					std::string lev_str;
					lev_str.assign(field_name,field_name.size()-4,3);
					field_name.assign(field_name,0,field_name.size()-5);
					lev = Translator<std::string,int>()(lev_str);
				}
				if( search_fields.size() == 0 || search_fields.find(field_name) != search_fields.end() )
				{
					if( lev==-1 )
					{
						Log::debug() << "Extracting field " << field_name << std::endl;
						extract = true;
					}
					else if( search_levels.size() == 0 || search_levels.find(lev) != search_levels.end() )
					{
						Log::debug() << "Extracting field " << field_name << "[" << lev << "]" << std::endl;
						extract = true;
					}
				}
				if( extract )
				{
					out << "$"<<ctxt<<"\n1\n" << "\"" << field_name_read << "\"\n";
					while( true )
					{
						std::getline(in_file,line);
						out << line << "\n";
						if( line == end_ctxt ) { out<< std::flush; break; }
					}
				}
				ctxt.clear();
			}
		}
	}
	if( !out_filename.empty() )
		out_file.close();
	atlas_finalize();
}

//------------------------------------------------------------------------------------------------------

int main( int argc, char **argv )
{
  gmsh_extract tool(argc,argv);
  tool.start();
  return 0;
}
