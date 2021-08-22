/*
Created by  : Vaisakh Dileep
Date		: 18, August, 2021
Description : Class implementation for the vector class(3 dimensional).
*/

#include "vector_3d.hpp"

#include<math.h>

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

vector_3d& vector_3d::operator=(const vector_3d &rhs) // Copy constructor
{
	if(this == &rhs)
	{
		return *this; // This is useful when chaining assignment operator.
	}

	for(int i {0}; i < 3; i++)
	{
		d[i] = rhs.d[i];
	}

	return *this; // This is useful when chaining assignment operator.
}

vector_3d& vector_3d::operator=(vector_3d &&rhs) // Move constructor
{
	if(this == &rhs)
	{
		return *this; // This is useful when chaining assignment operator.
	}

	for(int i {0}; i < 3; i++)
	{
		d[i] = rhs.d[i];
	}

	return *this; // This is useful when chaining assignment operator.
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

std::ostream& operator<<(std::ostream &os, const vector_3d &rhs) // Stream insertion operator
{
	os<<rhs.d[0]<<" "<<rhs.d[1]<<" "<<rhs.d[2];

	return os;
}

std::istream& operator>>(std::istream &is, vector_3d &rhs) // Stream extraction operator
{
	is>>rhs.d[0]>>rhs.d[1]>>rhs.d[2];

	return is;
}

vector_3d& vector_3d::operator+=(const vector_3d &rhs) // Adds corresponding elements
{
	d[0] += rhs.d[0];
	d[1] += rhs.d[1];
	d[2] += rhs.d[2];

	return *this;
}

vector_3d& vector_3d::operator-=(const vector_3d &rhs) // Subtracts corresponding elements
{
	d[0] -= rhs.d[0];
	d[1] -= rhs.d[1];
	d[2] -= rhs.d[2];

	return *this;
}

vector_3d& vector_3d::operator*=(const vector_3d &rhs) // Multiplies corresponding elements
{
	d[0] *= rhs.d[0];
	d[1] *= rhs.d[1];
	d[2] *= rhs.d[2];

	return *this;
}

vector_3d& vector_3d::operator/=(const vector_3d &rhs) // Divides corresponding elements
{
	d[0] /= rhs.d[0];
	d[1] /= rhs.d[1];
	d[2] /= rhs.d[2];

	return *this;
}

vector_3d& vector_3d::operator*=(const double rhs) // Scalar operation
{
	d[0] *= rhs;
	d[1] *= rhs;
	d[2] *= rhs;

	return *this;
}

vector_3d& vector_3d::operator/=(const double rhs) // Scalar operation
{
	d[0] /= rhs;
	d[1] /= rhs;
	d[2] /= rhs;

	return *this;
}

vector_3d operator+(const vector_3d &lhs, const vector_3d &rhs) // Binary + operator(l-value + l-value)
{
	return vector_3d {lhs.d[0] + rhs.d[0], lhs.d[1] + rhs.d[1], lhs.d[2] + rhs.d[2]};
}

vector_3d operator-(const vector_3d &lhs, const vector_3d &rhs) // Binary - operator(l-value + l-value)
{
	return vector_3d {lhs.d[0] - rhs.d[0], lhs.d[1] - rhs.d[1], lhs.d[2] - rhs.d[2]};
}

vector_3d operator*(const vector_3d &lhs, const vector_3d &rhs) // Binary * operator(l-value + l-value)
{
	return vector_3d {lhs.d[0] * rhs.d[0], lhs.d[1] * rhs.d[1], lhs.d[2] * rhs.d[2]};
}

vector_3d operator/(const vector_3d &lhs, const vector_3d &rhs) // Binary / operator(l-value + l-value)
{
	return vector_3d {lhs.d[0] / rhs.d[0], lhs.d[1] / rhs.d[1], lhs.d[2] / rhs.d[2]};
}

vector_3d operator*(const vector_3d &lhs, double rhs) // Binary * operator(l-value + double)
{
	return vector_3d {lhs.d[0] * rhs, lhs.d[1] * rhs, lhs.d[2] * rhs};
}

vector_3d operator/(const vector_3d &lhs, double rhs) // Binary * operator(l-value + double)
{
	return vector_3d {lhs.d[0] / rhs, lhs.d[1] / rhs, lhs.d[2] / rhs};
}

vector_3d operator*(double lhs, const vector_3d &rhs) // Binary * operator(double + l-value)
{
	return vector_3d {lhs * rhs.d[0], lhs * rhs.d[1], lhs * rhs.d[2]};
}

double dot(const vector_3d &lhs, const vector_3d &rhs) // Dot product
{
	return lhs.d[0] * rhs.d[0] + lhs.d[1] * rhs.d[1] + lhs.d[2] * lhs.d[2];
}

vector_3d cross(const vector_3d &lhs, const vector_3d &rhs) // Cross product
{
	return vector_3d {(lhs.d[1] * rhs.d[2] - rhs.d[1] * lhs.d[2]), -(lhs.d[0] * rhs.d[2] - rhs.d[0] * lhs.d[2]), (lhs.d[0] * rhs.d[1] - rhs.d[0] * lhs[1])};
}

double vector_3d::length() const
{
	return sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
}

double vector_3d::squared_length() const
{
	return d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
}

void vector_3d::make_unit_vector() // Makes the vector a unit vector.
{
	double length {sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2])};

	d[0] /= length;
	d[1] /= length;
	d[2] /= length;
}

vector_3d vector_3d::unit_vector() const // Returns a unit vector.
{
	double length {sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2])};

	return vector_3d {d[0] / length, d[1] / length, d[2] / length};
}