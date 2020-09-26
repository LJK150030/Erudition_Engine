#include "Engine/Math/Vec2.hpp"
#include "Engine/EngineCommon.hpp"
#include "Engine/Math/MathUtils.hpp"

const STATIC Vec2 Vec2::NULL(0.f, 0.f);
const STATIC Vec2 Vec2::UNIT_X(1.f, 0.f);
const STATIC Vec2 Vec2::UNIT_Y(0.f, 1.f);

//--------------------------------------------------------------------------------------
float Vec2::GetLength() const
{
	const float length_squared = x * x + y * y;
	return Sqrt(length_squared);
}


//--------------------------------------------------------------------------------------
float Vec2::GetLengthSquared() const
{
	return x * x + y * y;
}


//--------------------------------------------------------------------------------------
float Vec2::GetAngleDegrees() const
{
	return ArcTan2Degrees(y, x);
}


//--------------------------------------------------------------------------------------
float Vec2::GetAngleRadians() const
{
	return ArcTan2Radians(y, x);
}


//--------------------------------------------------------------------------------------
const Vec2 Vec2::GetRotated90Degrees() const
{
	return Vec2(-y, x);
}


//--------------------------------------------------------------------------------------
const Vec2 Vec2::GetRotatedMinus90Degrees() const
{
	return Vec2(y, -x);
}


//--------------------------------------------------------------------------------------
const Vec2 Vec2::GetRotatedDegrees(const float degrees_to_rotate) const
{
	const float new_x = x * CosDegrees(degrees_to_rotate) - y * SinDegrees(degrees_to_rotate);
	const float new_y = x * SinDegrees(degrees_to_rotate) + y * CosDegrees(degrees_to_rotate);
	return Vec2(new_x, new_y);
}


//--------------------------------------------------------------------------------------
const Vec2 Vec2::GetRotatedRadians(const float radians_to_rotate) const
{
	const float new_x = x * CosRadians(radians_to_rotate) - y * SinRadians(radians_to_rotate);
	const float new_y = x * SinRadians(radians_to_rotate) + y * CosRadians(radians_to_rotate);
	return Vec2(new_x, new_y);
}


//--------------------------------------------------------------------------------------
const Vec2 Vec2::GetClamped(float max_length) const
{
	const float length_squared = x * x + y * y;
	const float max_length_squared = max_length * max_length;
	
	if(length_squared < max_length_squared)
	{
		return Vec2(x, y);
	}

	TODO("const Vec2 Vec2::GetClamped(float max_length) const");

	return Vec2(-1.0f, -1.0f);
}


//--------------------------------------------------------------------------------------
const Vec2 Vec2::GetNormalized() const
{
	TODO("const Vec2 Vec2::GetNormalized() const");
	
	return Vec2(-1.0f, -1.0f);
}


//--------------------------------------------------------------------------------------
void Vec2::SetLength(float new_length)
{
	TODO("void Vec2::SetLength(float new_length)");
}


//--------------------------------------------------------------------------------------
void Vec2::SetAngleDegrees(float new_angle_degrees)
{
	TODO("void Vec2::SetAngleDegrees(float new_angle_degrees)")
}


//--------------------------------------------------------------------------------------
void Vec2::SetAngleRadians(float new_angle_radians)
{
	TODO("void Vec2::SetAngleRadians(float new_angle_radians)")
}


//--------------------------------------------------------------------------------------
void Vec2::Rotate90Degrees()
{
	TODO("void Vec2::Rotate90Degrees()")
}


//--------------------------------------------------------------------------------------
void Vec2::RotateMinus90Degrees()
{
	TODO("void Vec2::RotateMinus90Degrees()")
}


//--------------------------------------------------------------------------------------
void Vec2::RotateDegrees(float additional_angle_degrees)
{
	TODO("void Vec2::RotateDegrees(float additional_angle_degrees)")
}


//--------------------------------------------------------------------------------------
void Vec2::RotateRadians(float additional_angle_radians)
{
	TODO("void Vec2::RotateRadians(float additional_angle_radians)")
}


//--------------------------------------------------------------------------------------
void Vec2::ClampLength(float max_length)
{
	TODO("void Vec2::ClampLength(float max_length)")
}


//--------------------------------------------------------------------------------------
void Vec2::Normalize()
{
	TODO("void Vec2::Normalize()")
}


//--------------------------------------------------------------------------------------
float Vec2::NormalizeAndGetOldLength()
{
	TODO("float Vec2::NormalizeAndGetOldLength()");
	return -1;
}


//--------------------------------------------------------------------------------------
const Vec2 Vec2::operator+(const Vec2& vec_to_add) const
{
	TODO("const Vec2 Vec2::operator+(const Vec2& vec_to_add) const")
	return Vec2(-1.0f, -1.0f);
}


//--------------------------------------------------------------------------------------
const Vec2 Vec2::operator-(const Vec2& vec_to_subtract) const
{
	TODO("const Vec2 Vec2::operator-(const Vec2& vec_to_subtract) const")
	return Vec2(-1.0f, -1.0f);
}


//--------------------------------------------------------------------------------------
const Vec2 Vec2::operator*(float uniform_scale) const
{
	TODO("const Vec2 Vec2::operator*(float uniform_scale) const")
	return Vec2(-1.0f, -1.0f);
}


//--------------------------------------------------------------------------------------
const Vec2 Vec2::operator/(float inverse_scale) const
{
	TODO("const Vec2 Vec2::operator/(float inverse_scale) const")
	return Vec2(-1.0f, -1.0f);
}


//--------------------------------------------------------------------------------------
void Vec2::operator+=(const Vec2& vec_to_add)
{
	TODO("void Vec2::operator+=(const Vec2& vec_to_add)")
}


//--------------------------------------------------------------------------------------
void Vec2::operator-=(const Vec2& vec_to_subtract)
{
	TODO("void Vec2::operator-=(const Vec2& vec_to_subtract)")
}


//--------------------------------------------------------------------------------------
void Vec2::operator*=(float uniform_scale)
{
	TODO("void Vec2::operator*=(float uniform_scale)")
}


//--------------------------------------------------------------------------------------
void Vec2::operator/=(float uniform_divisor)
{
	TODO("void Vec2::operator/=(float uniform_divisor)")
}


//--------------------------------------------------------------------------------------
void Vec2::operator=(const Vec2& copy_from)
{
	TODO("void Vec2::operator=(const Vec2& copy_from)")
}


//--------------------------------------------------------------------------------------
bool Vec2::operator==(const Vec2& compare) const
{
	TODO("bool Vec2::operator==(const Vec2& compare) const")
	return false;
}


//--------------------------------------------------------------------------------------
bool Vec2::operator!=(const Vec2& compare) const
{
	TODO("bool Vec2::operator!=(const Vec2& compare) const")
	return false;
}
