/*
Created by  : Vaisakh Dileep
Date        : 20, September, 2021
Description : Class declaration for the metal class.
*/

#ifndef _METAL_HPP_
#define _METAL_HPP_

#include "../material/material.hpp"

using namespace std;

class metal: public material
{
public:
    colour_3d albedo;

    metal(); // No-args constructor

    metal(colour_3d albedo); // Overloaded constructor

    virtual bool scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const override;
};

#endif