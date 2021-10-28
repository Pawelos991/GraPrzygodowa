#ifndef C_OBJECTS_H
#define C_OBJECTS_H

#include "Chest.h"
#include "Door.h"

/**
* Klasa reprezentuj�ca grup� obiekt�w koliduj�cych z postaci� gracza
*/
class C_Objects
{
    public:
        /**
        * Konstruktor klasy
        */
        C_Objects();
        /**
        * Destruktor klasy
        */
        virtual ~C_Objects(){}
        /**
        * Vector wska�nik�w na �ciany znajduj�ce si� w grupie obiekt�w koliduj�cych z postaci� gracza
        */
        std::vector <Wall*> walls;
        /**
        * Vector wska�nik�w na skrzynie znajduj�ce si� w grupie obiekt�w koliduj�cych z postaci� gracza
        */
        std::vector <Chest*> chests;
        /**
        * Vector wska�nik�w na drzwi znajduj�ce si� w grupie obiekt�w koliduj�cych z postaci� gracza
        */
        std::vector <Door*> doors;
        /**
        * Funkcja s�u��ca do otwarcia drzwi
        * @param door Wska�nik na drzwi kt�re maj� zosta� otwarte
        */
        void open_door(Door* door);

    protected:
        /**
        * Funkcja dodaj�ca �cian� do grupy obiekt�w koliduj�cych z postaci� gracza
        * @param location �cie�ka do tekstury dodawanej �ciany
        * @param Position Pozycja w oknie w kt�rej ma zosta� umieszczona dodawana �ciana
        * @param SizeOfBox Rozmiar hitboxa �ciany
        * @return Wska�nik na dodan� do grupy �cian�
        */
        Wall* add_wall(std::string location,Vector2f Position,Vector2f SizeOfBox);
        /**
        * Funkcja dodaj�ca skrzyni� do grupy obiekt�w koliduj�cych z postaci� gracza
        * @param location_closed �cie�ka do tekstury zamkni�tej skrzyni
        * @param location_open �cie�ka do tekstury otwartej skrzyni
        * @param Position Pozycja w kt�rej skrzynia ma zosta� umieszczona w oknie
        * @param SizeOfBox Rozmiar hitboxa skrzyni
        * @param Item_IDs ID przedmiot�w kt�re maj� si� znale�� w dodawanej skrzyni
        */
        void add_chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs);
        /**
        * Funkcja dodaj�ca drzwi do grupy obiekt�w koliduj�cych z postaci� gracza
        * @param texture_location �cie�ka do tekstury drzwi
        * @param wall Wska�nik na �cian� odpowiadaj�c� drzwiom
        * @param key_id ID klucza potrzebnego do otwarcia drzwi
        */
        void add_door(std::string texture_location, Wall* wall, int key_id);
        /**
        * Funkcja zwalaniaj�ca pami�� zaalokowan� przez obiekty znajduj�ce si� w grupie
        */
        void clear_data_CO();
        /**
        * Funkcja wy�wietlaj�ca obiekty koliduj�ce z postaci� gracza w oknie
        * @param window Okno w kt�rym wy�wietlone maj� zosta� obiekty
        * @param is_everyone_dead Informacja o tym czy wszyscy przeciwnicy zostali pokonani
        */
        void display_CO(RenderWindow &window, bool is_everyone_dead);

};

#endif // C_OBJECTS_H
