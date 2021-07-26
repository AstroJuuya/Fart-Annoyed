#include "Ball.h"

Ball::Ball(Vec2 pos, Vec2 vel)
	:
	pos( pos ),
	vel( vel )
{
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
	collided = true;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
	collided = true;
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

RectF Ball::GetRect() const
{
	return RectF::fromCenter( pos, radius, radius );
}

bool Ball::HasCollided() const
{
	return collided;
}
