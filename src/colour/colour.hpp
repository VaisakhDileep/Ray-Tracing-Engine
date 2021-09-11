/*
Created by  : Vaisakh Dileep
Date		: 9, September, 2021
Description : Class declaration for the colour class.
*/

#ifndef _COLOUR_HPP_
#define _COLOUR_HPP_

#include<iostream>

#include<fstream>

#include "../vector_3d/vector_3d.hpp"

using namespace std;

void write_colour_0_1_format(ofstream &out_file, const colour_3d pixel)
{
	int r {static_cast<int>(255.9999 * pixel.r())}, g {static_cast<int>(255.9999 * pixel.g())}, b {static_cast<int>(255.9999 * pixel.b())};

	out_file<<r<<" "<<g<<" "<<b<<"    ";
}

void write_colour_0_1_format(ofstream &out_file, const colour_3d pixel, const int samples_per_pixel)
{
	int r {static_cast<int>(255.9999 * (pixel.r() / samples_per_pixel))}, g {static_cast<int>(255.9999 * (pixel.g() / samples_per_pixel))}, b {static_cast<int>(255.9999 * (pixel.b() / samples_per_pixel))};

	out_file<<r<<" "<<g<<" "<<b<<"    ";
}

void write_colour_0_255_format(ofstream &out_file, const colour_3d pixel)
{
	out_file<<pixel.r()<<" "<<pixel.g()<<" "<<pixel.b()<<"    ";
}

#endif