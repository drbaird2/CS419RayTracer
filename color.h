#ifndef COLOR_H
#define COLOR_H

#include "ray.h"
#include <limits>
#include <iostream>


//The Color class, holds R G B values for a particular color
class Color{
    public:
        double red, green, blue;

    public:
    //Constructors, Default should be gray
        Color();
        Color(double r, double g, double b);
        Color(const vec3& colour);
    
    //Getters
        double getRed();
        double getGreen();
        double getBlue();
    //Setters
        void setRed(double r);
        void setGreen(double g);
        void setBlue(double b);

    //Makes sure that the color is a valid color so no values go over 1 or under 0
        Color validateColor();

		Color operator+ (const Color& c) const;	

        Color operator* (const double scalar) const;

        Color operator/ (const double scalar) const;

        Color operator* (const Color& c) const;

        Color& operator= (const Color& rhs); 

		Color& operator+= (const Color& c);
		
		Color& operator*= (const double scalar);					
						
		Color& operator/= (const float scalar); 

		bool operator== (const Color& c) const;	

        void write_color(std::ostream &out, Color pixel_color);		

        //Some common numbers for colors I think are pretty
        Color white();
        Color solidRed();
        Color solidGreen();
        Color solidBlue();
        Color crimson();
        Color cerulean();
        Color gray();
        Color black();

};

inline double Color::getRed(){
    return red;
}

inline double Color::getGreen(){
    return green;
}

inline double Color::getBlue(){
    return blue;
}

    //Setters
inline void Color::setRed(double r){
    red = r;
}

inline void Color::setGreen(double g){
    green = g;
}

inline void Color::setBlue(double b){
    blue = b;
}

//Series of operator overrides
inline Color Color::operator+(const Color& c) const {
    return Color(red + c.red, green + c.green, blue + c.blue);
}

inline Color Color::operator*(const Color& c) const {
    return Color(red * c.red, green * c.green, blue * c.blue);
}

inline Color Color::operator*(double scalar) const {
    return Color(scalar*red, scalar*green, scalar*blue);
}

inline Color Color::operator/(double scalar) const {
    return c*(1/t);
}

inline Color& Color::operator+= (const Color& c) {
	red += c.red; green += c.green; blue += c.blue;
    return (*this);
}

inline Color& Color::operator*= (const double scalar) {
	red *= scalar; green *= scalar; blue *= scalar;
	return (*this);
}

inline Color& Color::operator/= (const float scalar) {	
	red /= scalar; green /= scalar; blue /= scalar;
	return (*this);
}

inline bool Color::operator== (const Color& c) const {
	return (red == c.red && green == c.green && blue == c.blue);
}

#endif