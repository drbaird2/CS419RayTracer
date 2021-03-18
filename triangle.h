#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object.h"

class Triangle : public Object{
    public:
        point3 poi1, poi2, poi3;
        vec3 normal;
        Color col;

    public:
        Triangle();
        Triangle(const point3& vert1, const point3& vert2, const point3& vert3, const Color& c);

        void setPoint1(const point3& poi);
        void setPoint2(const point3& poi);
        void setPoint3(const point3& poi);

        void makeNormal(void);



        bool intersect(const ray& r, double t_min, double t_max, recent_hits& record) const override;

};

inline void Triangle::setPoint1(const point3& poi){
    poi1 = poi;
}
inline void Triangle::setPoint2(const point3& poi){
    poi2 = poi;
}
inline void Triangle::setPoint3(const point3& poi){
    poi3 = poi;
}
#endif