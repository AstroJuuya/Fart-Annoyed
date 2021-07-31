#include "Ball.h"

Ball::Ball(const Vec2& pos, const Vec2& vel)
	:
	pos( pos ),
	vel( vel )
{
}

void Ball::Update(const float delta_time)
{
	pos += vel * delta_time;
}

void Ball::ReboundX(const RectF& other)
{
	if (pos.x - radius < other.left)
	{
		pos.x += other.left - (pos.x + radius);
		vel.x = -vel.x;
		collided = true;
	}
	else if (pos.x + radius >= other.right)
	{
		pos.x += other.right - (pos.x - radius);
		vel.x = -vel.x;
		collided = true;
	}
}

void Ball::ReboundY(const RectF& other)
{
	if (pos.y - radius < other.top)
	{
		pos.y += other.top - (pos.y + radius);
		vel.y = -vel.y;
		collided = true;
	}
	else if (pos.y + radius >= other.bottom)
	{
		pos.y += other.bottom - (pos.y - radius);
		vel.y = -vel.y;
		collided = true;
	}
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::DoWallCollision(const RectF& walls)
{
	if (pos.x - radius < walls.left)
	{
		pos.x += walls.left - (pos.x - radius);
		vel.x = -vel.x;
	}
	else if (pos.x + radius >= walls.right)
	{
		pos.x += walls.right - (pos.x + radius);
		vel.x = -vel.x;
	}

	if (pos.y - radius < walls.top)
	{
		pos.y += walls.top - (pos.y - radius);
		vel.y = -vel.y;
	}
	else if (pos.y + radius >= walls.bottom)
	{
		pos.y += walls.bottom - (pos.y + radius);
		vel.y = -vel.y;
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
