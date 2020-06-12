#include "hitableList.h"

bool HitableList::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
	hit_record temp_rec;

	// Initially assume we hit nothing and set "closest hit" to the furthest possible point in the world
	bool hit_anything = false;
	float closest_so_far = t_max;
	
	// Go through all objects in the scene and see if we hit any.
	//	We are only concerned with the closest object for now b/c further objects
	//	may be obscured by closer objects
	for (int i = 0; i < list_size; i++) {
		if (list[i]->hit(r, t_min, closest_so_far, temp_rec)) {
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return hit_anything;
}
