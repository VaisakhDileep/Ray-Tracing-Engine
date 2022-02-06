/*
Created by  : Vaisakh Dileep
Date        : 30, January, 2022
Description : Class declration for the bvh class.
*/

#ifndef _BVH_HPP_
#define _BVH_HPP_

#include "../hitable/hitable.hpp"

#include "../hitable_list/hitable_list.hpp"

bool box_compare(const shared_ptr<hitable> object_1, const shared_ptr<hitable> object_2, int axis);

bool box_compare_x(const shared_ptr<hitable> object_1, const shared_ptr<hitable> object_2);
bool box_compare_y(const shared_ptr<hitable> object_1, const shared_ptr<hitable> object_2);
bool box_compare_z(const shared_ptr<hitable> object_1, const shared_ptr<hitable> object_2);
// Note: We can't make the following functions as member methods since we need these functions to be passed to the STL algorithms.

class bvh_node : public hitable
{
public:
    shared_ptr<hitable> left_branch;

    shared_ptr<hitable> right_branch;

    aabb box;

    bvh_node(); // No-args constructor
    bvh_node(const vector<shared_ptr<hitable>> &objects, size_t start, size_t end, double time_0, double time_1); // Overloaded constructor
    bvh_node(const hitable_list &object_hitable_list, double time_0, double time_1); // Overloaded constructor

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const override;

    virtual bool bounding_box(double time_0, double time_1, aabb &output_box) const override;
};

#endif