#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "ray.h"
#include <limits>
#include <iostream>
//These are some of the constants I was going to use.
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radiants(double degrees){
    return degrees * pi / 180.0;
}

//The Color class, holds R G B values for a particular color
class Color{
    public:
        double red, green, blue;

    public:
    //Constructors, Default should be gray
        Color() : red(0.5), green(0.5), blue(0.5) {}
        Color(double r, double g, double b) : red(r), green(g), blue(b) {}
        Color(const vec3& colour) : red(colour[0]), green(colour[1]), blue(colour[2]){}
    
    //Getters
        double getRed(){return red;}
        double getGreen(){return green;}
        double getBlue(){return blue;}
    //Setters
        void setRed(double r){red = r;}
        void setGreen(double g){green = g;}
        void setBlue(double b){blue = b;}

    //Total brightness of the color
        double brightness(){return red + green + blue;}

    //Makes sure that the color is a valid color so no values go over 1 or under 0
        Color validateColor(){
            if (red > 1) {red = 1;}
            if (red < 0) {red = 0;}
		    if (green > 1) {green = 1;}
            if (green < 0) {green = 0;}
		    if (blue > 1) {blue = 1;}
		    if (blue < 0) {blue = 0;}
            return Color(red,green,blue);
        }
    //averages the given color
        Color average(Color c){
            return Color((red+c.getRed())/2, (green+c.getGreen())/2, (blue+c.getBlue())/2);
        }




};

//Series of operator overrides

inline Color operator+(const Color& c1, const Color& c2) {
    return Color(c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue);
}

inline Color operator+(const vec3 v, const Color& c2) {
    return Color(v.e[0] + c2.red, v.e[1] + c2.green, v.e[2] + c2.blue);
}

inline Color operator*(const Color& c1, const Color& c2) {
    return Color(c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue);
}

inline Color operator*(double scalar, const Color& c) {
    return Color(scalar*c.red, scalar*c.green, scalar*c.blue);
}

inline Color operator*(const Color& c, double t) {
    return t * c;
}

inline Color operator/(Color c, double t) {
    return (1/t) * c;
}

//Writes the current color out to the ppm file
void write_color(std::ostream &out, Color pixel_color) {
    // Write the translated [0,255] value of each color component.
    pixel_color = pixel_color.validateColor();
    out << static_cast<int>(255.999 * pixel_color.getRed()) << ' '
    << static_cast<int>(255.999 * pixel_color.getGreen()) << ' '
    << static_cast<int>(255.999 * pixel_color.getBlue()) << '\n';
}

//Some common numbers for colors I think are pretty
Color white(){ return Color(1.0, 1.0, 1.0);}
Color solidRed(){ return Color(1.0 ,0.0 ,0.0);}
Color solidGreen(){ return Color(0.0 ,1.0 ,0.0);}
Color solidBlue(){ return Color(0.0 ,0.0 ,1.0);}
Color crimson(){ return Color(0.5, 0.25, 0.25);}
Color cerulean(){ return Color(0.0, 1.0, 1.0);}
Color gray(){return Color(0.5, 0.5, 0.5);}
Color black(){return Color(0.0, 0.0, 0.0);}



#endif