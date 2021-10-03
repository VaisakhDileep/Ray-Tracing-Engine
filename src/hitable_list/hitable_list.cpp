/*
Created by  : Vaisakh Dileep
Date        : 10, September, 2021
Description : Class implementation for the hitable_list class.
*/

#include "hitable_list.hpp"

#include<vector>

#include<memory>

using namespace std;

hitable_list::hitable_list() // No-args constructor
{
}

hitable_list::hitable_list(vector<shared_ptr<hitable>> object_list) // Overloaded constructor
    : object_list {object_list}
{
}

void hitable_list::add_object(shared_ptr<hitable> object) // Adds an object to the vector list.
{
    object_list.push_back(object);
}

void hitable_list::clear_object_list() // This will clear the vector list.
{
    object_list.clear();
}

bool hitable_list::hit(const ray &r, double t_min, double t_max, hit_record &record) const
{
    hit_record hit_record_current_object {};

    bool hit_anything {false};

    double closest_object_so_far {t_max};

    for(int i {0}; i < object_list.size(); i++)
    {
        if(object_list[i]->hit(r, t_min, closest_object_so_far, hit_record_current_object))
        {
            hit_anything = true;

            closest_object_so_far = hit_record_current_object.t;

            record = hit_record_current_object;
        }
    }

    return hit_anything;
}