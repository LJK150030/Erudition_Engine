#pragma once


//-----------------------------------------------------------------------------------------------
struct Vec3
{
public:
	const static Vec3 ZERO;
	const static Vec3 ONE;
	
public:
	// Construction/Destruction
	Vec3() = default;													// default constructor: do nothing (for speed)
	~Vec3() = default;													// destructor: do nothing (for speed)
	Vec3(const Vec3& copy_from);										// copy constructor (from another Vec3)
	explicit Vec3(float initial_x, float initial_y, float initial_z);	// explicit constructor (from x, y, z)

	// Accessors
	float GetLength() const;
	float GetLengthSquared() const;
	const Vec3 GetNormalized() const;

	// Mutators
	void Normalize();
	void operator+=(const Vec3& vec_to_add);					// Vec3 += Vec3
	void operator-=(const Vec3& vec_to_subtract);				// Vec3 -= Vec3
	void operator*=(const float uniform_scale);					// Vec3 *= float
	void operator/=(const float uniform_divisor);				// Vec3 /= float
	void operator=(const Vec3& copy_from);						// Vec3 = Vec3
	bool operator==(const Vec3& compare) const;					// Vec3 == Vec3
	bool operator!=(const Vec3& compare) const;					// Vec3 != Vec3

	
	const Vec3 operator+(const Vec3& vec_to_add) const;			// Vec3 + Vec3
	const Vec3 operator-(const Vec3& vec_to_subtract) const;	// Vec3 - Vec3
	const Vec3 operator*(float uniform_scale) const;			// Vec3 * float
	const Vec3 operator/(float inverse_scale) const;			// Vec3 / float
	friend const Vec3 operator*(float uniform_scale, const Vec3& vec_to_scale);	// float * Vec3


public: // NOTE: this is one of the few cases where we break both the "m_" naming rule AND the avoid-public-members rule
	float x;
	float y;
	float z;
};


