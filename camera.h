#ifndef CAMERAH
#define CAMERAH

#include "ray.h"

class Camera {
public:
	// Default camera view window
	Camera() {
		lower_left_corner = vec3(-2.0, -1.0, -1.0);
	    horizontal = vec3(4.0, 0.0, 0.0);
	    vertical = vec3(0.0, 2.0, 0.0);
	    origin = vec3(0.0, 0.0, 0.0);
	}
	
	// Return ray from camera with given u and v coordinates 
	ray get_ray(float u, float v) {
		return ray(origin, lower_left_corner + u * horizontal + v * vertical);
	}

private:
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	vec3 origin;
};

#endif