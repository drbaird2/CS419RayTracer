#include "aabb.h"



AABB::AABB(void) 

{}
        
AABB::AABB(const point3& a, const point3& b) :
    minimum(a),
    maximum(b)
{}

bool AABB::intersect(const ray& r, double t_min, double t_max) const {
    for (int a = 0; a < 3; a++) {
        auto invD = 1.0f/ r.direction()[a];
        auto t0 = (min()[a] - r.origin()[a]) *invD;
        auto t1 = (max()[a] - r.origin()[a]) *invD;
        if(invD < 0.0f){
            std::swap(t0, t1);
        }
        if(t0>t_min){
            t_min = t0;
        }
        if (t1<t_max){
            t_max = t1;
        }
        if (t_max <= t_min)
            return false;
    }
            return true;
}

AABB AABB::surrounding_box(const AABB& box0, const AABB& box1){
    point3 small(fmin(box0.min().x(), box1.min().x()), fmin(box0.min().y(), box1.min().y()), fmin(box0.min().z(), box1.min().z()));
    point3 big(fmax(box0.max().x(), box1.max().x()), fmax(box0.max().y(), box1.max().y()), fmax(box0.max().z(), box1.max().z()));
            
    return AABB(small,big);
}

