/*
Created by  : Vaisakh Dileep
Date        : 3, September, 2021
Description : Class definition for the hitable class.
*/

#ifndef _HITABLE_HPP_
#define _HITABLE_HPP_

#include<memory>

#include "../ray/ray.hpp"

#include "../material/material.hpp"

using namespace std;

class material; // Forward declaration.

struct hit_record
{
    double t;

    vector_3d p;

    vector_3d normal; // normal should always face opposite to the incident ray.

    shared_ptr<material> material_ptr;

    bool outer_face;

    void set_face_normal(const ray &r, const vector_3d &outward_normal)
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
};

class hitable // Abstract class
{
public:
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const = 0;
};
#endif