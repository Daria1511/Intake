#pragma once
#include "template.h"
#include "surface.h"

class Paddle
{
public:
	Paddle(Tmpl8::vec2& pos1) :
		pos(pos1),
		paddle(new Tmpl8::Surface("assets/PADDLE.png"), 1)
	{}

	void drawPaddle(Tmpl8::Surface* surface)
	{
		paddle.Draw(surface,pos.x,pos.y);
	}

	const float GetPositionX1() { return pos.x; } 
	const float GetPositionY1() { return pos.y; }
	const float GetPositionX2() { return pos.x + paddle.GetWidth(); }
	const float GetPositionY2() { return pos.y + paddle.GetHeight(); }

	//Paddle divided in 3 segments
	const float GetLeft() { return pos.x + paddle.GetWidth() / 3; }
	const float GetMiddle() { return pos.x + paddle.GetWidth() * static_cast<float>(2) / 3; }

	void restartPaddle(float px, float py);
	void movePaddle();
	

private:
	Tmpl8::vec2 pos;
	Tmpl8 ::Sprite paddle;
};