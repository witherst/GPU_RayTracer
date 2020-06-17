#include "material.h"
#include "ray.h"
#include "hitable.h"

// Function prototypes
vec3 reflect(const vec3& v, const vec3& n);

bool Lambert::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const 
{
	// Using the hitpoint p, we create a random ray that goes OUTWARDS from the hitpoint
	vec3 target = rec.p + rec.N + random_in_unit_sphere();
	scattered = ray(rec.p, target - rec.p);
	attenuation = albedo;
	return true;
}

bool Metal::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const
{
	vec3 reflected = reflect(unit_vector(r_in.direction()), rec.N);
	scattered = ray(rec.p, reflected + fuzz * random_in_unit_sphere());
	attenuation = albedo;
	return (dot(scattered.direction(), rec.N) > 0);
}

vec3 reflect(const vec3& v, const vec3& n)
{
	return v - 2 * dot(v, n) * n;
}
