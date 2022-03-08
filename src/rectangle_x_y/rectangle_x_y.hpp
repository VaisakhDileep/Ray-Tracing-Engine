/*
Created by  : Vaisakh Dileep
Date        : 7, March, 2022
Description : Class declaration for the rectangle_x_y class.
*/

#ifndef _RECTANGLE_X_Y_HPP_
#define _RECTANGEL_X_Y_HPP_

#include "../hitable/hitable.hpp"

#include "../material/material.hpp"

class rectangle_x_y: public hitable
{
public:
    double x_0, x_1;

    double y_0, y_1;

    double z; // Since the rectangle is in the 'x-y plane' it will have a constant 'z' value.

    shared_ptr<material> material_ptr;

    rectangle_x_y(); // No-args constructor
    rectangle_x_y(double x_0, double x_1, double y_0, double y_1, double z, shared_ptr<material> material_ptr); // Overloaded constructor

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const override;

    virtual bool bounding_box(double time_0, double time_1, aabb &output_box) const override;
};

#endif