/*
Created by  : Vaisakh Dileep
Date        : 7, February, 2022
Description : Class defintion for the solid_colour class.
*/

#include "../solid_colour/solid_colour.hpp"

solid_colour::solid_colour() // No-args constructor
    : colour_value {0, 0, 0}
{
}

solid_colour::solid_colour(colour_3d colour_value) // Overloaded constructor
    : colour_value {colour_value}
{
}

colour_3d solid_colour::colour_output(double latitude, double longitude, const point_3d &p) const
{
    return colour_value;
}