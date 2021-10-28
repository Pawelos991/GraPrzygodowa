#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "NC_Object.h"

/**
*Klasa reprezentująca tło ekranu (tło + obiekty niekolidujące z postaciami)
*/
class Background
{
    public:

    protected:
        /**Vector obiektów niekolidujących z postaciami*/
        std::vector <NC_Object*> NC_Objects;
        /**Sprite tła ekranu*/
        Sprite Bck;
        /**Tekstura tła ekranu*/
        Texture pic;
        /**
        *Funkcja odpowiedzialna za wyświetlenie tła w oknie
        *@param window Okno w którym ma zostać wyświetlone tło
        */
        void displayBackground(RenderWindow &window);
        /**
        *Funkcja dodająca obiekt niekolidujący z postaciami do vectora tych obiektów
        *@param location Ścieżka do tekstury obiektu niekolidującego dodawanego do vectora 
        *@param Position Pozycja na ekranie w której ma zostać umieszczony dodawany obiekt
        */
        void add_NC_Object(std::string location,Vector2f Position);
        /**
        *Funkcja odpowiedzialna za zwolnienie pamięci zaalokowanej przez obiekt tej klasy
        */
        void clearData_Bck();
};

#endif // BACKGROUND_H
