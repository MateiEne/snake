#include <SFML/Graphics.hpp>
#include <iostream>	
#include "Constants.h"
#include <fstream>

using namespace std;

void citire(int a[100][100]);
void afisare(int a[100][100]);

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake");

	int mat[100][100];
	citire(mat);
	afisare(mat);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}

	return 0;
}

void citire(int a[100][100])
{
	ifstream f("mat.in");
	for (int i = 0; i < NL; i++)
	{
		for (int j = 0; j < NC; j++)
		{
			f >> a[i][j];
		}
	}
}

void afisare(int a[100][100])
{
	for (int i = 0; i < NL; i++)
	{
		for (int j = 0; j < NC; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}