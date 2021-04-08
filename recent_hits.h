#ifndef RECENT_HITS_H
#define RECENT_HITS_H


class Material;
class Scene;


#include "ray.h"
//#include "object.h"

class recent_hits {
    public:
        bool colided;
        Material* material_ptr;
        point3 colidePoint;
        vec3 colideNormal;
        ray ra;
        Scene& sceneRef;
        Color col;
        double t;

    public:
        recent_hits(Scene& wr);			
		recent_hits(const recent_hits& sr);

};

#endif