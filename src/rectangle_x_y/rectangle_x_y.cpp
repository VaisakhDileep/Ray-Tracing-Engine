/*
Created by  : Vaisakh Dileep
Date        : 7, March, 2022
Description : Class defintion for the rectangle_x_y class.
*/

#include "../rectangle_x_y/rectangle_x_y.hpp"

rectangle_x_y::rectangle_x_y() // No-args constructor
    : x_0 {0}, x_1 {0}, y_0 {0}, y_1 {0}, z {0}, material_ptr {nullptr}
{
}

rectangle_x_y::rectangle_x_y(double x_0, double x_1, double y_0, double y_1, double z, shared_ptr<material> material_ptr) // Overloaded constructor
    : x_0 {x_0}, x_1 {x_1}, y_0 {y_0}, y_1 {y_1}, z {z}, material_ptr {material_ptr}
{
}

bool rectangle_x_y::hit(const ray &r, double t_min, double t_max, hit_record &record) const
{
    double t {(z - r.origin().z()) / r.direction().z()};

    if((t < t_min) or (t > t_max))
    {
        return false;
    }

    double x {r.origin().x() + (t * r.direction().x())};

    double y {r.origin().y() + (t * r.direction().y())};

    if((x < x_0) or (x > x_1) or (y < y_0) or (y > y_1))
    {
        return false;
    }

    record.t = t;

    record.p = r.point_at_parameter(t);

    record.material_ptr = material_ptr;

    record.longitude = (x - x_0) / (x_1 - x_0);

    record.latitude = (y - y_0) / (y_1 - y_0);

    vector_3d outward_normal {vector_3d {0, 0, 1}};

    record.set_face_normal(r, outward_normal);

    return true;
}

bool rectangle_x_y::bounding_box(double time_0, double time_1, aabb &output_box) const
{
    output_box = aabb {point_3d {x_0, y_0, z - 0.0001}, point_3d {x_1, y_1, z + 0.0001}}; // We pad the z-direction by a small value.

    return true;
}