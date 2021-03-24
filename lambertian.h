#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H


#include "brdf.h"

class Lambertian: public BRDF 
{
	public:
	
		Lambertian(void);
		
		Lambertian(const Lambertian& lamb);
		
		Lambertian& operator= (const Lambertian& rhs);
		
		virtual Lambertian* clone(void) const;
		
		virtual Color f(const recent_hits& sr, const vec3& wo, const vec3& wi) const;
		
		virtual Color sample_f(const recent_hits& sr, const vec3& wo, vec3& wi, double& pdf) const;
		
		virtual Color rho(const recent_hits& sr, const vec3& wo) const;
			
		void set_ka(const float ka);	
				
		void set_kd(const float kd);
		
		void set_cd(const Color& c);
		
		void set_cd(const float r, const float g, const float b);
		
		void set_cd(const float c);
					
	public:
	
		double		kd;
		Color 	    cd;
};




// -------------------------------------------------------------- set_ka

inline void Lambertian::set_ka(const float k) {
	kd = k;
}



// -------------------------------------------------------------- set_kd

inline void Lambertian::set_kd(const float k) {
	kd = k;
}


// -------------------------------------------------------------- set_cd

inline void Lambertian::set_cd(const Color& c) {
	cd = c;
}


// ---------------------------------------------------------------- set_cd

inline void	Lambertian::set_cd(const float r, const float g, const float b) {
	cd.red = r; cd.green = g; cd.blue = b;
}


// ---------------------------------------------------------------- set_cd

inline void	Lambertian::set_cd(const float c) {
	cd.red = c; cd.green = c; cd.blue = c;
}

#endif

