#ifndef ITEMS_H
#define ITEMS_H

#include "Item.h"

/**
* Klasa reprezentuj¹ca listê przedmiotów
*/
class Items
{
    public:
        /**
        * Konsturktor klasy ustawiaj¹cy wskaŸnik na pierwszy element listy na nullptr
        */
        Items():head(nullptr){};
        /**
        * Destruktor klasy zwalaniaj¹cy ca³¹ zaalokowan¹ pamiêæ
        */
        ~Items(){delete_all_items();};
        /**
        * Funkcja usuwaj¹ca wszystkie elementy z listy i zwalaniaj¹ca pamiêæ zaalokowan¹ przez te elementy
        */
        void delete_all_items();
        /**
        * *Funkcja usuwaj¹ca konrektny element z listy i zwalaniaj¹ca pamiêæ zaalokowan¹ przez ten element
        * @param ID ID przedmiotu który ma zostaæ usuniêty z listy
        */
        void delete_item(int ID);
        /**
        * Funkcja dodaj¹ca istniej¹cy przedmiot do listy 
        * @param added WskaŸnik do przedmiotu, który ma zostaæ dodany do listy
        */
        void add_item(Item *added);
        /**
        * Funkcja dodaj¹ca nowy przedmiot do listy
        * @param IDc ID przedmiotu
        * @param namec Nazwa przedmiotu
        * @param location Œcie¿ka do tekstury przedmiotu
        */
        void add_item(int IDc, std::string namec, std::string location);
        /**
        * Funkcja zwracaj¹ca wskaŸnik do przedmiotu szukanego po jego ID
        * @param ID ID szukanego przedmiotu
        * @return WskaŸnik do przedmiotu jeœli zosta³ znaleziony, nullptr jeœli przedmiot od podanym ID nie zosta³ znaleziony w liœcie
        */
        Item* find_item(int ID);
        /**
        * Funkcja zwracaj¹ca wskaŸnik do pierwszego elementu na liœcie
        * @return WskaŸnik do pierwszego elementu na liœcie
        */
        Item* get_head(){return head;}
        /**
        * Funkcja zwracaj¹ca vector wszystkich ID przedmiotów znajduj¹cych siê na liœcie
        * @return Vector ID przedmiotów znajduj¹cych siê na liœcie
        */
        std::vector<int> Item_ids();

        /**
        * Funkcja ³aduje przedmioty z plików konfiguracyjnych i umieszcza na liœcie
        */
        void LoadItemsFromFile();

    private:
        /**WskaŸnik na pierwszy element listy*/
        Item *head;

};

/**
* Funkcja zastêpuje znaki '_' w obiektach typu string spacjami
* @param to_replace Obiekt typu string w którym znaki '_' maj¹ zostaæ zast¹pione spacjami
*/
void Replace_withSpace(std::string &to_replace);

#endif // ITEMS_H
