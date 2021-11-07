/*
Created by  : Vaisakh Dileep
Date        : 11, September, 2021
Description : Class declaration for the camera class.
*/

#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include "../ray/ray.hpp"

class camera
{
public:
    point_3d origin;

    vector_3d upper_left_corder;

    vector_3d horizontal_sweep;

    vector_3d vertical_sweep;

    camera(); // No-args constructor

    camera(point_3d origin, vector_3d upper_left_corner, vector_3d horizontal_sweep, vector_3d vertical_sweep); // Overloaded constructor

    camera(double vertical_fov, double aspect_ratio); // Overloaded constructor

    camera(point_3d look_from, point_3d look_at, vector_3d up_vector, double vertical_fov, double aspect_ratio); // Overloaded constructor

    void set_origin(point_3d origin);

    void set_upper_left_corner(vector_3d upper_left_corner);

    void set_horizontal_sweep(vector_3d horizontal_sweep);

    void set_vertical_sweep(vector_3d vertical_sweep);

    ray get_ray(double u, double v) const;
};

#endif