#include "ViewPlane.h"

// ---------------------------------------------------------------- default constructor	
						
ViewPlane::ViewPlane(void)							
	: 	hres(400), 
		vres(400),
		s(1.0)
{}


// ---------------------------------------------------------------- copy constructor

ViewPlane::ViewPlane(const ViewPlane& vp)   
	:  	hres(vp.hres),  
		vres(vp.vres), 
		s(vp.s)
{}


// ---------------------------------------------------------------- assignment operator

ViewPlane& 
ViewPlane::operator= (const ViewPlane& rhs) {
	if (this == &rhs)
		return (*this);
		
	hres 				= rhs.hres;
	vres 				= rhs.vres;
	s					= rhs.s;
	
	return (*this);
}