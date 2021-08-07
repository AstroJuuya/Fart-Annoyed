#include "Paddle.h"

Paddle::Paddle( const RectF& rect, const Color& color )
	:
	paddle( rect ),
	paddle_color( color )
{
}

Paddle::Paddle( const RectF& rect, const float speed, const Color& color )
	:
	paddle( rect ),
	vel( speed ),
	paddle_color( color )
{
}

Paddle::Paddle( const RectF& rect, const Color& paddle_color, const float wings_width, const Color& wings_color )
	:
	paddle( rect ),
	paddle_color( paddle_color ),
	wingsW( wings_width ),
	wingsC( wings_color )
{
}

Paddle::Paddle( const RectF& rect, const float paddle_speed, const Color& paddle_color, const float wings_width, const Color& wings_color )
	:
	paddle( rect ),
	vel( paddle_speed ),
	paddle_color( paddle_color ),
	wingsW( wings_width ),
	wingsC( wings_color )
{
}

void Paddle::DoBallCollision( Ball& ball ) const
{
	if ( paddle.IsOverlappingWith( ball.GetRect() ) )
	{
		RectF b = ball.GetRect();
		if (	( abs( b.right - paddle.left ) <= abs( b.bottom - paddle.top ) && abs( b.right - paddle.left ) <= abs( b.top - paddle.bottom ) )
			||	( abs( b.left - paddle.right ) <= abs( b.bottom - paddle.top ) && abs( b.left - paddle.right ) <= abs( b.top - paddle.bottom ) ) )
		{
			ball.ReboundPadX(paddle);
		}
		if (	( abs( b.bottom - paddle.top ) <= abs( b.right - paddle.left ) && abs( b.bottom - paddle.top ) <= abs( b.left - paddle.right ) )
			||	( abs( b.top - paddle.bottom ) <= abs( b.right - paddle.left ) && abs( b.top - paddle.bottom ) <= abs( b.left - paddle.right ) ) )
		{
			ball.ReboundPadY(paddle);
		}
	}
}

void Paddle::DoWallCollision(const RectF& walls)
{
	if (paddle.left < walls.left)
	{
		paddle.right += walls.left - paddle.left;
		paddle.left += walls.left - paddle.left;
	}
	else if (paddle.right >= walls.right)
	{
		paddle.left += walls.right - paddle.right;
		paddle.right += walls.right - paddle.right;
	}
}

void Paddle::Update( const MainWindow& wnd, const float dt )
{
	if ( wnd.kbd.KeyIsPressed( VK_LEFT ) )
	{
		paddle.left -= vel * dt;
		paddle.right -= vel * dt;
	}
	if ( wnd.kbd.KeyIsPressed( VK_RIGHT ))
	{
		paddle.left += vel * dt;
		paddle.right += vel * dt;
	}
}

void Paddle::Draw( Graphics& gfx ) const
{
	RectF( 
		paddle.left + wingsW, paddle.top, 
		paddle.right - wingsW, paddle.bottom ).Draw( gfx, paddle_color );

	if ( int( wingsW * 2 ) != 0 )
	{
		RectF( 
			paddle.left, paddle.top,
			paddle.left + wingsW, paddle.bottom ).Draw( gfx, wingsC );
		RectF(
			paddle.right - wingsW, paddle.top,
			paddle.right, paddle.bottom ).Draw( gfx, wingsC );
	}
}
