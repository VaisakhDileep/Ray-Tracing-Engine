/*
Created by  : Vaisakh Dileep
Date        : 8, March, 2022
Description : Demonstrates rectangle_x_y.
*/

#include "../../src/sphere/sphere.hpp"

#include "../../src/colour/colour.hpp"

#include "../../src/hitable_list/hitable_list.hpp"

#include "../../src/ray_tracing_utility/ray_tracing_utility.hpp"

#include "../../src/camera/camera.hpp"

#include "../../src/metal/metal.hpp"

#include "../../src/lambertian/lambertian.hpp"

#include "../../src/dielectric/dielectric.hpp"

#include "../../src/checker_texture/checker_texture.hpp"

#include "../../src/diffuse_light/diffuse_light.hpp"

#include "../../src/rectangle_x_y/rectangle_x_y.hpp"

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
        colour_3d emitted_colour {record.material_ptr->emitted_colour(record.latitude, record.longitude, record.p)};

        if(record.material_ptr->scatter(r, record, attenuation, scattered_ray))
        {
            return emitted_colour + (attenuation * colour_output(scattered_ray, world, depth - 1));
        }
        else // If it directly hits a light source.
        {
            return emitted_colour;
        }
    }

    return colour_3d {0, 0, 0}; // Notice here we are not return "sky blue colour"(no background light source).
}

void paint()
{
    shared_ptr<checker_texture> checker_pattern {make_shared<checker_texture>(colour_3d {0, 0, 0}.convert_0_255_to_0_1(), colour_3d {255, 255, 0}.convert_0_255_to_0_1(), 0.1)};

    shared_ptr<diffuse_light> star {make_shared<diffuse_light>(colour_3d {5, 5, 5})};

    hitable_list world {vector<shared_ptr<hitable>> {make_shared<rectangle_x_y>(-0.5, 0.5, -0.25, 0.75, -1, star), make_shared<sphere>(point_3d {0, -100000.5, -1}, 100000, make_shared<lambertian>(checker_pattern))}};

    ofstream out_file {"sphere.ppm"};

    int width {400}, height {200}, samples_per_pixel {300}, max_depth {50};

    initialize_p_3_file(out_file, width, height);

    camera cam {point_3d {0, 0, 0}, vector_3d {-2, 1, -1}, vector_3d {4, 0, 0}, vector_3d {0, -2, 0}};

    cout<<"progress bar: ";
    for(int i {0}; i < height; i++)
    {
        if((i % 2) == 0)
        {
            cout<<"#";
        }

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
    cout<<"\n";
}

int main()
{
    chrono::high_resolution_clock::time_point start {chrono::high_resolution_clock::now()};

    paint();

    chrono::high_resolution_clock::time_point stop {chrono::high_resolution_clock::now()};

    elapsed_time(start, stop);

    return 0;
}