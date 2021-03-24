
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
		for (int c = 0; c < hres; c++) {	// across 					
			ra.orig = point3(s * (c - hres / 2.0 + 0.5), s * (r - vres / 2.0 + 0.5), zw);
			pixel_color = tracer_ptr->trace_ray(ra);
			//pixel_color.write_color(std::cout, pixel_color);
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
   int index = (column * vp.vres) + row;

	mapped_color.red = std::fmin(raw_color.red,1);
	mapped_color.green = std::fmin(raw_color.green,1);
	mapped_color.blue = std::fmin(raw_color.blue,1);

}

void Scene::save_bmp(const std::string& outputFile) const{
	const int image_size = vp.hres * vp.vres * 4;
    const int headers_size = 14 + 40;
    const int filesize = image_size + headers_size;
    const int pixelsPerMeter = 2835;
    
    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
    //size of the file in bytes
    bmpfileheader[ 2] = (unsigned char)(filesize);
    bmpfileheader[ 3] = (unsigned char)(filesize>>8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);
            
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};
    //width of the image in bytes
    bmpinfoheader[ 4] = (unsigned char)(vp.vres);
    bmpinfoheader[ 5] = (unsigned char)(vp.vres>>8);
    bmpinfoheader[ 6] = (unsigned char)(vp.vres>>16);
    bmpinfoheader[ 7] = (unsigned char)(vp.vres>>24);
    
    //height of the image in bytes
    bmpinfoheader[ 8] = (unsigned char)(vp.hres);
    bmpinfoheader[ 9] = (unsigned char)(vp.hres>>8);
    bmpinfoheader[10] = (unsigned char)(vp.hres>>16);
    bmpinfoheader[11] = (unsigned char)(vp.hres>>24);

    // Size image in bytes
    bmpinfoheader[21] = (unsigned char)(image_size);
    bmpinfoheader[22] = (unsigned char)(image_size>>8);
    bmpinfoheader[23] = (unsigned char)(image_size>>16);
    bmpinfoheader[24] = (unsigned char)(image_size>>24);

    bmpinfoheader[25] = (unsigned char)(pixelsPerMeter);
    bmpinfoheader[26] = (unsigned char)(pixelsPerMeter>>8);
    bmpinfoheader[27] = (unsigned char)(pixelsPerMeter>>16);
    bmpinfoheader[28] = (unsigned char)(pixelsPerMeter>>24);

    bmpinfoheader[29] = (unsigned char)(pixelsPerMeter);
    bmpinfoheader[30] = (unsigned char)(pixelsPerMeter>>8);
    bmpinfoheader[31] = (unsigned char)(pixelsPerMeter>>16);
    bmpinfoheader[32] = (unsigned char)(pixelsPerMeter>>24);

    FILE *file = fopen(outputFile.c_str(), "wb");//write-binary
    
    fwrite(bmpfileheader,1,14, file);
    fwrite(bmpinfoheader,1,40, file);
    
    for (int i = 0; i < pixels.size(); ++i){
        const Color pixel = pixels[i];
        unsigned char color[3] = {
            (int) (pixel.blue * 255), 
            (int) (pixel.green * 255), 
            (int) (pixel.red * 255)
        };
        fwrite(color, 1, 3, file);
    }
    fclose(file);

}

// ----------------------------------------------------------------------------- hit_bare_bones_objects

recent_hits Scene::intersect(const ray& ra) {
	recent_hits	records(*this); 
	double		t_min; 			
	double		t_max 			= kHugeValue;
	int 		num_objects 	= objects.size();
	
	for (int j = 0; j < num_objects; j++){
		if (objects[j]->intersect(ra, t_min, t_max, records)) {
			records.colided	    = true;
			t_max 				= t_min; 
			records.col		= objects[j]->get_color(); 
		}
	}
	return (records);   
}

void Scene::build(void){
    int num_samples = 1;

    //viewplane

    vp.set_hres(500);
    vp.set_vres(500);
    vp.set_pixel_size(1);
    vp.set_samples(num_samples);

    Ambient* ambient_ptr = new Ambient;
    ambient_ptr->scale_radiance(1.0);
    set_ambient_light(ambient_ptr);
    background_color = solidblue;
    tracer_ptr = new RayCast(this);

    //camera

    Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(0,0,100);
    pinhole_ptr->set_look(0,0,0);
    pinhole_ptr->set_view_distance(500);
    pinhole_ptr->uvwBase();
    set_camera(pinhole_ptr);

    //light

    Ambient* light_ptr1 = new Ambient;
    add_light(light_ptr1);

    //Material

    double ka = 0.25;
    double kd = 0.75;

    //Materials

    Matte* matte_green = new Matte;
    matte_green->set_ka(ka);
    matte_green->set_kd(kd);
    matte_green->set_cd(solidgreen);

    Matte* matte_blue = new Matte;
    matte_blue->set_ka(ka);
    matte_blue->set_kd(kd);
    matte_blue->set_cd(solidblue);

    Matte* matte_red = new Matte;
    matte_red->set_ka(ka);
    matte_red->set_kd(kd);
    matte_red->set_cd(solidred);

    Matte* matte_crimson = new Matte;
    matte_crimson->set_ka(ka);
    matte_crimson->set_kd(kd);
    matte_crimson->set_cd(crimson);

    //Shapes
    Plane* land = new Plane(vec3(0,-250,-1), point3(0,-100,-1), Color(0.0 ,1.0 ,0.0));
    Sphere* head = new Sphere(point3(0,.75,-1), 0.35, Color(0.0 ,0.0 ,1.0));
    Sphere* middle = new Sphere(point3(0,0,-1), .5, Color(1.0 ,0.0 ,0.0));
    Sphere* butt = new Sphere(point3(0,-.6,-1), 0.65, Color(0.0 ,1.0 ,0.0));
    Triangle* nose1 = new Triangle(point3(0,.75,-.5),point3(.2,.75,-1), point3(0,.9,-1), Color(0.5, 0.25, 0.25));
    Triangle* nose2 = new Triangle(point3(0,.75,-.5),point3(-.2,.75,-1), point3(0,.9,-1), Color(0.5, 0.25, 0.25));
    
    land->set_material(matte_green);
    head->set_material(matte_blue);
    middle->set_material(matte_red);
    butt->set_material(matte_blue);
    nose1->set_material(matte_crimson);
    nose2->set_material(matte_crimson);

    add_object(land);
    add_object(head);
    add_object(middle);
    add_object(butt);
    add_object(nose1);
    add_object(nose2);


}