
#include "tracer.h"

// -------------------------------------------------------------------- default constructor

Tracer::Tracer(void)
	: scene_ptr(NULL)
{}


// -------------------------------------------------------------------- constructor

Tracer::Tracer(Scene* scene_ref)
	: scene_ptr(scene_ref)
{}



// -------------------------------------------------------------------- trace_ray

Color Tracer::trace_ray(const ray& ra) const {
	return (black);
}


// -------------------------------------------------------------------- trace_ray

Color Tracer::trace_ray(const ray ra, const int depth) const {
	return (black);
}




