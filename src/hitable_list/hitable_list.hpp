/*
Created by  : Vaisakh Dileep
Date        : 10, September, 2021
Description : Class definition for the hitable_list class.
*/

#ifndef _HITABLE_LIST_HPP_
#define _HITABLE_LIST_HPP_

#include "../hitable/hitable.hpp"

#include<vector>

#include<memory>

using namespace std;

class hitable_list: public hitable
{
public:
    vector<shared_ptr<hitable>> object_list;

    hitable_list(); // No-args constructor

    hitable_list(vector<shared_ptr<hitable>> object_list); // Overloaded constructor

    void add_object(shared_ptr<hitable> object); // Adds an object to the vector list.

    void clear_object_list(); // This will clear the vector list.

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const override;
};

#endif