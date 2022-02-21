/*
Created by  : Vaisakh Dileep
Date        : 19, September, 2021
Description : Class declaration for the lambertian class.
*/

#ifndef _LAMBERTIAN_HPP_
#define _LAMBERTIAN_HPP_

#include "../material/material.hpp"

#include "../texture/texture.hpp"

using namespace std;

class lambertian: public material
{
public:
    shared_ptr<texture> albedo;

    lambertian(); // No-args constructor
    lambertian(colour_3d colour); // Overloaded constructor
    lambertian(shared_ptr<texture> custom_texture); // Overloaded constructor

    virtual bool scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const override;
};

#endif