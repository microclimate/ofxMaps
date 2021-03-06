// =============================================================================
//
// Copyright (c) 2014 Christopher Baker <http://christopherbaker.net>
// Copyright (c) -2014 Tom Carden <https://github.com/RandomEtc>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include <string>
#include <vector>
#include "Types.h"
#include "GeoLocation.h"


class GeoUtils
{
public:
    static GeoPolyline decodeGeoPolyline(const std::string& encodedGeoPolyline);

    /// \brief Get the distance in kilometers between two GeoLocations on earth.
    ///     Calculation uses the great-circle distance uses the approximated
    ///     radius of a sphereical earth in kilometers.
    /// \returns the spherical distance in kilometers.
	static double getSphericalDistance(const GeoLocation& location0,
                                       const GeoLocation& location1);


    /// \brief Get the distance in kilometers between two GeoLocations on earth.
    ///     Calculation uses the haversine formula. Uses the approximated
    ///     radius of a sphereical earth in kilometers.
    /// \returns the spherical distance in kilometers.
    static double getHaversineDistance(const GeoLocation& location0,
                                       const GeoLocation& location1);


    // \returns the bearing in degrees between two GeoLocations.
    static double getBearingBetween(const GeoLocation& location0,
                                    const GeoLocation& location1);

    static const double EARTH_RADIUS_KM;
        ///< The approximate radius of a spherical earth in kilometers.

};
