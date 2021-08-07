/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "FrameTimer.h"
#include "Sound.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Keyboard kbd;

	RectF walls;
	FrameTimer ft;
	static constexpr float simulationStep = 0.0025f;

	Sound paddleHit;
	Sound brickHit;
	static constexpr float volume = 0.2f;

	Ball ball;

	static constexpr int rows = 4;
	static constexpr int cols = 12;
	static constexpr float width = 50.0f;
	static constexpr float height = 25.0f;
	static constexpr float border = 0.5f;
	static constexpr Color brick_color[rows]{ Colors::Cyan, Colors::Green, Colors::Yellow, Colors::Red };
	Brick bricks[rows][cols];

	Paddle paddle;
	static constexpr float paddle_width = 40.0f;
	static constexpr float paddle_height = 10.0f;
	static constexpr float paddle_speed = 400.0f;
	static constexpr Color paddle_color = Colors::White;
	static constexpr float paddle_wingspan = 10.0f;
	static constexpr Color paddle_wing_color = Colors::Red;
	/********************************/
};