#ifndef INVENTORY_H
#define INVENTORY_H

#include "Items.h"

/**
* Klasa reprezentuj�ca inwentarz postaci gracza
*/
class Inventory
{
    public:
        /**
        * Konstruktor klasy �aduj�cy tekstur� t�a inwentarza
        */
        Inventory(){LoadBackground();}
        /**
        * Destruktor klasy zwalniaj�cy zaalokowan� pami�� poprzez usuni�cie wszystkich przedmiot�w znajduj�cych si� w inwentarzu
        */
        virtual ~Inventory(){items.delete_all_items();}
        /**Lista przedmiot�w znajduj�cych si� w inwentarzu*/
        Items items;
        /**
        * Funkcja dodaj�ca przedmiot do inwentarzu
        * @param ID ID dodawanego przedmiotu
        * @param all_items Lista wszystkich przedmiot�w obecnych w grze 
        */
        void add_item_to_inventory(int ID, Items &all_items);
        /**
        * Funkcja usuwaj�ca jeden przedmiot o podanym ID z inwentarza
        * @param ID ID usuwanego przedmiotu
        */
        void delete_item_from_inventory(int ID);
        /**
        * Funkcja zwalniaj�ca pami�� poprzez usuni�cie wszystkich przedmiot�w z inwentarza
        */
        void clear_items();
        /**
        * Funkcja �aduj�ca tekstur� t�a inwentarza z pliku
        */
        void LoadBackground();
        /**
        * Funkcja wy�wietlaj�ca inwentarz w oknie
        * @param window Okno w kt�rym ma zosta� wy�wietlony inwentarz
        */
        void Display_Inventory(RenderWindow &window);
        /**
        * Funkcja zwracaj�ca informacj� o tym czy w inwentarzu znajduje si� przedmiot o podanym ID
        * @param ID ID przedmiotu kt�rego obecno�� w inwentarzu jest sprawdzana
        */
        bool Is_there_an_item(int ID);

    private:
        /**Tekstura t�a inwentarza*/
        Texture texture;
        /**Sprite t�a inwentarza s�u��cy do wy�wietlania go w oknie*/
        Sprite sp;

};

#endif // INVENTORY_H
