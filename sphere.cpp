#include "sphere.h"
#include "ray.h"
#include "hitable.h"

bool Sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
	vec3 oc = r.origin() - p;

	// Setup discriminant values from the quadratic equation (this way is unbelievably faster than other ways I've found on youtube)
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;

	// If discriminant > 0, there's two solutions, i.e. our ray has entered and exited this sphere
	if (discriminant > 0) {

		// Find closest t value (first intersection of ray with sphere)
		float temp = (-b - sqrtf(discriminant)) / (2*a);

		// Check closest intersection --
		//	t_min < t < t_max = valid hit
		if (temp < t_max && temp > t_min) {	
			rec.t = temp;							// Distance along ray where intersection occurs
			rec.p = r.point_at_parameter(rec.t);	// Position on sphere where intersection occurs
			rec.N = (rec.p - p) / radius;			// Normal of hit position
			return true;
		}

		// Check furthest intersection
		temp = (-b + sqrtf(discriminant)) / (2*a); 
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.N = (rec.p - p) / radius;
			return true;
		}

	}

	return false;
}
