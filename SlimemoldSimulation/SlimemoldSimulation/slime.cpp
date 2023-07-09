#include "slime.h"

void slime::initialise(sf::Vector2f p, float a)
{
	pos = p;
	angle = a;
}

void slime::update(sf::Image& i)
{
	sf::Vector2u w = i.getSize();
	sf::Vector2f dir = sf::Vector2f(cos(angle), sin(angle));
	sf::Vector2f dirL = sf::Vector2f(cos(angle - virAngle), sin(angle - virAngle));
	sf::Vector2f dirR = sf::Vector2f(cos(angle + virAngle), sin(angle + virAngle));
	if ((i.getPixel(pos.x + dir.x, pos.y + dir.y).r >= i.getPixel(pos.x + dirL.x, pos.y + dirL.y).r) && (i.getPixel(pos.x + dir.x, pos.y + dir.y).r >= i.getPixel(pos.x + dirR.x, pos.y + dirR.y).r))
	{
		pos = sf::Vector2f(pos.x + dir.x, pos.y + dir.y );
	}
	else if (i.getPixel(pos.x + dirR.x, pos.y + dirR.y).r >= i.getPixel(pos.x + dirL.x, pos.y + dirL.y).r)
	{
		dirR = sf::Vector2f(cos(angle + turnAngle), sin(angle + turnAngle));
		pos = sf::Vector2f(pos.x + dirR.x, pos.y + dirR.y);
		angle += turnAngle;
	}
	else
	{
		dirL = sf::Vector2f(cos(angle - turnAngle), sin(angle - turnAngle));
		pos = sf::Vector2f(pos.x + dirL.x, pos.y + dirL.y);
		angle -= turnAngle;
	}
	
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
	i.setPixel(pos.x, pos.y, sf::Color::White);
}

sf::Vector2i slime::getpos()
{
	return sf::Vector2i(pos.x , pos.y );
}
