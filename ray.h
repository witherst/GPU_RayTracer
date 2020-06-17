#ifndef RAYH
#define RAYH

#include "vector.h"
class ray {
public:
	ray() {};
	ray(const vec3& a, const vec3& b) { A = a; B = b; }
	vec3 origin() const { return A; }
	vec3 direction() const { return B; }
	vec3 point_at_parameter(float t) const { return A + t * B; } // Plug in a different t and p(t) moves along the ray.

	vec3 A;	// The origin of the ray
	vec3 B; // The ray direction
};

// Color function
class Hitable;		// Forward declaration of class, can't include "hitable.h" or we get a circular dependency
vec3 color(const ray& r, Hitable* world, int depth);

#endif
