#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	circle_1.setRadius(30);
	circle_1.setPosition(100, 100);
	circle_1.setFillColor(sf::Color::Red);

	circle_2.setRadius(30);
	circle_2.setPosition(200, 200);
	circle_2.setFillColor(sf::Color::Red);

	circle_3.setRadius(30);
	circle_3.setPosition(300, 300);
	circle_3.setFillColor(sf::Color::Red);

	speed = 200.f;
	speed2 = 200.f;
	velocity = (100, -100);
}

Level::~Level()
{
	
}

// handle user input
void Level::handleInput(float dt)
{
	//move up
	if (input->isKeyDown(sf::Keyboard::W))
	{
		circle_2.move(0, -speed2 * dt);
	}
	//move down
	if (input->isKeyDown(sf::Keyboard::S))
	{
		circle_2.move(0, speed2 * dt);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		circle_2.move(-speed2 * dt,0);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		circle_2.move(speed2 * dt,0);
	}
}

void Level::collision(sf::CircleShape &circle)
{
	if (circle.getPosition().x + (2 * circle.getRadius()) > window->getSize().x)
	{
		circle.setPosition(window->getSize().x - (2* circle.getRadius()), circle.getPosition().y);
		speed = -speed;
	}
	if (circle.getPosition().x < 0)
	{
		circle.setPosition(0 , circle.getPosition().y);
		speed = -speed;
	}

	if (circle.getPosition().y + (2 * circle.getRadius()) > window->getSize().y)
	{
		circle.setPosition(circle.getPosition().x , window->getSize().x);
		speed = -speed;
	}
	if (circle.getPosition().y < 0)
	{
		circle.setPosition(circle.getPosition().x ,0);
		speed = -speed;
	}

}

void Level::collision2(sf::CircleShape& circle)
{
	if (circle.getPosition().x + (2 * circle.getRadius()) > window->getSize().x)
	{
		circle.setPosition(window->getSize().x - (2 * circle.getRadius()), circle.getPosition().y);
		speed = -speed;
	}
	if (circle.getPosition().x < 0)
	{
		circle.setPosition(0, circle.getPosition().y);
		speed = -speed;
	}

	if (circle.getPosition().y + (2 * circle.getRadius()) > window->getSize().y)
	{
		circle.setPosition(circle.getPosition().x, window->getSize().x);
		speed = -speed;
	}
	if (circle.getPosition().y < 0)
	{
		circle.setPosition(circle.getPosition().x, 0);
		speed = -speed;
	}
// Update game objects
void Level::update(float dt)
{
	circle_1.move(speed * dt, 0);
	collision(circle_1);
	collision(circle_2);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle_1);
	window->draw(circle_2);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}