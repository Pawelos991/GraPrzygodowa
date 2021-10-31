#ifndef MISSILES_H
#define MISSILES_H

#include "Missile.h"

/**
* Klasa reprezentuje listê pocisków
*/
class Missiles
{
    public:
        /**
        * Konstruktor klasy ustawiaj¹cy wskaŸnik na pierwszy element listy na nullptr
        */
        Missiles():head(nullptr){}
        /**
        * Destruktor klasy zwalaniaj¹cy pamiêæ zaalokowan¹ przez pociski na liœcie
        */
        ~Missiles(){delete_all_missiles();}
        /**
        * Funkcja dodaj¹ca pocisk do listy
        * @param added WskaŸnik na pocisk dodawany do listy
        */
        void add_missile(Missile* added);
        /**
        * Funkcja usuwaj¹ca pocisk z listy
        * @param deleted WskaŸnik na pocisk usuwany z listy
        */
        void delete_missile(Missile* deleted);
        /**
        * Funkcja usuwaj¹ca wszystkie pociski z listy
        */
        void delete_all_missiles();
        /**
        * Funkcja zwracaj¹ca wskaŸnik na pierwszy element listy
        * @return WskaŸnik na pierwszy element listy
        */
        Missile* getHead(){return head;}

        /**
        * Funkcja wyœwietla wszystkie pociski znajduj¹ce siê na liœcie na ekranie
        * @param window Okno w którym wyœwietlane s¹ pociski
        * @param counter Licznik klatek potrzebny do poprawnego wyœwietlenia animacji pocisków
        */
        void Display_all_missiles(RenderWindow &window, int counter);
        /**
        * Funkcja aktualizuj¹ca pozycje wszystkich pocisków znajduj¹cych siê na liœcie
        * @param window Okno w którym znajduj¹ siê pociski potrzebne do okreœlenia, czy pocisk dalej znajduje siê w obrêbie okna (jesli nie to jest usuwany)
        */
        void Update_all_missiles(RenderWindow &window);
        /**
        * Funkcja odpowiedzialna za utrzymanie ruchu pocisków - wywo³uje inne funkcje tej klasy
        * @param window Okno w którym znajduj¹ siê i s¹ wyœwietlane pociski
        * @param counter Licznik klatek potrzebny do poprawnego wyœwietlenia animacji pocisków
        */
        void maintenance(RenderWindow&window, int counter);

    private:
        /**WskaŸnik na pierwszy element listy*/
        Missile *head;
};

#endif // MISSILES_H
