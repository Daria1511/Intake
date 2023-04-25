#include "game.h"
#include "surface.h"
#include "template.h"
#include "windows.h"
#include "Menu.h"
#include "Level.h"

void Menu::InitMenu(Menu::Type& menu, Tmpl8::Surface* screen, const Tmpl8::vec2& mouse, bool& inMenu, Level::Type level)
{
	switch (menu)
	{
	case Type::MENU:
		UpdateMenu(screen, mouse, menu);
		break;
	case Type::LEVELS:
		UpdateLevels(screen, mouse, menu, inMenu, level);
		break;
	case Type::CONTROLS:
		UpdateControls(screen, mouse, menu);
		break;
	default:
		break;
	}

}


void Menu::DrawMenu(Tmpl8::Surface* screen)
{
	menuBackground.Draw(screen, 0, 0);
	levelsButton1.Draw(screen, 95, 300);
	controlsButton1.Draw(screen, 95, 400);
	exitButton1.Draw(screen, 95, 500);
}

void Menu::UpdateMenu(Tmpl8::Surface* screen, const Tmpl8::vec2& mouse, Type& menu)
{
	DrawMenu(screen);
	bool mouseButtonPressed = GetAsyncKeyState(VK_LBUTTON);
	bool collidesLevelsButton = (mouse.y>=300 && mouse.y<=388) && (mouse.x>=95 && mouse.x<=559);
	if (collidesLevelsButton)
	{
		levelsButton2.Draw(screen, 95, 300);
		if (mouseButtonPressed)
			menu = Menu::Type::LEVELS;
	}

	bool collidesControlsButton = (mouse.y >= 400 && mouse.y <= 488) && (mouse.x >= 95 && mouse.x <= 559);
	if (collidesControlsButton)
	{
		controlsButton2.Draw(screen, 95, 400);
		if (mouseButtonPressed)
			menu = Menu::Type::CONTROLS;
	}

	bool collidesExitButton = (mouse.y >= 500 && mouse.y <= 588) && (mouse.x >= 95 && mouse.x <= 559);
	if (collidesExitButton)
	{
		exitButton2.Draw(screen, 95, 500);
		if (mouseButtonPressed)
		{
			SDL_Event e{};
			e.type = SDL_QUIT;
			SDL_PushEvent(&e);
		}
	}

}


void Menu::DrawLevels(Tmpl8::Surface* screen)
{
	levelsMenu.Draw(screen, 0, 0);
	button1A.Draw(screen, 50, 200);
	button2A.Draw(screen, ScreenWidth / 2 - 44, 200);
	button3A.Draw(screen, 500, 200);
	homeButton1.Draw(screen, ScreenWidth / 2 - 50, ScreenHeight * 3 / 4);
}

void Menu::UpdateLevels(Tmpl8::Surface* screen, const Tmpl8::vec2& mouse, Type& menu, bool& inMenu, Level::Type& level)
{
	DrawLevels(screen);
	bool mouseButtonPressed = GetAsyncKeyState(VK_LBUTTON);
	bool collidesButton1 = (mouse.y >= 200 && mouse.y <= 288) && (mouse.x >= 50 && mouse.x <= 138);
	if (collidesButton1)
	{
		button1B.Draw(screen, 50, 200);
		if (mouseButtonPressed)
		{
			level = Level::Type::FIRST;
			inMenu = false;
		}
	}

	bool collidesButton2 = (mouse.y >= 200 && mouse.y <= 288) && (mouse.x >= ScreenWidth / 2 - 44 && mouse.x <= ScreenWidth / 2 + 44);
	if (collidesButton2)
	{
		button2B.Draw(screen, ScreenWidth / 2 - 44, 200);
		if (mouseButtonPressed)
		{
			level = Level::Type::SECOND;
			inMenu = false;
		}
	}

	bool collidesButton3 = (mouse.y >= 200 && mouse.y <= 288) && (mouse.x >= 500 && mouse.x <= 588);
	if (collidesButton3)
	{
		button3B.Draw(screen, 500, 200);
		if (mouseButtonPressed)
		{
			level = Level::Type::THIRD;
			inMenu = false;
		}
	}

	bool collidesHomeButton = (mouse.y >= static_cast<float>(ScreenHeight * 3) / 4 && mouse.y <= ScreenHeight * 3 / 4 + 100) && (mouse.x >= ScreenWidth / 2 - 50 && mouse.x <= ScreenWidth / 2 + 50);
	if (collidesHomeButton)
	{
		homeButton2.Draw(screen, ScreenWidth / 2 - 50, ScreenHeight * 3 / 4);
		if (mouseButtonPressed)
			menu = Menu::Type::MENU;
	}
}


void Menu::DrawControls(Tmpl8::Surface* screen)
{
	controlsMenu.Draw(screen, 0, 0);
	homeButton1.Draw(screen, ScreenWidth / 2 - 50, ScreenHeight * 3 / 4);
}

void Menu::UpdateControls(Tmpl8::Surface* screen, const Tmpl8::vec2& mouse, Type& menu)
{
	DrawControls(screen);
	bool mouseButtonPressed = GetAsyncKeyState(VK_LBUTTON);
	bool collidesHomeButton = (mouse.y >= static_cast<float>(ScreenHeight * 3) / 4 && mouse.y <= ScreenHeight * 3 / 4 + 100) && (mouse.x >= ScreenWidth / 2 - 50 && mouse.x <= ScreenWidth / 2 + 50);
	if (collidesHomeButton)
	{
		homeButton2.Draw(screen, ScreenWidth / 2 - 50, ScreenHeight * 3 / 4);
		if (mouseButtonPressed)
			menu = Menu::Type::MENU;
	}
}
