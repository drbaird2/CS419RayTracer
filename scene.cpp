
#include "scene.h"
#include "constants.h"
#include "color.h"

// geometric objects

#include "sphere.h"
#include "plane.h"
#include "triangle.h"

// tracers

#include "raycast.h"

//cameras
#include "pinhole.h"

//lights
//#include "directional.h"
//#include "pointlight.h"
#include "ambient.h"

//materials
#include "matte.h"

// utilities

#include "recent_hits.h"
#include "vec3.h"
#include "Maths.h"

// build functions

//#include "BuildSingleSphere.cpp"
//#include "BuildMultipleObjects.cpp"
//#include "BuildBBCoverPic.cpp"
#include "buildSnowman.cpp"


// -------------------------------------------------------------------- default constructor

Scene::Scene(void)
	:  	background_color(black),
		tracer_ptr(NULL),
		ambient_ptr(new Ambient),
		camera_ptr(NULL)
{}





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
	std::cout << "P3\n" << vres << " " << hres << "\n255\n";
	for (int r = 0; r < vres; r++){			// up
		std::cerr << "\rRendering: " << r << ' ' << std::flush;
		for (int c = 0; c <= hres; c++) {	// across 					
			ra.orig = point3(s * (c - hres / 2.0 + 0.5), s * (r - vres / 2.0 + 0.5), zw);
			pixel_color = tracer_ptr->trace_ray(ra);
			pixel_color.write_color(std::cout, pixel_color);
			display_pixel(r, c, pixel_color);
		}
	}
	std::cerr << "\nDone.\n";
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

   //paintArea->setPixel(x, y, (int)(mapped_color.r * 255),
     //                        (int)(mapped_color.g * 255),
       //                      (int)(mapped_color.b * 255));
}



// ----------------------------------------------------------------------------- hit_bare_bones_objects

recent_hits Scene::intersect(const ray& ra) {
	recent_hits	records(*this); 
	double		t_min; 			
	double		t_max 			= kHugeValue;
	int 		num_objects 	= objects.size();
	
	for (int j = 0; j < num_objects; j++){
		if (objects[j]->intersect(ra, t_min, t_max, records) {
			records.colided	    = true;
			t_max 				= t_min; 
			records.color		= objects[j]->get_color(); 
		}
	}
	return (records);   
}

