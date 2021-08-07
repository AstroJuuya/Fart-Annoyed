#pragma once

#include "Graphics.h"
#include "RectF.h"
#include "SpriteCodex.h"
#include "FrameTimer.h"

class Ball
{
public:
	Ball(const Vec2& pos, const Vec2& vel);
	void Update(const float delta_time);
	void ReboundX(const RectF& other);
	void ReboundY(const RectF& other);
	void ReboundPadX(const RectF& paddle);
	void ReboundPadY(const RectF& paddle);
	void Draw(Graphics& gfx) const;
	void DoWallCollision(const RectF& walls);
	RectF GetRect() const;
	Vec2 GetPosition() const;
	Vec2 GetVelocity() const;
	float GetRadius() const;
	bool HasCollided() const;
	bool IsDestroyed() const;
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
	float setVelX;
	float setVelY;
	bool collided = false;
	bool collidedPad = false;
	bool destroyed = false;
};