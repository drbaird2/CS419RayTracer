#include "plane.h"

Plane::Plane() : 
    aPoint(point3(0,0,0)),
    norm(vec3(0,1,0))    
{}

Plane::Plane(const vec3& normal, const point3& p, const Color& c) : 
    norm(normal), 
    aPoint(p), 
    col(c) 
{}


bool Plane::intersect(const ray& r, double t_min, double t_max, recent_hits& record) const {
    auto denomenator = dot(r.direction(), norm);
    //if the denomenator for the plane equation is 0 the plane is parallel so ignored
    if (denomenator == 0) {
        return false;
    }else{
        auto numerator = dot((aPoint - r.origin()), norm);
        double t = numerator/denomenator;
        //get the numerator and find t, if it's below the min it's behind us, if it's greater than max it's been blocked
        if (t < t_min || t >t_max){
            return false;
        }else{
        //The t is closer than the max but still visible, update record.
            record.t = t;
            record.origin = r.at(record.t);
            vec3 outward_normal = norm;
            record.set_face_normal(r, outward_normal);
            return true;
        }
        return false;

    }
} 
