//This was my attempt to create a moveable camera, in the end it wouldn't work so I didn't use it.
#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"


class Camera {
    public:
        point3 eye;
        vec3 dir;
        vec3 upDir;
        vec3 w,u,v;
        double dist;
        bool perp;
    public:
        Camera() : eye(point3(0,0,0)), dir(vec3(0,0,1)), upDir(vec3(0,0,0)), dist(1.0), perp(true) {}
        Camera(const point3& eyepoint, const vec3& direction, const vec3& up, double distance, bool perspective)
            : eye(eyepoint), dir(direction), upDir(up), dist(distance), perp(perspective)
        {}

        point3 eyepoint() const  { return eye; }
        vec3 direction() const { return dir; }
        vec3 up() const { return upDir;}
        double distance() { return dist;}
        
        
         

        


        double aspect = 4.0/3.0;
        double hres = 500.0;
        double vres = hres/aspect;
        double field_of_view = 60.0;

        double screen_height = 3.0;
        double screen_width = aspect * screen_height;

        vec3 horizon = vec3(screen_width, 0, 0);
        vec3 vertrizon = vec3(0, screen_height, 0);
        vec3 lower_left_screen_corner = eye - horizon/2 - vertrizon/2 - vec3(0, 0, dist);

        

        //double deltax = 0.5;
        //double deltay = 0.5;
        //double pixelsize = 1;
        void uvwBase(){
            w = unit_vector(eye - dir);
            u = unit_vector(cross(upDir,w));
            v = cross(w,u);
        }

        ray getRay(double xpoint, double ypoint){
            if(perp){
                
                vec3 direction = xpoint*u + ypoint*v - dist*w;
                return ray(eye,unit_vector(direction));
            }else{
                vec3 direction = eye - dir;
                return ray(vec3(xpoint,ypoint,0),  unit_vector(direction));

            }
            
        }

    
};



#endif

