#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H

#include "Screen.h"

/**
* Klasa reprezentuje ekran �adowania
*/
class Loading_Screen
{
    public:
        /**
        * Kontruktor klasy przygotowuj�cy ekran i �aduj�ce dane z plik�w
        */
        Loading_Screen();
        /**
        * Destruktor klasy
        */
        virtual ~Loading_Screen();
        /**
        * Funkcja wy�wietla ekran �adowania z pustym paskiem �adowania
        * @param window Okno w kt�rym ma zosta� wy�wietlony ekran �adowania
        */
        void start_loading(RenderWindow &window);
        /**
        * Funkcja wy�wietla ekran �adowania z paskiem �adowania zape�nionym w zale�no�ci od podanego parametru i wiadomo�ci� pod paskiem
        * @param window Oknow w kt�rym ma zosta� wy�wietlony ekran �adowania
        * @param perc Informacja jaka cz�� paska ma zosta� zape�niona
        * @param message Wiadomo�� wy�wietlana pod paskiem informuj�ca o tym co w danym momencie jest �adowane
        */
        void set_loading(RenderWindow& window, float perc, std::string message);

    private:
        /**Tekstura t�a ekranu �adowania*/
        Texture background_texture;
        /**Sprite s�u��cy do wy�wietlenia t�a ekranu �adowania*/
        Sprite background_sprite;
        /**Pasek �adowania*/
        RectangleShape loading_bar;
        /**Czcionka tekstu wiadomo�ci znajduj�cej si� poni�ej paska �adowania*/
        Font font;
        /**Wiadomo�� wy�wietlana pod paskiem �adowania*/
        Text text;
};

#endif // LOADING_SCREEN_H
