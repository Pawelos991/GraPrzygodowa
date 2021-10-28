#ifndef NC_OBJECT_H
#define NC_OBJECT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

/**
*Klasa reprezentująca obiekt niekolidujący z postaciami
*/
class NC_Object
{
    public:
        /**
        *Konstruktor klasy ładujący odpowiednią teksturę z pliku i ustawiający obiekt w odpowiedniej pozycji
        *@param location Ścieżka do pliku tekstury obiektu
        *@param Position Pozycja w której ma zostać ustawiony obiekt
        */
        NC_Object(std::string location, Vector2f Position);
        /**
        *Funkcja odpowiedzialna za wyświetlenie obiektu w oknie
        *@param window Okno w którym ma zostać wyświetlony obiekt
        */
        void displayObject(RenderWindow &window);

    private:
        /**Tekstura obiektu niekolidującego z postaciami*/
        Texture pic;
        /**Sprite służący do wyświetlania obiektu*/
        Sprite sp;
        /**Pozycja obiektu w oknie*/
        Vector2f position;
};

#endif // NC_OBJECT_H
