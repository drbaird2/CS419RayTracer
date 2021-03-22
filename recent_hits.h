#ifndef RECENT_HITS_H
#define RECENT_HITS_H


class Material;
class Scene;


#include "ray.h"
#include "object.h"

struct recent_hits{
    bool colided;
    Material* material_ptr;
    point3 colidePoint;
    vec3 colideNormal;
    ray ra;
    Scene* scene_ptr;
    Object* object_ptr;
    
};

#endif