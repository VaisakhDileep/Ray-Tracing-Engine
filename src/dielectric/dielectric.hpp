/*
Created by  : Vaisakh Dileep
Date        : 11, October, 2021
Description : Class declaration for the dielectric class.
*/

#ifndef _DIELECTRIC_HPP_
#define _DIELECTRIC_HPP_

#include "../material/material.hpp"

using namespace std;

class dielectric: public material
{
public:
    double refractive_index_medium;

    double refractive_index_external_medium;

    dielectric(); // No-args constructor

    dielectric(double refractive_index_medium); // Overloaded constructor

    dielectric(double refractive_index_medium, double refractive_index_external_medium); // Overloaded constructor

    virtual bool scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const override;
};

#endif