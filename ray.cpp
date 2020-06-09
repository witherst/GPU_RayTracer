#include "ray.h"
#include "sphere.h"
#include <iostream>

using std::cout;
using std::endl;

bool hit_sphere(const vec3& center, float radius, const ray& r) {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	
	return(discriminant > 0);
}

bool hit_sphere(const ray& r, const Sphere* s) {
	vec3 oc = r.origin() - s->getP();
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - s->getRadius() * s->getRadius();
	float discriminant = b * b - 4 * a * c;
	
	return(discriminant > 0);
}

vec3 color(const ray& r, const Sphere* s) {

	// Make red sphere
//	if (hit_sphere(vec3(0, 0, -1), .5, r)) {
//		return vec3(1, 0, 0);
//	}

	if (hit_sphere(r,s)) {
		return s[0].getColor();
	}

	// Color background the faded blue to white
	vec3 unit_dir = unit_vector(r.direction());
	float t = .5 * (unit_dir.y() + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}
