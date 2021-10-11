/*
Created by  : Vaisakh Dileep
Date        : 14, September, 2021
Description : Class for material.
*/

#ifndef _MATERIAL_HPP_
#define _MATERIAL_HPP_

#include "../hitable/hitable.hpp"

struct hit_record; // Forward declaration.

class material
{
public:
    virtual bool scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const; // For metal and lambertian.

    virtual bool scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray, double refractive_index_incident_material) const; // For dielectric.
};

#endif