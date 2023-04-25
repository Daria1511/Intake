#pragma once
#include "template.h"
#include "surface.h"
#include "Windows.h"
#include "SDL.h"
#include "Paddle.h"
#include "Ball.h"
#include "Level.h"



void Level::InitLevel(Type& level, Tmpl8::Surface* screen)
{
	switch (level)
	{
	case Type::FIRST:
		LoadLevel1(screen);
		break;
	case Type::SECOND:
		LoadLevel2(screen);
		break;
	case Type::THIRD:
		LoadLevel3(screen);
		break;
	default:
		break;
	}
}


void Level::Restart()
{
		paddle.restartPaddle(ScreenWidth / 2 - 60, ScreenHeight - ScreenHeight / 7);
}


void Level::Collision()
{

	if (ball.GetPositionY2() > paddle.GetPositionY1() && ball.GetPositionY1() < paddle.GetPositionY1() && ball.GetPositionY2() < paddle.GetPositionY2())
		if (ball.GetPositionX1() > paddle.GetPositionX1() && ball.GetPositionX1() < paddle.GetLeft()
			|| ball.GetPositionX2() > paddle.GetPositionX1() && ball.GetPositionX2() < paddle.GetLeft())
			ball.changeDirectionLeft();
		else if (ball.GetPositionX1() > paddle.GetMiddle() && ball.GetPositionX1() < paddle.GetPositionX2()
			|| ball.GetPositionX2() > paddle.GetMiddle() && ball.GetPositionX2() < paddle.GetPositionX2())
			ball.changeDirectionRight();
		else if (ball.GetPositionX1() >= paddle.GetLeft() && ball.GetPositionX1() <= paddle.GetMiddle()
			|| ball.GetPositionX2() <= paddle.GetLeft() && ball.GetPositionX2() >= paddle.GetMiddle())
			ball.changeDirectionMiddle();

}

void Level::checkCollision(Brick* brick) {
	// hit from above or below
	if (ball.GetPositionY1() <= brick->getY2() && ball.GetPositionY2() >= brick->getY2() ||
		ball.GetPositionY2() >= brick->getY1() && ball.GetPositionY1() <= brick->getY1() &&
		ball.GetPositionX1() >= brick->getX1() && ball.GetPositionX1() <= brick->getX2() ||
		ball.GetPositionX2() >= brick->getX1() && ball.GetPositionX2() <= brick->getX2()) {
		if (brick->getState() != 0 && brick->getState() != 3) {
			brick->setState(brick->getState()+1);
			Tmpl8::vec2 newDir = ball.getDir();
			newDir.y = -newDir.y;
			ball.setDir(newDir);

		}
	}
		//hit from left or right
	if (ball.GetPositionX2() > brick->getX1() && ball.GetPositionX1() < brick->getX1() ||
		ball.GetPositionX1() < brick->getX2() && ball.GetPositionX2() > brick->getX2() &&
		ball.GetPositionY1() >= brick->getY1() && ball.GetPositionY1() <= brick->getY2() ||
		ball.GetPositionY2() >= brick->getY1() && ball.GetPositionY2() <= brick->getY2()) {

		if (brick->getState() != 0 && brick->getState() != 3) {
			brick->setState(brick->getState() + 1);
			Tmpl8::vec2 newDir = ball.getDir();
			newDir.x = -newDir.x;
			ball.setDir(newDir);

		}

	}





}

void Level::GoMenu(const Tmpl8::vec2& mouse, bool& inMenu, Tmpl8::Surface* screen)
{
	bool mouseButtonPressed = GetAsyncKeyState(VK_LBUTTON);
	bool collidesMenuButton = (mouse.y >= 4 && mouse.y <= 54) && (mouse.x >= 4 && mouse.x <= 54);
	if (collidesMenuButton)
	{
		menuButton2.Draw(screen, 4, 4);
		if (mouseButtonPressed)
		{
			inMenu = true;
			Restart();
			ball.BallRespawn();
		}
	}
}

void Level::LoadLevelDefault(Tmpl8::Surface* screen)
{
	background.Draw(screen, 0, 0);
	menuButton.Draw(screen, 4, 4);
	ball.drawBall(screen);
	ball.moveBall();
	paddle.drawPaddle(screen);
	paddle.movePaddle();
	Collision();
	if (ball.GetPositionY2() >= ScreenHeight)
	{
		Restart();
	}
}

void Level::LoadLevel1(Tmpl8::Surface* screen)
{
	LoadLevelDefault(screen);
	if (!initialised) {
		for (int i = 0; i < 24; i++) {
			pos.x = 40 + w * 95;
			pos.y = 100 + h * 46;
			bricks[i] = new Brick(pos, 1);
			w++;
			if (w > 5) {
				h++;
				w = 0;
			}
			bricks[i]->DrawBrick(screen);

		}
		h = 0;
		initialised = true;
	}
	else {
		for (auto i :bricks) {
			i->DrawBrick(screen);
			checkCollision(i);
		}
	}
	
	
	
	
}

void Level::LoadLevel2(Tmpl8::Surface* screen)
{
	LoadLevelDefault(screen);
}

void Level::LoadLevel3(Tmpl8::Surface* screen)
{
	LoadLevelDefault(screen);
}