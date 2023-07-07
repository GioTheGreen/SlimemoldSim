// SlimemoldSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "slime.h"

int main()
{
    unsigned int ww{ 300 }, wh{300};
	sf::RenderWindow window(sf::VideoMode(ww, wh), "Slimemold Sim");
	sf::Event e;

    std::vector<slime> slimes;
    for (size_t i = 0; i < 200; i++)
    {
        slime s;
        s.initialise(sf::Vector2f(rand() % ww, rand() % wh), rand() % 360);
        slimes.push_back(s);
    }
    sf::Image image;
    sf::Texture tex;
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(ww, wh));
    rect.setPosition(0, 0);
    image.create(ww,wh,sf::Color::Black);

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(0, 0, 0, 255));
        for (size_t i = 0; i < slimes.size(); i++)
        {
            slimes[i].update(window.getSize());
            image.setPixel(slimes[i].getpos().x, slimes[i].getpos().y, sf::Color::White);
        }
        for (int i = 1; i < image.getSize().x-1; i++)
        {
            for (size_t j = 1; j < image.getSize().y-1; j++)
            {
                int blend = (image.getPixel(i - 1, j - 1).r + image.getPixel(i - 1, j).r + image.getPixel(i - 1, j + 1).r + image.getPixel(i , j - 1).r + (image.getPixel(i, j).r * 50) + image.getPixel(i, j +1).r + image.getPixel(i + 1, j - 1).r + image.getPixel(i + 1, j).r + image.getPixel(i + 1, j + 1).r ) / 58;
                image.setPixel(i, j, sf::Color(blend, blend, blend));
            }
        }
        for (int i = 0; i < image.getSize().x; i++)
        {
            for (size_t j = 0; j < image.getSize().y; j++)
            {
                sf::Color c = image.getPixel(i, j);
                if (c != sf::Color(0, 0, 0))
                {
                    image.setPixel(i, j, sf::Color(c.r - 0.1, c.g - 0.1, c.b - 0.1));
                }
            }
        }
        tex.loadFromImage(image);
        rect.setTexture(&tex);
        window.draw(rect);
        window.display();
    }
}

