/*
Created by  : Vaisakh Dileep
Date        : 11, September, 2021
Description : Class definition for the camera class.
*/

#include "camera.hpp"

#include "../ray_tracing_utility/ray_tracing_utility.hpp"

#include "math.h"

// Note: We are using the right-handed coordinate system here.

camera::camera() // No-args constructor
    : origin {0, 0, 0}, upper_left_corner {0, 0, 0}, horizontal_sweep {0, 0, 0}, vertical_sweep {0, 0, 0}
{
}

camera::camera(point_3d origin, vector_3d upper_left_corner, vector_3d horizontal_sweep, vector_3d vertical_sweep) // Overloaded constructor
    : origin {origin}, upper_left_corner {upper_left_corner}, horizontal_sweep {horizontal_sweep}, vertical_sweep {vertical_sweep}
{
}

camera::camera(double vertical_fov, double aspect_ratio) // Overloaded constructor
{
    origin = vector_3d {0, 0, 0};

    double theta {degrees_to_radians(vertical_fov)}; // "vertical_fov" stands for vertical field-of-view.

    double vector_plane_half_height {tan(theta / 2)};

    double vector_plane_half_width {aspect_ratio * vector_plane_half_height}; // aspect_ratio = width_vector_plane / height_vector_plane

    horizontal_sweep = vector_3d {2 * vector_plane_half_width, 0, 0};

    vertical_sweep = vector_3d {0, -2 * vector_plane_half_height, 0};

    upper_left_corner = vector_3d {-vector_plane_half_width, vector_plane_half_height, -1};
}

camera::camera(point_3d look_from, point_3d look_at, vector_3d up_vector, double vertical_fov, double aspect_ratio) // Overloaded constructor
{
    double theta {degrees_to_radians(vertical_fov)}; // "vertical_fov" stands for vertical field-of-view.

    double vector_plane_half_height {tan(theta / 2)};

    double vector_plane_half_width {aspect_ratio * vector_plane_half_height}; // aspect_ratio = width_vector_plane / height_vector_plane

    origin = look_from;

    w = (look_from - look_at).unit_vector();

    u = cross(up_vector, w).unit_vector();

    v = cross(w, u); // Since 'w' and 'u' are already unit vectors, their cross product also results in a unit vector.

    horizontal_sweep = 2 * vector_plane_half_width * u;

    vertical_sweep = -2 * vector_plane_half_height * v;

    upper_left_corner = origin - (vector_plane_half_width * u) + (vector_plane_half_height * v) - w; // This is with respect to {0, 0, 0} not the new origin. The view-plane is 'w' units in front of the camera(the camera is at the new origin("look_from")).
}

camera::camera(point_3d look_from, point_3d look_at, vector_3d up_vector, double vertical_fov, double aspect_ratio, double aperture, double focus_distance) // Overloaded constructor
{
    double theta {degrees_to_radians(vertical_fov)}; // "vertical_fov" stands for vertical field-of-view.

    double vector_plane_half_height {tan(theta / 2)}; // This is considering that the camera is placed '1' unit behind the vector plane(object plane).

    double vector_plane_half_width {aspect_ratio * vector_plane_half_height}; // aspect_ratio = width_vector_plane / height_vector_plane

    origin = look_from;

    w = (look_from - look_at).unit_vector();

    u = cross(up_vector, w).unit_vector();

    v = cross(w, u); // Since 'w' and 'u' are already unit vectors, their cross product also results in a unit vector.

    horizontal_sweep = focus_distance * (2 * vector_plane_half_width) * u; // Since we are using a pinhole camera, the magnification is linear. 'm' units away from the camera(focus distance) will result in a 'm' times magnification.

    vertical_sweep = focus_distance * (-2 * vector_plane_half_height) * v;

// Note: Here we don't have an object plane, but a focus plane. We shoot the rays to the focus plane.

    upper_left_corner = origin - horizontal_sweep / 2 - vertical_sweep / 2 - focus_distance * w; // This is with respect to {0, 0, 0} not the new origin. The view-plane is "focus_distance * w" units in front of the camera(the camera is at the new origin("look_from")).

// Note: For "upper_left_corner" we used "-vertical_sweep / 2" because "vertical_sweep" is already negative and we need a positive value.

    lens_radius = aperture / 2; // aperture is the diameter.
}

void camera::set_origin(point_3d origin)
{
    this->origin = origin;
}

void camera::set_upper_left_corner(vector_3d upper_left_corner)
{
    this->upper_left_corner = upper_left_corner;
}

void camera::set_horizontal_sweep(vector_3d horizontal_sweep)
{
    this->horizontal_sweep = horizontal_sweep;
}

void camera::set_vertical_sweep(vector_3d vertical_sweep)
{
    this->vertical_sweep = vertical_sweep;
}

ray camera::get_ray(double r, double c) const
{
    vector_3d random_vec {lens_radius * random_3_d_vector_in_unit_sphere()}; // This is a random point inside a sphere of radius "lens_radius" and center at {0, 0, 0}.

    vector_3d offset = u * random_vec.x() + v * random_vec.y();

    return ray {origin + offset, upper_left_corner + (r * horizontal_sweep) + (c * vertical_sweep) - origin - offset}; // This is with respect to the camera.
}