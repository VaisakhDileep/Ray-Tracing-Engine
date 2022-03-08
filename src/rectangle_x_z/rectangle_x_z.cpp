/*
Created by  : Vaisakh Dileep
Date        : 8, March, 2022
Description : Class definition for the rectangle_x_z class.
*/

#include "rectangle_x_z.hpp"

rectangle_x_z::rectangle_x_z() // No-args constructor
    : x_0 {0}, x_1 {0}, z_0 {0}, z_1 {0}, y {0}, material_ptr {nullptr}
{
}

rectangle_x_z::rectangle_x_z(double x_0, double x_1, double z_0, double z_1, double y, shared_ptr<material> material_ptr) // Overloaded constructor
    : x_0 {x_0}, x_1 {x_1}, z_0 {z_0}, z_1 {z_1}, y {y}, material_ptr {material_ptr}
{
}

bool rectangle_x_z::hit(const ray &r, double t_min, double t_max, hit_record &record) const
{
    double t {(y - r.origin().y()) / r.direction().y()};

    if((t < t_min) or (t > t_max))
    {
        return false;
    }

    double x {r.origin().x() + (t * r.direction().x())};

    double z {r.origin().z() + (t * r.direction().z())};

    if((x < x_0) or (x > x_1) or (z < z_0) or (z > z_1))
    {
        return false;
    }

    record.t = t;

    record.p = r.point_at_parameter(t);

    record.material_ptr = material_ptr;

    record.longitude = (x - x_0) / (x_1 - x_0);

    record.latitude = (z - z_0) / (z_1 - z_0);

    vector_3d outward_normal {vector_3d {0, 1, 0}};

    record.set_face_normal(r, outward_normal);

    return true;
}

bool rectangle_x_z::bounding_box(double time_0, double time_1, aabb &output_box) const
{
    output_box = aabb {point_3d {x_0, y - 0.0001, z_0}, point_3d {x_1, y + 0.0001, z_1}}; // We pad the y-direction by a small value.

    return true;
}