#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H

#include "Screen.h"

/**
* Klasa reprezentuje ekran ³adowania
*/
class Loading_Screen
{
    public:
        /**
        * Kontruktor klasy przygotowuj¹cy ekran i ³aduj¹ce dane z plików
        */
        Loading_Screen();
        /**
        * Destruktor klasy
        */
        virtual ~Loading_Screen();
        /**
        * Funkcja wyœwietla ekran ³adowania z pustym paskiem ³adowania
        * @param window Okno w którym ma zostaæ wyœwietlony ekran ³adowania
        */
        void start_loading(RenderWindow &window);
        /**
        * Funkcja wyœwietla ekran ³adowania z paskiem ³adowania zape³nionym w zale¿noœci od podanego parametru i wiadomoœci¹ pod paskiem
        * @param window Oknow w którym ma zostaæ wyœwietlony ekran ³adowania
        * @param perc Informacja jaka czêœæ paska ma zostaæ zape³niona
        * @param message Wiadomoœæ wyœwietlana pod paskiem informuj¹ca o tym co w danym momencie jest ³adowane
        */
        void set_loading(RenderWindow& window, float perc, std::string message);

    private:
        /**Tekstura t³a ekranu ³adowania*/
        Texture background_texture;
        /**Sprite s³u¿¹cy do wyœwietlenia t³a ekranu ³adowania*/
        Sprite background_sprite;
        /**Pasek ³adowania*/
        RectangleShape loading_bar;
        /**Czcionka tekstu wiadomoœci znajduj¹cej siê poni¿ej paska ³adowania*/
        Font font;
        /**Wiadomoœæ wyœwietlana pod paskiem ³adowania*/
        Text text;
};

#endif // LOADING_SCREEN_H
