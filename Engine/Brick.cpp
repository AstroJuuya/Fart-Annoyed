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
	// Compares penetration depth on each side and rebounds the shallowest side
	if (brick.IsOverlappingWith(ball.GetRect()) && !destroyed )
	{
		const RectF b = ball.GetRect();
		const Vec2 center = Vec2( ( brick.right - brick.left ) / 2, ( brick.bottom - brick.top ) / 2 );
		if (	( abs(b.right - brick.left) <= abs(b.bottom - brick.top) && abs(b.right - brick.left) <= abs(b.top - brick.bottom) ) 
			||	( abs(b.left - brick.right) <= abs(b.bottom - brick.top) && abs(b.left - brick.right) <= abs(b.top - brick.bottom) ) )
		{
			// Check if the ball is actually moving towards the other object otherwise rebound the other way
			if ( signbit( (ball.GetPosition() - center).GetLengthSq() ) == signbit( ball.GetVelocity().GetLengthSq() ) )
			{
				ball.ReboundX(brick);
			}
			else
			{
				ball.ReboundY(brick);
			}
			
		}
		if (	( abs(b.bottom - brick.top) <= abs(b.right - brick.left) && abs(b.bottom - brick.top) <= abs(b.left - brick.right) )
			||	( abs(b.top - brick.bottom) <= abs(b.right - brick.left) && abs(b.top - brick.bottom) <= abs(b.left - brick.right) ) )
		{
			if ( signbit( (ball.GetPosition() - center).GetLengthSq() ) == signbit( ball.GetVelocity().GetLengthSq() ) )
			{
				ball.ReboundY(brick);
			}
			else
			{
				ball.ReboundX(brick);
			}
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
