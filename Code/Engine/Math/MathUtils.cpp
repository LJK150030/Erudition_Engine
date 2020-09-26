#include "Engine/Math/MathUtils.hpp"
#include "Engine/Math/Vec2.hpp"
#include "Engine/EngineCommon.hpp"
#include <cmath>

//-----------------------------------------------------------------------------------------------
float Sqrt(const float num)
{
	return sqrt(num);
}


//-----------------------------------------------------------------------------------------------
float SinDegrees(const float value)
{
	return sinf(value) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float SinRadians(const float value)
{
	return sinf(value);
}


//-----------------------------------------------------------------------------------------------
float CosDegrees(const float value)
{
	return cosf(value) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float CosRadians(const float value)
{
	return cosf(value);
}


//-----------------------------------------------------------------------------------------------
float TanDegrees(const float value)
{
	return  tanf(value) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float TanRadians(const float value)
{
	return  tanf(value);
}


//-----------------------------------------------------------------------------------------------
float ArcSinDegrees(const float value)
{
	return asinf(value) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float ArcSinRadians(const float value)
{
	return asinf(value);
}


//-----------------------------------------------------------------------------------------------
float ArcCosDegrees(const float value)
{
	return acosf(value) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float ArcCosRadians(const float value)
{
	return acosf(value);
}


//-----------------------------------------------------------------------------------------------
float ArcTanDegrees(const float value)
{
	return atanf(value) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float ArcTanRadians(const float value)
{
	return atanf(value);
}


//-----------------------------------------------------------------------------------------------
float ArcTan2Degrees(const float y, const float x)
{
	return atan2f(y,x) * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float ArcTan2Radians(const float y, const float x)
{
	return atan2f(y, x);
}


//-----------------------------------------------------------------------------------------------
float RadiansToDegrees(const float radians)
{
	return radians * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float DegreesToRadians(const float degrees)
{
	return degrees * RAD_TO_DEG;
}


//-----------------------------------------------------------------------------------------------
float RangeMap(const float in_value, const float in_start, const float in_end, const float out_start, 
			   const float out_end)
{
	if (in_end == in_start)
	{
		return 0.5f * (out_start + out_end);
	}

	const float in_range = in_end - in_start;
	const float out_range = out_end - out_start;
	const float in_distance = in_value - in_start;
	const float in_fraction = in_distance / in_range;
	const float out_distance = in_fraction * out_range;
	const float out_value = out_start + out_distance;
	return out_value;
}


//-----------------------------------------------------------------------------------------------
float Distance(const Vec2& from, const Vec2& to)
{
	const Vec2 displacement = to - from;
	return displacement.GetLength();
}


//-----------------------------------------------------------------------------------------------
float DistanceSquared(const Vec2& from, const Vec2& to)
{
	const Vec2 displacement = to - from;
	return displacement.GetLengthSquared();
}


//-----------------------------------------------------------------------------------------------
Vec2 Min(const Vec2& v1, const Vec2& v2)
{
	const float x_min = Min(v1.x, v2.x);
	const float y_min = Min(v1.y, v2.y);
	return Vec2(x_min, y_min);
}


//-----------------------------------------------------------------------------------------------
Vec2 Max(const Vec2& v1, const Vec2& v2)
{
	const float x_max = Max(v1.x, v2.x);
	const float y_max = Max(v1.y, v2.y);
	return Vec2(x_max, y_max);
}


//-----------------------------------------------------------------------------------------------
Vec2 RangeMap(const Vec2& in_value, const Vec2& in_start, const Vec2& in_end, const Vec2& out_start, const Vec2& out_end)
{
	const float x_value = RangeMap(in_value.x, in_start.x, in_end.x, out_start.x, out_end.x);
	const float y_value = RangeMap(in_value.y, in_start.y, in_end.y, out_start.y, out_end.y);
	return Vec2(x_value, y_value);
}

//-----------------------------------------------------------------------------------------------
Vec2 Reflect(const Vec2& incident_vec, const Vec2& surface_vec)
{
	//Calculating the vector that bounces off of a surface, given a starting vector
	TODO("Vec2 Reflect(const Vec2& incident_vec, const Vec2& surface_vec)");
	return Vec2(-1.0f, -1.0f);
}


