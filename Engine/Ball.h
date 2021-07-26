#pragma once

#include "Graphics.h"
#include "RectF.h"
#include "SpriteCodex.h"

class Ball
{
public:
	Ball(Vec2 pos, Vec2 vel);
	void ReboundX();
	void ReboundY();
	void Draw(Graphics& gfx) const;
	bool HasCollided() const;
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
	bool collided = false;
};