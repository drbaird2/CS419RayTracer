#ifndef SAMPLER_H
#define SAMPLER_H


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include <vector>
#include <math.h>

using std::vector;

#include "vec2.h"
#include "vec3.h"
#include "Maths.h"

class Sampler {	
	public:	
		
		Sampler(void);								
		
		Sampler(const int num);						
		
		Sampler(const int num, const int num_sets);		

		Sampler(const Sampler& s);						

		Sampler& operator= (const Sampler& rhs);

		virtual Sampler* clone(void) const = 0;												
		
		void set_num_sets(const int np);					
		
		virtual void generate_samples(void) = 0;

		int get_num_samples(void);							
		
		void shuffle_x_coordinates(void);
		
		void shuffle_y_coordinates(void);
			
		void setup_shuffled_indices(void);
		
		void map_samples_to_unit_disk(void);
		
		void map_samples_to_hemisphere(const float p);		
		
		void map_samples_to_sphere(void);					
		
		
		// the following functions are not const because they change count and jump
		
		vec2 sample_unit_square(void);  				// get next sample on unit square
		
		
													    // get next sample on unit disk
		vec2 sample_unit_disk(void);
		
		vec3 sample_hemisphere(void);					// get next sample on unit hemisphere
		
		
		vec3 sample_sphere(void);						// get next sample on unit sphere

		
	public:
	
		int 					num_samples;     		// the number of sample points in a set
		int 					num_sets;				// the number of sample sets
		vector<vec2>			samples;				// sample points on a unit square
		vector<int>				shuffled_indices;		// shuffled samples array indices
		vector<vec2>			disk_samples;			// sample points on a unit disk
		vector<vec3> 		    hemisphere_samples;		// sample points on a unit hemisphere
		vector<vec3> 		    sphere_samples;			// sample points on a unit sphere
		unsigned long 			count;					// the current number of sample points used
		int 					jump;					// random index jump
};

#endif

