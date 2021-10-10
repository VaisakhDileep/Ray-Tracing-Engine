/*
Created by  : Vaisakh Dileep
Date        : 20, September, 2021
Description : Class definition for the metal class.
*/

#include "metal.hpp"

#include "../ray/ray.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

using namespace std;

metal::metal() // No-args constructor
    : albedo {0, 0, 0}
{
}

metal::metal(colour_3d albedo) // Overloaded constructor
    : albedo {albedo}
{
}

bool metal::scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const
{
    vector_3d reflected_ray_direction {reflect(incident_ray.direction(), record.normal)};

    scattered_ray = ray {record.p, reflected_ray_direction};

    attenuation = albedo;

    if(dot(scattered_ray.direction(), record.normal) == 0) // Since both of them are unit-vectors, if they are in opposite direction, they will null out(angle of incidence is '0 degree').
    {
        return false;
    }
    return true;
}