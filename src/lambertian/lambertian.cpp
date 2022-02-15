/*
Created by  : Vaisakh Dileep
Date        : 19, September, 2021
Description : Class definition for the lambertian class.
*/

#include "lambertian.hpp"

#include "../ray/ray.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

#include "../solid_colour/solid_colour.hpp"

using namespace std;

lambertian::lambertian() // No-args constructor
    : albedo {make_shared<solid_colour>(colour_3d {0, 0, 0})}
{
}

lambertian::lambertian(colour_3d colour) // Overloaded constructor
    : albedo {make_shared<solid_colour>(colour)}
{
}

bool lambertian::scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const
{
    vector_3d scatter_direction {record.normal + random_3_d_vector_in_unit_sphere_surface()};

    scattered_ray = ray {record.p, scatter_direction, incident_ray.time()};

    attenuation = albedo->colour_output(record.latitude, record.longitude, record.p);

    return true; // It will always scatter.
}