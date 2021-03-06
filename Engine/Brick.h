#pragma once

#include "RectF.h"
#include "Ball.h"
#include <math.h>

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect);
	void SetBorder(const float border);
	void DoBallCollision(Ball& ball);
	void Draw(Graphics& gfx, Color color) const;
	void DrawReducedBorder(Graphics& gfx, Color color) const;
	bool IsDestroyed() const;
private:
	RectF brick;
	Vec2 topLeft;
	Vec2 topRight;
	Vec2 bottomLeft;
	Vec2 bottomRight;
	bool destroyed = false;
	float brdr;
};