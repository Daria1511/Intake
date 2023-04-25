#include "game.h"
#include "surface.h"
#include "template.h"
#include "windows.h"
#include "Paddle.h"


void Paddle::restartPaddle(float px, float py)
{
	pos.x = px;
	pos.y = py;
}

void Paddle::movePaddle()
{
	// Paddle movement and wall collision

	if (GetAsyncKeyState(0x41))
		if (pos.x <= 0)
			pos.x = 0;
		else
			pos.x-=2;

	if (GetAsyncKeyState(0x44))
		if (pos.x >= ScreenWidth - paddle.GetWidth())
			pos.x = ScreenWidth - paddle.GetWidth();
		else
			pos.x+=2;

}
