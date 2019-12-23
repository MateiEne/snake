#include "World.h"
#include <fstream>
#include <iostream>

using namespace std;

World::World(const char* fileName, const char* wallTexture, const char* sandTexture)
{
	ReadFromFile(fileName);

	if (!this->wallTexture.loadFromFile(wallTexture))
	{
		cout << "error wallTexture/n";
		exit(-1);
	}


	if (!this->sandTexture.loadFromFile(sandTexture))
	{
		cout << "error sandTexture/n";
		exit(-1);
	}

	wallSprite.setTexture(this->wallTexture);
	sandSprite.setTexture(this->sandTexture);
}

World::~World()
{
}

void World::ReadFromFile(const char* fileName)
{
	ifstream f(fileName);
	f >> nl >> nc;
	for (int i = 0; i < nl; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			f >> mat[i][j];
		}
	}
}

void World::Print()
{
	for (int  i = 0; i < nl; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			cout << mat[i][j];
		}
		cout << endl;
	}
}

void World::Update(float dt)
{

}

void World::Draw(sf::RenderWindow& window)
{
	auto size = this->wallTexture.getSize();
	wallSprite.setScale(CELL_WIDTH / size.x, CELL_HEIGHT / size.y);

	size = this->sandTexture.getSize();
	sandSprite.setScale(CELL_WIDTH / size.x, CELL_HEIGHT / size.y);

	for (int i = 0; i < nl; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			if (mat[i][j] == CH_WALL)
			{
				wallSprite.setPosition(j * CELL_WIDTH, i * CELL_HEIGHT);

				window.draw(wallSprite);
			}
			else if (mat[i][j] == CH_SAND)
			{
				sandSprite.setPosition(j * CELL_WIDTH, i * CELL_HEIGHT);

				window.draw(sandSprite);
			}
		}
	}
}