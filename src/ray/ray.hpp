/*
Created by  : Vaisakh Dileep
Date        : 22, August, 2021
Description : Class definition for the ray class.
*/

#ifndef _RAY_HPP_
#define _RAY_HPP_

#include "../vector_3d/vector_3d.hpp"

class ray
{
public:
    point_3d origin_vec;

    vector_3d direction_vec;

    double time_val {0};

    ray(); // No-args constructor
    ray(const vector_3d &origin_vec, const vector_3d &direction_vec, double time = 0.0); // Overloaded constructor

    point_3d origin() const; // Returns the origin vector

    vector_3d direction() const; // Returns the direction vector

    double time() const; // Returns the time value

    point_3d point_at_parameter(double variable_param) const; // Returns the current position of the ray
};

#endif