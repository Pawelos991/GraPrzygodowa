#ifndef PORTAL_H
#define PORTAL_H

#include "Wall.h"

/**
* Klasa reprezentuje portal przenoszący postać gracza na wyższy poziom
*/
class Portal 
{
	public:
		/**
		* Konstruktor klasy ładujący dane z plików
		*/
		Portal();
		/**
		* Desktruktor klasy
		*/
		~Portal(){}
		/**
		* Funkcja wyświetlająca portal w oknie
		* @param window Okno w którym ma zostać wyświetlony portal
		*/
		void displayPortal(RenderWindow& window);
		/**
		* Funkcja która odtwarza dźwięk wejścia w portal
		*/
		void playSound();
		/**
		* Funkcja sprawdzająca czy postać gracza koliduje z portalem co jest interpretowane jako wejście w portal
		* @param players_hitbox Hitbox postaci gracza
		* @return true jeśli postać gracza koliduje z portalem, false jeśli postać gracza nie koliduje z portalem
		*/
		bool doesPlayerCollide(RectangleShape players_hitbox);

	private:
		/**Dźwięk wejścia w portal*/
		Sound sound;
		/**Bufor przechowujący dźwięk wejścia w portal*/
		SoundBuffer sb;
		/**Tekstura portala*/
		Texture tex;
		/**Sprite potrzebny do poprawnego wyświetlenia portala*/
		Sprite sp;

};

#endif //PORTAL_H