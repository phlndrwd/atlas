/*
 * (C) Copyright 1996-2014 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/// @author Peter Bispham
/// @author Tiago Quintino
/// @author Pedro Maciel
/// @date Jan 2015

#ifndef atlas_Grid_H
#define atlas_Grid_H

#include <cstddef>
#include <vector>
#include <cmath>
#include <string>

#include "eckit/exception/Exceptions.h"
#include "eckit/geometry/Point2.h"
#include "eckit/memory/Builder.h"
#include "eckit/memory/Owned.h"
#include "eckit/memory/SharedPtr.h"
#include "eckit/value/Params.h"
#include "eckit/utils/MD5.h"

#include "atlas/BoundBox.h"
#include "atlas/util/ObjectRegistry.h"

namespace atlas {

class Mesh;
class GridSpec;

//------------------------------------------------------------------------------------------------------

/**
 * Interface to a grid of points in a 2d cartesian space
 * For example a LatLon grid or a Reduced Graussian grid
 *
 *      DECODE                        ATLAS                      ENCODE
 *      NetCDFBuilder -->  |-------|         |----------|   ------>NetCDFWrite
 *                         | Grid  | <=====> | GridSpec |
 *      GribBuilder ---->  |-------|         |----------|   ------>GribWrite
 *
 */
class Grid : public eckit::Owned {

 public:  // types

  typedef eckit::BuilderT1<Grid> builder_t;
  typedef const eckit::Params& ARG1;

  typedef eckit::geometry::LLPoint2 Point;

  typedef BoundBox Domain;                        // To become abstract class used to mask a grid

  typedef eckit::SharedPtr<Grid> Ptr;
  typedef std::string uid_t;

  typedef util::ObjectRegistry<Grid> Registry;
  typedef Registry::Id Id;

public: // methods

  static Grid& from_id(Id);

  static std::string className() { return "atlas.Grid"; }

  static double degrees_eps();

  static Grid* create(const GridSpec&);

  static Grid* create(const eckit::Params&);
  static Grid* create(const Grid::uid_t& shortName);
  //  static Grid* create( const Grid::HumanName& name );
  //  static Grid* create( const eckit::Buffer& buff );

  Grid();

  virtual ~Grid();

  Ptr self() { return Ptr(this); }

  /// Human readable name (may not be unique)
  virtual std::string shortName() const = 0;

  /// Unique grid id
  /// Computed from the shortName and the hash
  uid_t unique_id() const;

  /// Adds to the MD5 the information that makes this Grid unique
  virtual void hash(eckit::MD5&) const = 0;
  /// @returns the hash of the information that makes this Grid unique
  eckit::MD5::digest_t hash() const;

  /**
   * @return bounding box
   * @note when the bounding box is not on the grid, the coordinate values will
   * be on the enclosing grid points
   * @note assumes NORTH-->SOUTH, and EAST-->WEST (hence independent of scanning
   * mode, since that is GRIB specific)
   * @note assumes range for latitude: [-90,+90] and longitude [-360,+360]
   */
  virtual BoundBox bounding_box() const = 0;

  /**
   * @return rea to which the original grid is cropped or masked
   * @todo For now this is alias of bounding_box()
   */
  virtual Domain domain() const;

  /// Mask with given Domain
  virtual void mask(const Domain&);

  /// Mask with given Params
  virtual void mask(const eckit::Params&);

  /// Return a copy of the grid, masked with given Domain
  virtual Grid* masked(const Domain&) const;

  /// Return a copy of the grid, masked with given Params
  virtual Grid* masked(const eckit::Params&) const;

  /**
   * @return number of grid points
   * @note This methods should have constant access time, if necessary derived
   * classes should compute it at construction
   */
  virtual size_t npts() const = 0;

  /**
   * @brief fill provided parameter with grid points, as (lon,lat) values
   * @note assumes that the input vectors have the correct size.
   * @note assumes we start at NORTH,WEST-->SOUTH,EAST
   */
  virtual void lonlat(double[]) const = 0;
  virtual void lonlat(std::vector<Point>&) const = 0;
  void lonlat(std::vector<double>&) const;

  virtual std::string grid_type() const = 0;

  virtual GridSpec spec() const = 0;

  virtual bool same(const Grid&) const;

  void set_mesh(const Mesh& mesh);
  Mesh& mesh() const;

  Id id() const { return registry_id_; }

 protected:  // methods

  /// helper function to initialise global grids, with a global area (BoundBox)
  static BoundBox make_global_bounding_box();

  /// helper function to create bounding boxes (for non-global grids)
  static BoundBox make_bounding_box(const eckit::Params&);

  virtual void print(std::ostream&) const;

private:  // methods

  //void build_mesh() const;

  friend std::ostream& operator<<(std::ostream& s, const Grid& p) {
      p.print(s);
      return s;
  }

  static Registry& registry();

private: // members

  Id registry_id_;
  mutable eckit::SharedPtr<Mesh> mesh_;
  mutable uid_t                  uid_;
  mutable eckit::MD5::digest_t   hash_;

};

//------------------------------------------------------------------------------------------------------

}  // namespace atlas

#endif
