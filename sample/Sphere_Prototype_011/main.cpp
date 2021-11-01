/*
Created by  : Vaisakh Dileep
Date        : 1, November, 2021
Description : Demonstrates the adjustable field-of-view property of the camera.
*/

#include "../../src/sphere/sphere.hpp"

#include "../../src/colour/colour.hpp"

#include "../../src/hitable_list/hitable_list.hpp"

#include "../../src/ray_tracing_utility/ray_tracing_utility.hpp"

#include "../../src/camera/camera.hpp"

#include "../../src/metal/metal.hpp"

#include "../../src/lambertian/lambertian.hpp"

#include "../../src/dielectric/dielectric.hpp"

using namespace std;

colour_3d colour_output(const ray &r, const hitable_list &world, int depth)
{
    if(depth == 0)
    {
        return colour_3d {0, 0, 0}; // If the recursive depth reaches the limit, return no colour.
    }

    hit_record record {};

    ray scattered_ray {};

    colour_3d attenuation {};

    if(world.hit(r, 0.0001, infinity, record))
    {
        if(record.material_ptr->scatter(r, record, attenuation, scattered_ray))
        {
            return attenuation * colour_output(scattered_ray, world, depth - 1);
        }
        else
        {
            return colour_3d {0, 0, 0};
        }
    }

    return colour_3d {135, 223, 235}.convert_0_255_to_0_1(); // sky blue colour.
}

void paint()
{
    hitable_list world {vector<shared_ptr<hitable>> {make_shared<sphere>(point_3d {-0.5, 0, -1}, 0.5, make_shared<lambertian>(colour_3d {230, 0, 255}.convert_0_255_to_0_1())), make_shared<sphere>(point_3d {0.5, 0, -1}, 0.5, make_shared<lambertian>(colour_3d {0, 255, 247}.convert_0_255_to_0_1())), make_shared<sphere>(point_3d {0, -100000.5, -1}, 100000, make_shared<lambertian>(colour_3d {128, 128, 128}.convert_0_255_to_0_1()))}};

    ofstream out_file {"sphere.ppm"};

    int width {200}, height {100}, samples_per_pixel {100}, max_depth {50};

    initialize_p_3_file(out_file, width, height);

    // camera cam {90, static_cast<double>(width) / static_cast<double>(height)};

    // camera cam {45, static_cast<double>(width) / static_cast<double>(height)};

    // camera cam {22.5, static_cast<double>(width) / static_cast<double>(height)};

    camera cam {11.25, static_cast<double>(width) / static_cast<double>(height)};

    for(int i {0}; i < height; i++)
    {
        for(int j {0}; j < width; j++)
        {
            colour_3d colour {};

            for(int sample {0}; sample < samples_per_pixel; sample++)
            {
                double u {static_cast<double>(j + random_double_range_0_1()) / width}, v {static_cast<double>(i + random_double_range_0_1()) / height};

                ray r {cam.get_ray(u, v)};

                colour+=colour_output(r, world, max_depth);
            }
            write_colour_0_1_format(out_file, colour, samples_per_pixel, 2.2); // gama correction = 2.2
        }
        out_file<<"\n";
    }
}

int main()
{
    paint();

    return 0;
}