/*
Created by  : Vaisakh Dileep
Date        : 8, March, 2022
Description : Class defintion for the rectangle_y_z class.
*/

#include "rectangle_y_z.hpp"

rectangle_y_z::rectangle_y_z() // No-args constructor
    : y_0 {0}, y_1 {0}, z_0 {0}, z_1 {0}, x {0}, material_ptr {nullptr}
{
}

rectangle_y_z::rectangle_y_z(double y_0, double y_1, double z_0, double z_1, double x, shared_ptr<material> material_ptr) // Overloaded constructor
    : y_0 {y_0}, y_1 {y_1}, z_0 {z_0}, z_1 {z_1}, x {x}, material_ptr {material_ptr}
{
}

bool rectangle_y_z::hit(const ray &r, double t_min, double t_max, hit_record &record) const
{
    double t {(x - r.origin().x()) / r.direction().x()};

    if((t < t_min) or (t > t_max))
    {
        return false;
    }

    double y {r.origin().y() + (t * r.direction().y())};

    double z {r.origin().z() + (t * r.direction().z())};

    if((y < y_0) or (y > y_1) or (z < z_0) or (z > z_1))
    {
        return false;
    }

    record.t = t;

    record.p = r.point_at_parameter(t);

    record.material_ptr = material_ptr;

    record.longitude = (y - y_0) / (y_1 - y_0);

    record.longitude = (z - z_0) / (z_1 - z_0);

    vector_3d outward_normal {vector_3d {1, 0, 0}};

    record.set_face_normal(r, outward_normal);

    return true;
}

bool rectangle_y_z::bounding_box(double time_0, double time_1, aabb &output_box) const
{
    output_box = aabb {point_3d {x - 0.0001, y_0, z_0}, point_3d {x + 0.001, y_1, z_1}}; // We pad the x-direction by a small value.
}