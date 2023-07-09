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
	if ((i.getPixel(int(pos.x + dir.x), int(pos.y + dir.y)).r >= i.getPixel(int(pos.x + dirL.x), int(pos.y + dirL.y)).r)
		&& (i.getPixel(int(pos.x + dir.x), int(pos.y + dir.y)).r >= i.getPixel(int(pos.x + dirR.x), int(pos.y + dirR.y)).r))
	{
		pos = sf::Vector2f(pos.x + dir.x, pos.y + dir.y );
	}
	else if ((i.getPixel(int(pos.x + dirR.x), int(pos.y + dirR.y)).r >= i.getPixel(int(pos.x + dirL.x), int(pos.y + dirL.y)).r)
		&& ((i.getPixel(int(pos.x + dirR.x), int(pos.y + dirR.y)).r >= mincol)))
	{
		float per = (i.getPixel(int(pos.x + dirR.x), int(pos.y + dirR.y)).r - i.getPixel(int(pos.x + dir.x), int(pos.y + dir.y)).r) / 255;
		dirR = sf::Vector2f(cos(angle + turnAngle), sin(angle + turnAngle))*per;
		pos = sf::Vector2f(pos.x + dirR.x, pos.y + dirR.y);
		angle += turnAngle;
	}
	else if (i.getPixel(pos.x + dirL.x, pos.y + dirL.y).r >= mincol)
	{
		float per = (i.getPixel(int(pos.x + dirL.x), int(pos.y + dir.y)).r - i.getPixel(int(pos.x + dir.x), int(pos.y + dir.y)).r) / 255;
		dirL = sf::Vector2f(cos(angle - turnAngle), sin(angle - turnAngle)) *per;
		pos = sf::Vector2f(pos.x + dirL.x, pos.y + dirL.y);
		angle -= turnAngle;
	}
	else
	{
		pos = sf::Vector2f(pos.x + dir.x, pos.y + dir.y);
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
		angle = rand() % (2 * 31415) /10000;
		wall = 0;
	}
	i.setPixel(pos.x, pos.y, sf::Color::White);
}

sf::Vector2i slime::getpos()
{
	return sf::Vector2i(pos.x , pos.y );
}
