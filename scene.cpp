// this file contains the definition of the World class

#include "scene.h"
//#include "Constants.h"

// geometric objects

#include "sphere.h"
#include "plane.h"
#include "triangle.h"

// tracers

//#include "SingleSphere.h"
//#include "MultipleObjects.h"

// utilities

#include "recent_hits.h"
//#include "Maths.h"

// build functions

//#include "BuildSingleSphere.cpp"
//#include "BuildMultipleObjects.cpp"
//#include "BuildBBCoverPic.cpp"


// -------------------------------------------------------------------- default constructor

Scene::Scene(void)
	:  	background_color(),
		//tracer_ptr(NULL)
{}



//------------------------------------------------------------------ destructor



//------------------------------------------------------------------ render_scene

// This uses orthographic viewing along the zw axis

void Scene::render_scene(void) const {

	Color	    pixel_color;	 	
	ray			ra;					
	int 		hres 	= vp.hres;
	int 		vres 	= vp.vres;
	float		s		= vp.s;
	float		zw		= 100.0;			// hardwired in

	ra.dir = vec3(0, 0, -1);
	
	for (int r = 0; r < vres; r++)			// up
		for (int c = 0; c <= hres; c++) {	// across 					
			ra.orig = point3(s * (c - hres / 2.0 + 0.5), s * (r - vres / 2.0 + 0.5), zw);
			pixel_color = tracer_ptr->trace_ray(ra);
			display_pixel(r, c, pixel_color);
		}	
}  



// ---------------------------------------------------------------------------display_pixel

// raw_color is the pixel color computed by the ray tracer
// its RGB floating point components can be arbitrarily large
// mapped_color has all components in the range [0, 1], but still floating point
// display color has integer components for computer display
// the Mac's components are in the range [0, 65535]
// a PC's components will probably be in the range [0, 255]
// the system-dependent code is in the function convert_to_display_color
// the function SetCPixel is a Mac OS function


void Scene::display_pixel(const int row, const int column, const Color& raw_color) const {
	Color mapped_color;
	
   //have to start from max y coordinate to convert to screen coordinates
   int x = column;
   int y = vp.vres - row - 1;

   paintArea->setPixel(x, y, (int)(mapped_color.r * 255),
                             (int)(mapped_color.g * 255),
                             (int)(mapped_color.b * 255));
}



// ----------------------------------------------------------------------------- hit_bare_bones_objects

recent_hits Scene::intersect(const ray& ra) {
	recent_hits	records; 
	double		t_min; 			
	double		t_max 			= kHugeValue;
	int 		num_objects 	= objects.size();
	
	for (int j = 0; j < num_objects; j++)
		if (objects[j]->intersect(ra, t_min, t_max, records) {
			sr.hit_an_object	= true;
			t_min 				= t; 
			records.color		= objects[j]->get_color(); 
		}
		
	return (sr);   
}


//------------------------------------------------------------------ delete_objects

// Deletes the objects in the objects array, and erases the array.
// The objects array still exists, because it's an automatic variable, but it's empty 

void
World::delete_objects(void) {
	int num_objects = objects.size();
	
	for (int j = 0; j < num_objects; j++) {
		delete objects[j];
		objects[j] = NULL;
	}	
	
	objects.erase (objects.begin(), objects.end());
}


