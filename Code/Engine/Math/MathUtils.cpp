#include "Engine/Math/MathUtils.hpp"
#include "Engine/Math/Vec2.hpp"
#include "Engine/Math/Vec3.hpp"
#include <cmath>


//-----------------------------------------------------------------------------------------------
float Sqrt(const float val)
{
	return sqrtf(val);
}


//-----------------------------------------------------------------------------------------------
float RadiansToDegrees(const float radians)
{
	return radians * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float DegreesToRadians(const float degrees)
{
	return degrees * DEG_TO_RAD;
}


//-----------------------------------------------------------------------------------------------
float CosDegrees(const float val)
{
	return cosf(val) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float CosRadians(const float val)
{
	return cosf(val);
}


//-----------------------------------------------------------------------------------------------
float SinDegrees(const float val)
{
	return sinf(val) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float SinRadians(const float val)
{
	return sinf(val);
}


//-----------------------------------------------------------------------------------------------
float TanDegrees(const float val)
{
	return tanf(val) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float TanRadians(const float val)
{
	return tanf(val);
}


//-----------------------------------------------------------------------------------------------
float ArcCosDegrees(const float val)
{
	return acosf(val) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float ArcCosRadians(const float val)
{
	return acosf(val);
}


//-----------------------------------------------------------------------------------------------
float ArcSinDegrees(const float val)
{
	return asinf(val) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float ArcSinRadians(const float val)
{
	return asinf(val);
}


//-----------------------------------------------------------------------------------------------
float ArcTanDegrees(const float val)
{
	return atanf(val) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float ArcTanRadians(const float val)
{
	return atanf(val);
}



//-----------------------------------------------------------------------------------------------
float DotProduct(const Vec2& u, const Vec2& v)
{
	return u.x*v.x + u.y*v.y;
}


//-----------------------------------------------------------------------------------------------
float DotProduct(const Vec3& u, const Vec3& v)
{
	return u.x*v.x + u.y*v.y + u.z*v.z;
}


//-----------------------------------------------------------------------------------------------
bool IsPerpendicular(const Vec2& u, const Vec2& v)
{
	return DotProduct(u, v) == 0.0f;
}


//-----------------------------------------------------------------------------------------------
bool IsPerpendicular(const Vec3& u, const Vec3& v)
{
	return DotProduct(u, v) == 0.0f;
}




