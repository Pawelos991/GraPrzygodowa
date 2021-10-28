#ifndef INVENTORY_H
#define INVENTORY_H

#include "Items.h"

/**
* Klasa reprezentuj¹ca inwentarz postaci gracza
*/
class Inventory
{
    public:
        /**
        * Konstruktor klasy ³aduj¹cy teksturê t³a inwentarza
        */
        Inventory(){LoadBackground();}
        /**
        * Destruktor klasy zwalniaj¹cy zaalokowan¹ pamiêæ poprzez usuniêcie wszystkich przedmiotów znajduj¹cych siê w inwentarzu
        */
        virtual ~Inventory(){items.delete_all_items();}
        /**Lista przedmiotów znajduj¹cych siê w inwentarzu*/
        Items items;
        /**
        * Funkcja dodaj¹ca przedmiot do inwentarzu
        * @param ID ID dodawanego przedmiotu
        * @param all_items Lista wszystkich przedmiotów obecnych w grze 
        */
        void add_item_to_inventory(int ID, Items &all_items);
        /**
        * Funkcja usuwaj¹ca jeden przedmiot o podanym ID z inwentarza
        * @param ID ID usuwanego przedmiotu
        */
        void delete_item_from_inventory(int ID);
        /**
        * Funkcja zwalniaj¹ca pamiêæ poprzez usuniêcie wszystkich przedmiotów z inwentarza
        */
        void clear_items();
        /**
        * Funkcja ³aduj¹ca teksturê t³a inwentarza z pliku
        */
        void LoadBackground();
        /**
        * Funkcja wyœwietlaj¹ca inwentarz w oknie
        * @param window Okno w którym ma zostaæ wyœwietlony inwentarz
        */
        void Display_Inventory(RenderWindow &window);
        /**
        * Funkcja zwracaj¹ca informacjê o tym czy w inwentarzu znajduje siê przedmiot o podanym ID
        * @param ID ID przedmiotu którego obecnoœæ w inwentarzu jest sprawdzana
        */
        bool Is_there_an_item(int ID);

    private:
        /**Tekstura t³a inwentarza*/
        Texture texture;
        /**Sprite t³a inwentarza s³u¿¹cy do wyœwietlania go w oknie*/
        Sprite sp;

};

#endif // INVENTORY_H
