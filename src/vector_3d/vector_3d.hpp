/*
Created by  : Vaisakh Dileep
Date        : 18, August, 2021
Description : Class defintion for the vector class(3 dimensional).
*/

#ifndef _VECTOR_3_D_HPP_
#define _VECTOR_3_D_HPP_

#include<iostream>

class vector_3d
{
public:
    double d[3];

    vector_3d(); // No-args constructor
    vector_3d(double d1, double d2, double d3); // Overloaded constructor

    vector_3d(const vector_3d &source); // Copy constructor
    vector_3d(vector_3d &&source); // Move constructor

    vector_3d& operator=(const vector_3d &rhs); // Copy assignment
    vector_3d& operator=(vector_3d &&rhs); // Move assignment

    double x() const; // returns the x-coordinate
    double y() const; // returns the y-coordinate
    double z() const; // returns the z-coordinate

    double r() const; // returns red value
    double g() const; // returns green value
    double b() const; // returns blue value

    const vector_3d& operator+() const; // Unary + operator
    vector_3d operator-() const; // Unary - operator

    double operator[](int i) const; // Subscript operator
    double& operator[](int i); // Subscript operator that returns by reference, fails for constant objects.

    friend std::ostream& operator<<(std::ostream &os, const vector_3d &rhs); // Stream insertion operator

    friend std::istream& operator>>(std::istream &is, vector_3d &rhs); // Stream extraction operator

    vector_3d& operator+=(const vector_3d &rhs);
    vector_3d& operator-=(const vector_3d &rhs);

    vector_3d& operator*=(const vector_3d &rhs);
    vector_3d& operator/=(const vector_3d &rhs);

    vector_3d& operator*=(const double rhs); // Scalar operation
    vector_3d& operator/=(const double rhs); // Scalar operation

    friend vector_3d operator+(const vector_3d &lhs, const vector_3d &rhs); // Binary + operator(l-value + l-value)
    friend vector_3d operator-(const vector_3d &lhs, const vector_3d &rhs); // Binary - operator(l-value + l-value)

    friend vector_3d operator*(const vector_3d &lhs, const vector_3d &rhs); // Binary * operator(l-value + l-value)
    friend vector_3d operator/(const vector_3d &lhs, const vector_3d &rhs); // Binary / operator(l-value + l-value)

    friend vector_3d operator*(const vector_3d &lhs, double rhs); // Binary * operator(l-value + double)
    friend vector_3d operator/(const vector_3d &lhs, double rhs); // Binary / operator(l-value + double)

    friend vector_3d operator*(double lhs, const vector_3d &rhs); // Binary * operator(double + l-value)

    friend double dot(const vector_3d &lhs, const vector_3d &rhs); // Dot product

    friend vector_3d cross(const vector_3d &lhs, const vector_3d &rhs); // Cross product

    double length() const;

    double squared_length() const;

    vector_3d& make_unit_vector(); // Makes the vector a unit vector

    vector_3d unit_vector() const; // Returns a unit vector

    void convert_0_255_to_0_1(); // Converts colour in [0, 255] format to [0, 1] format

    void convert_0_1_to_0_255(); // Converts colour in [0, 1] format to [0, 255] format.
};

using point_3d = vector_3d; // 3D point

using colour_3d = vector_3d; // RGB values

#endif