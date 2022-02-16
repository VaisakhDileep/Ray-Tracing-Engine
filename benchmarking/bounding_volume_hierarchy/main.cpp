/*
Created by  : Vaisakh Dileep
Date        : 15, February, 2022
Description : Compares performace with and without using bounding volume hierarchy.
*/

#include "../../src/sphere/sphere.hpp"

#include "../../src/colour/colour.hpp"

#include "../../src/hitable_list/hitable_list.hpp"

#include "../../src/ray_tracing_utility/ray_tracing_utility.hpp"

#include "../../src/camera/camera.hpp"

#include "../../src/metal/metal.hpp"

#include "../../src/lambertian/lambertian.hpp"

#include "../../src/dielectric/dielectric.hpp"

#include "../../src/bvh/bvh.hpp"

using namespace std;

void create_matrix_of_spheres(hitable_list &world, double radius, double x_start, double x_end, double y_start, double y_end, double z_start, double z_end, colour_3d colour)
{
    for(int z {z_start}; z < z_end; z += (2 * radius))
    {
        for(int x {x_start}; x < x_end; x += (2 * radius))
        {
            for(int y {y_start}; y < y_end; y += (2 * radius))
            {
                world.add_object(make_shared<sphere>(point_3d {x + radius, y + radius, z}, radius, make_shared<lambertian>(colour)));
            }
        }
    }
}

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

void paint_without_bvh()
{
    hitable_list world {};

    create_matrix_of_spheres(world, 0.5, -2, 2, -1, 1, -100, -1, colour_3d {1, 0, 0});

    ofstream out_file {"sphere.ppm"};

    int width {200}, height {100}, samples_per_pixel {100}, max_depth {50};

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

                colour+=colour_output(r, world, max_depth);
            }
            write_colour_0_1_format(out_file, colour, samples_per_pixel, 2.2); // gama correction = 2.2
        }
        out_file<<"\n";
    }
}

void paint_with_bvh()
{
    hitable_list world {};

    create_matrix_of_spheres(world, 0.5, -2, 2, -1, 1, -100, -1, colour_3d {128, 0, 128}.convert_0_255_to_0_1());

    hitable_list world_bvh {};

    world_bvh.add_object(make_shared<bvh_node>(world, 0, 1));

    ofstream out_file {"sphere.ppm"};

    int width {200}, height {100}, samples_per_pixel {100}, max_depth {50};

    initialize_p_3_file(out_file, width, height);

    camera cam {point_3d {0, 0, 0}, vector_3d {-2, 1, -1}, vector_3d {4, 0, 0}, vector_3d {0, -2, 0}};

    //camera cam {point_3d {-10, 0, -50}, point_3d {0, 0, -50}, vector_3d {0, 1, 0}, 90, static_cast<double>(width) / static_cast<double>(height)};

    for(int i {0}; i < height; i++)
    {
        for(int j {0}; j < width; j++)
        {
            colour_3d colour {};

            for(int sample {0}; sample < samples_per_pixel; sample++)
            {
                double u {static_cast<double>(j + random_double_range_0_1()) / width}, v {static_cast<double>(i + random_double_range_0_1()) / height};

                ray r {cam.get_ray(u, v)};

                colour+=colour_output(r, world_bvh, max_depth);
            }
            write_colour_0_1_format(out_file, colour, samples_per_pixel, 2.2); // gama correction = 2.2
        }
        out_file<<"\n";
    }
}

int main()
{
    chrono::high_resolution_clock::time_point start {chrono::high_resolution_clock::now()};

    paint_without_bvh();

    // paint_with_bvh();

    chrono::high_resolution_clock::time_point stop {chrono::high_resolution_clock::now()};

    elapsed_time(start, stop);

    return 0;
}