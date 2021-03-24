
#include "constants.h"
#include "brdf.h"

/*------------------------------------------
// Constructors
--------------------------------------------*/
BRDF::BRDF(void) 
	: sampler_ptr(NULL)
{}

BRDF::BRDF (const BRDF& brdf) {
	if(brdf.sampler_ptr)
		sampler_ptr	= brdf.sampler_ptr->clone(); 
	else  sampler_ptr = NULL;
}	

/*------------------------------------------
// operators
--------------------------------------------*/
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



void BRDF::set_sampler(Sampler* sPtr) {
	sampler_ptr = sPtr;
	sampler_ptr->map_samples_to_hemisphere(1);  // for perfect diffuse
}


Color BRDF::f(const recent_hits& sr, const vec3& wo, const vec3& wi) const {
	return (black);
}



Color BRDF::sample_f(const recent_hits& sr, const vec3& wo, vec3& wi) const {
	return (black);
}


Color BRDF::sample_f(const recent_hits& sr, const vec3& wo, vec3& wi, float& pdf) const {
	return (black);
}

	
Color BRDF::rho(const recent_hits& sr, const vec3& wo) const {
	return (black);
}

