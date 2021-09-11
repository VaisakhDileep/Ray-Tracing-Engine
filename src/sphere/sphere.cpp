/*
Created by  : Vaisakh Dileep
Date		: 8, September, 2021
Description : Class implementation for the sphere class.
*/

#include "sphere.hpp"

#include<math.h>

using namespace std;

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
	vector_3d ray_origin_to_center_of_sphere {r.origin() - center};

	double a {dot(r.direction(), r.direction())}; // ax^2 + bx^1 + cx^0.

	double b {2 * dot(ray_origin_to_center_of_sphere, r.direction())};

	double c {dot(ray_origin_to_center_of_sphere, ray_origin_to_center_of_sphere) - (radius * radius)};

	double discriminant {(b * b) - (4 * a * c)};

	if(discriminant > 0)
	{
		double solution = (-b - sqrt(discriminant)) / (2 * a);

		if((solution > t_min) and (solution < t_max))
		{
			record.t = solution;

			record.p = r.point_at_parameter(solution);

			record.normal = (r.point_at_parameter(solution) - center).make_unit_vector();

			return true;
		}

		solution = (-b + sqrt(discriminant)) / (2 * a);

		if((solution > t_min) and (solution < t_max))
		{
			record.t = solution;

			record.p = r.point_at_parameter(solution);

			record.normal = (r.point_at_parameter(solution) - center).make_unit_vector();

			return true;
		}
	}

	return false;
}