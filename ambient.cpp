
#include "ambient.h"
#include "constants.h"

// ---------------------------------------------------------------------- default constructor

Ambient::Ambient (void)
	: 	Light(),
		ls(1.0),
		color(white)			
{}


// ---------------------------------------------------------------------- copy constructor

Ambient::Ambient (const Ambient& a)
	: 	Light(a),
		ls(a.ls),
		color(a.color) 		
{}


// ---------------------------------------------------------------------- clone

Light* Ambient::clone(void) const {
	return (new Ambient(*this));
}	


// ---------------------------------------------------------------------- assignment operator

Ambient& Ambient::operator= (const Ambient& rhs) {
	if (this == &rhs)
		return (*this);
			
	Light::operator= (rhs);
	
	ls 		= rhs.ls;
	color 	= rhs.color;
	
	return (*this);
}


// ---------------------------------------------------------------------- get_direction	

vec3 Ambient::get_direction(recent_hits& s) {
	return (vec3(0.0,0.0,0.0));
}


// ---------------------------------------------------------------------- L

Color Ambient::L(recent_hits& record) {	
	return (color * ls);
}





