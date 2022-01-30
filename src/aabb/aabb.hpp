/*
Created by  : Vaisakh Dileep
Date        : 30, January, 2022
Description : Class declaration for the aabb class.
*/

#ifndef _AABB_HPP_
#define _AABB_HPP_

#include "../ray/ray.hpp"

class aabb
{
public:
    point_3d minimum_limit;

    point_3d maximum_limit;

    aabb(); // No-args constructor
    aabb(const point_3d minimum_limit, const point_3d maximum_limit); // Overloaded constructor

    point_3d minimum() const;
    point_3d maximum() const;

    bool hit(const ray &r, double t_min, double t_max) const;
};


aabb surrounding_box(aabb box_1, aabb box_2);

#endif