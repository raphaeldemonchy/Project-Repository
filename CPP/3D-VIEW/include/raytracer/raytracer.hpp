/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-raytracer-raphael.de-monchy
** File description:
** raytracer
*/

#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_
#include "../vector3D/vector3D.hpp"
#include <iostream>
#include <vector>
namespace RayTracer {
    class Rectangle3D {
    public:
        Math::Point3D origin;
        Math::Vector3D bottom_side;
        Math::Vector3D left_side;

        // Constructor with parameters
        Rectangle3D(const Math::Point3D& origin, const Math::Vector3D& bottom_side, const Math::Vector3D& left_side)
            : origin(origin), bottom_side(bottom_side), left_side(left_side) {}

        // Calculate the 3D coordinates of a point in the rectangle
        Math::Point3D pointAt(double u, double v) const {
            Math::Vector3D uVector = bottom_side * u;
            Math::Vector3D vVector = left_side * v;
            return origin + uVector + vVector;
        }
    };

    class Ray {
    public:
        Math::Vector3D origin;
        Math::Vector3D direction;

        // Default constructor
        Ray() = default;

        // Constructor with parameters
        Ray(const Math::Vector3D& origin, const Math::Vector3D& direction)
            : origin(origin), direction(direction) {}
        Math::Vector3D getRayOrigin () { return origin; }
	    Math::Vector3D getRayDirection () { return direction; }
        // Copy constructor
        Ray(const Ray& other) = default;

        // Move constructor
        Ray(Ray&& other) noexcept = default;

        // Copy assignment operator
        Ray& operator=(const Ray& other) = default;

        // Move assignment operator
        Ray& operator=(Ray&& other) noexcept = default;
        friend std::ostream& operator<<(std::ostream& os, const Ray& ray) {
            os << "Ray - Origin: (" << ray.origin.x << ", " << ray.origin.y << ", " << ray.origin.z << ")"
               << " Direction: (" << ray.direction.x << ", " << ray.direction.y << ", " << ray.direction.z << ")";
            return os;
        }
    };
    class Camera {
    public:
        Math::Vector3D campos;
        Math::Vector3D camdir;
        Math::Vector3D camright;
        Math::Vector3D camdown;

        // Constructor with parameters
        Camera(const Math::Vector3D& campos, const Math::Vector3D& camdir, const Math::Vector3D& camright, const Math::Vector3D& camdown)
        : campos(campos), camdir(camdir), camright(camright),camdown(camdown) {}

        // Generate a ray from the camera to the given point on the screen
        // Ray ray(double u, double v) const {
        //     Math::Point3D target = screen.pointAt(u, v);
        //     Math::Vector3D direction = target - position;
        //     return Ray(position, direction);
        // }
    };
    class Screen {
    public:
        int width;
        int height;

        // Default constructor
        Screen() : width(640), height(480) {}

        // Constructor with parameters
        Screen(int width, int height) : width(width), height(height) {}
    };



    class Color {
        public:
            double r, g, b, s;
            Color() {r = 0, g = 0 , b = 0  , s = 0;}
            Color(double r , double g, double b, double s) : r(r), g(g), b(b), s(s){}
            double brightness() {
                return(r + g + b)/3;
            }
            Color colorScalar(double scalar) {
	        	return Color (r*scalar, g*scalar, b*scalar, s);
        	}
            Color colorAdd(Color color) {
		        return Color (r + color.r, g + color.g, b + color.b, s);
	        }
            Color colorMultiply(Color color) {
		        return Color (r*color.r, g*color.g, b*color.b, s);
            }
	        Color colorAverage(Color color) {
	        	return Color ((r + color.r)/2, (g + color.g)/2, (b + color.b)/2, s);
    	    }
    };
    class Source {
    	public:

	        Source(){}
	        virtual Math::Vector3D getLightPosition() {return Math::Vector3D(0, 0, 0);}
	        virtual RayTracer::Color getLightColor() {return RayTracer::Color(1, 1, 1, 0);}
    };
    void write_color(const Color color) {
    int ir = static_cast<int>(255 * color.r);
    int ig = static_cast<int>(255 * color.g);
    int ib = static_cast<int>(255 * color.b);

    std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
    class Lights : public Source {
        public:
            Math::Vector3D position;
            Color color;
            Lights() : position(0,0,0), color(1,1,1,0) {};
            Lights(Math::Vector3D posistion, Color color) : position(position), color(color) {};
            std::vector<Math::Point3D> pointLights;
            std::vector<Math::Vector3D> directionalLights;

    // ...
    };
    class Object {
        public:
            virtual double hit(Ray ray) {return 0;}
            Object(){}
            virtual Color getColor () { return Color (0.0, 0.0, 0.0, 0); }
            virtual Math::Vector3D getNormalAt(Math::Vector3D point){
                return Math::Vector3D(0,0,0);
            }
    };
    class Sphere : public Object {
        public:
        Math::Vector3D center;
        double radius;
        RayTracer::Color color;

    // Constructor
        Sphere(const Math::Vector3D& center, double radius, const RayTracer::Color& color)
        : center(center), radius(radius), color(color) {}
        virtual Color getColor () { return color; }
        Math::Vector3D getNormalAt(Math::Vector3D point) {
                Math::Vector3D vec = point.add(center.neg()).normalize();
                return vec;
            }
        //-----------------------------------------------------------
        virtual double hit(Ray ray) {
            Math::Vector3D ray_o = ray.getRayOrigin();
            double ray_ox = ray_o.x;
            double ray_oy = ray_o.y;
            double ray_oz = ray_o.z;

            Math::Vector3D ray_d = ray.getRayDirection();
            double ray_dx = ray_d.x;
            double ray_dy = ray_d.y;
            double ray_dz = ray_d.z;

            Math::Vector3D sphere_c = center;
            double sphere_cx = sphere_c.x;
            double sphere_cy = sphere_c.y;
            double sphere_cz = sphere_c.z;

            double a = 1;
            double b = (2*(ray_ox - sphere_cx)*ray_dx) + (2*(ray_oy - sphere_cy)*ray_dy) + (2*(ray_oz - sphere_cz)*ray_dz);
            double c = pow(ray_ox - sphere_cx, 2) + pow(ray_oy - sphere_cy, 2) + pow(ray_oz - sphere_cz, 2) - (radius * radius);
            // std::cout << "b = " << b << std::endl;
		    // std::cout << "c = " << c << std::endl;
            double discri = b*b - 4*c;
            // std::cout << "discri = " << discri << std::endl;
            if (discri > 0) {
                double root_1 = ((-1*b - sqrt(discri))/2) - 0.000001;
                if (root_1 > 0)
                    return root_1;
                else {
                    double root_2 = ((sqrt(discri) - b)/2) - 0.000001;
                    return root_2;
                }
            } else
                return -1;
        }
        //-----------------------------------------------------------
        // Hits method
        // virtual double hit(Ray ray) {
        //     Math::Vector3D ray_o = ray.origin;
        //     double rayox = ray_o.x;
        //     double rayoy = ray_o.y;
        //     double rayoz = ray_o.z;
        //     Math::Vector3D ray_d = ray.direction;
        //     double raydx = ray_d.x;
        //     double raydy = ray_d.y;
        //     double raydz = ray_d.z;
        //     Math::Vector3D sphere_c = center;
        //     double spherecx = center.x;
        //     double spherecy = center.y;
        //     double spherecz = center.z;
        //     double a = 1;
        //     double b = (2*(rayox-spherecx) * raydx) + (2*(rayoy-spherecy) * raydy) + (2*(rayoz-spherecz) * raydz);
        //     double c = pow(rayox-spherecx, 2) + pow(rayoy-spherecy, 2) + pow(rayoz-spherecz, 2) - (radius*radius);
        //     double discri = b*b - 4 *c;
        //     std::cout << "discri = " << discri << std::endl;
        //     if (discri < 0) {
        //         double r1 = ((-1*b-sqrt(discri))/2) - 0.000001;
        //         if (r1 > 0)
        //             return r1;
        //         else {
        //             double r2 = ((sqrt(discri) - b) / 2) - 0.000001;
        //             return r2;
        //         }
        //     }
        //     else
        //         return -1;
        // }
    };
    class Plane : public Object {
        public:
            Math::Vector3D normal;
            double distance;
            Color color;
            Math::Vector3D getPlaneNormal () { return normal; }
	        double getPlaneDistance () { return distance; }
	        virtual Color getColor () { return color; }
            Plane(const Math::Vector3D& normal, double distance, const RayTracer::Color& color)
            : normal(normal), distance(distance), color(color) {}
            virtual double hit(Ray ray) {
                Math::Vector3D raydir = ray.getRayDirection();
                double s = raydir.dot(normal);
                if (s == 0)
                    return -1;
                else {
                    double r = normal.dot(ray.origin.add(normal.mul(distance).neg()));
                    return -1*r/s;
                }
            }
            virtual Math::Vector3D getNormalAt(Math::Vector3D point) {
                return normal;
            }

    };
}

#endif /* !RAYTRACER_HPP_ */
