/*
Created by  : Vaisakh Dileep
Date		: 3, September, 2021
Description : Class definition for the hitable class.
*/

#ifndef _HITABLE_HPP_
#define _HITABLE_HPP_

#include "../ray/ray.hpp"

struct hit_record
{
	double t;

	vector_3d p;

	vector_3d normal;
};

class hitable // Abstract class
{
public:
	virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const = 0;
};
#endif