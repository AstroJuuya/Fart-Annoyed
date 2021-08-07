#include "Ball.h"

Ball::Ball(const Vec2& pos, const Vec2& vel)
	:
	pos( pos ),
	vel( vel )
{
}

void Ball::Update(const float delta_time)
{
	// Moves ball relative to elapsed time, effectively moving the vel value in pixels per second
	pos += vel * delta_time;
	collided = false;
}

void Ball::ReboundX(const RectF& other)
{
	// Moves the ball back outside the other rectangle's boundaries before reversing the respective collision velocity
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
	// Moves the ball back within the wall's boundaries before reversing the respective collision velocity
	if (pos.x - radius < walls.left)
	{
		pos.x += walls.left - (pos.x - radius);
		vel.x = -vel.x;
		collided = true;
	}
	else if (pos.x + radius >= walls.right)
	{
		pos.x += walls.right - (pos.x + radius);
		vel.x = -vel.x;
		collided = true;
	}

	if (pos.y - radius < walls.top)
	{
		pos.y += walls.top - (pos.y - radius);
		vel.y = -vel.y;
		collided = true;
	}
	else if (pos.y + radius >= walls.bottom)
	{
		pos.y += walls.bottom - (pos.y + radius);
		vel.y = -vel.y;
		collided = true;
	}
}

RectF Ball::GetRect() const
{
	return RectF::fromCenter( pos, radius, radius );
}

Vec2 Ball::GetPosition() const
{
	return pos;
}

Vec2 Ball::GetVelocity() const
{
	return vel;
}

bool Ball::HasCollided() const
{
	return collided;
}
