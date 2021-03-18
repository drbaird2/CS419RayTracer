#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"


class Sphere : public Object {
    public:
        double radius;
        point3 center;
        
        Color col;
    public:
        Sphere(void);
        Sphere( const point3& cen, double rad, const Color& c);

        double getRadius() const; 
        point3 getCenter() const; 

        void setRadius(const double rad);
        void setCenter(const point3& cen);
        void setCenter(const double x, const double y, const double z);

        //The intersect function using the quadratic equation.
        virtual bool intersect(const ray& r, double t_min, double t_max, recent_hits& record) const override;
            
        virtual bool bounding_box(aabb& bounder) const override;
    
        
};

inline double Sphere::getRadius() const {return radius;}
inline point3 Sphere::getCenter() const {return center;}
        
inline void Sphere::setRadius(double rad){
    radius = rad;
}
inline void Sphere::setCenter(const point3& cen){
    center = cen;
}
inline void Sphere::setCenter(const double x, const double y, const double z){
    center = point3(x,y,z);
}

#endif  