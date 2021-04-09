#ifndef MATERIAL_H
#define MATERIAL_H




#include "scene.h"			// required for the shade function in all derived classes
#include "color.h"
#include "recent_hits.h"
#include <memory>

using namespace std;

class Material {	
	public:
	
		Material(void);						
		
		Material(const Material& material); 

		virtual shared_ptr<Material> clone(void) const = 0;
				
		virtual Color shade(recent_hits& sr);	
		
	public:
	
		Material& operator= (const Material& rhs);						
};

#endif

