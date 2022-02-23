/*
Created by  : Vaisakh Dileep
Date        : 23, February, 2022
Description : Class definition for the material class.
*/

#include "material.hpp"

colour_3d material::emitted_colour(double latitude, double longitude, const point_3d &p) const
{
    return colour_3d {0, 0, 0}; // Black colour.
}