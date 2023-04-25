#pragma once
#include "template.h"
#include "surface.h"

class Brick
{
	
public:

	enum class Type
	{
		NOTHING,
		HIT0,
		HIT1,
		HIT2
	};

	
	void DrawBrick(Tmpl8::Surface* surface)
	{
		switch (state) {
		case 0: brick0.Draw(surface, hitbox.x, hitbox.y); break;
		case 1: brick1.Draw(surface, hitbox.x, hitbox.y); break;
		case 2: brick2.Draw(surface, hitbox.x, hitbox.y); break;
		default: break; // we don't draw here
		}
		

	}

	

	
	Brick(Tmpl8::vec2 hitbox, int state):
		brick1(new Tmpl8::Surface("assets/Brick1.png"),1),
		brick2(new Tmpl8::Surface("assets/Brick2.png"),1),
		brick0(new Tmpl8::Surface("assets/Nokia.png"),1)
	{
		this->state = state;
		this->hitbox = hitbox;
	}

	Brick():
		brick1(new Tmpl8::Surface("assets/Brick1.png"), 1),
		brick2(new Tmpl8::Surface("assets/Brick2.png"), 1),
		brick0(new Tmpl8::Surface("assets/Nokia.png"), 1) {

	}

	Tmpl8::vec2 getHitBox() {
		return this->hitbox;
	}
	
	int getState() {
		return state;
	}

	void setHitBox(Tmpl8::vec2 hitbox) {
		this->hitbox = hitbox;
	}

	void setState(int state) {
		this->state = state;
	}

	int getX1() {
		return this->hitbox.x;
	}
	int getX2() {
		return this->hitbox.x + brick0.GetWidth();
	}
	int getY1() {
		return this->hitbox.y;
	}
	int getY2() {
		return this->hitbox.y + brick0.GetHeight();
	}


private:
	Tmpl8::Sprite brick0;
	Tmpl8::Sprite brick1;
	Tmpl8::Sprite brick2;
	Tmpl8::vec2 hitbox;
	int state = 3;
};