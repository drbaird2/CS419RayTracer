// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "lambertian.h"
#include "constants.h"

// ---------------------------------------------------------------------- default constructor

Lambertian::Lambertian(void) 
	:   BRDF(),
		kd(0.0), 
		cd(Color(0.0,0.0,0.0))
{}


// ---------------------------------------------------------------------- copy constructor

Lambertian::Lambertian(const Lambertian& lamb) 
	:   BRDF(lamb),
		kd(lamb.kd), 
		cd(lamb.cd)
{}


// ---------------------------------------------------------------------- assignment operator

Lambertian& Lambertian::operator= (const Lambertian& rhs) {
	if (this == &rhs)
		return (*this);
		
	BRDF::operator= (rhs);
	
	kd = rhs.kd; 
	cd = rhs.cd;
	
	return (*this);
}


// ---------------------------------------------------------------------- clone

Lambertian* 
Lambertian::clone(void) const {
	return (new Lambertian(*this));
}	


// ---------------------------------------------------------------------- f
// there is no sampling here

Color Lambertian::f(const recent_hits& record, const vec3& wo, const vec3& wi) const {
	return ( cd * kd * invPI);
}


// ---------------------------------------------------------------------- sample_f

// this generates a direction by sampling the hemisphere with a cosine distribution
// this is called in path_shade for any material with a diffuse shading component
// the samples have to be stored with a cosine distribution

Color Lambertian::sample_f(const recent_hits& record, const vec3& wo, vec3& wi, double& pdf) const {
	
	vec3 w = record.colideNormal;
	vec3 v = cross(vec3(0.0034, 1, 0.0071), w);
	v = unit_vector(v);
	vec3 u = cross(v, w);
	
	point3 sp = sampler_ptr->sample_hemisphere();  
	wi = sp.x() * u + sp.y() * v + sp.z() * w;
	wi = unit_vector(wi); 	
	
	pdf = dot(wi, record.colideNormal) * invPI;
	
	return ( cd * kd * invPI); 
}



// ---------------------------------------------------------------------- rho

Color Lambertian::rho(const recent_hits& record, const vec3& wo) const {
	return ( cd * kd);
}


