#ifndef TRACER_H
#define TRACER_H

#include "constants.h"
#include "ray.h"
#include "color.h"

class Scene;

class Tracer {
	public:
	
		Tracer(void);									
		
		Tracer(Scene* scene_ref);						
								

		virtual Color trace_ray(const ray& ra) const;

		virtual Color trace_ray(const ray ra, const int depth) const;
				
	protected:
	
		Scene* scene_ptr;
};

#endif

