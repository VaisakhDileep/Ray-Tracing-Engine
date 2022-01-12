/*
Created by  : Vaisakh Dileep
Date        : 11, January, 2022
Description : Class definition for the moving_sphere class.
*/

#include "moving_sphere.hpp"

#include<math.h>

using namespace std;

moving_sphere::moving_sphere() // No-args constructor
    : center_0 {point_3d {0, 0, 0}}, center_1 {point_3d {0, 0, 0}}, time_0 {0.0}, time_1 {0.0}, radius {0.0}, material_ptr {nullptr}
{
}

moving_sphere::moving_sphere(point_3d center_0, point_3d center_1, double time_0, double time_1, double radius) // Overloaded constructor
    : center_0 {center_0}, center_1 {center_1}, time_0 {time_0}, time_1 {time_1}, radius {radius}
{
}

moving_sphere::moving_sphere(point_3d center_0, point_3d center_1, double time_0, double time_1, double radius, shared_ptr<material> material_ptr) // Overloaded constructor
    : center_0 {center_0}, center_1 {center_1}, time_0 {time_0}, time_1 {time_1}, radius {radius}, material_ptr {material_ptr}
{
}

point_3d moving_sphere::center(double time) const
{
    return center_0 + ((time - time_0) / (time_1 - time_0)) * (center_1 - center_0);
}

bool moving_sphere::hit(const ray &r, double t_min, double t_max, hit_record &record) const
{
    vector_3d ray_origin_to_center_of_sphere {r.origin() - center(r.time())};

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

            vector_3d outer_normal {(r.point_at_parameter(solution) - center(r.time())).make_unit_vector()};

            if(radius < 0) // Sometimes we specify the radius as a negative value to suggest that the normal should be in the same direction as the incoming ray.
            {
                outer_normal *= -1;
            }

            record.set_face_normal(r, outer_normal);

            return true;
        }

        solution = (-b + sqrt(discriminant)) / (2 * a);

        if((solution > t_min) and (solution < t_max))
        {
            record.t = solution;

            record.p = r.point_at_parameter(solution);

            record.material_ptr = material_ptr;

            vector_3d outer_normal {(r.point_at_parameter(solution) - center(r.time())).make_unit_vector()};

            if(radius < 0) // Sometimes we specify the radius as a negative value to suggest that the normal should be in the same direction as the incoming ray.
            {
                outer_normal *= -1;
            }

            record.set_face_normal(r, outer_normal);

            return true;
        }
    }

    return false;
}