/*
Created by  : Vaisakh Dileep
Date        : 30, January, 2022
Description : Class definition for the aabb class.
*/

#include "aabb.hpp"

#include<math.h>

using namespace std;

aabb::aabb() // No-args constructor
    : minimum_limit {0, 0, 0}, maximum_limit {0, 0, 0}
{
}

aabb::aabb(const point_3d minimum_limit, const point_3d maximum_limit) // Overloaded constructor
    : minimum_limit {minimum_limit}, maximum_limit {maximum_limit}
{
}

point_3d aabb::minimum() const
{
    return minimum_limit;
}

point_3d aabb::maximum() const
{
    return maximum_limit;
}

bool aabb::hit(const ray &r, double t_min, double t_max) const // Andrew Kensler's method.
{
    double inverse {};

    for(int i {0}; i < 3; i++)
    {
        inverse = 1.0 / r.direction()[i];

        double t_0 {(minimum()[i] - r.origin()[i]) * inverse};
        double t_1 {(maximum()[i] - r.origin()[i]) * inverse};

        if(inverse < 0.0)
        {
            swap(t_0, t_1);
        }

        if(t_0 > t_min)
        {
            t_min = t_0;
        }

        if(t_1 < t_max)
        {
            t_max = t_1;
        }

        if(t_max <= t_min)
        {
            return false;
        }
    }
    return true;
}

aabb surrounding_box(aabb box_0, aabb box_1)
{
    aabb output_box {};

    output_box.minimum_limit = vector_3d {fmin(box_0.minimum().x(), box_1.minimum().x()), fmin(box_0.minimum().y(), box_1.minimum().y()), fmin(box_0.minimum().z(), box_1.minimum().z())};
    output_box.maximum_limit = vector_3d {fmax(box_0.maximum().x(), box_1.maximum().x()), fmax(box_0.maximum().y(), box_1.maximum().y()), fmax(box_0.maximum().z(), box_1.maximum().z())};

    return output_box;
}