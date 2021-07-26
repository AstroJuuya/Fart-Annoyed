#pragma once

#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"

class RectF
{
public:
	RectF( const float left, const float top, const float right, const float bottom, const Color color );
	RectF( const Vec2& top_left, const Vec2& bottom_right, const Color color );
	RectF( const Vec2& top_left, const float width, const float height, const Color color );
	static void fromCenter( const Vec2& center, const float half_width, const float half_height, const Color color );
	void Draw(Graphics& gfx) const;
public:
	float left;
	float top;
	float right;
	float bottom;
	Color color;
};