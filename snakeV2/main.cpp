#include <SFML/Graphics.hpp>
#include <iostream>	
#include "Constants.h"
#include <fstream>
#include "World.h"

using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake");

	World world("mat.in", "Textures\\wall.png", "Textures\\sand.png");

	world.Print();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		world.Draw(window);
		window.display();
	}

	return 0;
}