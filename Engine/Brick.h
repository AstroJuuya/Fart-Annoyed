#pragma once

#include "RectF.h"
#include "Ball.h"

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
	bool destroyed = false;
	float brdr;
};