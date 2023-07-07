#include "slime.h"

void slime::initialise(sf::Vector2f p, float a)
{
	pos = p;
	angle = a;
}

void slime::update(sf::Vector2u w)
{
	sf::Vector2f dir = sf::Vector2f(cos(angle), sin(angle));
	pos = sf::Vector2f(pos.x + dir.x, pos.y + dir.y );
	bool wall{ 0 };

	if (pos.x < 0)
	{
		pos.x = 0;
		wall = 1;
	}
	else if (pos.x >= w.x)
	{
		pos.x = (w.x - 1);
		wall = 1;
	}
	if (pos.y < 0)
	{
		pos.y = 0;
		wall = 1;
	}
	else if (pos.y >= w.y)
	{
		pos.y = (w.y - 1);
		wall = 1;
	}
	if (wall)
	{
		angle = rand() % 360;
		wall = 0;
	}
	
}

sf::Vector2i slime::getpos()
{
	return sf::Vector2i(pos.x , pos.y );
}
