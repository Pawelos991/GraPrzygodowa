#ifndef ITEMS_H
#define ITEMS_H

#include "Item.h"

/**
* Klasa reprezentująca listę przedmiotów
*/
class Items
{
    public:
        /**
        * Konsturktor klasy ustawiający wskaźnik na pierwszy element listy na nullptr
        */
        Items():head(nullptr){};
        /**
        * Destruktor klasy zwalaniający całą zaalokowaną pamięć
        */
        ~Items(){delete_all_items();};
        /**
        * Funkcja usuwająca wszystkie elementy z listy i zwalaniająca pamięć zaalokowaną przez te elementy
        */
        void delete_all_items();
        /**
        * *Funkcja usuwająca konrektny element z listy i zwalaniająca pamięć zaalokowaną przez ten element
        * @param ID ID przedmiotu który ma zostać usunięty z listy
        */
        void delete_item(int ID);
        /**
        * Funkcja dodająca istniejący przedmiot do listy 
        * @param added Wskaźnik do przedmiotu, który ma zostać dodany do listy
        */
        void add_item(Item *added);
        /**
        * Funkcja dodająca nowy przedmiot do listy
        * @param IDc ID przedmiotu
        * @param namec Nazwa przedmiotu
        * @param location Ścieżka do tekstury przedmiotu
        */
        void add_item(int IDc, std::string namec, std::string location);
        /**
        * Funkcja zwracająca wskaźnik do przedmiotu szukanego po jego ID
        * @param ID ID szukanego przedmiotu
        * @return Wskaźnik do przedmiotu jeśli został znaleziony, nullptr jeśli przedmiot od podanym ID nie został znaleziony w liście
        */
        Item* find_item(int ID);
        /**
        * Funkcja zwracająca wskaźnik do pierwszego elementu na liście
        * @return Wskaźnik do pierwszego elementu na liście
        */
        Item* get_head(){return head;}
        /**
        * Funkcja zwracająca vector wszystkich ID przedmiotów znajdujących się na liście
        * @return Vector ID przedmiotów znajdujących się na liście
        */
        std::vector<int> Item_ids();

        /**
        * Funkcja ładuje przedmioty z plików konfiguracyjnych i umieszcza na liście
        */
        void LoadItemsFromFile();

    private:
        /**Wskaźnik na pierwszy element listy*/
        Item *head;

};

/**
* Funkcja zastępuje znaki '_' w obiektach typu string spacjami
* @param to_replace Obiekt typu string w którym znaki '_' mają zostać zastąpione spacjami
*/
void Replace_withSpace(std::string &to_replace);

#endif // ITEMS_H
