#include "Brick.h"

Brick::Brick(const RectF& rect)
	:
	brick( rect )
{
}

void Brick::DoBallCollision(Ball& ball)
{
	if ( IsOverlappingWith( ball.GetRect() ) && !ball.HasCollided() )
	{
		ball.ReboundY();
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
		&& brick.right < other. left && brick.bottom < other.top;
}
