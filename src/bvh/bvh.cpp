/*
Created by  : Vaisakh Dileep
Date        : 30, January, 2022
Description : Class definition for the bvh class.
*/

#include<algorithm>

#include "../bvh/bvh.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

using namespace std;

bool box_compare(const shared_ptr<hitable> object_1, const shared_ptr<hitable> object_2, int axis) // returns "true" if object_1 < object_2.
{
    aabb box_1 {}, box_2 {};

    if((object_1->bounding_box(0, 0, box_1) == false) or (object_2->bounding_box(0, 0, box_2) == false))
    {
        cerr<<"No bounding box could be found for the bvh_node .....";
    }

    return box_1.minimum().d[axis] < box_2.minimum().d[axis];
}

bool box_compare_x(const shared_ptr<hitable> object_1, const shared_ptr<hitable> object_2)
{
    return box_compare(object_1, object_2, 0);
}

bool box_compare_y(const shared_ptr<hitable> object_1, const shared_ptr<hitable> object_2)
{
    return box_compare(object_1, object_2, 1);
}

bool box_compare_z(const shared_ptr<hitable> object_1, const shared_ptr<hitable> object_2)
{
    return box_compare(object_1, object_2, 2);
}

bvh_node::bvh_node() // No-args constructor
    : left_branch {}, right_branch {}, box {}
{
}

bvh_node::bvh_node(const vector<shared_ptr<hitable>> &objects, size_t start, size_t end, double time_0, double time_1) // Overloaded constructor
{
    vector<shared_ptr<hitable>> objects_mutable {objects}; // creates a copy of "objects" that is mutable.

    int axis {random_int(0, 2)};

    bool (*compare_function)(shared_ptr<hitable>, shared_ptr<hitable>) {}; // pointer to function.

    if(axis == 0)
    {
        compare_function = box_compare_x;
    }
    else if(axis == 1)
    {
        compare_function = box_compare_y;
    }
    else
    {
        compare_function = box_compare_z;
    }

    int object_count {end - start};

    if(object_count == 1)
    {
        left_branch = right_branch = objects_mutable[start];
    }
    else if(object_count == 2)
    {
        if(compare_function(objects_mutable[start], objects_mutable[end - 1]) == true)
        {
            left_branch = objects_mutable[start];

            right_branch = objects_mutable[end - 1];
        }
        else
        {
            left_branch = objects_mutable[end - 1];

            right_branch = objects_mutable[start];
        }
    }
    else
    {
        sort(objects_mutable.begin() + start, objects_mutable.begin() + end, compare_function);

        int mid {(start + end) / 2};

        left_branch = make_shared<bvh_node>(objects_mutable, start, mid, time_0, time_1);

        right_branch = make_shared<bvh_node>(objects_mutable, mid, end, time_0, time_1);
    }

    aabb left_box {}, right_box {};

    if((left_branch->bounding_box(time_0, time_1, left_box) == false) or (right_branch->bounding_box(time_0, time_1, right_box) == false))
    {
        cerr<<"No bounding box could be found for the bvh_node .....";
    }

    box = surrounding_box(left_box, right_box);
}

bvh_node::bvh_node(const hitable_list &object_hitable_list, double time_0, double time_1) // Overloaded constructor
    : bvh_node(object_hitable_list.object_list, 0, object_hitable_list.object_list.size(), time_0, time_1)
{
}

bool bvh_node::hit(const ray &r, double t_min, double t_max, hit_record &record) const
{
    if(box.hit(r, t_min, t_max) == false)
    {
        return false;
    }

    bool left_branch_hit {left_branch->hit(r, t_min, t_max, record)};

    bool right_branch_hit {};

    if(left_branch_hit == true)
    {
        right_branch_hit = right_branch->hit(r, t_min, record.t, record);
    }
    else
    {
        right_branch_hit = right_branch->hit(r, t_min, t_max, record);
    }

    return (left_branch_hit or right_branch_hit);
}

bool bvh_node::bounding_box(double time_0, double time_1, aabb &output_box) const // returns(through "output_box") the "bounding_box" of the node.
{
    output_box = box;

    return true;
}