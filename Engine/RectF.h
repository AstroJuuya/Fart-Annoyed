#pragma once

#include "Vec2.h"
#include "Graphics.h"

class RectF
{
public:
	RectF() = default;
	RectF( const float left, const float top, const float right, const float bottom);
	RectF( const Vec2& top_left, const Vec2& bottom_right);
	RectF( const Vec2& top_left, const float width, const float height);
	static RectF fromCenter( const Vec2& center, const float half_width, const float half_height);
	void Draw(Graphics& gfx, const Color color) const;
public:
	float left;
	float top;
	float right;
	float bottom;
};