#ifndef SPHEREH
#define SPHEREH

#include "vector.h"

class Sphere{
public:
	Sphere() {};
	Sphere(float e0, float e1, float e2, float r) {
		p.setP(e0, e1, e2); 
		radius = r;
		color = vec3(1, 0, 0);
	};

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
