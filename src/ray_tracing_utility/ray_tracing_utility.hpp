/*
Created by  : Vaisakh Dileep
Date        : 10, September, 2021
Description : Utility functions for the ray-tracing engine(declaration).
*/

#ifndef _RAY_TRACING_UTILITY_HPP_
#define _RAY_TRACING_UTILITY_HPP_

#include<fstream>

#include<limits>

#include<chrono>

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

vector_3d refract(const vector_3d &incident_ray, const vector_3d &normal, double relative_refractive_index); // "relative_refractive_index" = (refractive index of tranmitted medium / refractive index of incident medium).

double schlicks_approximation(double cos_incident_angle, double relative_refractive_index);

double degrees_to_radians(double degree);

void elapsed_time(chrono::high_resolution_clock::time_point start, chrono::high_resolution_clock::time_point stop);

#endif