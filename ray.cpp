#include <float.h>
#include <iostream>
#include "ray.h"
#include "sphere.h"
#include "hitable.h"

using std::cout;
using std::endl;

vec3 color(const ray& r, Hitable *world) {

	hit_record rec;

	// Check for intersection with any object in the world 
	if (world->hit(r, 0.001, FLT_MAX, rec)) {
		// Using the hitpoint p, we create a random ray that goes OUTWARDS from the hitpoint
		vec3 target = rec.p + rec.N + random_in_unit_sphere();

		// Now we're sending a new ray out from p (the original hit point, which is the new origin)
		return .5 * color(ray(rec.p, target-rec.p), world);
	}
	else {
		// Color background the faded blue to white
		vec3 unit_dir = unit_vector(r.direction());
		float t = .5 * (unit_dir.y() + 1.0);
		return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	}
} 
