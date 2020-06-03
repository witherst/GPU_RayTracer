#pragma once
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