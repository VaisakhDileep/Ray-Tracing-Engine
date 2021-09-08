/*
Created by  : Vaisakh Dileep
Date		: 22, August, 2021
Description : Class definition for the ray class.
*/

#ifndef _RAY_HPP_
#define _RAY_HPP_

#include "../vector_3d/vector_3d.hpp"

class ray
{
public:
	vector_3d origin_vec;

	vector_3d direction_vec;

	ray(); // No-args constructor
	ray(const vector_3d &origin_vec, const vector_3d &direction_vec); // Overloaded constructor

	vector_3d origin() const; // Returns the origin vector
	vector_3d direction() const; // Returns the direction vector

	vector_3d point_at_parameter(double time) const; // Returns the current position of the ray.
};
#endif