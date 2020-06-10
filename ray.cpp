#include "ray.h"
#include "sphere.h"
#include <iostream>

using std::cout;
using std::endl;

float hit_sphere(const ray& r, const Sphere* s) {
	vec3 oc = r.origin() - s->getP();
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - s->getRadius() * s->getRadius();
	float discriminant = b * b - 4 * a * c;

	if (discriminant < 0) { return -1; }
	else {
		// Return smallest t value
		return ((-b - sqrtf(discriminant)) / (2 * a));
	}	
}

vec3 color(const ray& r, const Sphere* s) {

	// Check for sphere intersection and return color of the sphere
	float t = hit_sphere(r, s);

	if (t > 0.0) {
		vec3 N = r.point_at_parameter(t) - s->getP();	
		return .5 * vec3(N.x() + 1, N.y() + 1, N.z() + 1);
	}

	// Color background the faded blue to white
	vec3 unit_dir = unit_vector(r.direction());
	t = .5 * (unit_dir.y() + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}
