#include "color.h"

Color::Color() : 
    red(0.5), 
    green(0.5), 
    blue(0.5) 
{}

Color::Color(double r, double g, double b) : 
    red(r), 
    green(g), 
    blue(b) 
{}
        
Color::Color(const vec3& colour) : 
    red(colour[0]), 
    green(colour[1]), 
    blue(colour[2])
{}
    

    //Makes sure that the color is a valid color so no values go over 1 or under 0
void Color::validateColor(){
    if (red > 1) {red = 1;}
    if (red < 0) {red = 0;}
	if (green > 1) {green = 1;}
    if (green < 0) {green = 0;}
	if (blue > 1) {blue = 1;}
	if (blue < 0) {blue = 0;}
    //return Color(red,green,blue);
}



//Writes the current color out to the ppm file
void Color::write_color(std::ostream &out, Color pixel_color) {
    // Write the translated [0,255] value of each color component.
    //pixel_color = pixel_color.validateColor();
    pixel_color.validateColor();
    out << static_cast<int>(255.999 * pixel_color.getRed()) << ' '
    << static_cast<int>(255.999 * pixel_color.getGreen()) << ' '
    << static_cast<int>(255.999 * pixel_color.getBlue()) << '\n';
}

