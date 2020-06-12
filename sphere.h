#ifndef SPHEREH
#define SPHEREH

#include "vector.h"
#include "hitable.h"

class Sphere : public Hitable{
public:
	Sphere() {};
	Sphere(vec3 cen, float r) : p(cen), radius(r) {};
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;	

	// Getters
	inline float x() const { return p.x(); }
	inline float y() const { return p.y(); }
	inline float z() const { return p.z(); }
	inline float r() const { return radius; }
	inline vec3 getP() const { return p; }
	inline vec3 getColor() const { return color; }
	inline float getRadius() const { return radius; }

	// Setters
	inline void setP(float x, float y, float z) { p.setP(x, y, z); }
	inline void setColor(float r, float g, float b) { color.setP(r, g, b); }
	inline void setRadius(float r) { radius = r; }

private:
	vec3 color;
	vec3 p;		// Center of sphere: (x, y, z,)
	float radius;
};


#endif
