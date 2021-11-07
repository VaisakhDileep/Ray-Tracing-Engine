/*
Created by  : Vaisakh Dileep
Date        : 11, September, 2021
Description : Class definition for the camera class.
*/

#include "camera.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

#include "math.h"

// Note: We are using the right-handed coordinate system here.

camera::camera() // No-args constructor
    : origin {0, 0, 0}, upper_left_corder {0, 0, 0}, horizontal_sweep {0, 0, 0}, vertical_sweep {0, 0, 0}
{
}

camera::camera(point_3d origin, vector_3d upper_left_corder, vector_3d horizontal_sweep, vector_3d vertical_sweep) // Overloaded constructor
    : origin {origin}, upper_left_corder {upper_left_corder}, horizontal_sweep {horizontal_sweep}, vertical_sweep {vertical_sweep}
{
}

camera::camera(double vertical_fov, double aspect_ratio) // Overloaded constructor
{
    origin = vector_3d {0, 0, 0};

    double theta {degrees_to_radians(vertical_fov)}; // "vertical_fov" stands for vertical field-of-view.

    double vector_plane_half_height {tan(theta / 2)};

    double vector_plane_half_width {aspect_ratio * vector_plane_half_height}; // aspect_ratio = width_vector_plane / height_vector_plane

    upper_left_corder = vector_3d {-vector_plane_half_width, vector_plane_half_height, -1};

    horizontal_sweep = vector_3d {2 * vector_plane_half_width, 0, 0};

    vertical_sweep = vector_3d {0, -2 * vector_plane_half_height, 0};
}

camera::camera(point_3d look_from, point_3d look_at, vector_3d up_vector, double vertical_fov, double aspect_ratio) // Overloaded constructor
{
    vector_3d u {}, v {}, w {}; // new 'x', 'y' and 'z' axis respectively.

    double theta {degrees_to_radians(vertical_fov)}; // "vertical_fov" stands for vertical field-of-view.

    double vector_plane_half_height {tan(theta / 2)};

    double vector_plane_half_width {aspect_ratio * vector_plane_half_height}; // aspect_ratio = width_vector_plane / height_vector_plane

    origin = look_from;

    w = (look_at - look_from).unit_vector();

    u = cross(up_vector, w).unit_vector();

    v = cross(w, u).unit_vector();

    upper_left_corder = origin - w - (vector_plane_half_width * u) + (vector_plane_half_height * v); // This is with respect to {0, 0, 0} not the new the origin.

    horizontal_sweep = 2 * vector_plane_half_width * u;

    vertical_sweep = -2 * vector_plane_half_height * v;
}

void camera::set_origin(point_3d origin)
{
    this->origin = origin;
}

void camera::set_upper_left_corner(vector_3d upper_left_corder)
{
    this->upper_left_corder = upper_left_corder;
}

void camera::set_horizontal_sweep(vector_3d horizontal_sweep)
{
    this->horizontal_sweep = horizontal_sweep;
}

void camera::set_vertical_sweep(vector_3d vertical_sweep)
{
    this->vertical_sweep = vertical_sweep;
}

ray camera::get_ray(double u, double v) const
{
    return ray {origin, upper_left_corder + (u * horizontal_sweep) + (v * vertical_sweep) - origin};
}