#pragma once

#include "template.h"
#include "surface.h"

class Ball
{
public:
	Ball(Tmpl8::vec2& pos1) :
		pos(pos1),
		ball(new Tmpl8::Surface("assets/TennisBall.png"), 1),
		dir(0,- 1.5),
		ballActive(0)
	{}

	void drawBall(Tmpl8::Surface* surface)
	{
		ball.Draw(surface, pos.x, pos.y);
	}

	const float GetPositionX1() { return pos.x; }
	const float GetPositionY1() { return pos.y; }
	const float GetPositionX2() { return pos.x + ball.GetWidth(); }
	const float GetPositionY2() { return pos.y + ball.GetHeight(); }
	const float GetDirectionX() { return dir.x; }
	const float GetDirectionY() { return dir.y; }
	const float GetCenterX() { return (pos.x + ball.GetWidth()) / 2; }
	const float GetCenterY() { return (pos.y + ball.GetHeight()) / 2; }

	void moveBall();
	void changeDirectionLeft();
	void changeDirectionRight();
	void changeDirectionMiddle();
	void collideWall();
	void BallRespawn();


	Tmpl8::vec2 getDir() {
		return this->dir;
	}

	void setDir(Tmpl8::vec2 dir) {
		this->dir = dir;
	}

private:
	Tmpl8::vec2 pos;
	Tmpl8::Sprite ball;
	Tmpl8::vec2 dir;
	int ballActive;
};