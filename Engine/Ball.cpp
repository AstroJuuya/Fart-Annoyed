#include "Ball.h"

Ball::Ball(const Vec2& pos, const Vec2& vel)
	:
	pos( pos ),
	vel( vel ),
	setVelX( abs(vel.x) ),
	setVelY( abs(vel.y) )
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
		collidedPad = false;
	}
	else if (pos.x + radius >= other.right)
	{
		pos.x += other.right - (pos.x - radius);
		vel.x = -vel.x;
		collided = true;
		collidedPad = false;
	}
}

void Ball::ReboundY(const RectF& other)
{
	if (pos.y - radius < other.top)
	{
		pos.y += other.top - (pos.y + radius);
		vel.y = -vel.y;
		collided = true;
		collidedPad = false;
	}
	else if (pos.y + radius >= other.bottom)
	{
		pos.y += other.bottom - (pos.y - radius);
		vel.y = -vel.y;
		collided = true;
		collidedPad = false;
	}
}

void Ball::ReboundPadX(const RectF& paddle)
{
	if (!collidedPad)
	{
		ReboundX( paddle );
		collidedPad = true;
	}
}

void Ball::ReboundPadY(const RectF& paddle)
{
	if (pos.y - radius < paddle.top && !collidedPad)
	{
		const Vec2 paddleCenter = Vec2( paddle.right - ( paddle.right - paddle.left ) / 2, paddle.bottom - ( paddle.bottom - paddle.top ) / 2);

		pos.y += paddle.top - (pos.y + radius); // Move ball outside the paddle

		// Rebound ball relative to it's impact position on the paddle up to 45 degrees
		const float impactX = pos.x - paddleCenter.x;
		const float padWidth = paddle.right - paddleCenter.x;
		if ( impactX != 0.0f )
		{
			const float newVelDel = impactX / padWidth;
			float newVel = setVelX * newVelDel;

			vel.x = newVel;
			vel.y = -( setVelY * ( 2.0f - abs(newVelDel) ) );
		}
		else
		{
			vel.x = 0.0f;
			vel.y = setVelY * 2.0f;
		}
		collided = true;
		collidedPad = true;
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
		collidedPad = false;
	}
	else if (pos.x + radius >= walls.right)
	{
		pos.x += walls.right - (pos.x + radius);
		vel.x = -vel.x;
		collided = true;
		collidedPad = false;
	}

	if (pos.y - radius < walls.top)
	{
		pos.y += walls.top - (pos.y - radius);
		vel.y = -vel.y;
		collided = true;
		collidedPad = false;
	}
	else if (pos.y + radius >= walls.bottom)
	{
		pos.y += walls.bottom - (pos.y + radius);
		vel.y = -vel.y;
		destroyed = true;
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

float Ball::GetRadius() const
{
	return radius;
}

bool Ball::HasCollided() const
{
	return collided;
}

bool Ball::IsDestroyed() const
{
	return destroyed;
}
