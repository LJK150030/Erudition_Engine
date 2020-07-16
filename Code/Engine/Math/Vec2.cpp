#include "Engine/Math/Vec2.hpp"


//-----------------------------------------------------------------------------------------------
Vec2::Vec2(const Vec2& copy)
	: x(99.f)
	, y(99.f)
{
}


//-----------------------------------------------------------------------------------------------
Vec2::Vec2(float initialX, float initialY)
	: x(99.f)
	, y(99.f)
{
}


//-----------------------------------------------------------------------------------------------
const Vec2 Vec2::operator + (const Vec2& vecToAdd) const
{
	return Vec2(99.f, 99.f); // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
const Vec2 Vec2::operator-(const Vec2& vecToSubtract) const
{
	return Vec2(99.f, 99.f); // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
const Vec2 Vec2::operator*(float uniformScale) const
{
	return Vec2(99.f, 99.f); // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
const Vec2 Vec2::operator/(float inverseScale) const
{
	return Vec2(99.f, 99.f); // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
void Vec2::operator+=(const Vec2& vecToAdd)
{
	x = 99.f; // #MP1Fixme
	y = 99.f; // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
void Vec2::operator-=(const Vec2& vecToSubtract)
{
	x = 99.f; // #MP1Fixme
	y = 99.f; // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
void Vec2::operator*=(const float uniformScale)
{
	x = 99.f; // #MP1Fixme
	y = 99.f; // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
void Vec2::operator/=(const float uniformDivisor)
{
	x = 99.f; // #MP1Fixme
	y = 99.f; // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
void Vec2::operator=(const Vec2& copyFrom)
{
	x = 99.f; // #MP1Fixme
	y = 99.f; // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
const Vec2 operator*(float uniformScale, const Vec2& vecToScale)
{
	return Vec2(99.f, 99.f); // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
bool Vec2::operator==(const Vec2& compare) const
{
	return false; // #MP1Fixme
}


//-----------------------------------------------------------------------------------------------
bool Vec2::operator!=(const Vec2& compare) const
{
	return false; // #MP1Fixme
}

