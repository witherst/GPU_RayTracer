#ifndef HITABLELISTH
#define HITABLELISTH

#include "hitable.h"

class HitableList : public Hitable {
public:
	HitableList() {};
	HitableList(Hitable** l, int size) { list = l; list_size = size; }
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;

	Hitable** list;
	int list_size;	
};

#endif
