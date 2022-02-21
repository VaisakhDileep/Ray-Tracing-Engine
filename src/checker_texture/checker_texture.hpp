/*
Created by  : Vaisakh Dileep
Date        : 20, February, 2022
Description : Class definition for the checker_texture.
*/

#ifndef _CHECKER_TEXTURE_HPP_
#define _CHECKER_TEXTURE_HPP_

#include "../texture/texture.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

#include<memory>

class checker_texture: public texture
{
public:
    shared_ptr<texture> odd;

    shared_ptr<texture> even;

    double length; // length of each side of the checker box.

    checker_texture(); // No-args constructor
    checker_texture(shared_ptr<texture> odd, shared_ptr<texture> even, double length = 0); // Overloaded constructor
    checker_texture(colour_3d odd_colour, colour_3d even_colour, double length = 0); // Overloaded constructor

    virtual colour_3d colour_output(double latitude, double longitude, const point_3d &p) const override;
};

#endif