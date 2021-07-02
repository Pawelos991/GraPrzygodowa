#ifndef MAP_H
#define MAP_H

#include "Screens.h"

class Map
{
	public:
		Map();
		~Map();
		void prepareMap(std::vector<Screen*>& screens);
		void displayBigMap(std::vector<Screen*>& screens, RenderWindow& window, int Actual_Screen_ID);
		void displaySmallMap(std::vector<Screen*>& screens, RenderWindow& window, int Actual_Screen_ID);
	
	private:
		Texture smallMapTex;
		Texture bigMapTex;
		Sprite smallMapSprite;
		Sprite bigMapSprite;
		RectangleShape smallMapPieces[20];
		RectangleShape bigMapPieces[20];
};


#endif // MAP_H