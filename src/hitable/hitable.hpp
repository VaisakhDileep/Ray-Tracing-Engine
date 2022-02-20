/*
Created by  : Vaisakh Dileep
Date        : 3, September, 2021
Description : Class declaration for the hitable class.
*/

#ifndef _HITABLE_HPP_
#define _HITABLE_HPP_

#include<memory>

#include "../ray/ray.hpp"

#include "../material/material.hpp"

#include "../aabb/aabb.hpp"

using namespace std;

class material; // Forward declaration.

struct hit_record
{
    double t;

    vector_3d p;

    vector_3d normal; // normal should always face opposite to the incident ray.

    shared_ptr<material> material_ptr;

    double latitude; // varies from 0 to pi.

    double longitude; // varies from 0 to 2*pi.

    bool outer_face;

    void set_face_normal(const ray &r, const vector_3d &outward_normal);
};

class hitable // Abstract class
{
public:
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const = 0;

    virtual bool bounding_box(double time_0, double time_1, aabb &output_box) const = 0; // "bool" is returned to denote whether we have successfully constructed the bounding volume.
};

#endif