/*
Created by  : Vaisakh Dileep
Date        : 8, September, 2021
Description : Class declaration for the sphere class.
*/

#ifndef _SPHERE_HPP_
#define _SPHERE_HPP_

#include "../hitable/hitable.hpp"

#include "../material/material.hpp"

class sphere: public hitable
{
public:
    point_3d center; // Center of the sphere

    double radius;

    shared_ptr<material> material_ptr;

    sphere(); // No-args constructor

    sphere(point_3d center, double radius); // Overloaded constructor

    sphere(point_3d center, double radius, shared_ptr<material> material_ptr); // Overloaded constructor

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const;
};

#endif