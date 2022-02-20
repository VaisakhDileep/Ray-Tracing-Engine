/*
Created by  : Vaisakh Dileep
Date        : 21, February, 2022
Description : Class definition for the checker_texture class.
*/

#include "checker_texture.hpp"

#include "../solid_colour/solid_colour.hpp"

#include<math.h>

checker_texture::checker_texture() // No-args constructor
    : odd {nullptr}, even {nullptr}
{
}

checker_texture::checker_texture(shared_ptr<texture> odd, shared_ptr<texture> even) // Overloaded constructor
    : odd {odd}, even {even}
{
}

checker_texture::checker_texture(colour_3d odd_colour, colour_3d even_colour) // Overloaded constructor
    : odd {make_shared<solid_colour>(odd_colour)}, even {make_shared<solid_colour>(even_colour)}
{
}

colour_3d checker_texture::colour_output(double latitude, double longitude, const point_3d &p) const
{
    double sin_value {sin(p.x()) * sin(p.y()) * sin(p.z())};

    if(sin_value < 0)
    {
        return odd->colour_output(latitude, longitude, p);
    }
    else
    {
        return even->colour_output(latitude, longitude, p);
    }
}