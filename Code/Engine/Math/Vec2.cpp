#include "Engine/Math/Vec2.hpp"
#include "Engine/EngineCommon.hpp"
#include "Engine/Math/MathUtils.hpp"
#include "Engine/Core/ErrorWarningAssert.hpp"

const STATIC Vec2 Vec2::ZERO(0.f, 0.f);
const STATIC Vec2 Vec2::ONE(1.f, 1.f);

//-----------------------------------------------------------------------------------------------
Vec2::Vec2(const Vec2& copy_from): x(copy_from.x), y(copy_from.y)
{
}


//-----------------------------------------------------------------------------------------------
Vec2::Vec2(const float initial_x, const float initial_y): x(initial_x), y(initial_y)
{	
}


//-----------------------------------------------------------------------------------------------
float Vec2::GetLength() const
{
	const float length_squared = GetLengthSquared();
	return Sqrt(length_squared);
}


//-----------------------------------------------------------------------------------------------
float Vec2::GetLengthSquared() const
{
	return x*x + y*y;
}


//-----------------------------------------------------------------------------------------------
const Vec2 Vec2::GetNormalized() const
{
	const float length = GetLength();
	ASSERT_OR_DIE(length != 0.0f, "Vec2::GetNormalized() is attempting to divide by zero.");
	return *this / length;
}


//-----------------------------------------------------------------------------------------------
void Vec2::Normalize()
{
	const float length = GetLength();
	ASSERT_OR_DIE(length != 0.0f, "Vec2::Normalize() is attempting to divide by zero.");
	*this /= length;
}


//-----------------------------------------------------------------------------------------------
void Vec2::operator+=(const Vec2& vec_to_add)					// vec2 += vec_to_add
{
	x += vec_to_add.x;
	y += vec_to_add.y;
}


//-----------------------------------------------------------------------------------------------
void Vec2::operator-=(const Vec2& vec_to_subtract)				// vec2 -= vec_to_subtract
{
	x -= vec_to_subtract.x;
	y -= vec_to_subtract.y;
}


//-----------------------------------------------------------------------------------------------
void Vec2::operator*=(const float uniform_scale)				// vec2 *= uniform_scale
{
	x *= uniform_scale;
	y *= uniform_scale;
}


//-----------------------------------------------------------------------------------------------
void Vec2::operator/=(const float uniform_divisor)				// vec2 /= uniform_divisor
{
	ASSERT_OR_DIE(uniform_divisor != 0.0f, "The uniform_divisor cannot be zero.");
	x /= uniform_divisor;
	y /= uniform_divisor;
}


//-----------------------------------------------------------------------------------------------
void Vec2::operator=(const Vec2& copy_from)						// vec2 = copy_from
{
	x = copy_from.x;
	y = copy_from.y;
}


//-----------------------------------------------------------------------------------------------
const Vec2 Vec2::operator + (const Vec2& vec_to_add) const		// vec2 + vec_to_add
{
	return Vec2(x + vec_to_add.x, y + vec_to_add.y);
}


//-----------------------------------------------------------------------------------------------
const Vec2 Vec2::operator-(const Vec2& vec_to_subtract) const	// vec2 - vec_to_subtract
{
	return Vec2(x - vec_to_subtract.x, y - vec_to_subtract.y);
}


//-----------------------------------------------------------------------------------------------
const Vec2 Vec2::operator*(const float uniform_scale) const		// vec2 * uniform_scale
{
	return Vec2(x * uniform_scale, y * uniform_scale);
}


//-----------------------------------------------------------------------------------------------
const Vec2 Vec2::operator/(const float inverse_scale) const		// vec2 / inverse_scale
{
	return Vec2(x / inverse_scale, y / inverse_scale);
}


//-----------------------------------------------------------------------------------------------
bool Vec2::operator==(const Vec2& compare) const				// vec2 == compare
{
	return x == compare.x && y == compare.y;
}


//-----------------------------------------------------------------------------------------------
bool Vec2::operator!=(const Vec2& compare) const				// vec2 != compare
{
	return x != compare.x || y != compare.y;
}


//-----------------------------------------------------------------------------------------------
const Vec2 operator*(const float uniform_scale, const Vec2& vec_to_scale)	// float * vec2
{
	return Vec2(vec_to_scale.x * uniform_scale, vec_to_scale.y * uniform_scale);
}

