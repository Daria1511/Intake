#include "game.h"
#include "surface.h"
#include "template.h"
#include "Menu.h"
#include "Level.h"

 /*TO DO:
Create menu
Load the levels
Create brick levels
create collectables
points sistem*/


namespace Tmpl8
{
	Menu menu;
	Menu::Type menuType;
	bool inMenu;
	Level level;
	Level::Type levelType;
	

	void Game::Init()
	{
		inMenu = true;
		menuType = Menu::Type::MENU;
	}
	void Game::Shutdown()
	{
	}


	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------

	void Game::Tick(float deltaTime)
	{
		if (inMenu)
			menu.InitMenu(menuType, screen, mouse, inMenu, levelType);
		else
		{
			level.InitLevel(levelType, screen);
			level.GoMenu(mouse, inMenu, screen);
			if (inMenu) menuType = Menu::Type::MENU;
		}
	}
	
}