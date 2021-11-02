#ifndef CHEST_H
#define CHEST_H

#include "Items.h"

/**
* Klasa reprezentuje pojedynczą skrzynię, w której znajdują się przedmioty, które gracz może zebrać
*/
class Chest
{
    public:
        /**
        * Konstuktor klasy ładujący tekstury z plików, ustawiający skrzynię i uzupełniający jej listę przedmiotów
        * @param location_closed Ścieżka do tekstury zamkniętej skrzyni
        * @param location_open Ścieżka do tekstury otwartej skrzyni
        * @param Position Pozycja w oknie w której ma zostać umieszczona skrzynia
        * @param SizeOfBox Rozmiar hitboxa skrzyni
        * @param Item_IDs Vector ID przedmiotów które mają się znaleźć w skrzyni
        */
        Chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs);
        /**
        * Destruktor klasy
        */
        virtual ~Chest();
        /**Hitbox skrzyni*/
        RectangleShape box;
        /**Lista ID przedmiotów które znajdują się w skrzyni*/
        std::vector<int> Items_IDs;
        /**
        * Funkcja wyświetlająca skrzynię w oknie
        * @param window Okno w którym ma zostać wyświetlona skrzynia
        */
        void DisplayChest(RenderWindow &window);
        /**
        * Funkcja służąca do otwarcia skrzyni. Tekstura skrzyni zmienia się na otwartą i odtwarzany jest dźwięk otwarcia skrzyni
        */
        void OpenChest();
        /**Informacja o tym, czy skrzynia jest otwarta*/
        bool is_open;

    private:
        /**Tekstura otwartej skrzyni*/
        Texture pic_open;
        /**Tekstura zamkniętej skrzyni*/
        Texture pic_closed;
        /**Sprite otwartej skrzyni*/
        Sprite sp_open;
        /**Sprite zamkniętej skrzyni*/
        Sprite sp_closed;
        /**Dźwięk otwierania skrzyni odtwarzany przy otwieraniu skrzyni*/
        Sound opening;
        /**Bufor do którego ładowany jest dźwięk otwierania skrzyni*/
        SoundBuffer opening_buffer;

};

#endif // CHEST_H
