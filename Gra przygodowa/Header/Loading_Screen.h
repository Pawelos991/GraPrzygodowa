#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H

#include "Screen.h"

/**
* Klasa reprezentuje ekran ładowania
*/
class Loading_Screen
{
    public:
        /**
        * Kontruktor klasy przygotowujący ekran i ładujące dane z plików
        */
        Loading_Screen();
        /**
        * Destruktor klasy
        */
        virtual ~Loading_Screen();
        /**
        * Funkcja wyświetla ekran ładowania z pustym paskiem ładowania
        * @param window Okno w którym ma zostać wyświetlony ekran ładowania
        */
        void start_loading(RenderWindow &window);
        /**
        * Funkcja wyświetla ekran ładowania z paskiem ładowania zapełnionym w zależności od podanego parametru i wiadomością pod paskiem
        * @param window Oknow w którym ma zostać wyświetlony ekran ładowania
        * @param perc Informacja jaka część paska ma zostać zapełniona
        * @param message Wiadomość wyświetlana pod paskiem informująca o tym co w danym momencie jest ładowane
        */
        void set_loading(RenderWindow& window, float perc, std::string message);

    private:
        /**Tekstura tła ekranu ładowania*/
        Texture background_texture;
        /**Sprite służący do wyświetlenia tła ekranu ładowania*/
        Sprite background_sprite;
        /**Pasek ładowania*/
        RectangleShape loading_bar;
        /**Czcionka tekstu wiadomości znajdującej się poniżej paska ładowania*/
        Font font;
        /**Wiadomość wyświetlana pod paskiem ładowania*/
        Text text;
};

#endif // LOADING_SCREEN_H
