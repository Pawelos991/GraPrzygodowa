#ifndef ITEMS_H
#define ITEMS_H

#include "Item.h"

/**
* Klasa reprezentuj�ca list� przedmiot�w
*/
class Items
{
    public:
        /**
        * Konsturktor klasy ustawiaj�cy wska�nik na pierwszy element listy na nullptr
        */
        Items():head(nullptr){};
        /**
        * Destruktor klasy zwalaniaj�cy ca�� zaalokowan� pami��
        */
        ~Items(){delete_all_items();};
        /**
        * Funkcja usuwaj�ca wszystkie elementy z listy i zwalaniaj�ca pami�� zaalokowan� przez te elementy
        */
        void delete_all_items();
        /**
        * *Funkcja usuwaj�ca konrektny element z listy i zwalaniaj�ca pami�� zaalokowan� przez ten element
        * @param ID ID przedmiotu kt�ry ma zosta� usuni�ty z listy
        */
        void delete_item(int ID);
        /**
        * Funkcja dodaj�ca istniej�cy przedmiot do listy 
        * @param added Wska�nik do przedmiotu, kt�ry ma zosta� dodany do listy
        */
        void add_item(Item *added);
        /**
        * Funkcja dodaj�ca nowy przedmiot do listy
        * @param IDc ID przedmiotu
        * @param namec Nazwa przedmiotu
        * @param location �cie�ka do tekstury przedmiotu
        */
        void add_item(int IDc, std::string namec, std::string location);
        /**
        * Funkcja zwracaj�ca wska�nik do przedmiotu szukanego po jego ID
        * @param ID ID szukanego przedmiotu
        * @return Wska�nik do przedmiotu je�li zosta� znaleziony, nullptr je�li przedmiot od podanym ID nie zosta� znaleziony w li�cie
        */
        Item* find_item(int ID);
        /**
        * Funkcja zwracaj�ca wska�nik do pierwszego elementu na li�cie
        * @return Wska�nik do pierwszego elementu na li�cie
        */
        Item* get_head(){return head;}
        /**
        * Funkcja zwracaj�ca vector wszystkich ID przedmiot�w znajduj�cych si� na li�cie
        * @return Vector ID przedmiot�w znajduj�cych si� na li�cie
        */
        std::vector<int> Item_ids();

        /**
        * Funkcja �aduje przedmioty z plik�w konfiguracyjnych i umieszcza na li�cie
        */
        void LoadItemsFromFile();

    private:
        /**Wska�nik na pierwszy element listy*/
        Item *head;

};

/**
* Funkcja zast�puje znaki '_' w obiektach typu string spacjami
* @param to_replace Obiekt typu string w kt�rym znaki '_' maj� zosta� zast�pione spacjami
*/
void Replace_withSpace(std::string &to_replace);

#endif // ITEMS_H
