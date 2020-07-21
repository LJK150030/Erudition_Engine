#pragma once


//-----------------------------------------------------------------------------------------------
struct Vec2
{
public:
	const static Vec2 ZERO;
	const static Vec2 ONE;
	
public:
	// Construction/Destruction
	Vec2() = default;								// default constructor: do nothing (for speed)
	~Vec2() = default;								// destructor: do nothing (for speed)
	Vec2(const Vec2& copy_from);					// copy constructor (from another vec2)
	explicit Vec2(float initial_x, float initial_y);	// explicit constructor (from x, y)

	// Accessors
	float GetLength() const;
	float GetLengthSquared() const;
	const Vec2 GetNormalized() const;

	// Mutators
	void Normalize();
	void operator+=(const Vec2& vec_to_add);					// vec2 += vec2
	void operator-=(const Vec2& vec_to_subtract);				// vec2 -= vec2
	void operator*=(const float uniform_scale);					// vec2 *= float
	void operator/=(const float uniform_divisor);				// vec2 /= float
	void operator=(const Vec2& copy_from);						// vec2 = vec2
	bool operator==(const Vec2& compare) const;					// vec2 == vec2
	bool operator!=(const Vec2& compare) const;					// vec2 != vec2


	const Vec2 operator+(const Vec2& vec_to_add) const;			// vec2 + vec2
	const Vec2 operator-(const Vec2& vec_to_subtract) const;	// vec2 - vec2
	const Vec2 operator*(float uniform_scale) const;			// vec2 * float
	const Vec2 operator/(float inverse_scale) const;			// vec2 / float
	friend const Vec2 operator*(float uniform_scale, const Vec2& vec_to_scale);	// float * vec2

	
public: // NOTE: this is one of the few cases where we break both the "m_" naming rule AND the avoid-public-members rule
	float x;
	float y;
};


