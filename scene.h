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

using namespace std;


class Scene {	
	public:
	
		ViewPlane					vp;
		Color					    background_color;
		Tracer*						tracer_ptr;
		Light*						ambient_ptr;
		Camera*						camera_ptr;
		vector<Object*>				objects;		
		vector<Light*>				lights;
			

	public:
	
		Scene(void);												
								
		void add_object(Object* object_ptr);

		void add_light(Light* light_ptr);

		void set_ambient_light(Light* light_ptr);

		void set_camer(Camera* cam_ptr);
		
		void build(void);

		void render_scene(void) const;
		
		void display_pixel(const int row, const int column, const Color& pixel_color) const;

		recent_hits intersect(const ray& ra);
						
	public:
		
		void clear_objects();

		void clear_lights();

};



inline void Scene::add_object(Object* object_ptr) {  
	objects.push_back(object_ptr);	
}

inline void Scene::add_light(Light* light_ptr) {  
	lights.push_back(light_ptr);	
}

inline void Scene::set_ambient_light(Light* light_ptr){
	ambient_ptr = light_ptr;
}

inline void Scene::set_camera(Camera* cam_ptr){
	camera_ptr = cam_ptr
}

#endif
