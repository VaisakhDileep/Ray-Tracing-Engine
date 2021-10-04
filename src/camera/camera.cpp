/*
Created by  : Vaisakh Dileep
Date        : 11, September, 2021
Description : Class definition for the camera class.
*/

#include "camera.hpp"

camera::camera() // No-args constructor
    : origin {0, 0, 0}, upper_left_corder {0, 0, 0}, horizontal_sweep {0, 0, 0}, vertical_sweep {0, 0, 0}
{
}

camera::camera(point_3d origin, vector_3d upper_left_corder, vector_3d horizontal_sweep, vector_3d vertical_sweep) // Overloaded constructor
    : origin {origin}, upper_left_corder {upper_left_corder}, horizontal_sweep {horizontal_sweep}, vertical_sweep {vertical_sweep}
{
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