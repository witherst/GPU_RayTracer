#include <float.h>
#include <iostream>
#include "ray.h"
#include "sphere.h"
#include "hitable.h"
#include "material.h"

using std::cout;
using std::endl;

vec3 color(const ray& r, Hitable *world, int depth) {

	hit_record rec;

	// Check for intersection with any object in the world 
	if (world->hit(r, 0.001, FLT_MAX, rec)) {
		ray scattered;
		vec3 attenuation;

		if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
			return attenuation * color(scattered, world, depth + 1);
		}
		else {
			return vec3(0, 0, 0);
		}	
	}
	else {
		// Color background the faded blue to white
		vec3 unit_dir = unit_vector(r.direction());
		float t = .5 * (unit_dir.y() + 1.0);
		return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	}
} 
