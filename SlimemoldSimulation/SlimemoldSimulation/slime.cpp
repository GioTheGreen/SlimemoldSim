#include "slime.h"

void slime::initialise(sf::Vector2i p, float a)
{
	pos = p;
	angle = a;
}

void slime::update(sf::Vector2u w)
{
	sf::Vector2f dir = sf::Vector2f(cos(angle), sin(angle));
	pos = sf::Vector2i((pos.x + int(dir.x + 0.5f)), (pos.y + int(dir.y + 0.5f)));

	//if (pos.x < 0 || pos.x >= w.x || pos.y < 0 || pos.y >= w.y)
	//{
	//	pos.x = (w.x - 0.01, std::max(0, pos.x));
	//}
}

sf::Vector2i slime::getpos()
{
	return pos;
}
