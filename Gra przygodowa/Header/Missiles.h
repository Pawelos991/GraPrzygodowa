#ifndef MISSILES_H
#define MISSILES_H

#include "Missile.h"

/**
* Klasa reprezentuje listę pocisków
*/
class Missiles
{
    public:
        /**
        * Konstruktor klasy ustawiający wskaźnik na pierwszy element listy na nullptr
        */
        Missiles():head(nullptr){}
        /**
        * Destruktor klasy zwalaniający pamięć zaalokowaną przez pociski na liście
        */
        ~Missiles(){delete_all_missiles();}
        /**
        * Funkcja dodająca pocisk do listy
        * @param added Wskaźnik na pocisk dodawany do listy
        */
        void add_missile(Missile* added);
        /**
        * Funkcja usuwająca pocisk z listy
        * @param deleted Wskaźnik na pocisk usuwany z listy
        */
        void delete_missile(Missile* deleted);
        /**
        * Funkcja usuwająca wszystkie pociski z listy
        */
        void delete_all_missiles();
        /**
        * Funkcja zwracająca wskaźnik na pierwszy element listy
        * @return Wskaźnik na pierwszy element listy
        */
        Missile* getHead(){return head;}

        /**
        * Funkcja wyświetla wszystkie pociski znajdujące się na liście na ekranie
        * @param window Okno w którym wyświetlane są pociski
        * @param counter Licznik klatek potrzebny do poprawnego wyświetlenia animacji pocisków
        */
        void Display_all_missiles(RenderWindow &window, int counter);
        /**
        * Funkcja aktualizująca pozycje wszystkich pocisków znajdujących się na liście
        * @param window Okno w którym znajdują się pociski potrzebne do określenia, czy pocisk dalej znajduje się w obrębie okna (jesli nie to jest usuwany)
        */
        void Update_all_missiles(RenderWindow &window);
        /**
        * Funkcja odpowiedzialna za utrzymanie ruchu pocisków - wywołuje inne funkcje tej klasy
        * @param window Okno w którym znajdują się i są wyświetlane pociski
        * @param counter Licznik klatek potrzebny do poprawnego wyświetlenia animacji pocisków
        */
        void maintenance(RenderWindow&window, int counter);

    private:
        /**Wskaźnik na pierwszy element listy*/
        Missile *head;
};

#endif // MISSILES_H
