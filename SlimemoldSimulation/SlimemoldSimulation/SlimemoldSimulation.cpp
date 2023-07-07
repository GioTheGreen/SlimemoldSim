// SlimemoldSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "slime.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1800, 900), "Slimemold Sim");
	sf::Event e;

    std::vector<slime> slimes;
    for (size_t i = 0; i < 10; i++)
    {
        slime s;
        s.initialise(sf::Vector2i(rand() % 1800, rand() % 900), rand() % 360);
        slimes.push_back(s);
    }
    sf::Image image;
    sf::Texture tex;
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(1800, 900));
    rect.setPosition(0, 0);
    image.create(1800,900,sf::Color::Black);

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
        tex.loadFromImage(image);
        rect.setTexture(&tex);
        window.draw(rect);
        window.display();
    }
}

