/*
Created by  : Vaisakh Dileep
Date		: 7, Setember, 2021
Description : Constructing a sphere with shader enabled.
*/

#include "../ray/ray.hpp"

#include<fstream>

#include<math.h>

using namespace std;

pair<double, double> solve_sphere_equation(const vector_3d &center_of_sphere, double radius, const ray &r)
{
	pair<double, double> solution {};

	vector_3d ray_origin_to_center_of_sphere {r.origin() - center_of_sphere};

	double a {dot(r.direction(), r.direction())}; // ax^2 + bx^1 + cx^0.

	double b {2 * dot(ray_origin_to_center_of_sphere, r.direction())};

	double c {dot(ray_origin_to_center_of_sphere, ray_origin_to_center_of_sphere) - (radius * radius)};

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

bool hit_sphere(const vector_3d &center_of_sphere, double radius, const ray &r)
{
	vector_3d ray_origin_to_center_of_sphere {r.origin() - center_of_sphere};

	double a {dot(r.direction(), r.direction())}; // ax^2 + bx^1 + cx^0.

	double b {2 * dot(ray_origin_to_center_of_sphere, r.direction())};

	double c {dot(ray_origin_to_center_of_sphere, ray_origin_to_center_of_sphere) - (radius * radius)};

	double discriminant {(b * b) - (4 * a * c)};

	return (discriminant > 0);
}

vector_3d colour_output(const ray &r)
{
	vector_3d center_of_sphere {0, 0, -1};

	double radius {0.5};

	if(hit_sphere(center_of_sphere, radius, r))
	{
		pair<double, double> solution {solve_sphere_equation(center_of_sphere, radius, r)};

		int t {min(solution.first, solution.second)}; // origin + direction_vector * t --> Ray equation.

		vector_3d normal {r.point_at_parameter(t) - center_of_sphere};

		normal.make_unit_vector(); // normal components vary from -1 to 1.

		normal = (normal + vector_3d {1, 1, 1}) / 2; // normal components now vary from 0 to 1.

		int r {255.9999 * normal.r()}, g {255.9999 * normal.g()}, b {255.9999 * normal.b()};

		return vector_3d {r, g, b};
	}
	else
	{
		return vector_3d {0, 0, 0}; // Background.
	}
}

void paint()
{
	ofstream out_file {"sphere.ppm"};

	int width {200}, height {100};

	out_file<<"P3\n";
	out_file<<width<<" "<<height<<"\n";
	out_file<<255<<"\n";

	vector_3d origin {0, 0, 0};

	vector_3d upper_left_corner {-2, 1, -1};

	vector_3d horizontal_sweep {4, 0, 0};

	vector_3d vertical_sweep {0, -2, 0};

	for(int i {0}; i < height; i++)
	{
		for(int j {0}; j < width; j++)
		{
			double u {static_cast<double>(j) / width};

			double v {static_cast<double>(i) / height};

			vector_3d direction_vector {upper_left_corner + u * horizontal_sweep + v * vertical_sweep};

			ray r {origin, direction_vector};

			vector_3d colour {colour_output(r)};

			out_file<<colour.r()<<" "<<colour.g()<<" "<<colour.b()<<"    ";
		}
		out_file<<"\n";
	}
}

int main()
{
	paint();

	return 0;
}