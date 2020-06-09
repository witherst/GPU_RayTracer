#include "ray.h"
#include "sphere.h"
#include <iostream>

using std::cout;
using std::endl;

//bool hit_sphere(const ray& r, const Sphere* s) {
//	vec3 oc = r.origin() - s->getP();
//	float a = dot(r.direction(), r.direction());
//	float b = 2.0 * dot(oc, r.direction());
//	float c = dot(oc, oc) - s->getRadius() * s->getRadius();
//	float discriminant = b * b - 4 * a * c;
//	
//	return(discriminant > 0);
//}

/*
Explanation of the below sphere intersection equation: 
	https://www.youtube.com/watch?v=HFPlKQGChpE
*/
bool hit_sphere(const ray& r, const Sphere* s) {
	float t = dot((s->getP() - r.origin()), r.direction());

	// Check negative t, if so, ray missed the sphere
	if (t < 0) {
		return false;
	}
	vec3 p = s->getP() - r.point_at_parameter(t);
	float y = p.length();

	// Check if y is bigger than radius, ray missed
	if (y > s->getRadius()) {
		return false;
	}

	float x = sqrtf((s->getRadius() * s->getRadius()) - (y * y));

	float t1 = t - x;	// Intersection 1
	float t2 = t + x;	// Intersection 2
	return (t1 > 0 && t2 > 0);
}

vec3 color(const ray& r, const Sphere* s) {

	// Check for sphere intersection and return color of the sphere
	if (hit_sphere(r,s)) {
		return s[0].getColor();
	}

	// Color background the faded blue to white
	vec3 unit_dir = unit_vector(r.direction());
	float t = .5 * (unit_dir.y() + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}
