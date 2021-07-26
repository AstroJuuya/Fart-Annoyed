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
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

bool Ball::HasCollided() const
{
	return collided;
}
