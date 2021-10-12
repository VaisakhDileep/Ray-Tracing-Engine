/*
Created by  : Vaisakh Dileep
Date        : 11, October, 2021
Description : Class definition for the dielectric class.
*/

#include "dielectric.hpp"

#include "../ray/ray.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

using namespace std;

dielectric::dielectric() // No-args constructor
    : refractive_index_medium {0.0}
{
}

dielectric::dielectric(double refractive_index_medium) // Overloaded constructor
    : refractive_index_medium {refractive_index_medium}
{
}

dielectric::dielectric(double refractive_index_medium, double refractive_index_external_medium) // Overloaded constructor
    : refractive_index_medium {refractive_index_medium}, refractive_index_external_medium {refractive_index_external_medium}
{
}

bool dielectric::scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const
{
    attenuation = colour_3d {1, 1, 1};

    double relative_refractive_index {};

    if(record.outer_face == true)
    {
        relative_refractive_index = refractive_index_external_medium / refractive_index_medium;
    }
    else
    {
        relative_refractive_index = refractive_index_medium / refractive_index_external_medium;
    }

    vector_3d refracted_ray_direction {refract(incident_ray.direction(), record.normal, relative_refractive_index)};

    scattered_ray = ray {record.p, refracted_ray_direction};

    return true;
}