/*
Created by  : Vaisakh Dileep
Date        : 4, October, 2021
Description : Class definition for the hitable class.
*/

#include "hitable.hpp"

void hit_record::set_face_normal(const ray &r, const vector_3d &outward_normal)
{
    if(dot(r.direction(), outward_normal) < 0)
    {
        outer_face = true;
    }
    else
    {
        outer_face = false;
    }

    if(outer_face == true)
    {
        normal = outward_normal;
    }
    else
    {
        normal = -outward_normal;
    }
}