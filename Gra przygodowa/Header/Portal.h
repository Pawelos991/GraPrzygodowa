#ifndef PORTAL_H
#define PORTAL_H

#include "Wall.h"

/**
* Klasa reprezentuje portal przenosz�cy posta� gracza na wy�szy poziom
*/
class Portal 
{
	public:
		/**
		* Konstruktor klasy �aduj�cy dane z plik�w
		*/
		Portal();
		/**
		* Desktruktor klasy
		*/
		~Portal(){}
		/**
		* Funkcja wy�wietlaj�ca portal w oknie
		* @param window Okno w kt�rym ma zosta� wy�wietlony portal
		*/
		void displayPortal(RenderWindow& window);
		/**
		* Funkcja kt�ra odtwarza d�wi�k wej�cia w portal
		*/
		void playSound();
		/**
		* Funkcja sprawdzaj�ca czy posta� gracza koliduje z portalem co jest interpretowane jako wej�cie w portal
		* @param players_hitbox Hitbox postaci gracza
		* @return true je�li posta� gracza koliduje z portalem, false je�li posta� gracza nie koliduje z portalem
		*/
		bool doesPlayerCollide(RectangleShape players_hitbox);

	private:
		/**D�wi�k wej�cia w portal*/
		Sound sound;
		/**Bufor przechowuj�cy d�wi�k wej�cia w portal*/
		SoundBuffer sb;
		/**Tekstura portala*/
		Texture tex;
		/**Sprite potrzebny do poprawnego wy�wietlenia portala*/
		Sprite sp;

};

#endif //PORTAL_H