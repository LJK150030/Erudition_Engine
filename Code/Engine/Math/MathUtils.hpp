#pragma once

struct Vec2;
constexpr float PI = 3.1415926535f;
constexpr float RAD_TO_DEG = 180.0f / PI;
constexpr float DEG_TO_RAD = PI / 180.0f;

constexpr float Min(float a, float b) {	return (((a) < (b)) ? (a) : (b)); }
constexpr float Max(float a, float b) {	return (((a) > (b)) ? (a) : (b)); }


float Sqrt(float num);


// Trigonometry
float SinDegrees(float value);
float SinRadians(float value);
float CosDegrees(float value);
float CosRadians(float value);
float TanDegrees(float value);
float TanRadians(float value);
float ArcSinDegrees(float value);
float ArcSinRadians(float value);
float ArcCosDegrees(float value);
float ArcCosRadians(float value);
float ArcTanDegrees(float value);
float ArcTanRadians(float value);
float ArcTan2Degrees(float y, float x);
float ArcTan2Radians(float y, float x);

float RadiansToDegrees(float radians);
float DegreesToRadians(float degrees);
float RangeMap(float in_value, float in_start, float in_end, float out_start, float out_end);

float Distance(const Vec2& from, const Vec2& to);
float DistanceSquared(const Vec2& from, const Vec2& to);
Vec2 Min(const Vec2& v1, const Vec2& v2);
Vec2 Max(const Vec2& v1, const Vec2& v2);
Vec2 RangeMap(const Vec2& in_value, const Vec2& in_start, const Vec2& in_end, const Vec2& out_start, const Vec2& out_end);
Vec2 Reflect(const Vec2& incident_vec, const Vec2& surface_vec);
