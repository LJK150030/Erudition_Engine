#pragma once


//-----------------------------------------------------------------------------------------------
struct Vec2
{
public:
	// Construction/Destruction
	~Vec2() {}												// destructor: do nothing (for speed)
	Vec2() {}												// default constructor: do nothing (for speed)
	Vec2(const Vec2& copyFrom);							// copy constructor (from another vec2)
	explicit Vec2(float initialX, float initialY);		// explicit constructor (from x, y)

	// Operators
	const Vec2 operator+(const Vec2& vecToAdd) const;			// vec2 + vec2
	const Vec2 operator-(const Vec2& vecToSubtract) const;	// vec2 - vec2
	const Vec2 operator*(float uniformScale) const;			// vec2 * float
	const Vec2 operator/(float inverseScale) const;			// vec2 / float
	void operator+=(const Vec2& vecToAdd);					// vec2 += vec2
	void operator-=(const Vec2& vecToSubtract);				// vec2 -= vec2
	void operator*=(const float uniformScale);				// vec2 *= float
	void operator/=(const float uniformDivisor);				// vec2 /= float
	void operator=(const Vec2& copyFrom);						// vec2 = vec2
	bool operator==(const Vec2& compare) const;				// vec2 == vec2
	bool operator!=(const Vec2& compare) const;				// vec2 != vec2

	friend const Vec2 operator*(float uniformScale, const Vec2& vecToScale);	// float * vec2

public: // NOTE: this is one of the few cases where we break both the "m_" naming rule AND the avoid-public-members rule
	float x;
	float y;
};


