#include "Brick.h"

Brick::Brick(const RectF& rect)
	:
	brick( rect )
{
}

void Brick::DoBallCollision(Ball& ball)
{
	if (IsOverlappingWith(ball.GetRect()) && !ball.HasCollided() )
	{
		RectF b = ball.GetRect();
		if (	( abs(b.right - brick.left) <= abs(b.bottom - brick.top) && abs(b.right - brick.left) <= abs(b.top - brick.bottom) ) 
			||	( abs(b.left - brick.right) <= abs(b.bottom - brick.top) && abs(b.left - brick.right) <= abs(b.top - brick.bottom) ) )
		{
			ball.ReboundX(brick);
		}
		if (	( abs(b.bottom - brick.top) <= abs(b.right - brick.left) && abs(b.bottom - brick.top) <= abs(b.left - brick.right) )
			||	( abs(b.top - brick.bottom) <= abs(b.right - brick.left) && abs(b.top - brick.bottom) <= abs(b.left - brick.right) ) )
		{
			ball.ReboundY(brick);
		}
		destroyed = true;
	}
}

void Brick::Draw(Graphics& gfx, Color color) const
{
	brick.Draw(gfx, color);
}

bool Brick::IsOverlappingWith(const RectF& other) const
{
	return brick.left < other.right && brick.top < other.bottom
		&& brick.right > other. left && brick.bottom > other.top;
}
