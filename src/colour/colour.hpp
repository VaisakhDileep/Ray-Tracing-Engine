/*
Created by  : Vaisakh Dileep
Date        : 9, September, 2021
Description : Helper functions for writing colour to the p3 file(declaration).
*/

#ifndef _COLOUR_HPP_
#define _COLOUR_HPP_

#include<fstream>

#include "../vector_3d/vector_3d.hpp"

using namespace std;

void write_colour_0_1_format(ofstream &out_file, const colour_3d pixel, double gama_correction = 1);

void write_colour_0_1_format(ofstream &out_file, const colour_3d pixel, const int samples_per_pixel, double gama_correction = 1);

void write_colour_0_255_format(ofstream &out_file, const colour_3d pixel); // For 0..255 format, we are ignoring gama correction.

void write_colour_0_255_format(ofstream &out_file, const colour_3d pixel, const int samples_per_pixel); // For 0..255 format, we are ignoring gama correction.

#endif