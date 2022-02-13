/*
Created by  : Vaisakh Dileep
Date        : 7, February, 2022
Description : Class declaration for the solid_colour class.
*/

#ifndef _SOLID_COLOUR_HPP_
#define _SOLID_COLOUR_HPP_

#include "../texture/texture.hpp"

class solid_colour: public texture
{
private:
    colour_3d colour_value;

public:
    solid_colour(); // No-args constructor

    solid_colour(colour_3d colour_value); // Overloaded constructor

    virtual colour_3d colour_output(double u, double v, const point_3d &p) const override;
};

#endif