#ifndef VECTORH
#define VECTORH

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
public:
	vec3() {};
	vec3(float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2; e[3] = 0; }

	// Getters
	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	inline float r() const { return e[1]; }
	inline float g() const { return e[2]; }
	inline float b() const { return e[3]; }

	// Setters
	inline void setX(float x) { e[0] = x; }
	inline void setY(float y) { e[1] = y; }
	inline void setZ(float z) { e[2] = z; }
	inline void setP(float x, float y, float z) { e[0] = x; e[1] = y; e[2] = z; }

	friend std::istream& operator>>(std::istream& is, vec3& t);
	friend std::ostream& operator<<(std::ostream& os, const vec3& t);
	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }
		
	inline vec3& operator+=(const vec3& v2);
	inline vec3& operator-=(const vec3& v2);
	inline vec3& operator*=(const vec3& v2);
	inline vec3& operator/=(const vec3& v2);
	inline vec3& operator*=(const float t);
	inline vec3& operator/=(const float t);

	inline float length() const {	
		return sqrtf(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}

	inline float squared_length() const{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	inline void make_unit_vector();

	float e[4];	// 4 for (x, y, z, w). Even though we won't use w--it plays nicer with GPU
};

extern inline vec3 operator+(const vec3& v1, const vec3& v2);
extern inline vec3 operator-(const vec3& v1, const vec3& v2);
extern inline vec3 operator*(const vec3& v1, const vec3& v2);
extern inline vec3 operator/(const vec3& v1, const vec3& v2);
extern inline vec3 operator*(float t, const vec3& v);
extern inline vec3 operator/(const vec3& v, float t);
extern inline vec3 operator*(const vec3& v, float t);
extern inline float dot(const vec3& v1, const vec3& v2);
extern inline vec3 cross(const vec3& v1, const vec3& v2);
extern inline vec3 unit_vector(vec3 v);
extern inline vec3 random_in_unit_sphere();

#endif
