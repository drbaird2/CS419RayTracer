#ifndef BRDF_H
#define BRDF_H


#include "Color.h"
#include "vec3.h"
#include "recent_hits.h"
#include "Sampler.h"

class BRDF {
	public:
	
		BRDF(void);						
		
		BRDF(const BRDF& brdf);		
		
		virtual BRDF* clone(void)const = 0;
		
		BRDF& operator= (const BRDF& rhs);
		
				
		void							
		set_sampler(Sampler* sPtr);
		
		virtual Color f(const recent_hits& record, const vec3& wo, const vec3& wi) const;
		
		virtual Color sample_f(const recent_hits& record, const vec3& wo, vec3& wi) const;
		
		virtual Color sample_f(const recent_hits& record, const vec3& wo, vec3& wi, float& pdf) const;
		
		virtual Color rho(const recent_hits& record, const vec3& wo) const;
		
			
	public:
	
		Sampler* sampler_ptr;		// for indirect illumination
};

#endif

