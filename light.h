//These classes were an attempt to create light and shading but failed in the end.

#ifndef LIGHT_H
#define LIGHT_H

#include "ray.h"
#include "color.h"
#include "vec3.h"

class recent_hits;

class Light{
    public:
        Light();

        Light(const Light& ls);

        Light& operator= (const Light& rhs);

        virtual Light* clone(void) const = 0;

        virtual vec3 get_direction(recent_hits& record) = 0;

        virtual Color L(recent_hits& record);

};


#endif