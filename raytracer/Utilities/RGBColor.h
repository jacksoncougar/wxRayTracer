#ifndef __RGB_COLOR__
#define __RGB_COLOR__

// This file contains the declaration of the class RGBColor

//------------------------------------------------------------ class RGBColor

#include "Vector3D.h"

class RGBColor {

public:

	float r, g, b;

public:

	RGBColor(void);                                        // default constructor
	RGBColor(float c);                                    // constructor
	RGBColor(float _r, float _g, float _b);                // constructor
	RGBColor(const RGBColor& c);                        // copy constructor

	~RGBColor(void);                                    // destructor

	RGBColor&                                            // assignment operator
		operator=(const RGBColor& rhs);

	RGBColor                                            // addition
		operator+(const RGBColor& c) const;

	RGBColor operator-(const RGBColor& c) const;

	RGBColor&                                            // compound addition
		operator+=(const RGBColor& c);

	RGBColor                        // multiplication by a float on the right
		operator*(const float a) const;

	RGBColor&                // compound multiplication by a float on the right
		operator*=(const float a);

	RGBColor                                            // division by a float
		operator/(const float a) const;

	RGBColor operator/(const RGBColor& a) const {
		return { r / a.r, g / a.g, b / a.b };
	}

	RGBColor&                                    // compound division by a float
		operator/=(const float a);

	RGBColor                                    // component-wise multiplication
		operator*(const RGBColor& c) const;

	bool                                        // are two RGBColours the same?
		operator==(const RGBColor& c) const;

	bool             operator!=(const RGBColor& c) const;

	RGBColor                                    // raise components to a power
		powc(float p) const;

	float                                        // the average of the components
		average(void) const;
};

namespace std {
	RGBColor pow(const RGBColor& a, const Vector3D& b);
}

// inlined member functions

// ----------------------------------------------------------------------- operator+
// addition of two colors

inline RGBColor RGBColor::operator+(const RGBColor& c) const {
	return (RGBColor(r + c.r, g + c.g, b + c.b));
}

inline RGBColor RGBColor::operator-(const RGBColor& c) const {
	return (RGBColor(r - c.r, g - c.g, b - c.b));
}

// ----------------------------------------------------------------------- operator+=
// compound addition of two colors

inline RGBColor& RGBColor::operator+=(const RGBColor& c) {
	r += c.r;
	g += c.g;
	b += c.b;
	return (*this);
}

// ----------------------------------------------------------------------- operator*
// multiplication by a float on the right

inline RGBColor RGBColor::operator*(const float a) const {
	return (RGBColor(r * a, g * a, b * a));
}

// ----------------------------------------------------------------------- operator*=
// compound multiplication by a float on the right

inline RGBColor& RGBColor::operator*=(const float a) {
	r *= a;
	g *= a;
	b *= a;
	return (*this);
}

// ----------------------------------------------------------------------- operator/
// division by float

inline RGBColor RGBColor::operator/(const float a) const {
	return (RGBColor(r / a, g / a, b / a));
}

// ----------------------------------------------------------------------- operator/=
// compound division by float

inline RGBColor& RGBColor::operator/=(const float a) {
	r /= a;
	g /= a;
	b /= a;
	return (*this);
}

// ----------------------------------------------------------------------- operator*
// component-wise multiplication of two colors

inline RGBColor RGBColor::operator*(const RGBColor& c) const {
	return (RGBColor(r * c.r, g * c.g, b * c.b));
}

// ----------------------------------------------------------------------- operator==
// are two RGBColors the same?

inline bool RGBColor::operator==(const RGBColor& c) const {
	return (r == c.r && g == c.g && b == c.b);
}

inline bool RGBColor::operator!=(const RGBColor& c) const {
	return !(*this == c);
}

// ----------------------------------------------------------------------- average
// the average of the three components

inline float RGBColor::average(void) const {
	return (0.333333333333f * (r + g + b));
}

// inlined non-member function

// ----------------------------------------------------------------------- operator*
// multiplication by a float on the left

RGBColor operator*(const float a, const RGBColor& c);

inline RGBColor operator*(const float a, const RGBColor& c) {
	return (RGBColor(a * c.r, a * c.g, a * c.b));
}

#endif
