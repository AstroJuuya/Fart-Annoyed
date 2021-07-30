#include "Ball.h"

Ball::Ball(Vec2 pos, Vec2 vel)
	:
	pos( pos ),
	vel( vel )
{
}

void Ball::Update(const float delta_time)
{
	pos += vel * delta_time;
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

void Ball::DoWallCollision(RectF walls)
{
	if (pos.x - radius < walls.left)
	{
		pos.x += walls.left - ( pos.x - radius );
		ReboundX();
	}
	else if (pos.x + radius >= walls.right)
	{
		pos.x += walls.right - ( pos.x + radius );
		ReboundX();
	}

	if (pos.y - radius < walls.top)
	{
		pos.y += walls.top - (pos.y - radius);
		ReboundY();
	}
	else if (pos.y + radius >= walls.bottom)
	{
		pos.y += walls.bottom - (pos.y + radius);
		ReboundY();
	}
}

RectF Ball::GetRect() const
{
	return RectF::fromCenter( pos, radius, radius );
}

bool Ball::HasCollided() const
{
	return collided;
}
