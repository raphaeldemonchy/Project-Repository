/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-raphael.de-monchy
** File description:
** rayTracer.cpp
*/

#include "./include/raytracer/raytracer.hpp"

int objindex(std::vector<double> inter)
{
    int index;
    if (inter.size() == 0)
        return -1;
    else if (inter.size() == 1) {
        if (inter.at(0) > 0)
            return 0;
        else
            return -1;
    } else {
        double max = 0;
        for (int i = 0; i < inter.size(); i++) {
            if (max < inter.at(i))
                max = inter.at(i);
        }
        if (max > 0) {
            for (int i = 0; i < inter.size(); i++) {
                if (inter.at(i) > 0 && inter.at(i) <= max) {
                    max = inter.at(i);
                    index = i;
                }
            }
            return index;
        } else
            return -1;
    }
}

RayTracer::Color getColorAt(Math::Vector3D intersection_position, Math::Vector3D intersecting_ray_direction, std::vector<RayTracer::Object*> scene_objects, int index_of_winning_object, std::vector<RayTracer::Source*> light_sources, double accuracy, double ambientlight) {

	RayTracer::Color winning_object_color = scene_objects.at(index_of_winning_object)->getColor();
	Math::Vector3D winning_object_normal = scene_objects.at(index_of_winning_object)->getNormalAt(intersection_position);

	// if (winning_object_color.s == 2) {
	// 	// checkered/tile floor pattern

	// 	int square = (int)floor(intersection_position.getVectX()) + (int)floor(intersection_position.getVectZ());

	// 	if ((square % 2) == 0) {
	// 		// black tile
	// 		winning_object_color.r = 0;
	// 		winning_object_color.g = 0;
	// 		winning_object_color.b = 0;
	// 	}
	// 	else {
	// 		// white tile
	// 		winning_object_color.r = 1;
	// 		winning_object_color.g = 1;
	// 		winning_object_color.b = 1;
	// 	}
	// }

	RayTracer::Color final_color = winning_object_color.colorScalar(ambientlight);

	// if (winning_object_color.getColorSpecial() > 0 && winning_object_color.getColorSpecial() <= 1) {
	// 	// reflection from objects with specular intensity
	// 	double dot1 = winning_object_normal.dot(intersecting_ray_direction.neg());
	// 	Math::Vector3D scalar1 = winning_object_normal.mul(dot1);
	// 	Math::Vector3D add1 = scalar1.add(intersecting_ray_direction);
	// 	Math::Vector3D scalar2 = add1.mul(2);
	// 	Math::Vector3D add2 = intersecting_ray_direction.neg().add(scalar2);
	// 	Math::Vector3D reflection_direction = add2.normalize();

	// 	RayTracer::Ray reflection_ray (intersection_position, reflection_direction);

	// 	// determine what the ray intersects with first
	// 	std::vector <double> reflection_intersections;

	// 	for (int reflection_index = 0; reflection_index < scene_objects.size(); reflection_index++) {
	// 		reflection_intersections.push_back(scene_objects.at(reflection_index)->hit(reflection_ray));
	// 	}

	// 	int index_of_winning_object_with_reflection = objindex(reflection_intersections);

	// 	if (index_of_winning_object_with_reflection != -1) {
	// 		// reflection ray missed everthing else
	// 		if (reflection_intersections.at(index_of_winning_object_with_reflection) > accuracy) {
	// 			// determine the position and direction at the point of intersection with the reflection ray
	// 			// the ray only affects the color if it reflected off something

	// 			Math::Vector3D reflection_intersection_position = intersection_position.add(reflection_direction.mul(reflection_intersections.at(index_of_winning_object_with_reflection)));
	// 			Math::Vector3D reflection_intersection_ray_direction = reflection_direction;

	// 			RayTracer::Color reflection_intersection_color = getColorAt(reflection_intersection_position, reflection_intersection_ray_direction, scene_objects, index_of_winning_object_with_reflection, light_sources, accuracy, ambientlight);

	// 			final_color = final_color.colorAdd(reflection_intersection_color.colorScalar(winning_object_color.s));
	// 		}
	// 	}
	// }

	for (int light_index = 0; light_index < light_sources.size(); light_index++) {
		Math::Vector3D light_direction = light_sources.at(light_index)->getLightPosition().add(intersection_position.neg()).normalize();

		float cosine_angle = winning_object_normal.dot(light_direction);

		if (cosine_angle > 0) {
			// test for shadows
			bool shadowed = false;

			Math::Vector3D distance_to_light = light_sources.at(light_index)->getLightPosition().add(intersection_position.neg()).normalize();
			float distance_to_light_magnitude = distance_to_light.mag();

			RayTracer::Ray shadow_ray (intersection_position, light_sources.at(light_index)->getLightPosition().add(intersection_position.neg()).normalize());

			std::vector <double> secondary_intersections;

			for (int object_index = 0; object_index < scene_objects.size() && shadowed == false; object_index++) {
				secondary_intersections.push_back(scene_objects.at(object_index)->hit(shadow_ray));
			}
			for (int c = 0; c < secondary_intersections.size(); c++) {
				if (secondary_intersections.at(c) > accuracy) {
					if (secondary_intersections.at(c) <= distance_to_light_magnitude) {
						shadowed = true;
					}
				}
				break;
			}
			if (shadowed == false) {
				final_color = final_color.colorAdd(winning_object_color.colorMultiply(light_sources.at(light_index)->getLightColor()).colorScalar(cosine_angle));
				if (winning_object_color.s > 0 && winning_object_color.s <= 1) {
					// special [0-1]
					double dot1 = winning_object_normal.dot(intersecting_ray_direction.neg());
					Math::Vector3D scalar1 = winning_object_normal.mul(dot1);
					Math::Vector3D add1 = scalar1.add(intersecting_ray_direction);
					Math::Vector3D scalar2 = add1.mul(2);
					Math::Vector3D add2 = intersecting_ray_direction.neg().add(scalar2);
					Math::Vector3D reflection_direction = add2.normalize();
					double specular = reflection_direction.dot(light_direction);
					if (specular > 0) {
						specular = pow(specular, 10);
						final_color = final_color.colorAdd(light_sources.at(light_index)->getLightColor().colorScalar(specular*winning_object_color.s));
					}
				}
			}
		}
	}
	return (final_color);
	// return final_color.clip();
}

int main() {
    Math::Vector3D cameraOrigin(3, -0.5, -4);
    Math::Vector3D X(1, 0, 0);
    Math::Vector3D Y(0, 1, 0);
    Math::Vector3D Z(0, 0, 1);
    Math::Vector3D l(0, 0, 0);
    Math::Vector3D diff_btw (cameraOrigin.getVectX() - l.getVectX(), cameraOrigin.getVectY() - l.getVectY(), cameraOrigin.getVectZ() - l.getVectZ());
    Math::Vector3D camdir = diff_btw.neg().normalize();
    Math::Vector3D camright = Y.crossprod(camdir).normalize();
	Math::Vector3D camdown = camright.crossprod(camdir);
    RayTracer::Camera cam(cameraOrigin, camdir, camright, camdown);
    int screenWidth = 640;
    int screenHeight = 480;
    int aspec = (double)screenWidth / (double)screenHeight;
    RayTracer::Color white_light(1.0, 1.0, 1.0, 0);
    RayTracer::Color green(0.5, 1.0, 0.5, 0.3);
    RayTracer::Color grey(0.5, 0.5, 0.5, 0);
    RayTracer::Color maron(0.5, 0.25, 0.25, 0);
    RayTracer::Color black(0.0, 0.0, 0.0, 0);
    // Math::Vector3D lightpos(-7, 10, -10);
    // RayTracer::Lights scene_light(lightpos, white_light);
    RayTracer::Sphere sphere(l, 1, green);
    RayTracer::Plane plane (Y, -1, maron);
    std::cout << "P3\n640 480\n255" << std::endl;
    Math::Vector3D light_position (1.5,3,-6);
	RayTracer::Lights scene_light (light_position, white_light);
	std::vector<RayTracer::Source*> light_sources;
	light_sources.push_back(dynamic_cast<RayTracer::Source*>(&scene_light));
    std::vector<RayTracer::Object*> scene_obj;
    scene_obj.push_back(dynamic_cast<RayTracer::Sphere*> (&sphere));
    scene_obj.push_back(dynamic_cast<RayTracer::Plane*> (&plane));
    double aspect_ratio = static_cast<double>(screenWidth) / static_cast<double>(screenHeight);
    double p, q;
    double amlight = 0.2;
    double accu = 0.000001;
    for (int y = 0; y < screenHeight; ++y) {
        for (int x = 0; x < screenWidth; ++x) {
            if (screenWidth > screenHeight) {
                p = ((x + 0.5) / screenWidth) * aspect_ratio - (((screenWidth - screenHeight) / static_cast<double>(screenHeight)) / 2);
                q = ((screenHeight - y) + 0.5) / screenHeight;
            }
            else if (screenHeight > screenWidth) {
                p = (x + 0.5) / screenWidth;
                q = (((screenHeight - y) + 0.5) / screenHeight) / aspect_ratio - (((screenHeight - screenWidth) / static_cast<double>(screenWidth)) / 2);
            }
            else {
                p = (x + 0.5) / screenWidth;
                q = ((screenHeight - y) + 0.5) / screenHeight;
            }
            Math::Vector3D cam_raydir = camdir.add(camright.mul(p - 0.5).add(camdown.mul(q - 0.5))).normalize();
            RayTracer::Ray camray(cameraOrigin, cam_raydir);
            // std::cout << "cameraOrigin.x = " << cameraOrigin.x << " cameraOrigin.y = " << cameraOrigin.y << " cameraOrigin.z = " << cameraOrigin.z << std::endl;
            // std::cout << "cam_raydir.x = " << cam_raydir.x << " cam_raydir.y = " << cam_raydir.y << " cam_raydir.z = " << cam_raydir.z << std::endl;
            std::vector<double> inter;
            for (int index = 0; index < scene_obj.size(); index++) {
                inter.push_back(scene_obj.at(index)->hit(camray));
            }
            int ind = objindex(inter);
            if (ind == -1)
                RayTracer::write_color(black);
            else {
                if (inter.at(ind) > accu) {
                    Math::Vector3D inter_pos = cameraOrigin.add(cam_raydir.mul(inter.at(ind)));
                    Math::Vector3D cam_inter_dir = cam_raydir;
                    RayTracer::Color intersection_color = getColorAt(inter_pos, cam_inter_dir, scene_obj, ind, light_sources, accu, amlight);
                    RayTracer::write_color(intersection_color);
                }
            }
        }
    }
    return 0;
}