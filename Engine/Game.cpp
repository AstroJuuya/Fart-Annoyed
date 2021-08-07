/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball( Vec2( 200.0f, 400.0f ), Vec2( 400.0f, -400.0f ) ),
	bricks(),
	paddle( RectF().fromCenter( Vec2( 400.0f, 500.0f ), paddle_width, paddle_height ), paddle_speed, paddle_color, paddle_wingspan, paddle_wing_color ),
	walls( 0, 0, gfx.ScreenWidth, gfx.ScreenHeight ),
	brickHit( L"Sounds\\arkbrick.wav" ),
	paddleHit( L"Sounds\\arkpad.wav" ),
	titleMusic( L"Sounds\\ready.wav" ),
	gameoverSound( L"Sounds\\fart.wav" )
{
	const Vec2 bricks_origin( 100.0f, 50.0f );
	for ( int y = 0; y < rows; y++ )
	{
		for ( int x = 0; x < cols; x++ )
		{
			bricks[y][x] = RectF( bricks_origin + Vec2( width * x, height * y ), width, height );
			bricks[y][x].SetBorder( border );
		}
	}

	titleMusic.Play(1.0f, volume);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	float dtRemaining = dt;

	if ( title && wnd.kbd.KeyIsPressed(VK_RETURN) )
	{
		title = false;
	}

	while ( dtRemaining > 0.0f && !gameover && !title )
	{
		const float step = dtRemaining > simulationStep ? simulationStep : dtRemaining;
		dtRemaining -= simulationStep;

		paddle.Update( wnd, step );
		paddle.DoWallCollision( walls );

		ball.Update(step);
		paddle.DoBallCollision(ball);

		ball.DoWallCollision(walls);
		if( ball.IsDestroyed() )
		{
			gameover = true;
			gameoverSound.Play(1.0f, volume);
		}

		if (ball.HasCollided())
		{
			paddleHit.Play( 1.0f, volume );
		}

		for ( int y = 0; y < rows; y++ )
		{
			for ( int x = 0; x < cols; x++ )
			{
				if ( !ball.HasCollided() )
				{
					bricks[y][x].DoBallCollision( ball );

					if ( bricks[y][x].IsDestroyed() && ball.HasCollided() )
					{
						brickHit.Play( 1.0f, volume );
					}
				}
			}
		}
	}
}

void Game::ComposeFrame()
{
	if( !title )
	{
		for ( int y = 0; y < rows; y++ )
		{
			for ( int x = 0; x < cols; x++ )
			{
				if ( !bricks[y][x].IsDestroyed() )
				{
					bricks[y][x].DrawReducedBorder( gfx, brick_color[y] );
				}
			}
		}

		ball.Draw( gfx );
		paddle.Draw( gfx );

		if ( gameover )
		{
			SpriteCodex::DrawGameOver( Vec2( gfx.ScreenWidth / 2, gfx.ScreenHeight / 2 ), gfx );
		}
	}
	else
	{
		SpriteCodex::DrawTitle( Vec2( gfx.ScreenWidth / 2, gfx.ScreenHeight / 2 ), gfx );
	}
}
