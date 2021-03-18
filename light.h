//These classes were an attempt to create light and shading but failed in the end.

#ifndef LIGHT_H
#define LIGHT_H

#include "ray.h"
#include "color.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;


class Light{
    public:
        point3 pos;
        Color color;
    public:
        Light() : pos(point3(0,0,0)), color(Color()) {}
        
        Light(const point3& position, Color col) : pos(position), color(col){}

        point3 getPosition(){return pos;}
        Color getColor(){return color;}



};

class Chandelier : public Light{
    public:
        std::vector<shared_ptr<Light>> lights_on_chandelier;
    public:
        Chandelier(){}
        Chandelier(shared_ptr<Light> candle) {add(candle);}

        void clear() {lights_on_chandelier.clear();}
        void add(shared_ptr<Light> candle){ lights_on_chandelier.push_back(candle);}



};


#endif