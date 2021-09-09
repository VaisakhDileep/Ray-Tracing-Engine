/*
Created by  : Vaisakh Dileep
Date		: 9, September, 2021
Description : Constructing a sphere with shader enabled.
*/

#include<fstream>

#include "../../src/ray/ray.hpp"

#include "../../src/colour/colour.hpp"

using namespace std;

bool hit_sphere(const point_3d &center_of_sphere, double radius_of_sphere, const ray &r)
{
	vector_3d ray_origin_to_center_of_sphere {r.origin() - center_of_sphere};

	double a {dot(r.direction(), r.direction())}; // ax^2 + bx^1 + cx^0.

	double b {2.0 * dot(ray_origin_to_center_of_sphere, ray_origin_to_center_of_sphere) - (radius_of_sphere * radius_of_sphere)};
}

int main()
{

	return 0;
}