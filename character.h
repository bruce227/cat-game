#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Character
{
private:
	void initializeVar();
	float movementSpeed;

	sf::Texture texture;
	sf::Sprite sprite;
	void initializeTexture();
public:
	Character(float x = 0.f, float y = 0.f);
	virtual ~Character();
	void newInput();
	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
	void windowCollison(sf::RenderTarget* target);
};