#ifndef VEC2_H
#define VEC2_H


class vec2 {	
	public:
	
		double x, y;
				
	public:
	
		vec2(void):
            x(0.0),
            y(0.0)
        {}	

		vec2(const double arg):
            x(arg),
            y(arg)
        {}	

		vec2(const double x1, const double y1):
            x(x1),
            y(y1)
        {}

		vec2(const vec2& p):
            x(p.x),
            y(p.y)
        {}								

		//vec2& operator= (const vec2& rhs);
		
		vec2 operator* (const double a);
};


// multiplication by a double on the right

inline vec2 vec2::operator* (const double a) {
	return (vec2(x * a, y * a));
}
/*
vec2& vec2::operator= (const vec2& rhs) {
	if (this == &rhs)
		return (*this);

	x = rhs.x;
	y = rhs.y;

	return (*this);
}*/
#endif


