#include <iostream>

#include "2dGame.h"
#include "character.h"
#include "enemy.h"

void myGame::initWind() //initalizes window and gives window size, sets framerate limit
{
	window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "2D Game");
	this->window->setFramerateLimit(60);
}


myGame::myGame()
{
	initWind();
}


myGame::~myGame()
{
	delete window;
}

bool myGame::run() const
{
	return this->window->isOpen();
}

void myGame::pollEvents()
{

	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{

		case sf::Event::Closed:
			this->window->close(); //closes window if we click close button
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) //closes window if we hit esc key
				this->window->close();
		default:
			break;
		
		}
	}
}



void myGame::update() //updates events
{
	pollEvents();
	character.update(window);
	enemy.updateEnemy();
}

void myGame::render() //clears frame then renders the game object then dispalys new frame
{
	this->window->clear(sf::Color(255, 255, 255, 255));
	character.render(window);
	enemy.render(window);
	this->window->display();
}

