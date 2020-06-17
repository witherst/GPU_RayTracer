#ifndef MATERIALH
#define MATERIALH

#include "vector.h"

class ray;
struct hit_record;

class Material {
public:
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;	// Pure virtual
};

/*
	Classic Lambert shader. 
	-- albedo: Essentially the color of the object.
*/

class Lambert : public Material {
public:
	Lambert(const vec3& a) : albedo(a){}
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;

private:
	vec3 albedo;
};

/*
	-- Metal class which does not absorb rays and just reflects rays off into the environment.
	-- Fuzz parameter is just randomizing the reflected direction. How does it work?
	--	We have a ray go from the hit point (rec.p) to a point in a random_in_unit_sphere(). The 'fuzz'
	--	parm scales the unit sphere. The bigger the 'fuzz' parm the blurrier the reflection. 
	--	We limit the fuzz to be a max of 1.
*/
class Metal : public Material {
public:
	Metal(const vec3& a, float f) : albedo(a) { if (f < 1) fuzz = f; else fuzz = 1; }
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;

private:
	vec3 albedo;
	float fuzz;
};

#endif
