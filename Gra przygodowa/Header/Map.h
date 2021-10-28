#ifndef MAP_H
#define MAP_H

#include "Screens.h"

/**
* Klasa reprezentuj�ca map� rozk�adu pomieszcze� na danym poziomie
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
		* Funkcja s�u��ca do utworzenia mapy bazuj�c na informacjach o po�o�eniu pomieszcze�
		* @param screens Vector ekran�w na danym poziomie
		*/
		void prepareMap(std::vector<Screen*>& screens);
		/**
		* Funkcja wy�wietlaj�ca map� w ca�ym oknie
		* @param screens Vector ekran�w na danym poziomie
		* @param window Okno w kt�rym ma zosta� wy�wietlona mapa
		* @param Actual_Screen_ID ID ekranu na kt�rym obecnie znajduje si� posta� gracza
		*/
		void displayBigMap(std::vector<Screen*>& screens, RenderWindow& window, int Actual_Screen_ID);
		/**
		* Funkcja wy�wietlaj�ca map� w prawym g�rnym rogu okna
		* @param screens Vector ekran�w na danym poziomie
		* @param window Okno w kt�rym ma zosta� wy�wietlona mapa
		* @param Actual_Screen_ID ID ekranu na kt�rym obecnie znajduje si� posta� gracza
		*/
		void displaySmallMap(std::vector<Screen*>& screens, RenderWindow& window, int Actual_Screen_ID);
	
	private:
		/**Tekstura t�a ma�ej mapy*/
		Texture smallMapTex;
		/**Tekstura t�a du�ej mapy*/
		Texture bigMapTex;
		/**Sprite t�a ma�ej mapy*/
		Sprite smallMapSprite;
		/**Sprite t�a du�ej mapy*/
		Sprite bigMapSprite;
		/**Tablica kafelk�w obrazuj�cych ekrany ma�ej mapy*/
		RectangleShape smallMapPieces[100];
		/**Tablica kafelk�w obrazuj�cych ekrany du�ej mapy*/
		RectangleShape bigMapPieces[100];
};


#endif // MAP_H