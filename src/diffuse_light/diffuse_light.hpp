/*
Created by  : Vaisakh Dileep
Date        : 23, February, 2022
Description : Class declaration for the the diffuse_light class.
*/

#ifndef _DIFFUSE_LIGHT_HPP_
#define _DIFFUSE_LIGHT_HPP_

#include "../material/material.hpp"

#include "../texture/texture.hpp"

class diffuse_light: public material
{
public:
    shared_ptr<texture> emitted_texture;

    diffuse_light(); // No-args constructor
    diffuse_light(shared_ptr<texture> custom_texture); // Overloaded constructor
    diffuse_light(colour_3d colour_value); // Overloaded constructor

    virtual colour_3d emitted_colour(double latitude, double longitude, const point_3d &p) const;

    virtual bool scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const;
};

#endif