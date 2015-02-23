/*
 * (C) Copyright 1996-2014 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include "atlas/ErrorHandling.h"
#include "atlas/mpi/mpi.h"
#include "atlas/meshgen/ReducedGridMeshGenerator.h"
#include "atlas/actions/GenerateMesh.h"
#include "atlas/util/Debug.h"
using namespace atlas::meshgen;
using namespace atlas::grids;
namespace atlas {
namespace actions {

// ------------------------------------------------------------------

Mesh* generate_mesh (const ReducedGrid& rgg)
{
  ReducedGridMeshGenerator generate;
  generate.options.set( "nb_parts", (int) eckit::mpi::size() );
  generate.options.set( "part"    , (int) eckit::mpi::rank() );
  return generate(rgg);
}

// ------------------------------------------------------------------


Mesh* atlas__generate_mesh (ReducedGrid* rgg)
{
  ATLAS_ERROR_HANDLING( return generate_mesh(*rgg); );
  return NULL;
}

// ------------------------------------------------------------------


} // namespace actions
} // namespace atlas
