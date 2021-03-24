
#include "light.h"
#include "constants.h"

Light::Light(void) {}

Light::Light(const Light& ls) {}

Light& Light::operator= (const Light& rhs) {
	if (this == &rhs)
		return (*this);

	return (*this);
}


// ---------------------------------------------------------------------- L
// returns the radiance

Color Light::L(recent_hits& s) {
	return (black);
}




