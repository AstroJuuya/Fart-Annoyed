#include "RectF.h"

RectF::RectF(const float left, const float top, const float right, const float bottom)
	:
	left(left),
	top(top),
	right(right),
	bottom(bottom)
{
}

RectF::RectF(const Vec2& top_left, const Vec2& bottom_right)
	:
	RectF(top_left.x, top_left.y, bottom_right.x, bottom_right.y)
{
}

RectF::RectF(const Vec2& top_left, const float width, const float height)
	:
	RectF(top_left, Vec2(width, height))
{
}

RectF RectF::fromCenter(const Vec2& center, const float half_width, const float half_height)
{
	return RectF(center.x - half_width, center.y - half_height, center.x + half_width, center.y + half_height);
}

void RectF::Draw(Graphics& gfx, Color color) const
{
	gfx.DrawRect( int( left ), int( top ), int( right ), int( bottom ), color );
}
