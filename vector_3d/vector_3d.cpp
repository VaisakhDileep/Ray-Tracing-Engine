/*
Created by  : Vaisakh Dileep
Date		: 18, August, 2021
Description : Class definition for the vector class(3 dimensional).
*/

#include "vector_3d.hpp"

vector_3d::vector_3d() // No-args constructor
{
	for(int i {0}; i < 3; i++)
	{
		d[i] = 0;
	}
}

vector_3d::vector_3d(double d1, double d2, double d3) // Overloaded constructor
{
	d[0] = d1;
	d[1] = d2;
	d[2] = d3;
}

vector_3d::vector_3d(const vector_3d &source) // Copy constructor
{
	d[0] = source.d[0];
	d[1] = source.d[1];
	d[2] = source.d[2];
}

vector_3d::vector_3d(vector_3d &&source) // Move constructor
{
	d[0] = source.d[0];
	d[1] = source.d[1];
	d[2] = source.d[2];
}

double vector_3d::x() const // returns the x-coordinate
{
	return d[0];
}

double vector_3d::y() const // returns the y-coordinate
{
	return d[1];
}

double vector_3d::z() const // returns the z-coordinate
{
	return d[2];
}

double vector_3d::r() const // returns the red value
{
	return d[0];
}

double vector_3d::g() const // returns the green value
{
	return d[1];
}

double vector_3d::b() const // returns the blue value
{
	return d[2];
}

const vector_3d& vector_3d::operator+() const // Unary + operator
{
	return *this;
}

vector_3d vector_3d::operator-() const // Unary - operator
{
	return vector_3d {-d[0], -d[1], -d[2]};
}

double vector_3d::operator[](int i) const // Subscript operator
{
	if((i < 0) or (i >= 3))
	{
		throw std::string {"[ERROR] vector_3d --> double vector_3d::operator[](int i) const --> index not valid, 0 < i < 2 .....\n"};
	}
	return d[i];
}

double& vector_3d::operator[](int i) // Subscript operator that returns by reference, fails for constant objects.
{
	if((i < 0) or (i >= 3))
	{
		throw std::string {"[ERROR] vector_3d --> double& vector_3d::operator[](int i) --> index not valid, 0 < i < 2 .....\n"};
	}
	return d[i];
}