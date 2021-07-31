#pragma once

#include "Graphics.h"
#include "MainWindow.h"
#include "RectF.h"
#include "Ball.h"

class Paddle
{
public:
	Paddle( const RectF& rect, const Color& color );
	Paddle( const RectF& rect, const float speed, const Color& color );
	Paddle( const RectF& rect, const Color& paddle_color, const float wings_width, const Color& wings_color );
	Paddle( const RectF& rect, const float paddle_speed, const Color& paddle_color, const float wings_width, const Color& wings_color );
	void DoBallCollision(Ball& ball) const;
	void DoWallCollision(const RectF& walls);
	void Update( const MainWindow& wnd,const float dt );
	void Draw( Graphics& gfx ) const;
private:
	RectF paddle;
	float vel;
	Color paddle_color;
	float wingsW = 0.0f;
	Color wingsC;
};

