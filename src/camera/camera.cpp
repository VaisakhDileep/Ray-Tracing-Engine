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

camera::camera(double vertical_fov, double aspect_ratio)
{
    origin = vector_3d {0, 0, 0};

    double theta {degrees_to_radians(vertical_fov)}; // "vertical_fov" stands for vertical field-of-view.

    double vector_plane_half_height {tan(theta / 2)};

    double vector_plane_half_width {aspect_ratio * vector_plane_half_height}; // aspect_ratio = width_vector_plane / height_vector_plane

    upper_left_corder = vector_3d {-vector_plane_half_width, vector_plane_half_height, -1};

    horizontal_sweep = vector_3d {2 * vector_plane_half_width, 0, 0};

    vertical_sweep = vector_3d {0, -2 * vector_plane_half_height, 0};
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