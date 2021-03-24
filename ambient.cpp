
#include "ambient.h"
#include "constants.h"
/*------------------------------------------------
// constructors
--------------------------------------------------*/

Ambient::Ambient (void)
	: 	Light(),
		ls(1.0),
		color(white)			
{}


Ambient::Ambient (const Ambient& a)
	: 	Light(a),
		ls(a.ls),
		color(a.color) 		
{}

Light* Ambient::clone(void) const {
	return (new Ambient(*this));
}	

/*------------------------------------------
// operators
--------------------------------------------*/
Ambient& Ambient::operator= (const Ambient& rhs) {
	if (this == &rhs)
		return (*this);
			
	Light::operator= (rhs);
	
	ls 		= rhs.ls;
	color 	= rhs.color;
	
	return (*this);
}

/*-------------------------------------------
// get_direction
// given a recent_hits record, returns a blank direction because it's ambient light
// it doesn't have a direction
---------------------------------------------*/
	

vec3 Ambient::get_direction(recent_hits& s) {
	return (vec3(0.0,0.0,0.0));
}

/*------------------------------------------
// L
// given a recen_hits record, returns the incident radiance
--------------------------------------------*/

Color Ambient::L(recent_hits& record) {	
	return (color * ls);
}





