#ifndef __GS_VECTOR_2_H__
#define __GS_VECTOR_2_H__

#include "gsConfig.h"
#include "gsMacros.h"
#include <ostream>

class GS_DLL gsVector2 {
public:
	union {
		float data[2];
		struct {
			float x;
			float y;
		};
	};

	gsVector2(void);
	gsVector2(float points[2]);
	gsVector2(float x, float y);

	float magnitude(void) const;
	void normalize(void);

	void rotate(float angle);

	bool isZeroVector(void) const;

	void operator +=(const gsVector2& rhs);
	void operator -=(const gsVector2& rhs);
	void operator *=(const float& rhs);
	void operator /=(const float& rhs);

public:
	static float dot(const gsVector2&, const gsVector2&);

	static gsVector2 zero() { return gsVector2(0.0f, 0.0f); }
	static gsVector2 one() { return gsVector2(1.0f, 1.0f); }
};

bool operator==(const gsVector2& lhs, const gsVector2& rhs);
bool operator!=(const gsVector2& lhs, const gsVector2& rhs);

gsVector2 operator+(const gsVector2& lhs, const gsVector2& rhs);
gsVector2 operator-(const gsVector2& lhs, const gsVector2& rhs);
gsVector2 operator*(const gsVector2& lhs, const float& rhs);
gsVector2 operator/(const gsVector2& lhs, const float& rhs);

std::ostream& operator<<(std::ostream& os, const gsVector2& vector);

#endif