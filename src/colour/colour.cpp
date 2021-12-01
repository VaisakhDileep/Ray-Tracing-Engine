/*
Created by  : Vaisakh Dileep
Date        : 4, October, 2021
Description : Helper functions for writing colour to the p3 file(definition).
*/

#include "colour.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

#include<math.h>

void write_colour_0_1_format(ofstream &out_file, const colour_3d pixel, double gama_correction = 1)
{
    int r {static_cast<int>(255.9999 * pow(pixel.r(), 1 / gama_correction))}, g {static_cast<int>(255.9999 * pow(pixel.g(), 1 / gama_correction))}, b {static_cast<int>(255.9999 * pow(pixel.b(), 1 / gama_correction))};

    out_file<<r<<" "<<g<<" "<<b<<"    ";
}

void write_colour_0_1_format(ofstream &out_file, const colour_3d pixel, const int samples_per_pixel, double gama_correction = 1)
{
    int r {static_cast<int>(255.9999 * pow(pixel.r() / samples_per_pixel, 1 / gama_correction))}, g {static_cast<int>(255.9999 * pow(pixel.g() / samples_per_pixel, 1 / gama_correction))}, b {static_cast<int>(255.9999 * pow(pixel.b() / samples_per_pixel, 1 / gama_correction))};

    out_file<<r<<" "<<g<<" "<<b<<"    ";
}

void write_colour_0_255_format(ofstream &out_file, const colour_3d pixel) // For 0..255 format, we are ignoring gama correction.
{
    out_file<<pixel.r()<<" "<<pixel.g()<<" "<<pixel.b()<<"    ";
}

void write_colour_0_255_format(ofstream &out_file, const colour_3d pixel, const int samples_per_pixel) // For 0..255 format, we are ignoring gama correction.
{
    out_file<<static_cast<int>(pixel.r() / samples_per_pixel)<<" "<<static_cast<int>(pixel.g() / samples_per_pixel)<<" "<<static_cast<int>(pixel.b() / samples_per_pixel)<<"    ";
}

colour_3d generate_random_colour() // Generated colour is in 0..255 format.
{
    return colour_3d {random_3_d_vector(0, 255)};
}