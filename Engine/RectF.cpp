#include "RectF.h"

RectF::RectF(const float left, const float top, const float right, const float bottom, const Color color)
	:
	left(left),
	top(top),
	right(right),
	bottom(bottom),
	color(color)
{
}

RectF::RectF(const Vec2& top_left, const Vec2& bottom_right, const Color color)
	:
	RectF(top_left.x, top_left.y, bottom_right.x, bottom_right.y, color)
{
}

RectF::RectF(const Vec2& top_left, const float width, const float height, const Color color)
	:
	RectF(top_left, Vec2(width, height), color)
{
}

void RectF::fromCenter(const Vec2& center, const float half_width, const float half_height, const Color color)
{
	RectF(center.x - half_width, center.y - half_height, center.x + half_width, center.y + half_height, color);
}

void RectF::Draw(Graphics& gfx) const
{
	gfx.DrawRect( int( left ), int( top ), int( right ), int( bottom ), color );
}
