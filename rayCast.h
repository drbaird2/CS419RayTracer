#ifndef RAYCAST_H
#define RAYCAST_H

#include "tracer.h"

class RayCast: public Tracer {
	public:
		
		RayCast(void);
		
		RayCast(Scene* sceneRef);
					

		virtual Color trace_ray(const ray ra) const;
};

#endif
