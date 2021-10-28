#ifndef CHEST_H
#define CHEST_H

#include "Items.h"

/**
* Klasa reprezentuje pojedyncz� skrzyni�, w kt�rej znajduj� si� przedmioty, kt�re gracz mo�e zebra�
*/
class Chest
{
    public:
        /**
        * Konstuktor klasy �aduj�cy tekstury z plik�w, ustawiaj�cy skrzyni� i uzupe�niaj�cy jej list� przedmiot�w
        * @param location_closed �cie�ka do tekstury zamkni�tej skrzyni
        * @param location_open �cie�ka do tekstury otwartej skrzyni
        * @param Position Pozycja w oknie w kt�rej ma zosta� umieszczona skrzynia
        * @param SizeOfBox Rozmiar hitboxa skrzyni
        * @param Item_IDs Vector ID przedmiot�w kt�re maj� si� znale�� w skrzyni
        */
        Chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs);
        /**
        * Destruktor klasy
        */
        virtual ~Chest();
        /**Hitbox skrzyni*/
        RectangleShape box;
        /**Lista ID przedmiot�w kt�re znajduj� si� w skrzyni*/
        std::vector<int> Items_IDs;
        /**
        * Funkcja wy�wietlaj�ca skrzyni� w oknie
        * @param window Okno w kt�rym ma zosta� wy�wietlona skrzynia
        */
        void DisplayChest(RenderWindow &window);
        /**
        * Funkcja s�u��ca do otwarcia skrzyni. Tekstura skrzyni zmienia si� na otwart� i odtwarzany jest d�wi�k otwarcia skrzyni
        */
        void OpenChest();
        /**Informacja o tym, czy skrzynia jest otwarta*/
        bool is_open;

    private:
        /**Tekstura otwartej skrzyni*/
        Texture pic_open;
        /**Tekstura zamkni�tej skrzyni*/
        Texture pic_closed;
        /**Sprite otwartej skrzyni*/
        Sprite sp_open;
        /**Sprite zamkni�tej skrzyni*/
        Sprite sp_closed;
        /**D�wi�k otwierania skrzyni odtwarzany przy otwieraniu skrzyni*/
        Sound opening;
        /**Bufor do kt�rego �adowany jest d�wi�k otwierania skrzyni*/
        SoundBuffer opening_buffer;

};

#endif // CHEST_H
