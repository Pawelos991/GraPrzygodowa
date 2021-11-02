#ifndef INVENTORY_H
#define INVENTORY_H

#include "Items.h"

/**
* Klasa reprezentująca inwentarz postaci gracza
*/
class Inventory
{
    public:
        /**
        * Konstruktor klasy ładujący teksturę tła inwentarza
        */
        Inventory(){LoadBackground();}
        /**
        * Destruktor klasy zwalniający zaalokowaną pamięć poprzez usunięcie wszystkich przedmiotów znajdujących się w inwentarzu
        */
        virtual ~Inventory(){items.delete_all_items();}
        /**Lista przedmiotów znajdujących się w inwentarzu*/
        Items items;
        /**
        * Funkcja dodająca przedmiot do inwentarzu
        * @param ID ID dodawanego przedmiotu
        * @param all_items Lista wszystkich przedmiotów obecnych w grze 
        */
        void add_item_to_inventory(int ID, Items &all_items);
        /**
        * Funkcja usuwająca jeden przedmiot o podanym ID z inwentarza
        * @param ID ID usuwanego przedmiotu
        */
        void delete_item_from_inventory(int ID);
        /**
        * Funkcja zwalniająca pamięć poprzez usunięcie wszystkich przedmiotów z inwentarza
        */
        void clear_items();
        /**
        * Funkcja ładująca teksturę tła inwentarza z pliku
        */
        void LoadBackground();
        /**
        * Funkcja wyświetlająca inwentarz w oknie
        * @param window Okno w którym ma zostać wyświetlony inwentarz
        */
        void Display_Inventory(RenderWindow &window);
        /**
        * Funkcja zwracająca informację o tym czy w inwentarzu znajduje się przedmiot o podanym ID
        * @param ID ID przedmiotu którego obecność w inwentarzu jest sprawdzana
        */
        bool Is_there_an_item(int ID);

    private:
        /**Tekstura tła inwentarza*/
        Texture texture;
        /**Sprite tła inwentarza służący do wyświetlania go w oknie*/
        Sprite sp;

};

#endif // INVENTORY_H
