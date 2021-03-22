#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "object.h"
#include "camera.h"
#include "light.h"
#include <iostream>
#include <limits>
#include "plane.h"
#include "sphere.h"
#include "triangle.h"

//Function used to find the closest intersection and color it.
Color ray_color(const ray& r, const Object& wonderland, const Light& wonderland_lighting) {
    recent_hits record;
    if(wonderland.intersect(r,0, infinity, record)){
        return  record.col;// + record.col;
    }
    //Setting the background color to a sky shaded blue if no object is found
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0 - t) * Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0);

}


int main() {

    // Image
    const auto aspect_ratio = 4.0 / 3.0;
    const int vres = 700;
    const int hres = static_cast<int>(vres / aspect_ratio);

    // Camera
    /* This camera was not used
    Camera movedView = Camera(point3(2,5,20),vec3(1,1,-1),vec3(0,1,0),30.0,false);
    movedView.uvwBase();
    Camera defaultview = Camera();*/
    //Default axis aligned camera
    auto viewport_height = 3.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    //Lights were not used
    //Chandelier wonderland_lighting;
    //wonderland_lighting.add(make_shared<Light>(point3(-3,8,-10), Color(1.0,1.0,1.0)))
    // Objects
    //Set up the winter wonderland
    Scene wonderland;
    wonderland.add(make_shared<Plane>(vec3(0,-250,-1), point3(0,-100,-1), Color(0.0 ,1.0 ,0.0)));
    wonderland.add(make_shared<Sphere>(point3(0,.75,-1), 0.35, Color(0.0 ,0.0 ,1.0)));
    wonderland.add(make_shared<Sphere>(point3(0,0,-1), .5, Color(1.0 ,0.0 ,0.0)));
    wonderland.add(make_shared<Sphere>(point3(0,-.6,-1), 0.65, Color(0.0 ,1.0 ,0.0)));
    wonderland.add(make_shared<Triangle>(point3(0,.75,-.5),point3(.2,.75,-1), point3(0,.9,-1), Color(0.5, 0.25, 0.25)));
    wonderland.add(make_shared<Triangle>(point3(0,.75,-.5),point3(-.2,.75,-1), point3(0,.9,-1), Color(0.5, 0.25, 0.25)));
    
    // Render
    float zw = 100.0;
    int n = 25;
    point3 samplePoint;
    Color pixel_color;
    ray ra;

    //Render the scene to a ppm file
    std::cout << "P3\n" << vres << " " << hres << "\n255\n";

    for (int r = hres-1; r >= 0 ; --r) {
        std::cerr << "\rRendering: " << r << ' ' << std::flush;
        for (int c = 0; c < vres; ++c) {
/*
            for (int p = n-1; p >= 0; p--)              // up pixel
                      for (int q = 0; q < n; q++) {       // across pixel
                            samplePoint[0] = (c - 0.5 * hres + (q + 0.5) / n);
                            samplePoint[1] = (r - 0.5 * vres + (p + 0.5) / n);
                            ra.orig = point3(samplePoint[0], samplePoint[1], zw);

                            //This ray is used for Orthographic projection
                            //ray ra = ray(vec3(x,y,0),lower_left_corner + x*horizontal + y*vertical - vec3(0,0,focal_length));
            
                            //This ray is used for Perspective
                            //ray ra = ray(origin, lower_left_corner + x*horizontal + y*vertical - origin);
                            pixel_color = pixel_color + ray_color(ra, wonderland, Light(point3(-3,8,-10),  Color(1.0,1.0,1.0)));
                      }*/
                  
                // pixel_color = pixel_color/(n *n);  // average the colors
            auto x = double(c) / (vres-1);
            auto y = double(r) / (hres-1);
            //auto x = (c - 0.5*(vres-1)+0.5);
            //auto y = (r - 0.5*(hres-1)+0.5);
            //ray ra = movedView.getRay(x,y);
            //This ray is used for Orthographic projection
            //ray ra = ray(vec3(x,y,0),lower_left_corner + x*horizontal + y*vertical - vec3(0,0,focal_length));
            
            //This ray is used for Perspective
            ray ra = ray(origin, lower_left_corner + x*horizontal + y*vertical - origin);
            
            //Get colored pixel back
            Color pixel_color = ray_color(ra,wonderland, Light(point3(-3,8,-10),  Color(1.0,1.0,1.0)));
            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
}
/*
void 
World::render_perspective(void) const {
     RGBColor pixel_color;   
     Ray      ray;                         
 
     open_window(hres, vres);
     ray.o = Point3D(0.0, 0.0, eye);
 
     for (int r = 0; r < vp.vres; r++)            // up
          for (int c = 0; c <= vp.hres; c++)  {   // across 
                ray.d = Vector3D(s * (c - 0.5 * (hres - 1.0)), s * (r - 0.5 * (vres - 1.0)), -d);
                ray.d.normalize();
                pixel_color = tracer_ptr->trace_ray(ray);
                display_pixel(r, c, pixel_color);
          }
}*/