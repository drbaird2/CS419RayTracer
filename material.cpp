#include "material.h"
#include "constants.h"


Material::Material(void) {}

Material::Material(const Material& m) {}

Material& Material::operator= (const Material& rhs) {
	if (this == &rhs)
		return (*this);

	return (*this);
}


// ---------------------------------------------------------------- shade

Color Material::shade(recent_hits& record) {
	return (black);
}




