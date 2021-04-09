#include "matte.h"

// ---------------------------------------------------------------- default constructor

Matte::Matte (void)
	:	Material(),
		ambient_brdf(new Lambertian),
		diffuse_brdf(new Lambertian)
{}



// ---------------------------------------------------------------- copy constructor

Matte::Matte(const Matte& m)
	: 	Material(m)
{
	if(m.ambient_brdf)
		ambient_brdf = m.ambient_brdf->clone(); 
	else  ambient_brdf = NULL;
	
	if(m.diffuse_brdf)
		diffuse_brdf = m.diffuse_brdf->clone(); 
	else  diffuse_brdf = NULL;
}


// ---------------------------------------------------------------- clone

shared_ptr<Material> Matte::clone(void) const {
	return (make_shared<Matte>(*this));
}	


// ---------------------------------------------------------------- assignment operator

Matte& Matte::operator= (const Matte& rhs) {
	if (this == &rhs)
		return (*this);
		
	Material::operator=(rhs);
	
	if (ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = NULL;
	}

	if (rhs.ambient_brdf)
		ambient_brdf = rhs.ambient_brdf->clone();
		
	if (diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = NULL;
	}

	if (rhs.diffuse_brdf)
		diffuse_brdf = rhs.diffuse_brdf->clone();

	return (*this);
}





// ---------------------------------------------------------------- shade

Color Matte::shade(recent_hits& record) {
	vec3 	wo 			= -record.ra.dir;
	Color 	L 			= ambient_brdf->rho(record, wo) * record.sceneRef.ambient_ptr->L(record);
	int 		num_lights	= record.sceneRef.lights.size();
	
	for (int j = 0; j < num_lights; j++) {
		vec3 wi = record.sceneRef.lights[j]->get_direction(record);    
		double ndotwi = dot(record.colideNormal, wi);
	
		if (ndotwi > 0.0) 
			L += diffuse_brdf->f(record, wo, wi) * record.sceneRef.lights[j]->L(record) * ndotwi;
	}
	
	return (L);
}




