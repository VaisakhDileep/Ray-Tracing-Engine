/*
Created by  : Vaisakh Dileep
Date        : 8, March, 2022
Description : Class declaration for the rectangle_y_z class.
*/

#ifndef _RECTANGLE_Y_Z_HPP_
#define _RECTANGLE_Y_Z_HPP_

#include "../hitable/hitable.hpp"

#include "../material/material.hpp"

class rectangle_y_z: public hitable
{
public:
    double y_0, y_1;

    double z_0, z_1;

    double x; // Since the rectangle is in the 'y-z plane' it will have a constant 'x' value.

    shared_ptr<material> material_ptr;

    rectangle_y_z(); // No-args constructor
    rectangle_y_z(double y_0, double y_1, double z_0, double z_1, double x, shared_ptr<material> material_ptr); // Overloaded constructor

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const override;

    virtual bool bounding_box(double time_0, double time_1, aabb &output_box) const override;
};

#endif