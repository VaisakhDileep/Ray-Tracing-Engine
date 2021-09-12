/*
Created by  : Vaisakh Dileep
Date		: 9, September, 2021
Description : Constructing a sphere with shader enabled.
*/

#include "../../src/ray/ray.hpp"

#include "../../src/colour/colour.hpp"

using namespace std;

pair<double, double> solve_sphere_equation(const point_3d &center_of_sphere, double radius_of_sphere, const ray &r)
{
	pair<double, double> solution {};

	vector_3d ray_origin_to_center_of_sphere {r.origin() - center_of_sphere};

	double a {dot(r.direction(), r.direction())}; // ax^2 + bx^1 + cx^0.

	double b {2 * dot(ray_origin_to_center_of_sphere, r.direction())};

	double c {dot(ray_origin_to_center_of_sphere, ray_origin_to_center_of_sphere) - (radius_of_sphere * radius_of_sphere)};

	double discriminant {(b * b) - (4 * a * c)};

	if(discriminant >= 0)
	{
		solution.first = (-b + sqrt(discriminant)) / (2 * a);

		solution.second = (-b - sqrt(discriminant)) / (2 * a);
	}
	else
	{
		throw string {"ERROR - Only imaginary roots exist ....."};
	}

	return solution;
}

bool hit_sphere(const point_3d &center_of_sphere, double radius_of_sphere, const ray &r)
{
	vector_3d ray_origin_to_center_of_sphere {r.origin() - center_of_sphere};

	double a {dot(r.direction(), r.direction())}; // ax^2 + bx^1 + cx^0.

	double b {2 * dot(ray_origin_to_center_of_sphere, r.direction())};

	double c {dot(ray_origin_to_center_of_sphere, ray_origin_to_center_of_sphere) - (radius_of_sphere * radius_of_sphere)};

	double discriminant {(b * b) - (4 * a * c)};

	return (discriminant > 0);
}

colour_3d colour_output(const ray &r)
{
	point_3d center_of_sphere {0, 0, -1};

	double radius_of_sphere {0.5};

	if(hit_sphere(center_of_sphere, radius_of_sphere, r))
	{
		pair<double, double> solution {solve_sphere_equation(center_of_sphere, radius_of_sphere, r)};

		double t {min(solution.first, solution.second)};

		vector_3d normal {(r.point_at_parameter(t) - center_of_sphere).make_unit_vector()};

		normal = (normal + vector_3d {1, 1, 1}) / 2;

		return normal; // We are returning the color in 0..1 format.
	}
	else
	{
		return colour_3d {0, 0, 0}; // Background.
	}
}

void paint()
{
	ofstream out_file {"sphere.ppm"};

	int width {200}, height {100};

	out_file<<"P3\n";
	out_file<<width<<" "<<height<<"\n";
	out_file<<255<<"\n";

	point_3d origin {0, 0, 0};

	point_3d upper_left_corner {-2, 1, -1};

	vector_3d horizontal_sweep {4, 0, 0};

	vector_3d vertical_sweep {0, -2, 0};

	for(int i {0}; i < height; i++)
	{
		for(int j {0}; j < width; j++)
		{
			double u {static_cast<double>(j) / width}, v {static_cast<double>(i) / height};

			vector_3d direction_vector {upper_left_corner + (u * horizontal_sweep) + (v * vertical_sweep) - origin};

			ray r {origin, direction_vector};

			colour_3d colour {colour_output(r)};

			write_colour_0_1_format(out_file, colour);
		}
		out_file<<"\n";
	}
}

int main()
{
	paint();

	return 0;
}