#ifndef SCENE_H
#define SCENE_H



#include <vector>

#include "viewPlane.h"
#include "color.h"
#include "tracer.h"
#include "object.h"
#include "ray.h"
#include "camera.h"
#include "light.h"
#include "ambient.h"
#include <memory>

using namespace std;


class Scene {	
	public:
	
		ViewPlane					vp;
		Color					    background_color;
		shared_ptr<Tracer>			tracer_ptr;
		shared_ptr<Light>			ambient_ptr;
		shared_ptr<Camera>			camera_ptr;
		vector<shared_ptr<Object>>	objects;		
		vector<shared_ptr<Light>>	lights;
		vector<Color>				pixels;
			

	public:
	
		Scene(void);												
								
		void add_object(shared_ptr<Object> object_ptr);

		void add_light(shared_ptr<Light> light_ptr);

		//void add_pixel(Color col);

		void set_ambient_light(shared_ptr<Light> light_ptr);

		void set_camera(shared_ptr<Camera> cam_ptr);
		
		void build(void);

		void render_scene(void) ;
		
		void display_pixel(const int row, const int column, const Color& pixel_color);

		void save_bmp(const std::string& outputFile) const;

		recent_hits intersect(const ray& ra);
						
	public:
		
		void clear_objects();

		void clear_lights();

};



inline void Scene::add_object(shared_ptr<Object> object_ptr) {  
	objects.push_back(object_ptr);	
}

inline void Scene::add_light(shared_ptr<Light> light_ptr) {  
	lights.push_back(light_ptr);	
}

/* inline void Scene::add_pixel(Color col){
	pixels.push_back(col);
} */

inline void Scene::set_ambient_light(shared_ptr<Light> light_ptr){
	ambient_ptr = light_ptr;
}

inline void Scene::set_camera(shared_ptr<Camera> cam_ptr){
	camera_ptr = cam_ptr;
}

#endif
