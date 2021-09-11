/*
Created by  : Vaisakh Dileep
Date		: 11, September, 2021
Description : Constructing a sphere with antialiasing enabled.
*/

#include<fstream>

#include "../../src/sphere/sphere.hpp"

#include "../../src/colour/colour.hpp"

#include "../../src/hitable_list/hitable_list.hpp"

#include "../../src/ray_tracing_utility/ray_tracing_utility.hpp"

#include "../../src/camera/camera.hpp"

using namespace std;

colour_3d colour_output(const ray &r, const hitable_list &world)
{
	hit_record record {};

	if(world.hit(r, 0, infinity, record))
	{
		return colour_3d {0, 255, 0};
	}
	else
	{
		return colour_3d {0, 0, 0}; // Background.
	}
}

void paint()
{
	hitable_list world {vector<shared_ptr<hitable>> {make_shared<sphere>(point_3d {0, 0, -1}, 0.5)}};

	ofstream out_file {"sphere.ppm"};

	int width {200}, height {100}, samples_per_pixel {100};

	initialize_p_3_file(out_file, width, height);

	camera cam {point_3d {0, 0, 0}, vector_3d {-2, 1, -1}, vector_3d {4, 0, 0}, vector_3d {0, -2, 0}};

	for(int i {0}; i < height; i++)
	{
		for(int j {0}; j < width; j++)
		{
			colour_3d colour {};

			for(int sample {0}; sample < samples_per_pixel; sample++)
			{
				double u {static_cast<double>(j + random_double_range_0_1()) / width}, v {static_cast<double>(i + random_double_range_0_1()) / height};

				ray r {cam.get_ray(u, v)};

				colour+=colour_output(r, world);
			}
			write_colour_0_255_format(out_file, colour, samples_per_pixel);
		}
		out_file<<"\n";
	}
}

int main()
{
	paint();

	return 0;
}