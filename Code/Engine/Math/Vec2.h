#pragma once
#include "Engine/Core/ErrorWarningAssert.hpp"

#include <DirectXMath.h>

//-----------------------------------------------------------------------------------------------
//Wrapper class for the DirectX::XMFLOAT2A, intended only for front end work
//-----------------------------------------------------------------------------------------------
struct Vec2F : public DirectX::XMFLOAT2A
{
	Vec2F() : XMFLOAT2A(0.0f, 0.0f) {}

	constexpr explicit Vec2F(const float init_x) : XMFLOAT2A(init_x, init_x) {}
	constexpr explicit Vec2F(const float init_x, const float init_y) : XMFLOAT2A(init_x, init_y) {}

	explicit Vec2F(const Vec2F&) = default;
	explicit Vec2F(_In_reads_(2) const float* p_array) : XMFLOAT2A(p_array) {}
	explicit Vec2F(const DirectX::FXMVECTOR& dx_vec) : XMFLOAT2A() { DirectX::XMStoreFloat2A(this, dx_vec); }
	explicit Vec2F(const DirectX::XMFLOAT2A& vec2f) : XMFLOAT2A() { this->x = vec2f.x; this->y = vec2f.y; }
	explicit Vec2F(const DirectX::XMVECTORF32& vec2f) : XMFLOAT2A() { this->x = vec2f.f[0]; this->y = vec2f.f[1]; }
	
	
	explicit operator DirectX::XMVECTOR() const { return DirectX::XMLoadFloat2A(this); }

	// Comparison operators
	bool operator == (const Vec2F& vec_to_compare) const noexcept;
	bool operator != (const Vec2F& vec_to_compare) const noexcept;

	// Assignment operators
	Vec2F& operator= (const Vec2F&) = default;
	Vec2F& operator= (Vec2F&&) = default;
	Vec2F& operator= (const DirectX::XMVECTORF32& vec_to_copy);
	Vec2F& operator+= (const Vec2F& vec_to_add);
	Vec2F& operator-= (const Vec2F& vec_to_remove);
	Vec2F& operator*= (const Vec2F& vec_to_multiply);
	Vec2F& operator*= (const float uniform_scalar);
	Vec2F& operator/= (const float uniform_divisor);
};


//-----------------------------------------------------------------------------------------------
inline bool Vec2F::operator==(const Vec2F& vec_to_compare) const noexcept
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadFloat2A(this);
	const DirectX::XMVECTOR v2 = DirectX::XMLoadFloat2A(&vec_to_compare);
	return DirectX::XMVector2Equal(v1, v2);
}


//-----------------------------------------------------------------------------------------------
inline bool Vec2F::operator!=(const Vec2F& vec_to_compare) const noexcept
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadFloat2A(this);
	const DirectX::XMVECTOR v2 = DirectX::XMLoadFloat2A(&vec_to_compare);
	return DirectX::XMVector2NotEqual(v1, v2);
}


//-----------------------------------------------------------------------------------------------
inline Vec2F& Vec2F::operator=(const DirectX::XMVECTORF32& vec_to_copy)
{
	x = vec_to_copy.f[0];
	y = vec_to_copy.f[1];
	return *this;
}


//-----------------------------------------------------------------------------------------------
inline Vec2F& Vec2F::operator+=(const Vec2F& vec_to_add)
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadFloat2A(this);
	const DirectX::XMVECTOR v2 = DirectX::XMLoadFloat2A(&vec_to_add);
	const DirectX::XMVECTOR result = DirectX::XMVectorAdd(v1, v2);
	DirectX::XMStoreFloat2A(this, result);
	return *this;
}


//-----------------------------------------------------------------------------------------------
inline Vec2F& Vec2F::operator-=(const Vec2F& vec_to_remove)
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadFloat2A(this);
	const DirectX::XMVECTOR v2 = DirectX::XMLoadFloat2A(&vec_to_remove);
	const DirectX::XMVECTOR result = DirectX::XMVectorSubtract(v1, v2);
	DirectX::XMStoreFloat2A(this, result);
	return *this;
}


//-----------------------------------------------------------------------------------------------
inline Vec2F& Vec2F::operator*=(const Vec2F& vec_to_multiply)
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadFloat2A(this);
	const DirectX::XMVECTOR v2 = DirectX::XMLoadFloat2A(&vec_to_multiply);
	const DirectX::XMVECTOR result = DirectX::XMVectorMultiply(v1, v2);
	DirectX::XMStoreFloat2A(this, result);
	return *this;
}


//-----------------------------------------------------------------------------------------------
inline Vec2F& Vec2F::operator*=(const float uniform_scalar)
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadFloat2A(this);
	const DirectX::XMVECTOR result = DirectX::XMVectorScale(v1, uniform_scalar);
	DirectX::XMStoreFloat2A(this, result);
	return *this;
}


//-----------------------------------------------------------------------------------------------
inline Vec2F& Vec2F::operator/=(const float uniform_divisor)
{
	ASSERT_OR_DIE(uniform_divisor != 0.0f, "Vec2F::operator/= attempting to divide by zero");
	const float uniform_scalar = 1.0f / uniform_divisor;
	const DirectX::XMVECTOR v1 = DirectX::XMLoadFloat2A(this);
	const DirectX::XMVECTOR result = DirectX::XMVectorScale(v1, 1.f / uniform_scalar);
	XMStoreFloat2(this, result);
	return *this;
}




//-----------------------------------------------------------------------------------------------
//Wrapper class for the DirectX::XMINT2, intended only for front end work
//-----------------------------------------------------------------------------------------------
struct Vec2I : public DirectX::XMINT2
{
	Vec2I() : XMINT2(0, 0) {}

	constexpr explicit Vec2I(const int32_t init_x) : XMINT2(init_x, init_x) {}
	constexpr explicit Vec2I(const int32_t init_x, const int32_t init_y) : XMINT2(init_x, init_y) {}

	explicit Vec2I(const Vec2I&) = default;
	explicit Vec2I(_In_reads_(2) const int32_t* p_array) : XMINT2(p_array) {}
	explicit Vec2I(const DirectX::FXMVECTOR& dx_vec) : XMINT2() { DirectX::XMStoreSInt2(this, dx_vec); }
	explicit Vec2I(const DirectX::XMINT2& Vec2I) : XMINT2() { this->x = Vec2I.x; this->y = Vec2I.y; }
	explicit Vec2I(const DirectX::XMVECTORI32& Vec2I) : XMINT2() { this->x = Vec2I.i[0]; this->y = Vec2I.i[1]; }


	explicit operator DirectX::XMVECTOR() const { return DirectX::XMLoadSInt2(this); }

	// Comparison operators
	bool operator == (const Vec2I& vec_to_compare) const noexcept;
	bool operator != (const Vec2I& vec_to_compare) const noexcept;

	// Assignment operators
	Vec2I& operator= (const Vec2I&) = default;
	Vec2I& operator= (Vec2I&&) = default;
	Vec2I& operator= (const DirectX::XMVECTORI32& vec_to_copy);
	Vec2I& operator+= (const Vec2I& vec_to_add);
	Vec2I& operator-= (const Vec2I& vec_to_remove);
	Vec2I& operator*= (const Vec2I& vec_to_multiply);
	Vec2I& operator*= (const float uniform_scalar);
	Vec2I& operator/= (const float uniform_divisor);
};


//-----------------------------------------------------------------------------------------------
inline bool Vec2I::operator==(const Vec2I& vec_to_compare) const noexcept
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadSInt2(this);
	const DirectX::XMVECTOR v2 = DirectX::XMLoadSInt2(&vec_to_compare);
	return DirectX::XMVector2Equal(v1, v2);
}


//-----------------------------------------------------------------------------------------------
inline bool Vec2I::operator!=(const Vec2I& vec_to_compare) const noexcept
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadSInt2(this);
	const DirectX::XMVECTOR v2 = DirectX::XMLoadSInt2(&vec_to_compare);
	return DirectX::XMVector2NotEqual(v1, v2);
}


//-----------------------------------------------------------------------------------------------
inline Vec2I& Vec2I::operator=(const DirectX::XMVECTORI32& vec_to_copy)
{
	x = vec_to_copy.i[0];
	y = vec_to_copy.i[1];
	return *this;
}


//-----------------------------------------------------------------------------------------------
inline Vec2I& Vec2I::operator+=(const Vec2I& vec_to_add)
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadSInt2(this);
	const DirectX::XMVECTOR v2 = DirectX::XMLoadSInt2(&vec_to_add);
	const DirectX::XMVECTOR result = DirectX::XMVectorAdd(v1, v2);
	DirectX::XMStoreSInt2(this, result);
	return *this;
}


//-----------------------------------------------------------------------------------------------
inline Vec2I& Vec2I::operator-=(const Vec2I& vec_to_remove)
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadSInt2(this);
	const DirectX::XMVECTOR v2 = DirectX::XMLoadSInt2(&vec_to_remove);
	const DirectX::XMVECTOR result = DirectX::XMVectorSubtract(v1, v2);
	DirectX::XMStoreSInt2(this, result);
	return *this;
}


//-----------------------------------------------------------------------------------------------
inline Vec2I& Vec2I::operator*=(const Vec2I& vec_to_multiply)
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadSInt2(this);
	const DirectX::XMVECTOR v2 = DirectX::XMLoadSInt2(&vec_to_multiply);
	const DirectX::XMVECTOR result = DirectX::XMVectorMultiply(v1, v2);
	DirectX::XMStoreSInt2(this, result);
	return *this;
}


//-----------------------------------------------------------------------------------------------
inline Vec2I& Vec2I::operator*=(const float uniform_scalar)
{
	const DirectX::XMVECTOR v1 = DirectX::XMLoadSInt2(this);
	const DirectX::XMVECTOR result = DirectX::XMVectorScale(v1, uniform_scalar);
	DirectX::XMStoreSInt2(this, result);
	return *this;
}


//-----------------------------------------------------------------------------------------------
inline Vec2I& Vec2I::operator/=(const float uniform_divisor)
{
	ASSERT_OR_DIE(uniform_divisor != 0.0f, "Vec2I::operator/= attempting to divide by zero");
	const float uniform_scalar = 1.0f / uniform_divisor;
	const DirectX::XMVECTOR v1 = DirectX::XMLoadSInt2(this);
	const DirectX::XMVECTOR result = DirectX::XMVectorScale(v1, 1.f / uniform_scalar);
	XMStoreSInt2(this, result);
	return *this;
}
