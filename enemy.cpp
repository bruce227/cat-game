#include "2dGame.h"
#include "character.h"
#include "enemy.h"

void Enemy::initializeVar() //initalizes variables for enemy
{
	float spawnTiming = 0.f;
	float spawnTimingMax = 1000.f;
	spawnTiming = spawnTimingMax;
	int maximumEnemies = 500;
}

void Enemy::initializeEnemy() //loads texture from file, then sets size and position
{
	if (!enemy_texture.loadFromFile("C:\\Users\\bruce\\source\\repos\\2D Game\\2D Game\\assets\\enemy.png"))
	{
		std::cout << "Unable to load texture." << std::endl;
	}
	enemy.setTexture(enemy_texture);
	enemy.setPosition(static_cast<float>(rand() & static_cast<int>(this->window.getSize().x - enemy.getGlobalBounds().top)), static_cast<float>(rand() & static_cast<int>(window.getSize().y - enemy.getGlobalBounds().left)));
	enemy.setScale(sf::Vector2f(0.2, 0.2));
	enemy_container.push_back(enemy); //adds enemy to vector

}


void Enemy::updateEnemy()
{	//spawn timing
	if (enemy_container.size() < maximumEnemies)
	{
		if (spawnTiming >= spawnTimingMax)
		{
			initializeEnemy();
			spawnTiming = 0.f;
		}
		else
		{
			spawnTiming += 1.f;
		}
	}

	for (auto &enemy : enemy_container) //for loop that moves enemy sprite across map
	{
		enemy.move(0.f, 5.f);
	}
	
	
}


void Enemy::render(sf::RenderTarget* target)
{
	initializeEnemy();
	initializeVar();
	updateEnemy();
	target->draw(this->enemy);
	for (auto& enemy : enemy_container)
	{	
		window.draw(enemy);
		
	}

}
