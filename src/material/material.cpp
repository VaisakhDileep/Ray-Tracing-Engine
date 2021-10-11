/*
Created by  : Vaisakh Dileep
Date        : 11, October, 2021
Description : Class definition for the material class.
*/

#include "material.hpp"

using namespace std;

bool material::scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray) const // For metal and lambertian.
{
}

bool material::scatter(const ray &incident_ray, const hit_record &record, colour_3d &attenuation, ray &scattered_ray, double refractive_index_incident_material) const // For dielectric.
{
}