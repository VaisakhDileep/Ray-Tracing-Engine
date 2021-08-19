/*
Created by  : Vaisakh Dileep
Date		: 18, August, 2021
Description : Class defintion for the vector class(3 dimensional).
*/

#ifndef _VECTOR_3_D_
#define _VECTOR_3_D_

#include<iostream>

class vector_3d
{
public:
	double d[3];

	vector_3d(); // No-args constructor
	vector_3d(double d1, double d2, double d3); // Overloaded constructor

	vector_3d(const vector_3d &source); // Copy constructor

	vector_3d(vector_3d &&source); // Move constructor

	inline double x() const; // returns the x-coordinate
	inline double y() const; // returns the y-coordinate
	inline double z() const; // returns the z-coordinate

	inline double r() const; // return red value
	inline double g() const; // return green value
	inline double b() const; // return blue value

	inline const vector_3d& operator+() const; // Unary + operator
	inline vector_3d operator-() const; // Unary - operator

	inline double operator[](int i) const; // Subscript operator
	inline double& operator[](int i); // Subscript operator that returns by reference, fails for constant objects.

	friend std::ostream& operator<<(std::ostream &os, const vector_3d &rhs); // Stream insertion operator

	friend std::istream& operator>>(std::istream &is, vector_3d &rhs); // Stream extraction operator

	inline vector_3d& operator+=(const vector_3d &rhs);
	inline vector_3d& operator-=(const vector_3d &rhs);

	inline vector_3d& operator*=(const vector_3d &rhs);
	inline vector_3d& operator/=(const vector_3d &rhs);

	inline vector_3d& operator*=(const double rhs); // Scalar operation
	inline vector_3d& operator/=(const double rhs); // Scalar operation

	friend vector_3d operator+(const vector_3d &lhs, const vector_3d &rhs); // Binary + operator(l-value + l-value)
	friend vector_3d operator-(const vector_3d &lhs, const vector_3d &rhs); // Binary - operator(l-value + l-value)

	friend vector_3d operator*(const vector_3d &lhs, const vector_3d &rhs); // Binary * operator(l-value + l-value)
	friend vector_3d operator/(const vector_3d &lhs, const vector_3d &rhs); // Binary / operator(l-value + l-value)

	friend vector_3d operator*(const vector_3d &lhs, double rhs); // Binary * operator(l-value + double)
	friend vector_3d operator/(const vector_3d &lhs, double rhs); // Binary / operator(l-value + double)

	friend vector_3d operator*(double lhs, const vector_3d &rhs); // Binary * operator(double + l-value)
	friend vector_3d operator/(double lhs, const vector_3d &rhs); // Binary / operator(double + l-value)

	inline double dot(const vector_3d &rhs);

	inline double cross(const vector_3d &rhs);

	inline double length() const;

	inline double squared_length() const;

	inline void make_unit_vector();

	inline vector_3d unit_vector(vector_3d vec);
};

#endif