/*
Created by  : Vaisakh Dileep
Date        : 19, September, 2021
Description : Class implementation of the lambertian class.
*/

#include "lambertian.hpp"

#include "../ray/ray.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

using namespace std;

lambertian::lambertian() // No-args constructor
    : albedo {0, 0, 0}
{
}

lambertian::lambertian(colour_3d albedo) // Overloaded constructor
    : albedo {albedo}
{
}

bool lambertian::scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const
{
    vector_3d scatter_direction {record.normal + random_3_d_vector_in_unit_sphere_surface()};

    scattered_ray = ray {record.p, scatter_direction};

    attenuation = albedo;

    return true; // It will always scatter.
}