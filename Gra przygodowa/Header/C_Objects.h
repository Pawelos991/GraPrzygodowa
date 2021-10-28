#ifndef C_OBJECTS_H
#define C_OBJECTS_H

#include "Chest.h"
#include "Door.h"

/**
* Klasa reprezentuj¹ca grupê obiektów koliduj¹cych z postaci¹ gracza
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
        * Vector wskaŸników na œciany znajduj¹ce siê w grupie obiektów koliduj¹cych z postaci¹ gracza
        */
        std::vector <Wall*> walls;
        /**
        * Vector wskaŸników na skrzynie znajduj¹ce siê w grupie obiektów koliduj¹cych z postaci¹ gracza
        */
        std::vector <Chest*> chests;
        /**
        * Vector wskaŸników na drzwi znajduj¹ce siê w grupie obiektów koliduj¹cych z postaci¹ gracza
        */
        std::vector <Door*> doors;
        /**
        * Funkcja s³u¿¹ca do otwarcia drzwi
        * @param door WskaŸnik na drzwi które maj¹ zostaæ otwarte
        */
        void open_door(Door* door);

    protected:
        /**
        * Funkcja dodaj¹ca œcianê do grupy obiektów koliduj¹cych z postaci¹ gracza
        * @param location Œcie¿ka do tekstury dodawanej œciany
        * @param Position Pozycja w oknie w której ma zostaæ umieszczona dodawana œciana
        * @param SizeOfBox Rozmiar hitboxa œciany
        * @return WskaŸnik na dodan¹ do grupy œcianê
        */
        Wall* add_wall(std::string location,Vector2f Position,Vector2f SizeOfBox);
        /**
        * Funkcja dodaj¹ca skrzyniê do grupy obiektów koliduj¹cych z postaci¹ gracza
        * @param location_closed Œcie¿ka do tekstury zamkniêtej skrzyni
        * @param location_open Œcie¿ka do tekstury otwartej skrzyni
        * @param Position Pozycja w której skrzynia ma zostaæ umieszczona w oknie
        * @param SizeOfBox Rozmiar hitboxa skrzyni
        * @param Item_IDs ID przedmiotów które maj¹ siê znaleŸæ w dodawanej skrzyni
        */
        void add_chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs);
        /**
        * Funkcja dodaj¹ca drzwi do grupy obiektów koliduj¹cych z postaci¹ gracza
        * @param texture_location Œcie¿ka do tekstury drzwi
        * @param wall WskaŸnik na œcianê odpowiadaj¹c¹ drzwiom
        * @param key_id ID klucza potrzebnego do otwarcia drzwi
        */
        void add_door(std::string texture_location, Wall* wall, int key_id);
        /**
        * Funkcja zwalaniaj¹ca pamiêæ zaalokowan¹ przez obiekty znajduj¹ce siê w grupie
        */
        void clear_data_CO();
        /**
        * Funkcja wyœwietlaj¹ca obiekty koliduj¹ce z postaci¹ gracza w oknie
        * @param window Okno w którym wyœwietlone maj¹ zostaæ obiekty
        * @param is_everyone_dead Informacja o tym czy wszyscy przeciwnicy zostali pokonani
        */
        void display_CO(RenderWindow &window, bool is_everyone_dead);

};

#endif // C_OBJECTS_H
