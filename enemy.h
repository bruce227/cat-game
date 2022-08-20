#pragma once

#include "character.h"
#include <ctime>

class Enemy
{
private:
	std::vector<sf::Sprite> enemy_container;
	sf::Texture enemy_texture;
	sf::Sprite enemy;
	void initializeVar();
	sf::RenderWindow window;

	//Game logic
	float spawnTiming;
	float spawnTimingMax;
	int maximumEnemies;


public:

	void render(sf::RenderTarget* target);
	void updateEnemy();
	void initializeEnemy();
};
