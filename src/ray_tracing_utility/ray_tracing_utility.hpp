/*
Created by  : Vaisakh Dileep
Date		: 10, September, 2021
Description : Class definition for the ray_tracing_utility class.
*/

#ifndef _RAY_TRACING_UTILITY_HPP_
#define _RAY_TRACING_UTILITY_HPP_

#define _USE_MATH_DEFINES // we need to use "_USE_MATH_DEFINES" inorder to use "M_PI". Make sure to define it before include the "math.h" library.

#include<fstream>

#include<limits>

#include<cstdlib>

#include<math.h>

using namespace std;

const double infinity {numeric_limits<double>::infinity()};

const double pi {M_PI};

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

#endif