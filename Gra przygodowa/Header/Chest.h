#ifndef CHEST_H
#define CHEST_H

#include "Items.h"

/**
* Klasa reprezentuje pojedyncz¹ skrzyniê, w której znajduj¹ siê przedmioty, które gracz mo¿e zebraæ
*/
class Chest
{
    public:
        /**
        * Konstuktor klasy ³aduj¹cy tekstury z plików, ustawiaj¹cy skrzyniê i uzupe³niaj¹cy jej listê przedmiotów
        * @param location_closed Œcie¿ka do tekstury zamkniêtej skrzyni
        * @param location_open Œcie¿ka do tekstury otwartej skrzyni
        * @param Position Pozycja w oknie w której ma zostaæ umieszczona skrzynia
        * @param SizeOfBox Rozmiar hitboxa skrzyni
        * @param Item_IDs Vector ID przedmiotów które maj¹ siê znaleŸæ w skrzyni
        */
        Chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs);
        /**
        * Destruktor klasy
        */
        virtual ~Chest();
        /**Hitbox skrzyni*/
        RectangleShape box;
        /**Lista ID przedmiotów które znajduj¹ siê w skrzyni*/
        std::vector<int> Items_IDs;
        /**
        * Funkcja wyœwietlaj¹ca skrzyniê w oknie
        * @param window Okno w którym ma zostaæ wyœwietlona skrzynia
        */
        void DisplayChest(RenderWindow &window);
        /**
        * Funkcja s³u¿¹ca do otwarcia skrzyni. Tekstura skrzyni zmienia siê na otwart¹ i odtwarzany jest dŸwiêk otwarcia skrzyni
        */
        void OpenChest();
        /**Informacja o tym, czy skrzynia jest otwarta*/
        bool is_open;

    private:
        /**Tekstura otwartej skrzyni*/
        Texture pic_open;
        /**Tekstura zamkniêtej skrzyni*/
        Texture pic_closed;
        /**Sprite otwartej skrzyni*/
        Sprite sp_open;
        /**Sprite zamkniêtej skrzyni*/
        Sprite sp_closed;
        /**DŸwiêk otwierania skrzyni odtwarzany przy otwieraniu skrzyni*/
        Sound opening;
        /**Bufor do którego ³adowany jest dŸwiêk otwierania skrzyni*/
        SoundBuffer opening_buffer;

};

#endif // CHEST_H
