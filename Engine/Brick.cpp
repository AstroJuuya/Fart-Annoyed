#include "Brick.h"

Brick::Brick(const RectF& rect)
	:
	brick( rect )
{
}

void Brick::SetBorder(const float border)
{
	brdr = border;
}

void Brick::DoBallCollision(Ball& ball)
{
	if (brick.IsOverlappingWith(ball.GetRect()) && !destroyed )
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

void Brick::DrawReducedBorder(Graphics& gfx, Color color) const
{
	RectF( Vec2( brick.left + brdr, brick.top + brdr ), Vec2( brick.right - brdr, brick.bottom - brdr) ).Draw(gfx, color);
}

bool Brick::IsDestroyed() const
{
	return destroyed;
}
