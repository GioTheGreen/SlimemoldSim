#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <cmath>

class slime
{
private:
	sf::Vector2f pos{ 0, 0 };
	sf::Image map;
	float angle{ 0 };
	float virAngle{ 30 };
	float turnAngle{ 0.5f };
public:
	void initialise(sf::Vector2f p, float a);
	void update(sf::Image &i);
	sf::Vector2i getpos();
};

