#include "Map.h"

Map::Map(){}

Map::~Map(){}

void Map::prepareMap(std::vector<Screen*>& screens)
{
	smallMapTex.loadFromFile("Textures/Map/Map_Small.png");
	bigMapTex.loadFromFile("Textures/Map/Map_Big.png");
	smallMapSprite.setTexture(smallMapTex);
	bigMapSprite.setTexture(bigMapTex);
	smallMapSprite.setPosition(Vector2f(1201,10));
	bigMapSprite.setPosition(Vector2f(0, 0));
	Vector2f smallStartPos = Vector2f(1214,40);
	Vector2f bigStartPos = Vector2f(54, 124);
	for (int i = 0; i < screens.size(); i++)
	{
		smallMapPieces[i].setFillColor(Color::Black);
		Vector2f pos = smallStartPos + Vector2f((screens[i]->getPosition().x+5)*37, (-(screens[i]->getPosition().y) + 4) * 18);
		smallMapPieces[i].setPosition(pos);
		smallMapPieces[i].setSize(Vector2f(32, 16));
	}
	for (int i = 0; i < screens.size(); i++)
	{
		bigMapPieces[i].setFillColor(Color::Black);
		Vector2f pos = bigStartPos + Vector2f((screens[i]->getPosition().x + 5) * 152, (-(screens[i]->getPosition().y) + 4) * 74);
		bigMapPieces[i].setPosition(pos);
		bigMapPieces[i].setSize(Vector2f(132, 66));
	}
}

void Map::displayBigMap(std::vector<Screen*>& screens, RenderWindow& window, int Actual_Screen_ID)
{
	window.draw(bigMapSprite);
	for (int i = 0; i < screens.size(); i++)
	{
		if (screens[i]->isVisited())
		{
			if (screens[i]->getID() == Actual_Screen_ID)
				bigMapPieces[i].setFillColor(Color::White);
			else
				bigMapPieces[i].setFillColor(Color::Black);
			window.draw(bigMapPieces[i]);
		}
	}
}

void Map::displaySmallMap(std::vector<Screen*>& screens, RenderWindow& window, int Actual_Screen_ID)
{
	window.draw(smallMapSprite);
	for (int i = 0; i < screens.size(); i++)
	{
		if (screens[i]->isVisited())
		{
			if (screens[i]->getID() == Actual_Screen_ID)
				smallMapPieces[i].setFillColor(Color::White);
			else
				smallMapPieces[i].setFillColor(Color::Black);
			window.draw(smallMapPieces[i]);
		}
	}
}