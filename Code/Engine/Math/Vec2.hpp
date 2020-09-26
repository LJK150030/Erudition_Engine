#pragma once


struct Vec2
{
	const  static Vec2 NULL;
	const static Vec2 UNIT_X;
	const static Vec2 UNIT_Y;
	
public:
	float x;
	float y;

public:
	Vec2() : x(0.0f), y(0.0f) {};
	Vec2(const Vec2& copy): x(copy.x), y(copy.y) {}
	explicit Vec2(const float init_x, const float init_y): x(init_x), y(init_y) {}
	~Vec2() = default;

	
	// Accessors
	float GetLength() const;
	float GetLengthSquared() const;
	float GetAngleDegrees() const;
	float GetAngleRadians() const;
	const Vec2 GetRotated90Degrees() const;
	const Vec2 GetRotatedMinus90Degrees() const;
	const Vec2 GetRotatedDegrees(float degrees_to_rotate) const;
	const Vec2 GetRotatedRadians(float radians_to_rotate) const;
	const Vec2 GetClamped(float max_length) const;
	const Vec2 GetNormalized() const;

	// Mutilators
	void SetLength(const float new_length);
	void SetAngleDegrees(const float new_angle_degrees);
	void SetAngleRadians(const float new_angle_radians);
	void Rotate90Degrees();
	void RotateMinus90Degrees();
	void RotateDegrees(const float additional_angle_degrees);
	void RotateRadians(const float additional_angle_radians);
	void ClampLength(const float max_length);
	void Normalize();
	float NormalizeAndGetOldLength();

	// Operators
	const Vec2 operator+(const Vec2& vec_to_add) const; // vec2 + vec2
	const Vec2 operator-(const Vec2& vec_to_subtract) const; // vec2 - vec2
	const Vec2 operator*(float uniform_scale) const; // vec2 * float
	const Vec2 operator/(float inverse_scale) const; // vec2 / float
	void operator+=(const Vec2& vec_to_add); // vec2 += vec2
	void operator-=(const Vec2& vec_to_subtract); // vec2 -= vec2
	void operator*=(float uniform_scale); // vec2 *= float
	void operator/=(float uniform_divisor); // vec2 /= float
	void operator=(const Vec2& copy_from); // vec2 = vec2
	bool operator==(const Vec2& compare) const; // vec2 == vec2
	bool operator!=(const Vec2& compare) const; // vec2 != vec2
};