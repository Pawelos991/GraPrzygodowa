#ifndef MISSILES_H
#define MISSILES_H

#include "Missile.h"

/**
* Klasa reprezentuje list� pocisk�w
*/
class Missiles
{
    public:
        /**
        * Konstruktor klasy ustawiaj�cy wska�nik na pierwszy element listy na nullptr
        */
        Missiles():head(nullptr){}
        /**
        * Destruktor klasy zwalaniaj�cy pami�� zaalokowan� przez pociski na li�cie
        */
        ~Missiles(){delete_all_missiles();}
        /**
        * Funkcja dodaj�ca pocisk do listy
        * @param added Wska�nik na pocisk dodawany do listy
        */
        void add_missile(Missile* added);
        /**
        * Funkcja usuwaj�ca pocisk z listy
        * @param deleted Wska�nik na pocisk usuwany z listy
        */
        void delete_missile(Missile* deleted);
        /**
        * Funkcja usuwaj�ca wszystkie pociski z listy
        */
        void delete_all_missiles();
        /**
        * Funkcja zwracaj�ca wska�nik na pierwszy element listy
        * @return Wska�nik na pierwszy element listy
        */
        Missile* getHead(){return head;}

        /**
        * Funkcja wy�wietla wszystkie pociski znajduj�ce si� na li�cie na ekranie
        * @param window Okno w kt�rym wy�wietlane s� pociski
        * @param counter Licznik klatek potrzebny do poprawnego wy�wietlenia animacji pocisk�w
        */
        void Display_all_missiles(RenderWindow &window, int counter);
        /**
        * Funkcja aktualizuj�ca pozycje wszystkich pocisk�w znajduj�cych si� na li�cie
        * @param window Okno w kt�rym znajduj� si� pociski potrzebne do okre�lenia, czy pocisk dalej znajduje si� w obr�bie okna (jesli nie to jest usuwany)
        */
        void Update_all_missiles(RenderWindow &window);
        /**
        * Funkcja odpowiedzialna za utrzymanie ruchu pocisk�w - wywo�uje inne funkcje tej klasy
        * @param window Okno w kt�rym znajduj� si� i s� wy�wietlane pociski
        * @param counter Licznik klatek potrzebny do poprawnego wy�wietlenia animacji pocisk�w
        */
        void maintenance(RenderWindow&window, int counter);

    private:
        /**Wska�nik na pierwszy element listy*/
        Missile *head;
};

#endif // MISSILES_H
