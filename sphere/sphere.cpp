/*
Created by  : Vaisakh Dileep
Date		: 8, September, 2021
Description : Class implementation for the sphere class.
*/

#include "sphere.hpp"

sphere::sphere() // No-args constructor
	: center {vector_3d {0, 0, 0}}, radius {0}
{
}

sphere::sphere(vector_3d center, double radius) // Overloaded constructor
	: center {center}, radius {radius}
{
}

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &record) const
{
	pair<double, double> solution {};
}