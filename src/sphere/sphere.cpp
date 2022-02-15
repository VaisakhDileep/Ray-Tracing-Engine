/*
Created by  : Vaisakh Dileep
Date        : 8, September, 2021
Description : Class definition for the sphere class.
*/

#include "sphere.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

#include<math.h>

using namespace std;

sphere::sphere() // No-args constructor
    : center {point_3d {0, 0, 0}}, radius {0}, material_ptr {nullptr}
{
}

sphere::sphere(point_3d center, double radius) // Overloaded constructor
    : center {center}, radius {radius}, material_ptr {nullptr}
{
}

sphere::sphere(point_3d center, double radius, shared_ptr<material> material_ptr) // Overloaded constructor
    : center {center}, radius {radius}, material_ptr {material_ptr}
{
}

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &record) const
{
    vector_3d ray_origin_to_center_of_sphere {r.origin() - center};

    double a {dot(r.direction(), r.direction())}; // ax^2 + bx^1 + cx^0

    double b {2 * dot(ray_origin_to_center_of_sphere, r.direction())};

    double c {dot(ray_origin_to_center_of_sphere, ray_origin_to_center_of_sphere) - (radius * radius)};

    double discriminant {(b * b) - (4 * a * c)};

    if(discriminant > 0)
    {
        double solution = (-b - sqrt(discriminant)) / (2 * a);

        if((solution > t_min) and (solution < t_max))
        {
            record.t = solution;

            record.p = r.point_at_parameter(solution);

            record.material_ptr = material_ptr;

            vector_3d outer_normal {(r.point_at_parameter(solution) - center).make_unit_vector()};

            if(radius < 0) // Sometimes we specify the radius as a negative value to suggest that the normal should be in the same direction as that of the incoming ray.
            {
                outer_normal *= -1;
            }

            get_sphere_lat_long(outer_normal, record.latitude, record.longitude);

            record.set_face_normal(r, outer_normal);

            return true;
        }

        solution = (-b + sqrt(discriminant)) / (2 * a);

        if((solution > t_min) and (solution < t_max))
        {
            record.t = solution;

            record.p = r.point_at_parameter(solution);

            record.material_ptr = material_ptr;

            vector_3d outer_normal {(r.point_at_parameter(solution) - center).make_unit_vector()};

            if(radius < 0) // Sometimes we specify the radius as a negative value to suggest that the normal should be in the same direction as that of the incoming ray.
            {
                outer_normal *= -1;
            }

            get_sphere_lat_long(outer_normal, record.latitude, record.longitude);

            record.set_face_normal(r, outer_normal);

            return true;
        }
    }

    return false;
}

bool sphere::bounding_box(double time_0, double time_1, aabb &output_box) const
{
    output_box = aabb {center - vector_3d {radius, radius, radius}, center + vector_3d {radius, radius, radius}};

    return true;
}

void sphere::get_sphere_lat_long(const point_3d &p, double &latitude, double &longitude)
{
    latitude = (acos(-p.y())) / pi;

    longitude = (atan2(-p.z(), p.x()) + pi) / (2 * pi);
}