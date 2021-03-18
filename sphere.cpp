#include "sphere.h"

Sphere::Sphere() :
    center(point3(0,0,0)),
    radius(1.0)
{}

Sphere::Sphere(const point3& cen, double rad, const Color& c) :
    center(cen),
    radius(rad), 
    col(c) 
{}

//The intersect function using the quadratic equation.
bool Sphere::intersect(const ray& r, double t_min, double t_max, recent_hits& record) const {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = b*b - a*c;
    //if the discriminant is negative it is parallel
    if(discriminant < 0){return false;}
    auto sqrtd = sqrt(discriminant);
    //find the first root
    auto root = (-b - sqrtd)/a;
    //if it's not within the range check the other root.
    if(root < t_min || root>t_max){
        auto root = (-b + sqrtd)/a;
        if(root < t_min || root>t_max){
            return false;
        }
    }
    //one of them was closer, update the record
    record.t = root;
    record.origin = r.at(record.t);
    vec3 outward_normal = (record.origin - center)/radius;
    record.set_face_normal(r, outward_normal);
    return true;                
}

bool Sphere::bounding_box(aabb& bounder) const {
    bounder = aabb( center - vec3(radius, radius, radius), center + vec3(radius, radius, radius));
    return true;
}
