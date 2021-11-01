/*
Created by  : Vaisakh Dileep
Date        : 3, October, 2021
Description : Utility functions for the ray-tracing engine(definition).
*/

#include "ray_tracing_utility.hpp"

#include<math.h>

void initialize_p_3_file(ofstream &out_file, int width, int height)
{
    out_file<<"P3\n";
    out_file<<width<<" "<<height<<"\n";
    out_file<<"255\n";
}

double random_double_range_0_1()
{
    return static_cast<double>(rand()) / (RAND_MAX + 1.0); // Range (0, 1], not including 1.
}

double random_double_range_0_1(double min, double max)
{
    return min + (max - min) * random_double_range_0_1(); // Range (min, max], not including max.
}

vector_3d random_3_d_vector_range_0_1()
{
    return vector_3d {random_double_range_0_1(), random_double_range_0_1(), random_double_range_0_1()};
}

vector_3d random_3_d_vector_range_0_1(double min, double max)
{
    return vector_3d {random_double_range_0_1(min, max), random_double_range_0_1(min, max), random_double_range_0_1(min, max)};
}

vector_3d random_3_d_vector_in_unit_sphere()
{
    while(true) // trial and error(rejection method).
    {
        vector_3d p {random_3_d_vector_range_0_1(-1, 1)};

        if(p.length() >= 1) // Lies outside the unit circle.
        {
            continue;
        }
        return p;
    }
}

vector_3d random_3_d_vector_in_unit_sphere_surface()
{
    return random_3_d_vector_in_unit_sphere().unit_vector();
}

vector_3d reflect(const vector_3d &incident_ray, const vector_3d &normal)
{
    return incident_ray - 2 * (dot(incident_ray, normal) * normal); // "dot()" will return a '-ve' value.
}

vector_3d refract(const vector_3d &incident_ray_direction, const vector_3d &normal, double relative_refractive_index) // "relative_refractive_index" = (refractive index of tranmitted medium / refractive index of incident medium).
{
// normal will always be a unit_vector in my ray-tracing engine, so no need to handle it.

    vector_3d incident_ray_unit_vector {incident_ray_direction.unit_vector()};

    double cos_incident_angle {dot(-incident_ray_unit_vector, normal)}; // We reverse "incident_ray_unit_vector" so that "incident_ray_unit_vector" and "normal" are in the same direction.

    vector_3d transmitted_ray_component_perpendicular_to_normal {relative_refractive_index * (incident_ray_unit_vector + cos_incident_angle * normal)}; // Will be tangential to the normal.

    vector_3d transmitted_ray_component_parallel_to_normal {-sqrt(fabs(1.00 - transmitted_ray_component_perpendicular_to_normal.squared_length())) * normal}; // Will be in the same direction as that of normal.

    return transmitted_ray_component_perpendicular_to_normal + transmitted_ray_component_parallel_to_normal;
}

double schlicks_approximation(double cos_incident_angle, double relative_refractive_index)
{
    double R_zero {pow((1 - relative_refractive_index) / (1 + relative_refractive_index), 2)};

    double R_theta {R_zero + (1 - R_zero) * pow((1 - cos_incident_angle), 5)}; // Probability that the ray is reflected.

    return R_theta;
}

double degrees_to_radians(double degree)
{
    return (degree * pi) / 180.00;
}