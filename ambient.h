#ifndef AMBIENT_H
#define AMBIENT_H

#include "light.h"

class Ambient: public Light {
	public:
	
		Ambient(void);   							

		Ambient(const Ambient& a); 					 
	
		virtual Light* 	clone(void) const;	
		
		Ambient& operator= (const Ambient& rhs);
				
		void scale_radiance(const double b);
		
		void set_color(const double c);
		
		void set_color(const Color& c);
		
		void
		set_color(const double r, const double g, const double b); 
		
		virtual vec3 get_direction(recent_hits& s); 
		
		virtual Color L(recent_hits& s);
	
	public:
	
		double		ls;
		Color	    color;
};



/*------------------------------------------
// setters
--------------------------------------------*/
inline void Ambient::scale_radiance(const double b) { 
	ls = b;
}

inline void Ambient::set_color(const double c) {
	color.red = c; color.green = c; color.blue = c;
}

inline void Ambient::set_color(const Color& c) {
	color = c;
}

inline void Ambient::set_color(const double r, const double g, const double b) {
	color.red = r; color.green = g; color.blue = b;
}


#endif

