#ifndef MAP_H
#define MAP_H

#include "Screens.h"

/**
* Klasa reprezentująca mapę rozkładu pomieszczeń na danym poziomie
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
		* Funkcja służąca do utworzenia mapy bazując na informacjach o położeniu pomieszczeń
		* @param screens Vector ekranów na danym poziomie
		*/
		void prepareMap(std::vector<Screen*>& screens);
		/**
		* Funkcja wyświetlająca mapę w całym oknie
		* @param screens Vector ekranów na danym poziomie
		* @param window Okno w którym ma zostać wyświetlona mapa
		* @param Actual_Screen_ID ID ekranu na którym obecnie znajduje się postać gracza
		*/
		void displayBigMap(std::vector<Screen*>& screens, RenderWindow& window, int Actual_Screen_ID);
		/**
		* Funkcja wyświetlająca mapę w prawym górnym rogu okna
		* @param screens Vector ekranów na danym poziomie
		* @param window Okno w którym ma zostać wyświetlona mapa
		* @param Actual_Screen_ID ID ekranu na którym obecnie znajduje się postać gracza
		*/
		void displaySmallMap(std::vector<Screen*>& screens, RenderWindow& window, int Actual_Screen_ID);
	
	private:
		/**Tekstura tła małej mapy*/
		Texture smallMapTex;
		/**Tekstura tła dużej mapy*/
		Texture bigMapTex;
		/**Sprite tła małej mapy*/
		Sprite smallMapSprite;
		/**Sprite tła dużej mapy*/
		Sprite bigMapSprite;
		/**Tablica kafelków obrazujących ekrany małej mapy*/
		RectangleShape smallMapPieces[100];
		/**Tablica kafelków obrazujących ekrany dużej mapy*/
		RectangleShape bigMapPieces[100];
};


#endif // MAP_H