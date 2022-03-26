/*
Created by  : Vaisakh Dileep
Date        : 26, March, 2022
Description : Class definition for the box class.
*/

#include "box.hpp"

#include "../../src/rectangle_x_y/rectangle_x_y.hpp"

#include "../../src/rectangle_x_z/rectangle_x_z.hpp"

#include "../../src/rectangle_y_z/rectangle_y_z.hpp"

box::box() // No-args constructor
    : minimum_limit {0, 0, 0}, maximum_limit {0, 0, 0}, box_sides {vector<shared_ptr<hitable>> {}}
{
}

box::box(point_3d minimum_limit, point_3d maximum_limit, shared_ptr<material> material_ptr) // Overloaded constructor
    : minimum_limit {minimum_limit}, maximum_limit {maximum_limit}
{
    box_sides.add_object(make_shared<rectangle_x_y>(minimum_limit.x(), maximum_limit.x(), minimum_limit.y(), maximum_limit.y(), minimum_limit.z(), material_ptr));
    box_sides.add_object(make_shared<rectangle_x_y>(minimum_limit.x(), maximum_limit.x(), minimum_limit.y(), maximum_limit.y(), maximum_limit.z(), material_ptr));

    box_sides.add_object(make_shared<rectangle_x_z>(minimum_limit.x(), maximum_limit.x(), minimum_limit.z(), maximum_limit.z(), minimum_limit.y(), material_ptr));
    box_sides.add_object(make_shared<rectangle_x_z>(minimum_limit.x(), maximum_limit.x(), minimum_limit.z(), maximum_limit.z(), maximum_limit.y(), material_ptr));

    box_sides.add_object(make_shared<rectangle_y_z>(minimum_limit.y(), maximum_limit.y(), minimum_limit.z(), maximum_limit.z(), minimum_limit.x(), material_ptr));
    box_sides.add_object(make_shared<rectangle_y_z>(minimum_limit.y(), maximum_limit.y(), minimum_limit.z(), maximum_limit.z(), maximum_limit.x(), material_ptr));
}

bool box::hit(const ray &r, double t_min, double t_max, hit_record &record) const
{
    return box_sides.hit(r, t_min, t_max, record);
}

bool box::bounding_box(double time_0, double time_1, aabb &output_box) const
{
    output_box = aabb(minimum_limit, maximum_limit);

    return true;
}