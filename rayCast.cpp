

#include "rayCast.h"
#include "scene.h"
#include "recent_hits.h"
#include "material.h"

// -------------------------------------------------------------------- default constructor

RayCast::RayCast(void)
	: Tracer()
{}


// -------------------------------------------------------------------- constructor
		
RayCast::RayCast(Scene* sceneRef)
	: Tracer(sceneRef)
{}


// -------------------------------------------------------------------- trace_ray
// this ignores the depth argument

Color RayCast::trace_ray(const ray ra) const {
	recent_hits record(scene_ptr->intersect(ra));
		
	if (record.colided) {
		record.ra = ra;			// used for specular shading
		return (record.material_ptr->shade(record));
	}   
	else
		return (scene_ptr->background_color);
}


