#include <iostream>
#include "2dGame.h"
#include "character.h"
#include <ctime>

int main()
{
	std::srand(time(NULL));
	myGame game;

	while (game.run())
	{
		game.update();
		game.render();
	}
}