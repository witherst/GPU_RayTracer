/*
	HITABLE.H is just an interface, an abstract class. We implement these functions elsewhere.
*/

#ifndef HITABLEH
#define HITABLEH

#include "ray.h"

class Material;

struct hit_record {
	float t;
	vec3 p;
	vec3 N;
	Material* mat_ptr;
};

class Hitable{
public:
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;	// Pure virtual, every class inheriting must implement this function
};

#endif
