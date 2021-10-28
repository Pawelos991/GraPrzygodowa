#ifndef MAP_H
#define MAP_H

#include "Screens.h"

/**
* Klasa reprezentuj¹ca mapê rozk³adu pomieszczeñ na danym poziomie
*/
class Map
{
	public:
		/**
		* Konstruktor klasy
		*/
		Map();
		/**
		* Destruktor klasy
		*/
		~Map();
		/**
		* Funkcja s³u¿¹ca do utworzenia mapy bazuj¹c na informacjach o po³o¿eniu pomieszczeñ
		* @param screens Vector ekranów na danym poziomie
		*/
		void prepareMap(std::vector<Screen*>& screens);
		/**
		* Funkcja wyœwietlaj¹ca mapê w ca³ym oknie
		* @param screens Vector ekranów na danym poziomie
		* @param window Okno w którym ma zostaæ wyœwietlona mapa
		* @param Actual_Screen_ID ID ekranu na którym obecnie znajduje siê postaæ gracza
		*/
		void displayBigMap(std::vector<Screen*>& screens, RenderWindow& window, int Actual_Screen_ID);
		/**
		* Funkcja wyœwietlaj¹ca mapê w prawym górnym rogu okna
		* @param screens Vector ekranów na danym poziomie
		* @param window Okno w którym ma zostaæ wyœwietlona mapa
		* @param Actual_Screen_ID ID ekranu na którym obecnie znajduje siê postaæ gracza
		*/
		void displaySmallMap(std::vector<Screen*>& screens, RenderWindow& window, int Actual_Screen_ID);
	
	private:
		/**Tekstura t³a ma³ej mapy*/
		Texture smallMapTex;
		/**Tekstura t³a du¿ej mapy*/
		Texture bigMapTex;
		/**Sprite t³a ma³ej mapy*/
		Sprite smallMapSprite;
		/**Sprite t³a du¿ej mapy*/
		Sprite bigMapSprite;
		/**Tablica kafelków obrazuj¹cych ekrany ma³ej mapy*/
		RectangleShape smallMapPieces[100];
		/**Tablica kafelków obrazuj¹cych ekrany du¿ej mapy*/
		RectangleShape bigMapPieces[100];
};


#endif // MAP_H