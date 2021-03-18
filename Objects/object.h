#ifndef OBJECT_H
#define OBJECT_H

#include "ray.h"
#include "color.h"
#include <memory>
#include <vector>
#include "aabb.h"

using std::shared_ptr;
using std::make_shared;


//A struct to store the nearest hit object as well as the hit itself and it's normal
struct recent_hits{
    point3 origin;
    vec3 normal;
    double t;
    Color col;
    bool front_face;

//a function to set which side of the surface is the outwardfacing normal
    inline void set_face_normal(const ray& r, const vec3& outward_normal){
        front_face = dot(r.direction(), outward_normal)<0;
        if(front_face){
            normal = outward_normal;
        }else{
            normal = -outward_normal;
        }
    }
};


//base class for all hittiable objects, includes a virtual intersection function
class Object{
    public:
        Color col;
    public:
        virtual bool intersect(const ray& r, double t_min, double t_max, recent_hits& record) const = 0;
        virtual bool bounding_box(aabb& bounder) const = 0;
};

//The class used to make a list of all the hitable objects in a scene
class Scene : public Object{
    public:
        std::vector<shared_ptr<Object>> items_in_scene;
    public:

        //Constructors
        Scene(){}
        Scene(shared_ptr<Object> item) {add(item);}
        
        //Clears all Objects in the scene
        void clear() {items_in_scene.clear();}
        //Adds an object to the scene
        void add(shared_ptr<Object> item){ items_in_scene.push_back(item);}
        //The intersection function that will call each objects intersect function and keep record of which was the closest
        bool intersect(const ray& r, double t_min, double t_max, recent_hits& record) const override {
            recent_hits temp;
            bool collided = false;
            auto nearest_object = t_max;
            //for each item check if it was hit
            for(const auto& item : items_in_scene){
                //call the intersect function unique to each object type, update the record if the hit object was closer
                if( item->intersect(r, t_min,nearest_object,temp)){
                    
                    //set all the records, if something was hit, 
                    collided = true;
                    nearest_object = temp.t;
                    record.col = item->col;
                    record = temp;
                }
            }

            return collided;
        } 

        virtual bool bounding_box(aabb& bounder) const override{
            if(items_in_scene.empty()) return false;

            aabb temp_box;
            bool first_box = true;

            for(const auto& item: items_in_scene){
                if(!item->bounding_box( temp_box)) return false;
                bounder = first_box ? temp_box: surrounding_box(bounder, temp_box);
                first_box = false;
            }
            return true;
        }


};




#endif