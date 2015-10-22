/*
 * (C) Copyright 1996-2015 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#define BOOST_TEST_MODULE TestNablaEdgeBasedFiniteVolume
#include "ecbuild/boost_test_framework.h"

#include <cmath>
#include <iostream>
#include "eckit/memory/ScopedPtr.h"
#include "eckit/memory/SharedPtr.h"
#include "atlas/atlas.h"
#include "atlas/numerics/Nabla.h"
#include "atlas/Config.h"
#include "atlas/Grid.h"
#include "atlas/Mesh.h"
#include "atlas/meshgen/ReducedGridMeshGenerator.h"
#include "atlas/functionspace/EdgeBasedFiniteVolume.h"
#include "atlas/Nodes.h"
#include "atlas/Field.h"
#include "atlas/Parameters.h"
#include "atlas/io/Gmsh.h"
#include "atlas/FieldSet.h"

using namespace eckit;
using namespace atlas::numerics;
using namespace atlas::meshgen;

namespace atlas {
namespace test {

double dual_volume(Mesh& mesh)
{
  Nodes& nodes = mesh.nodes();
  int nb_nodes = nodes.size();
  const ArrayView<double,1> dual_volumes ( nodes.field("dual_volumes") );
  const ArrayView<gidx_t,1> glb_idx ( nodes.global_index() );
  const ArrayView<int,1> is_ghost ( nodes.ghost() );
  double area=0;
  for( int node=0; node<nb_nodes; ++node )
  {
    if( ! is_ghost(node) )
    {
      area += dual_volumes(node);
    }
  }
  ECKIT_MPI_CHECK_RESULT( MPI_Allreduce( MPI_IN_PLACE, &area, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD ) );
  return area;
}


struct AtlasFixture {
    AtlasFixture()  { atlas_init(); }
    ~AtlasFixture() { atlas_finalize(); }
};

BOOST_GLOBAL_FIXTURE( AtlasFixture )

BOOST_AUTO_TEST_CASE( test_factory )
{
  BOOST_CHECK( NablaFactory::has("EdgeBasedFiniteVolume") );
}

BOOST_AUTO_TEST_CASE( test_build )
{
  SharedPtr<Grid> grid ( Grid::create("oct.N24") );
  SharedPtr<MeshGenerator> meshgenerator ( MeshGenerator::create("ReducedGrid") );
  SharedPtr<Mesh> mesh( meshgenerator->generate(*grid) );
  const double R = Earth::radiusInMeters();
  functionspace::EdgeBasedFiniteVolume fvm(*mesh,Config("radius",R));
  SharedPtr<Nabla> nabla ( Nabla::create(fvm) );

  double spherical_area = 4.*M_PI*R*R;
  BOOST_CHECK_CLOSE(dual_volume(*mesh),spherical_area,0.001*spherical_area);

}


BOOST_AUTO_TEST_CASE( test_grad )
{
  const double radius = Earth::radiusInMeters();
  SharedPtr<Grid> grid ( Grid::create("oct.N64") );
  SharedPtr<MeshGenerator> meshgenerator ( MeshGenerator::create("ReducedGrid") );
  SharedPtr<Mesh> mesh( meshgenerator->generate(*grid) );
  functionspace::EdgeBasedFiniteVolume fvm(*mesh, Config("radius",radius));
  SharedPtr<Nabla> nabla ( Nabla::create(fvm) );

  ArrayView<double,2> lonlat( mesh->nodes().lonlat() );
  size_t nnodes = mesh->nodes().size();
  size_t nlev = 1;

  FieldSet fields;
  fields.add( fvm.createField<double>("var",nlev) );
  fields.add( fvm.createField<double>("grad",nlev,make_shape(2)) );
  fields.add( fvm.createField<double>("exact_yder",nlev) );
  fields.add( fvm.createField<double>("yder",nlev) );

  const double deg2rad = M_PI/180.;
  ArrayView<double,2> var( fields["var"] );
  ArrayView<double,2> exact_yder( fields["exact_yder"] );
  for( size_t jnode=0; jnode< nnodes ; ++jnode )
  {
    const double y  = lonlat(jnode,LAT) * deg2rad ;

    for(size_t jlev = 0; jlev < nlev; ++jlev) {
      var(jnode,jlev)        = std::sin(4.*y);
      exact_yder(jnode,jlev) = 4.*std::cos(4.*y)/radius;
    }
  }
  nabla->gradient(fields["var"],fields["grad"]);

  ArrayView<double,2> yder( fields["yder"] );
  const ArrayView<double,3> grad( fields["grad"] );
  for( size_t jnode=0; jnode< nnodes ; ++jnode )
  {
    for(size_t jlev = 0; jlev < nlev; ++jlev) {
      yder(jnode,jlev) = grad(jnode,jlev,LAT);
    }
  }

  // output to gmsh
  {
    io::Gmsh().write(*mesh,grid->shortName()+".msh");
    io::Gmsh().write(fields["var"],grid->shortName()+"_fields.msh");
    io::Gmsh().write(fields["yder"],grid->shortName()+"_fields.msh",std::ios::app);
    io::Gmsh().write(fields["exact_yder"],grid->shortName()+"_fields.msh",std::ios::app);
  }
}


} // namespace test
} // namespace atlas