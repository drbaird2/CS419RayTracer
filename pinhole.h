#ifndef PINHOLE_H
#define PINHOLE_H

#include "vec2.h"
#include "scene.h"    

//--------------------------------------------------------------------- class Pinhole

class Pinhole: public Camera {
	public:
	
		Pinhole();   							

		Pinhole(const Pinhole& ph);	
		
		virtual Camera*	clone(void) const;			

		Pinhole& operator= (const Pinhole& rhs);	
	
		void set_view_distance(const double vpd);
		
		void set_zoom(const double zoom_factor);
		
		vec3 get_direction(const vec2& p) const;
		
		virtual void render_scene(const Scene& sceneRef);
		
	private:
			
		double	dist;		// view plane distance
		double	zoom;	// zoom factor
		
};




//-------------------------------------------------------------------------- set_vpd

inline void Pinhole::set_view_distance(double _d) {
	dist = _d;
}	
	


//-------------------------------------------------------------------------- set_zoom

inline void Pinhole::set_zoom(double zoom_factor) {
	zoom = zoom_factor;
}	

#endif

