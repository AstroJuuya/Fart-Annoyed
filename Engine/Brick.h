#pragma once

#include "RectF.h"
#include "Ball.h"

class Brick
{
public:
	Brick(const RectF& rect);
	void DoBallCollision(Ball& ball);
	bool IsOverlappingWith(const RectF& other) const;
private:
	RectF brick;
	bool destroyed = false;
};