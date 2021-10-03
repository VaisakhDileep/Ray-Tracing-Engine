/*
Created by  : Vaisakh Dileep
Date        : 19, September, 2021
Description : Class definition for the lambertian class.
*/

#ifndef _LAMBERTIAN_HPP_
#define _LAMBERTIAN_HPP_

#include "../material/material.hpp"

using namespace std;

class lambertian: public material
{
public:
    colour_3d albedo;

    lambertian(); // No-args constructor

    lambertian(colour_3d albedo); // Overloaded constructor

    virtual bool scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const override;
};

#endif