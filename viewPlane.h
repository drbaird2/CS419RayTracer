#ifndef VIEWPLANE_H
#define VIEWPLANE_H

class ViewPlane {
	public:
		int 			hres;   					// horizontal image resolution 
		int 			vres;   					// vertical image resolution
		float			s;							// pixel size
		
	public:

    	ViewPlane();   								// default Constructor
				
		ViewPlane(const ViewPlane& vp);				// copy constructor

		ViewPlane& operator= (const ViewPlane& rhs);		// assignment operator
						
		void set_hres(const int h_res);
		
		void set_vres(const int v_res);
				
		void set_pixel_size(const float size);
				
};

inline void ViewPlane::set_hres(const int h_res) { 
    hres = h_res;
}

inline void ViewPlane::set_vres(const int v_res) {
	vres = v_res;
}

inline void ViewPlane::set_pixel_size(const float size) {
	s = size;
}







#endif