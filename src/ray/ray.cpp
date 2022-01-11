/*
Created by  : Vaisakh Dileep
Date        : 22, August, 2021
Description : Class definition for the ray class.
*/

#include "ray.hpp"

#include "../vector_3d/vector_3d.hpp"

ray::ray() // No-args constructor
{
    origin_vec = vector_3d {};

    direction_vec = vector_3d {};
}

ray::ray(const point_3d &origin_vec, const vector_3d &direction_vec, double time = 0.0) // Overloaded constructor
{
    this->origin_vec = origin_vec;

    this->direction_vec = direction_vec;

    this->time_val = time;
}

point_3d ray::origin() const // Returns the origin vector
{
    return origin_vec;
}

vector_3d ray::direction() const // Returns the direction vector
{
    return direction_vec;
}

double ray::time() const // Returns the time value
{
    return time_val;
}

point_3d ray::point_at_parameter(double variable_param) const // Returns the current position of the ray.
{
    return origin_vec + (variable_param * direction_vec);
}