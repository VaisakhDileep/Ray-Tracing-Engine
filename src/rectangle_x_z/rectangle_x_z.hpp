/*
Created by  : Vaisakh Dileep
Date        : 8, March, 2022
Description : Class declaration for the rectangle_x_z class.
*/

#ifndef _RECTANGLE_X_Z_HPP_
#define _RECTANGLE_X_Z_HPP_

#include "../hitable/hitable.hpp"

#include "../material/material.hpp"

class rectangle_x_z: public hitable
{
public:
    double x_0, x_1;

    double z_0, z_1;

    double y; // Since the rectangle is in the 'x-z plane' it will have a constant 'y' value.

    shared_ptr<material> material_ptr;

    rectangle_x_z(); // No-args constructor
    rectangle_x_z(double x_0, double x_1, double z_0, double z_1, double y, shared_ptr<material> material_ptr); // Overloaded constructor

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const override;

    virtual bool bounding_box(double time_0, double time_1, aabb &output_box) const override;
};

#endif