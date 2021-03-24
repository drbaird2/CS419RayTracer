#include "camera.h"

// ----------------------------------------------------------------- default constructor

Camera::Camera(void)		
	:	eye(0, 0, 100),
		lookAt(0,0,0),
		updir(0, 1, 0),
		u(1, 0, 0),
		v(0, 1, 0),
		w(0, 0, 1)
{}


// ----------------------------------------------------------------- copy constructor

Camera::Camera(const Camera& c)   		
	: 	eye(c.eye),
		lookAt(c.lookAt),
		updir(c.updir),
		u(c.u),
		v(c.v),
		w(c.w)
{}



// ----------------------------------------------------------------- assignment operator

Camera& Camera::operator= (const Camera& rhs) {
	if (this == &rhs)
		return (*this);
	
	eye				= rhs.eye;
	lookAt			= rhs.lookAt;
	updir			= rhs.updir;
	u				= rhs.u;
	v				= rhs.v;
	w				= rhs.w;

	return (*this);
}


//-------------------------------------------------------------- compute_uvw

// This computes an orthornormal basis given the view point, lookat point, and up vector
void Camera::uvwBase(){
    w = unit_vector(eye - lookAt);
    u = unit_vector(cross(updir,w));
    v = cross(w,u);

    if (eye.x() == lookAt.x() && eye.z() == lookAt.z() && eye.y() > lookAt.y()) { // camera looking vertically down
		u = vec3(0, 0, 1);
		v = vec3(1, 0, 0);
		w = vec3(0, 1, 0);	
	}
	
	if (eye.x() == lookAt.x() && eye.z() == lookAt.z() && eye.y() < lookAt.y()) { // camera looking vertically up
		u = vec3(1, 0, 0);
		v = vec3(0, 0, 1);
		w = vec3(0, -1, 0);
	}
}



