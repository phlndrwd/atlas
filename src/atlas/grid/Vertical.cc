/*
 * (C) Copyright 2013 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

#include "atlas/grid/Vertical.h"

namespace atlas {

//---------------------------------------------------------------------------------------------------------------------

namespace {

std::vector<double> linspace( double start, double end, idx_t N, bool endpoint ) {
    std::vector<double> x_;
    x_.resize( N );

    double step;
    if ( endpoint && N > 1 )
        step = ( end - start ) / double( N - 1 );
    else if ( N > 0 )
        step = ( end - start ) / double( N );
    else
        step = 0.;

    for ( idx_t i = 0; i < N; ++i ) {
        x_[i] = start + i * step;
    }
    return x_;
}

idx_t get_levels( const util::Config& config ) {
    return config.getInt( "levels", 0 );
}


}  // namespace

//---------------------------------------------------------------------------------------------------------------------

Vertical::Vertical( const util::Config& config ) :
    Vertical( get_levels( config ), linspace( 0., 1., get_levels( config ), true ), config ) {}

//---------------------------------------------------------------------------------------------------------------------

}  // namespace atlas
