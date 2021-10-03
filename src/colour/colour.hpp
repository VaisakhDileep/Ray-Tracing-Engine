/*
Created by  : Vaisakh Dileep
Date        : 9, September, 2021
Description : Class declaration for the colour class.
*/

#ifndef _COLOUR_HPP_
#define _COLOUR_HPP_

#include<fstream>

#include<math.h>

#include "../vector_3d/vector_3d.hpp"

using namespace std;

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

#endif