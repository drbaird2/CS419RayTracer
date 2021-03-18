#ifndef AABB_H
#define AABB_H

#include "ray.h"

class AABB {
    public:
        point3 minimum;
        point3 maximum;
    public:
        AABB();
        AABB(const point3& a, const point3& b);

        point3 min() const;
        point3 max() const;

        bool intersect(const ray& r, double t_min, double t_max) const; 

        AABB surrounding_box(const AABB& box0, const AABB& box1);
};

inline point3 AABB::min() const {return minimum; }
inline point3 AABB::max() const {return maximum; }

#endif