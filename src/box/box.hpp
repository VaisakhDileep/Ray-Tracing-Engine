/*
Created by  : Vaisakh Dileep
Date        : 26, March, 2022
Description : Class declaration for the box class.
*/

#ifndef _BOX_HPP_
#define _BOX_HPP_

#include "../hitable/hitable.hpp"

#include "../hitable_list/hitable_list.hpp"

class box : public hitable
{
public:
    point_3d minimum_limit;

    point_3d maximum_limit;

    hitable_list box_sides;

    box(); // No-args constructor
    box(point_3d minimum_limit, point_3d maximum_limit, shared_ptr<material> material_ptr); // Overloaded constructor

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const override;

    virtual bool bounding_box(double time_0, double time_1, aabb &output_box) const override;
};

#endif