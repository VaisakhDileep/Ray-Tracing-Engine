/*
Created by  : Vaisakh Dileep
Date		: 10, September, 2021
Description : Constructing multiple spheres(one huge one).
*/

#include<fstream>

#include "../../src/sphere/sphere.hpp"

#include "../../src/colour/colour.hpp"

#include "../../src/hitable_list/hitable_list.hpp"

#include "../../src/ray_tracing_utility/ray_tracing_utility.hpp"

using namespace std;

colour_3d colour_output(const ray &r, const hitable_list &world)
{
	hit_record record {};

	if(world.hit(r, 0, infinity, record))
	{
		return (record.normal + vector_3d {1, 1, 1}) / 2;
	}
	else
	{
		return colour_3d {0, 0, 0}; // Background.
	}
}

void paint()
{
	hitable_list world {vector<shared_ptr<hitable>> {make_shared<sphere>(point_3d {0, 0, -1}, 0.5) ,make_shared<sphere>(point_3d {0, -100000.5, -1}, 100000)}}; // The second sphere acts like a ground.

	ofstream out_file {"sphere.ppm"};

	int width {200}, height {100};

	initialize_p_3_file(out_file, width, height);

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

			colour_3d colour {colour_output(r, world)};

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