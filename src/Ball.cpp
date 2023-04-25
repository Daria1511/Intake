#include "game.h"
#include "surface.h"
#include "template.h"
#include "windows.h"
#include "Ball.h"

void Ball::BallRespawn()
{
		pos.x = ScreenWidth / 2 - 16;
		pos.y = ScreenHeight - ScreenHeight / 7 - 32;
		dir.x = 0; dir.y = -1.5;
		ballActive = 0;
}

void Ball::moveBall()
{
	//Collision with the ground (Ball Respawn)
	if (pos.y >= ScreenHeight - ball.GetHeight())
	{
		BallRespawn();
	}

	//Befor ball activation movement
	if (ballActive == 0)
	{
		if (GetAsyncKeyState(0x41))
			if (pos.x <= 0)
				pos.x = 0;
			else
				pos.x -= 2;

		if (GetAsyncKeyState(0x44))
			if (pos.x >= ScreenWidth - ball.GetWidth())
				pos.x = ScreenWidth - ball.GetWidth();
			else
				pos.x += 2;
	}

	//Ball activation
	if (GetAsyncKeyState(0x20))
		ballActive = 1;

	//Default ball movement + collision with walls
	if (ballActive == 1)
	{
		pos.y += dir.y;
		pos.x += dir.x;
		collideWall();
	}
}


void Ball::changeDirectionLeft()
{
	dir.x = -1;
	dir.y = -1.5;
}

void Ball::changeDirectionRight()
{
	dir.x = 1;
	dir.y = -1.5;
}

void Ball::changeDirectionMiddle()
{
	dir.x = 0;
	dir.y = -1.5;
}



void Ball::collideWall()
{
	//Wall collision

	if (pos.y <= 58)
		dir.y = -dir.y;


	if (pos.x <= 0)
		dir.x = -dir.x;

	if (pos.x >= ScreenWidth - ball.GetWidth())
		dir.x = -dir.x;

}

