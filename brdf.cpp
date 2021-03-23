// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "constants.h"
#include "brdf.h"

// ---------------------------------------------------------- default constructor

BRDF::BRDF(void) 
	: sampler_ptr(NULL)
{}


// ---------------------------------------------------------- copy constructor

BRDF::BRDF (const BRDF& brdf) {
	if(brdf.sampler_ptr)
		sampler_ptr	= brdf.sampler_ptr->clone(); 
	else  sampler_ptr = NULL;
}	



// --------------------------------------------------------------- assignment operator

BRDF& BRDF::operator= (const BRDF& rhs) {
	if (this == &rhs)
		return (*this);
		
	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}

	if (rhs.sampler_ptr)
		sampler_ptr	= rhs.sampler_ptr->clone();

	return (*this);
}



// ---------------------------------------------------------- set_sampler

void BRDF::set_sampler(Sampler* sPtr) {
	sampler_ptr = sPtr;
	sampler_ptr->map_samples_to_hemisphere(1);  // for perfect diffuse
}


// ------------------------------------------------------------------------ f

Color BRDF::f(const recent_hits& sr, const vec3& wo, const vec3& wi) const {
	return (black);
}


// ------------------------------------------------------------------------ sample_f

Color BRDF::sample_f(const recent_hits& sr, const vec3& wo, vec3& wi) const {
	return (black);
}


// ------------------------------------------------------------------------ sample_f

Color BRDF::sample_f(const recent_hits& sr, const vec3& wo, vec3& wi, float& pdf) const {
	return (black);
}


// ------------------------------------------------------------------------ rho	
	
Color BRDF::rho(const recent_hits& sr, const vec3& wo) const {
	return (black);
}

