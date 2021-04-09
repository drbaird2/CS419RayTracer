#ifndef OBJECT_H
#define OBJECT_H

#include <math.h>
#include "ray.h"
#include "color.h"
#include "recent_hits.h"
#include "vec3.h"
#include <memory>
//#include "aabb.h"

class Material;

using namespace std;
//base class for all hittiable objects, includes a virtual intersection function
class Object{
    public:
        shared_ptr<Material> material_ptr;
        Color col;
    public:
        Object();

        Object(const Object& object);

        //virtual Object* clone() const = 0;

        virtual bool intersect(const ray& r, double t_min, double t_max, recent_hits& record) const = 0;
        
        virtual void set_material(shared_ptr<Material> materialRef);

        shared_ptr<Material> get_material() const;

        void set_color(const Color& c);

        void set_color(const double r, const double g, const double b);

        Color get_color();

        virtual void add_object(shared_ptr<Object> object_ptr);
        
        //virtual void set_bounding_box();
        //virtual AABB get_bounding_box();

        virtual point3 sample();

        virtual double pdf(recent_hits& record);

        virtual vec3 get_normal() const;

        virtual vec3 get_normal(const point3& p);

        Object& operator= (const Object& rhs);
};

inline void Object::set_color(const Color& c){
    col = c;
}

inline void Object::set_color(const double r, const double g, const double b){
    col.red = r;
    col.green = g;
    col.blue = b;
}

inline Color Object::get_color(){
    return col;
}

/*
virtual bool bounding_box(AABB& bounder) const override{
            if(items_in_scene.empty()) return false;

            AABB temp_box;
            bool first_box = true;

            for(const auto& item: items_in_scene){
                if(!item->bounding_box( temp_box)) return false;
                bounder = first_box ? temp_box: surrounding_box(bounder, temp_box);
                first_box = false;
            }
            return true;
        }

*/
#endif