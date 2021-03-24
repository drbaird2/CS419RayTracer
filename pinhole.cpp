
#include "constants.h" 
#include "vec3.h"
#include "pinhole.h"
#include <math.h>

// ----------------------------------------------------------------------------- default constructor

Pinhole::Pinhole(void)		
	:	Camera(),
		dist(100),
		zoom(1.0)
{}


// ----------------------------------------------------------------------------- copy constructor

Pinhole::Pinhole(const Pinhole& c)   		
	: 	Camera(c),
		dist(c.dist),
		zoom(c.zoom)
{}


// ----------------------------------------------------------------------------- clone

Camera* Pinhole::clone(void) const {
	return (new Pinhole(*this));
}



// ----------------------------------------------------------------------------- assignment operator

Pinhole& Pinhole::operator= (const Pinhole& rhs) { 	
	if (this == &rhs)
		return (*this);
		
	Camera::operator= (rhs);

	dist 		= rhs.dist;
	zoom	    = rhs.zoom;

	return (*this);
}


// ----------------------------------------------------------------------------- get_direction

vec3 Pinhole::get_direction(const vec2& p) const {
	vec3 dir = p.x * u + p.y * v - dist * w;
	dir = unit_vector(dir);
	
	return(dir);
}



// ----------------------------------------------------------------------------- render_scene

void Pinhole::render_scene(const Scene& sceneRef) {
	Color	    L;
	ViewPlane	vp(sceneRef.vp);	 								
	ray			ra;
	int 		depth = 0;  
	vec2 	    pp;		// sample point on a pixel
	int n = (int)sqrt((double)vp.num_samples);
		
	vp.s /= zoom;
	ra.orig = eye;
		
	for (int r = 0; r < vp.vres; r++)			// up
		for (int c = 0; c < vp.hres; c++) {		// across 					
			L = black; 
			
			for (int p = 0; p < n; p++)			// up pixel
				for (int q = 0; q < n; q++) {	// across pixel
					pp.x = vp.s * (c - 0.5 * vp.hres + (q + 0.5) / n); 
					pp.y = vp.s * (r - 0.5 * vp.vres + (p + 0.5) / n);
					ra.dir = get_direction(pp);
					L += sceneRef.tracer_ptr->trace_ray(ra, depth);
				}	
											
			L /= vp.num_samples;
			sceneRef.display_pixel(r, c, L);
		} 
}



