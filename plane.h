#ifndef PLANE_H
#define PLANE_H

#include "object.h"

class Plane : public Object {
    public:
        vec3 norm;
        point3 aPoint;
        Color col;
    public:
        Plane();
        Plane(const vec3& normal, const point3& p, const Color& c);

        vec3 getNormal() const; 
        vec3 getPoint() const; 

        void setNormal(const vec3& normal);
        void setPoint(const point3& p);
        void setPoint(const double x, const double y, const double z);


        
        bool intersect(const ray& r, double t_min, double t_max, recent_hits& record) const override;
    
};

inline vec3 Plane::getNormal() const {return norm;}
inline vec3 Plane::getPoint() const {return aPoint;}

inline void Plane::setNormal(const vec3& normal){
    norm = normal;
}
inline void Plane::setPoint(const point3& p){
    aPoint = p;
}
inline void Plane::setPoint(const double x, const double y, const double z){
    aPoint = point3(x,y,z);
}

#endif