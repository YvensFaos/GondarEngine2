#ifndef __GS_COLOR_H__
#define __GS_COLOR_H__

#include "gsConfig.h"
#include "gsMacros.h"
#include <ostream>

class GS_DLL gsColor {
public:
	union {
		float data[4];
		struct {
			float r;
			float g;
			float b;
			float a;
		};
	};

	gsColor();
	gsColor(float r, float g, float b, float a = 1.0f);

	void sendToOpenGL_Color(void) const;

	void operator +=(const gsColor& rhs);
	void operator -=(const gsColor& rhs);
	void operator *=(const gsColor& rhs);
	void operator /=(const gsColor& rhs);
	void operator *=(const float& rhs);
	void operator /=(const float& rhs);

public:
	static gsColor white(float a = 1.0f) { return gsColor(1, 1, 1, a); }
	static gsColor black(float a = 1.0f) { return gsColor(0, 0, 0, a); }

	static gsColor gray75(float a = 1.0f) { return gsColor(0.75f, 0.75f, 0.75f, a); }
	static gsColor gray50(float a = 1.0f) { return gsColor(0.50f, 0.50f, 0.50f, a); }
	static gsColor gray25(float a = 1.0f) { return gsColor(0.25f, 0.25f, 0.25f, a); }

	static gsColor red(float a = 1.0f) { return gsColor(1, 0, 0, a); }
	static gsColor green(float a = 1.0f) { return gsColor(0, 1, 0, a); }
	static gsColor blue(float a = 1.0f) { return gsColor(0, 0, 1, a); }

	static gsColor magenta(float a = 1.0f) { return gsColor(1, 0, 1, a); }
	static gsColor yellow(float a = 1.0f) { return gsColor(1, 1, 0, a); }
	static gsColor cyan(float a = 1.0f) { return gsColor(0, 1, 1, a); }
};

bool operator==(const gsColor& lhs, const gsColor& rhs);
bool operator!=(const gsColor& lhs, const gsColor& rhs);

gsColor operator+(const gsColor& lhs, const gsColor& rhs);
gsColor operator-(const gsColor& lhs, const gsColor& rhs);
gsColor operator*(const gsColor& lhs, const gsColor& rhs);
gsColor operator/(const gsColor& lhs, const gsColor& rhs);
gsColor operator*(const gsColor& lhs, const float& rhs);
gsColor operator/(const gsColor& lhs, const float& rhs);

// To String
std::ostream& operator<<(std::ostream& os, const gsColor& color);

#endif