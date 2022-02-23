/*
Created by  : Vaisakh Dileep
Date        : 23, February, 2022
Description : Class definition for the diffuse_light class.
*/

#include "diffuse_light.hpp"

#include "../solid_colour/solid_colour.hpp"

diffuse_light::diffuse_light() // No-args constructor
    : emitted_texture {make_shared<solid_colour>(colour_3d {0, 0, 0})}
{
}

diffuse_light::diffuse_light(shared_ptr<texture> custom_texture) // Overloaded constructor
    : emitted_texture {custom_texture}
{
}

diffuse_light::diffuse_light(colour_3d colour) // Overloaded constructor
    : emitted_texture {make_shared<solid_colour>(colour)}
{
}

bool diffuse_light::scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const
{
    return false;
}

colour_3d diffuse_light::emitted_colour(double latitude, double longitude, const point_3d &p) const
{
    return emitted_texture->colour_output(latitude, longitude, p);
}