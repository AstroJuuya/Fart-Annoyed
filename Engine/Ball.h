#pragma once

#include "Graphics.h"
#include "RectF.h"
#include "SpriteCodex.h"
#include "FrameTimer.h"

class Ball
{
public:
	Ball(Vec2 pos, Vec2 vel);
	void Update(const float delta_time);
	void ReboundX();
	void ReboundY();
	void Draw(Graphics& gfx) const;
	void DoWallCollision(RectF walls);
	RectF GetRect() const;
	bool HasCollided() const;
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
	bool collided = false;
};