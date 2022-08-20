#pragma once
#include <iostream>
#include <vector>
#include "character.h"
#include "enemy.h"

class myGame
{
private:
	void initWind();
	Character character;  
	Enemy enemy;
	sf::RenderWindow* window;
	sf::Event event;

public:
	myGame();
	virtual ~myGame();
	bool run() const;
	void update();
	void render();
	void pollEvents();
};