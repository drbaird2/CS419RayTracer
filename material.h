#ifndef MATERIAL_H
#define MATERIAL_H




#include "scene.h"			// required for the shade function in all derived classes
#include "color.h"
#include "recent_hits.h"

class Material {	
	public:
	
		Material(void);						
		
		Material(const Material& material); 
				
		virtual Color shade(recent_hits& sr);	
		
	protected:
	
		Material& operator= (const Material& rhs);						
};

#endif

