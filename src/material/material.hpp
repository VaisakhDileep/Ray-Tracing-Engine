/*
Created by  : Vaisakh Dileep
Date        : 14, September, 2021
Description : Abstract class for material.
*/

#ifndef _MATERIAL_HPP_
#define _MATERIAL_HPP_

#include "../hitable/hitable.hpp"

struct hit_record; // Forward declaration.

class material
{
public:
    virtual bool scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const = 0;
};

#endif