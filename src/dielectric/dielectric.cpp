/*
Created by  : Vaisakh Dileep
Date        : 11, October, 2021
Description : Class definition for the dielectric class.
*/

#include "dielectric.hpp"

#include "../ray/ray.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

#include<math.h>

using namespace std;

dielectric::dielectric() // No-args constructor
    : refractive_index_medium {0.0}, refractive_index_external_medium {1.0} // "refractive_index_external_medium" will default to '1.0'.
{
}

dielectric::dielectric(double refractive_index_medium) // Overloaded constructor
    : refractive_index_medium {refractive_index_medium}, refractive_index_external_medium {1.0} // "refractive_index_external_medium" will default to '1.0'.
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

    if(record.outer_face == true) // If the radius is given as negative, then it will invert the "record.outer_face" value thereby inverting the refractive indices.
    {
        relative_refractive_index = refractive_index_external_medium / refractive_index_medium;
    }
    else
    {
        relative_refractive_index = refractive_index_medium / refractive_index_external_medium;
    }

    vector_3d incident_ray_unit_vector {incident_ray.direction().unit_vector()};

    double cos_incident_angle {dot(-incident_ray_unit_vector, record.normal)}; // We reverse "incident_ray_unit_vector" so that "incident_ray_unit_vector" and "normal" are in the same direction.

    double sin_incident_angle {sqrt(1.00 - cos_incident_angle * cos_incident_angle)};

    vector_3d refracted_ray_direction {};

    if((relative_refractive_index * sin_incident_angle > 1.00) or (schlicks_approximation(cos_incident_angle, relative_refractive_index) > random_double_range_0_1()))  // The ray will be reflected if it doesn't obey snell's law. Some of the rays will also be reflected depending on the angle of incidence(schlick's approximation).
    {
        refracted_ray_direction = reflect(incident_ray.direction(), record.normal);
    }
    else // Obeys snell's law, the ray will refract.
    {
        refracted_ray_direction = refract(incident_ray.direction(), record.normal, relative_refractive_index);
    }

    scattered_ray = ray {record.p, refracted_ray_direction, incident_ray.time()};

    return true;
}