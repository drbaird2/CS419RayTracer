
#include "constants.h"
#include "material.h"
#include "object.h"


// ---------------------------------------------------------------------- default constructor

Object::Object(void)
	: 	col(black),
		material_ptr(NULL)
		//shadows(true)
{}


// ---------------------------------------------------------------------- copy constructor

Object::Object (const Object& object)
	: 	col(object.col)
		//shadows(object.shadows) 
        {
	        if(object.material_ptr)
		        material_ptr = object.material_ptr->clone(); 
	        else  
		        material_ptr = NULL;
}	


// ---------------------------------------------------------------------- assignment operator

Object& Object::operator= (const Object& rhs) {
	if (this == &rhs)
		return (*this);
		
	col= rhs.col;
	
	if (material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}

	if (rhs.material_ptr)
		material_ptr = rhs.material_ptr->clone();

	//shadows = rhs.shadows;

	return (*this);
}


// ---------------------------------------------------------------------- destructor



// ---------------------------------------------------------------------- add_object
// required for Compound objects 

void Object::add_object(Object* object_ptr) {}


// ----------------------------------------------------------------------- get_normal

vec3 Object::get_normal(void) const{
	return (vec3(0,0,0));
} 


// ----------------------------------------------------------------------- set_material

void Object::set_material(Material* mPtr) {
	material_ptr = mPtr;
}


// ----------------------------------------------------------------------- get_material

Material* Object::get_material(void) const {
	return (material_ptr);
}


// ----------------------------------------------------------------------- compute_normal

vec3 GeometricObject::get_normal(const point3& p) {
	return (vec3(0,0,0));
}  


// ----------------------------------------------------------------------- set_bounding_box
/*
void 
GeometricObject::set_bounding_box (void) {}


// ----------------------------------------------------------------------- set_bounding_box

BBox 
GeometricObject::get_bounding_box (void) {
	return BBox();
}

*/

// ----------------------------------------------------------------------- sample
// returns a sample point on the object for area light shading

point3 Object::sample(void) {
	return (point3(0.0,0.0,0.0));
}


// ----------------------------------------------------------------------- pdf
// returns the probability density function for area light shading
		
double Object::pdf(recent_hits& record) {
	return (0.0);
}  	

									

