#ifndef C_OBJECTS_H
#define C_OBJECTS_H

#include "Chest.h"
#include "Door.h"

/**
* Klasa reprezentująca grupę obiektów kolidujących z postacią gracza
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
        * Vector wskaźników na ściany znajdujące się w grupie obiektów kolidujących z postacią gracza
        */
        std::vector <Wall*> walls;
        /**
        * Vector wskaźników na skrzynie znajdujące się w grupie obiektów kolidujących z postacią gracza
        */
        std::vector <Chest*> chests;
        /**
        * Vector wskaźników na drzwi znajdujące się w grupie obiektów kolidujących z postacią gracza
        */
        std::vector <Door*> doors;
        /**
        * Funkcja służąca do otwarcia drzwi
        * @param door Wskaźnik na drzwi które mają zostać otwarte
        */
        void open_door(Door* door);

    protected:
        /**
        * Funkcja dodająca ścianę do grupy obiektów kolidujących z postacią gracza
        * @param location Ścieżka do tekstury dodawanej ściany
        * @param Position Pozycja w oknie w której ma zostać umieszczona dodawana ściana
        * @param SizeOfBox Rozmiar hitboxa ściany
        * @return Wskaźnik na dodaną do grupy ścianę
        */
        Wall* add_wall(std::string location,Vector2f Position,Vector2f SizeOfBox);
        /**
        * Funkcja dodająca skrzynię do grupy obiektów kolidujących z postacią gracza
        * @param location_closed Ścieżka do tekstury zamkniętej skrzyni
        * @param location_open Ścieżka do tekstury otwartej skrzyni
        * @param Position Pozycja w której skrzynia ma zostać umieszczona w oknie
        * @param SizeOfBox Rozmiar hitboxa skrzyni
        * @param Item_IDs ID przedmiotów które mają się znaleźć w dodawanej skrzyni
        */
        void add_chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs);
        /**
        * Funkcja dodająca drzwi do grupy obiektów kolidujących z postacią gracza
        * @param texture_location Ścieżka do tekstury drzwi
        * @param wall Wskaźnik na ścianę odpowiadającą drzwiom
        * @param key_id ID klucza potrzebnego do otwarcia drzwi
        */
        void add_door(std::string texture_location, Wall* wall, int key_id);
        /**
        * Funkcja zwalaniająca pamięć zaalokowaną przez obiekty znajdujące się w grupie
        */
        void clear_data_CO();
        /**
        * Funkcja wyświetlająca obiekty kolidujące z postacią gracza w oknie
        * @param window Okno w którym wyświetlone mają zostać obiekty
        * @param is_everyone_dead Informacja o tym czy wszyscy przeciwnicy zostali pokonani
        */
        void display_CO(RenderWindow &window, bool is_everyone_dead);

};

#endif // C_OBJECTS_H
