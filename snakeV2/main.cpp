#include <SFML/Graphics.hpp>
#include <iostream>	
#include "Constants.h"
#include <fstream>

using namespace std;

void citire(char a[100][100], int& nl, int& nc);
void afisare(char a[100][100], int nl, int nc);

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake");

	char mat[100][100];
	int nl, nc;
	citire(mat, nl, nc);
	afisare(mat, nl, nc);

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

void citire(char a[100][100], int& nl, int& nc)
{
	ifstream f("mat.in");

	f >> nl >> nc;
	f.get();	// new line

	for (int i = 0; i < nl; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			f >> a[i][j];
		}
		f.get();	// new line
	}
}

void afisare(char a[100][100], int nl, int nc)
{
	for (int i = 0; i < nl; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}