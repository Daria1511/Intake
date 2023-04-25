#pragma once
#include "template.h"
#include "surface.h"
#include "Windows.h"
#include "SDL.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"


class Level
{
public:

	enum class Type
	{
		FIRST,
		SECOND,
		THIRD
	};

	void InitLevel(Type& level, Tmpl8::Surface* screen);



	Level():
		paddle(Tmpl8::vec2(ScreenWidth / 2 - 60, ScreenHeight - ScreenHeight / 7)),
		ball(Tmpl8::vec2(ScreenWidth / 2 - 16, ScreenHeight - ScreenHeight / 7 - 32)),
		background(new Tmpl8::Surface("assets/BackAlley.png"), 1),
		menuButton(new Tmpl8::Surface("assets/HomeButton.png"),1),
		menuButton2(new Tmpl8::Surface("assets/HomeButton3.png"), 1)
	{
	};

	void SelectLevel(int levelID, Tmpl8::Surface* screen);
	void checkCollision(Brick* brick);

	//Paddle Repositioning
	void Restart();
	//Paddle - Ball Collision
	void Collision();
	//Go back to menu
	void GoMenu(const Tmpl8::vec2& mouse, bool& inMenu, Tmpl8::Surface* screen);


private:
	Paddle paddle;
	Ball ball;
	Brick* bricks[25];
	Tmpl8::Sprite background;
	Tmpl8::Sprite menuButton;
	Tmpl8::Sprite menuButton2;
	Tmpl8::vec2 pos;
	int h = 0;
	int w = 0;
	bool initialised = false;
	void LoadLevelDefault(Tmpl8::Surface* screen);
	void LoadLevel1(Tmpl8::Surface* screen);
	void LoadLevel2(Tmpl8::Surface* screen);
	void LoadLevel3(Tmpl8::Surface* screen);
};