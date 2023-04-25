#pragma once
#include "template.h"
#include "surface.h"
#include "Windows.h"
#include "SDL.h"
#include "Level.h"

class Menu
{
public:
	enum class Type
	{
		MENU,
		LEVELS,
		CONTROLS
	};

	void InitMenu(Menu::Type& menu, Tmpl8::Surface* screen, const Tmpl8::vec2& mouse, bool& inMenu,Level::Type level );

	Menu():
		menuBackground(new Tmpl8::Surface("assets/MenuBackground.png"), 1),
		levelsButton1(new Tmpl8::Surface("assets/Levels1.png"), 1),
		controlsButton1(new Tmpl8::Surface("assets/Controls1.png"), 1),
		exitButton1(new Tmpl8::Surface("assets/Exit1.png"), 1),
		levelsButton2(new Tmpl8::Surface("assets/Levels2.png"), 1),
		controlsButton2(new Tmpl8::Surface("assets/Controls2.png"), 1),
		exitButton2(new Tmpl8::Surface("assets/Exit2.png"), 1),
		button1A(new Tmpl8::Surface("assets/Button1A.png"), 1),
		button1B(new Tmpl8::Surface("assets/Button1B.png"), 1),
		button2A(new Tmpl8::Surface("assets/Button2A.png"), 1),
		button2B(new Tmpl8::Surface("assets/Button2B.png"), 1),
		button3A(new Tmpl8::Surface("assets/Button3A.png"), 1),
		button3B(new Tmpl8::Surface("assets/Button3B.png"), 1),
		homeButton1(new Tmpl8::Surface("assets/HomeButton1.png"), 1),
		homeButton2(new Tmpl8::Surface("assets/HomeButton2.png"), 1),
		controlsMenu(new Tmpl8::Surface("assets/ControlsMenu.png"), 1),
		levelsMenu(new Tmpl8::Surface("assets/LevelsMenu.png"), 1)
	{}



	void DrawMenu(Tmpl8::Surface* screen);
	void UpdateMenu(Tmpl8::Surface* screen, const Tmpl8::vec2& mouse, Type& menu);
	void DrawLevels(Tmpl8::Surface* screen);
	void UpdateLevels(Tmpl8::Surface* screen, const Tmpl8::vec2& mouse, Type& menu, bool& inMenu, Level::Type& level);
	void DrawControls(Tmpl8::Surface* screen);
	void UpdateControls(Tmpl8::Surface* screen, const Tmpl8::vec2& mouse, Type& menu);



private:
	Tmpl8::Sprite menuBackground;
	Tmpl8::Sprite controlsMenu;
	Tmpl8::Sprite levelsMenu;
	Tmpl8::Sprite levelsButton1;
	Tmpl8::Sprite controlsButton1;
	Tmpl8::Sprite exitButton1;
	Tmpl8::Sprite levelsButton2;
	Tmpl8::Sprite controlsButton2;
	Tmpl8::Sprite exitButton2;
	Tmpl8::Sprite button1A; 
	Tmpl8::Sprite button1B;
	Tmpl8::Sprite button2A;
	Tmpl8::Sprite button2B;
	Tmpl8::Sprite button3A;
	Tmpl8::Sprite button3B;
	Tmpl8::Sprite homeButton1;
	Tmpl8::Sprite homeButton2;
};