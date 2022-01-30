/*
Created by  : Vaisakh Dileep
Date        : 11, January, 2022
Description : Class declaration for the moving_sphere class.
*/

#ifndef _MOVING_SPHERE_HPP_
#define _MOVING_SPHERE_HPP_

#include "../hitable/hitable.hpp"

#include "../material/material.hpp"

class moving_sphere: public hitable
{
public:
    point_3d center_0, center_1;

    double time_0, time_1;

    double radius;

    shared_ptr<material> material_ptr;

    moving_sphere(); // No-args constructor
    moving_sphere(point_3d center_0, point_3d center_1, double time_0, double time_1, double radius); // Overloaded constructor
    moving_sphere(point_3d center_0, point_3d center_1, double time_0, double time_1, double radius, shared_ptr<material> material_ptr); // Overloaded constructor

    point_3d center(double time) const;

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const;

    virtual bool bounding_box(double _time_0, double _time_1, aabb &output_box) const override;
};

#endif