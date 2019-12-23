#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
class World
{
public:
	World(const char* fileName, const char* wallTexture, const char* sandTexture);
	~World();

	void Print();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);

private:
	void ReadFromFile(const char* fileName);

	int nl, nc;
	char mat[100][100];

	sf::Sprite wallSprite;
	sf::Sprite sandSprite;

	sf::Texture wallTexture;
	sf::Texture sandTexture;
};

