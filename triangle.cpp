#include "triangle.h"


Triangle::Triangle() :
    poi1(point3(0,0,0)),
    poi2(point3(0,0,1)),
    poi3(point3(1,0,0)),
    normal(vec3(0,1,0))
{}
        
Triangle::Triangle(const point3& vert1, const point3& vert2, const point3& vert3, const Color& c): 
    poi1(vert1), 
    poi2(vert2), 
    poi3(vert3), 
    col(c)
{
    makeNormal();
}

void Triangle::makeNormal(void){
    normal = cross((poi2 - poi1),(poi3 - poi1));
    normal = unit_vector(normal);
}


        
        //intersect function uses the Möller–Trumbore algorithim
bool Triangle::intersect(const ray& r, double t_min, double t_max, recent_hits& record) const {

    vec3 edge1 = poi2 - poi1;
    vec3 edge2 = poi3 - poi1;
    const float EPSILON = 0.0000001;            
    vec3 h = cross(r.direction(), edge2);
    double a = dot(edge1, h);
    if(a> -EPSILON && a< EPSILON){
        return false;
    }
    double f = 1.0/a;
    vec3 s = r.origin() - poi1;
    double u = f * dot(s, h);
    if ( u< 0.0 || u> 1.0){
        return false;
    }
    vec3 q = cross(s,edge1);
    double v = f * dot(r.direction(), q);
    if( v < 0.0 || (u+v) > 1.0){
        return false;
    }
    double t = f * dot(edge2, q);
    if (t> EPSILON){
        if(t < t_min || t>t_max){
            return false;
            //if t is outside the range it is not the closest;
        }
        record.t = t;
        record.colidePoint = r.at(record.t);
        return true;
    }else{
        return false;
    }
}

