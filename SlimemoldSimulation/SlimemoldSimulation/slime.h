#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <cmath>

class slime
{
private:
	sf::Vector2f pos{ 0, 0 };
	float angle{ 0 };
public:
	void initialise(sf::Vector2f p, float a);
	void update(sf::Vector2u w);
	sf::Vector2i getpos();
};

