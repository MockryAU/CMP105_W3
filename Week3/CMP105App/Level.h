#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

	void collision(sf::CircleShape&);
	void collision2(sf::CircleShape&);

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::CircleShape circle_1;
	sf::CircleShape circle_2;
	sf::CircleShape circle_3;
	float speed;
	float speed2;
	sf::Vector2f velocity;
};