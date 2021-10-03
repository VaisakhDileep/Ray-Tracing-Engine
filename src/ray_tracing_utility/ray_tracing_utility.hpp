/*
Created by  : Vaisakh Dileep
Date        : 10, September, 2021
Description : Class definition for the ray_tracing_utility class.
*/

#ifndef _RAY_TRACING_UTILITY_HPP_
#define _RAY_TRACING_UTILITY_HPP_

#include<fstream>

#include<limits>

#include<cstdlib>

#include<math.h>

#include "../vector_3d/vector_3d.hpp"

using namespace std;

const double infinity {numeric_limits<double>::infinity()};

const double pi {3.14159265358979323846};

void initialize_p_3_file(ofstream &out_file, int width, int height)
{
    out_file<<"P3\n";
    out_file<<width<<" "<<height<<"\n";
    out_file<<"255\n";
}

double random_double_range_0_1()
{
    return static_cast<double>(rand()) / (RAND_MAX + 1.0); // Range (0, 1], not including 1.
}

double random_double_range_0_1(double min, double max)
{
    return min + (max - min) * random_double_range_0_1(); // Range (min, max], not including max.
}

vector_3d random_3_d_vector_range_0_1()
{
    return vector_3d {random_double_range_0_1(), random_double_range_0_1(), random_double_range_0_1()};
}

vector_3d random_3_d_vector_range_0_1(double min, double max)
{
    return vector_3d {random_double_range_0_1(min, max), random_double_range_0_1(min, max), random_double_range_0_1(min, max)};
}

vector_3d random_3_d_vector_in_unit_sphere()
{
    while(true) // trial and error(rejection method).
    {
        vector_3d p {random_3_d_vector_range_0_1(-1, 1)};

        if(p.length() >= 1) // Lies outside the unit circle.
        {
            continue;
        }
        return p;
    }
}

vector_3d random_3_d_vector_in_unit_sphere_surface()
{
    return random_3_d_vector_in_unit_sphere().unit_vector();
}

vector_3d reflect(const vector_3d &incident_ray, const vector_3d &normal)
{
    return incident_ray - 2 * (dot(incident_ray, normal) * normal); // "dot()" will return a '-ve' value.
}

#endif