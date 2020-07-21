#include "Engine/Math/Vec3.hpp"
#include "Engine/EngineCommon.hpp"
#include "Engine/Math/MathUtils.hpp"
#include "Engine/Core/ErrorWarningAssert.hpp"

const STATIC Vec3 Vec3::ZERO(0.f, 0.f, 0.0f);
const STATIC Vec3 Vec3::ONE(1.f, 1.f, 1.0f);

//-----------------------------------------------------------------------------------------------
Vec3::Vec3(const Vec3& copy_from) : x(copy_from.x), y(copy_from.y)
{
}


//-----------------------------------------------------------------------------------------------
Vec3::Vec3(const float initial_x, const float initial_y, const float initial_z) : x(initial_x),
	y(initial_y), z(initial_z)
{
}


//-----------------------------------------------------------------------------------------------
float Vec3::GetLength() const
{
	const float length_squared = GetLengthSquared();
	return Sqrt(length_squared);
}


//-----------------------------------------------------------------------------------------------
float Vec3::GetLengthSquared() const
{
	return x * x + y * y + z * z;
}


//-----------------------------------------------------------------------------------------------
const Vec3 Vec3::GetNormalized() const
{
	const float length = GetLength();
	ASSERT_OR_DIE(length != 0.0f, "Vec3::GetNormalized() is attempting to divide by zero.");
	return *this / length;
}


//-----------------------------------------------------------------------------------------------
void Vec3::Normalize()
{
	const float length = GetLength();
	ASSERT_OR_DIE(length != 0.0f, "Vec3::Normalize() is attempting to divide by zero.");
	*this /= length;
}


//-----------------------------------------------------------------------------------------------
void Vec3::operator+=(const Vec3& vec_to_add)					// Vec3 += vec_to_add
{
	x += vec_to_add.x;
	y += vec_to_add.y;
	z += vec_to_add.z;
}


//-----------------------------------------------------------------------------------------------
void Vec3::operator-=(const Vec3& vec_to_subtract)				// Vec3 -= vec_to_subtract
{
	x -= vec_to_subtract.x;
	y -= vec_to_subtract.y;
	z -= vec_to_subtract.z;
}


//-----------------------------------------------------------------------------------------------
void Vec3::operator*=(const float uniform_scale)				// Vec3 *= uniform_scale
{
	x *= uniform_scale;
	y *= uniform_scale;
	z *= uniform_scale;
}


//-----------------------------------------------------------------------------------------------
void Vec3::operator/=(const float uniform_divisor)				// Vec3 /= uniform_divisor
{
	ASSERT_OR_DIE(uniform_divisor != 0.0f, "The uniform_divisor cannot be zero.");
	x /= uniform_divisor;
	y /= uniform_divisor;
	z /= uniform_divisor;
}


//-----------------------------------------------------------------------------------------------
void Vec3::operator=(const Vec3& copy_from)						// Vec3 = copy_from
{
	x = copy_from.x;
	y = copy_from.y;
	z = copy_from.z;
}


//-----------------------------------------------------------------------------------------------
const Vec3 Vec3::operator + (const Vec3& vec_to_add) const		// Vec3 + vec_to_add
{
	return Vec3(x + vec_to_add.x, y + vec_to_add.y, z + vec_to_add.z);
}


//-----------------------------------------------------------------------------------------------
const Vec3 Vec3::operator-(const Vec3& vec_to_subtract) const	// Vec3 - vec_to_subtract
{
	return Vec3(x - vec_to_subtract.x, y - vec_to_subtract.y, z - vec_to_subtract.z);
}


//-----------------------------------------------------------------------------------------------
const Vec3 Vec3::operator*(const float uniform_scale) const		// Vec3 * uniform_scale
{
	return Vec3(x * uniform_scale, y * uniform_scale, z * uniform_scale);
}


//-----------------------------------------------------------------------------------------------
const Vec3 Vec3::operator/(const float inverse_scale) const		// Vec3 / inverse_scale
{
	return Vec3(x / inverse_scale, y / inverse_scale, z / inverse_scale);
}


//-----------------------------------------------------------------------------------------------
bool Vec3::operator==(const Vec3& compare) const				// Vec3 == compare
{
	return x == compare.x && y == compare.y &&  z == compare.z;
}


//-----------------------------------------------------------------------------------------------
bool Vec3::operator!=(const Vec3& compare) const				// Vec3 != compare
{
	return x != compare.x || y != compare.y || z != compare.z;
}


//-----------------------------------------------------------------------------------------------
const Vec3 operator*(const float uniform_scale, const Vec3& vec_to_scale)	// float * Vec3
{
	return Vec3(vec_to_scale.x * uniform_scale, vec_to_scale.y * uniform_scale,
		vec_to_scale.z * uniform_scale);
}

