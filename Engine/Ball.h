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
	void Draw(Graphics& gfx) const;
	void DoWallCollision(const RectF& walls);
	RectF GetRect() const;
	Vec2 GetPosition() const;
	Vec2 GetVelocity() const;
	bool HasCollided() const;
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
	bool collided = false;
};