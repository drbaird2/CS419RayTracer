#ifndef __WORLD__
#define __WORLD__



#include <vector>

#include "viewPlane.h"

//#include "tracer.h"
#include "color.h"
#include "object.h"

#include "ray.h"

using namespace std;


class Scene {	
	public:
	
		ViewPlane					vp;
		Color					    background_color;
		//Tracer*						tracer_ptr;
		Sphere 						sphere;		
		vector<Object*>	objects;		
			

	public:
	
		Scene(void);												
								
		void add(Object* object_ptr);
		
		void build(void);

		void render_scene(void) const;
		
		void display_pixel(const int row, const int column, const Color& pixel_color) const;

		recent_hits intersect(const ray& ra);
						
	public:
		
		void clear();

};


// ------------------------------------------------------------------ add_object

inline void Scene::add(Object* object_ptr) {  
	objects.push_back(object_ptr);	
}

#endif
