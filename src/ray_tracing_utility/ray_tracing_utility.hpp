/*
Created by  : Vaisakh Dileep
Date        : 10, September, 2021
Description : Utility functions for the ray-tracing engine(declaration).
*/

#ifndef _RAY_TRACING_UTILITY_HPP_
#define _RAY_TRACING_UTILITY_HPP_

#include<fstream>

#include<limits>

#include "../vector_3d/vector_3d.hpp"

using namespace std;

const double infinity {numeric_limits<double>::infinity()};

const double pi {3.14159265358979323846};

void initialize_p_3_file(ofstream &out_file, int width, int height);

double random_double_range_0_1();

double random_double_range_0_1(double min, double max);

vector_3d random_3_d_vector_range_0_1();

vector_3d random_3_d_vector_range_0_1(double min, double max);

vector_3d random_3_d_vector_in_unit_sphere();

vector_3d random_3_d_vector_in_unit_sphere_surface();

vector_3d reflect(const vector_3d &incident_ray, const vector_3d &normal);

#endif