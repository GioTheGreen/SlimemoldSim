// SlimemoldSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "slime.h"

int main()
{
    unsigned int ww{ 500 }, wh{500};
	sf::RenderWindow window(sf::VideoMode(ww, wh), "sussy stuff");//Slimemold Sim
	sf::Event e;

    std::vector<slime> slimes;
    for (size_t i = 0; i < 10000; i++)
    {
        slime s;
        s.initialise(sf::Vector2f(ww/2 + ((rand() % 50)-25),wh/2 + ((rand() % 50) - 25)), rand() % 360);
        //s.initialise(sf::Vector2f(ww/2, wh/2), rand() % (2 * 31415) / 10000);
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
            slimes[i].update(image);
            // image.setPixel(slimes[i].getpos().x, slimes[i].getpos().y, sf::Color::White);
        }
        for (int i = 1; i < image.getSize().x; i++)
        {
            for (size_t j = 1; j < image.getSize().y; j++)
            {
                bool left = (i - 1 >= 0);
                bool right = (i + 1 <= (image.getSize().x));
                bool up = (j - 1 >= 0);
                bool down = (j + 1 <= (image.getSize().y));

                //int blend = (image.getPixel(i - 1, j - 1).r + image.getPixel(i - 1, j).r + image.getPixel(i - 1, j + 1).r + image.getPixel(i , j - 1).r + (image.getPixel(i, j).r * 50) + image.getPixel(i, j +1).r + image.getPixel(i + 1, j - 1).r + image.getPixel(i + 1, j).r + image.getPixel(i + 1, j + 1).r ) / 58;
                int blend{ 0 };
                int totel{ 0 };
                if (left && up)
                {
                    blend += image.getPixel(i - 1, j - 1).r;
                    totel++;
                }
                if (left && down)
                {
                    blend += image.getPixel(i - 1, j + 1).r;
                    totel++;
                }
                if (left)
                {
                    blend += image.getPixel(i - 1, j).r;
                    totel++;
                }
                if (right && down)
                {
                    blend += image.getPixel(i + 1, j + 1).r;
                    totel++;
                }
                if (right && up)
                {
                    blend += image.getPixel(i + 1, j - 1).r;
                    totel++;
                }
                if (right)
                {
                    blend += image.getPixel(i + 1, j).r;
                    totel++;
                }
                if (up)
                {
                    blend += image.getPixel(i, j - 1).r;
                    totel++;
                }
                if (down)
                {
                    blend += image.getPixel(i, j + 1).r;
                    totel++;
                }
                blend += (image.getPixel(i, j).r * 50);
                totel+=50;
                blend /= totel;
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

