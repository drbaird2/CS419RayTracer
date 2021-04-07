#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"

class Scene;

class Camera {
    public:
        point3 eye, lookAt;
        vec3 updir;
        vec3 w,u,v;

    public:
        Camera();

        Camera(const Camera& camera);

        virtual Camera* clone(void) const = 0;

        virtual void render_scene(const Scene& scene_ref) = 0;

        void set_eye(const point3& p);

        void set_eye(const double x, const double y, const double z);

        void set_look(const point3& at);

        void set_look(const double x, const double y, const double z);

        void set_updir(const vec3& up);

        void set_updir(const double x, const double y, const double z);

        void uvwBase(void);

        Camera& operator= ( const Camera& camera);
    
};

inline void Camera::set_eye(const point3& p){
    eye = p;
}

inline void Camera::set_eye(const double x, const double y, const double z){
    eye = point3(x,y,z);
}

inline void Camera::set_look(const point3& at){
    lookAt = at;
}

inline void Camera::set_look(const double x, const double y, const double z){
    lookAt = point3(x,y,z);
}

inline void Camera::set_updir(const vec3& up){
    updir = up;
}

inline void Camera::set_updir(const double x, const double y, const double z){
    updir = vec3(x,y,z);
}


#endif

