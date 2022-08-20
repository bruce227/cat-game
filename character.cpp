#include "character.h"
#include "2dGame.h"
#include "enemy.h"
#include <iostream>
void Character::initializeVar() //initializes variables for character
{
	this->movementSpeed = 10.f;
}

void Character::initializeTexture() //loads character texture from file then assigns it to sprite
{
	if (!texture.loadFromFile("C:\\Users\\bruce\\source\\repos\\2D Game\\2D Game\\assets\\cat_3.png"))
	{
		std::cout << "Unable to load texture." << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(0.1, 0.1)); //sets scale of sprite
	sprite.move(sf::Vector2f(350, 300)); //moved to random position on window, just testing
}



Character::Character(float x, float y)
{
	sprite.setPosition(x, y);
	initializeTexture();
	initializeVar();
}

Character::~Character()
{
}

void Character::newInput() //accepting inputs from keyboard for movement
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		sprite.move(0.f, -movementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		sprite.move(0.f, movementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sprite.move(-movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sprite.move(movementSpeed, 0.f);
	}
}

void Character::windowCollison(sf::RenderTarget* target) //sets window edges as bounds for sprite movement
{
	sf::FloatRect windowBounds = sprite.getGlobalBounds();
	if (windowBounds.left <= 0.f)
	{
		this->sprite.setPosition(0.f, windowBounds.top);
	}
	else if(windowBounds.left + windowBounds.width >= target->getSize().x)
	{
		this->sprite.setPosition(target->getSize().x - windowBounds.width, windowBounds.top);
	}

	if (windowBounds.top <= 0.f)
	{
		sprite.setPosition(windowBounds.left, 0.f);
	}
	else if (windowBounds.top + windowBounds.height >= target->getSize().y)
	{
		sprite.setPosition(windowBounds.left, target->getSize().y - windowBounds.height);
	}
}


void Character::update(sf::RenderTarget* target)
{
	this->windowCollison(target);
	this->newInput();
}

void Character::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}