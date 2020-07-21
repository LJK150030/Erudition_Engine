#pragma once

constexpr float PI = 3.1415926535f;
constexpr float RAD_TO_DEG = 180.0f / PI;
constexpr float DEG_TO_RAD = PI / 180.0f;

struct Vec2;
struct Vec3;


// Algebra 
float Sqrt(float val);


// Trigonometry
float RadiansToDegrees(float radians);
float DegreesToRadians(float degrees);

float CosDegrees(float val);
float CosRadians(float val);
float SinDegrees(float val);
float SinRadians(float val);
float TanDegrees(float val);
float TanRadians(float val);
float ArcCosDegrees(float val);
float ArcCosRadians(float val);
float ArcSinDegrees(float val);
float ArcSinRadians(float val);
float ArcTanDegrees(float val);
float ArcTanRadians(float val);

float DotProduct(const Vec2& u, const Vec2& v);
float DotProduct(const Vec3& u, const Vec3& v);

bool IsPerpendicular(const Vec2& u, const Vec2& v);
bool IsPerpendicular(const Vec3& u, const Vec3& v);

const Vec2 Projection(const Vec2& vec, const Vec2& onto);
