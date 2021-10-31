#ifndef PORTAL_H
#define PORTAL_H

#include "Wall.h"

/**
* Klasa reprezentuje portal przenosz¹cy postaæ gracza na wy¿szy poziom
*/
class Portal 
{
	public:
		/**
		* Konstruktor klasy ³aduj¹cy dane z plików
		*/
		Portal();
		/**
		* Desktruktor klasy
		*/
		~Portal(){}
		/**
		* Funkcja wyœwietlaj¹ca portal w oknie
		* @param window Okno w którym ma zostaæ wyœwietlony portal
		*/
		void displayPortal(RenderWindow& window);
		/**
		* Funkcja która odtwarza dŸwiêk wejœcia w portal
		*/
		void playSound();
		/**
		* Funkcja sprawdzaj¹ca czy postaæ gracza koliduje z portalem co jest interpretowane jako wejœcie w portal
		* @param players_hitbox Hitbox postaci gracza
		* @return true jeœli postaæ gracza koliduje z portalem, false jeœli postaæ gracza nie koliduje z portalem
		*/
		bool doesPlayerCollide(RectangleShape players_hitbox);

	private:
		/**DŸwiêk wejœcia w portal*/
		Sound sound;
		/**Bufor przechowuj¹cy dŸwiêk wejœcia w portal*/
		SoundBuffer sb;
		/**Tekstura portala*/
		Texture tex;
		/**Sprite potrzebny do poprawnego wyœwietlenia portala*/
		Sprite sp;

};

#endif //PORTAL_H