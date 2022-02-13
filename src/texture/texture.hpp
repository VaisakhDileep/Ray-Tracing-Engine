/*
Created by  : Vaisakh Dileep
Date        : 7, February, 2022
Description : Class declaration for the texture class.
*/

#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include "../vector_3d/vector_3d.hpp"

class texture
{
public:
    virtual colour_3d colour_output(double u, double , const point_3d &p) const = 0;
};

#endif