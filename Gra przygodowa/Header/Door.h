#ifndef DOOR_H
#define DOOR_H

#include <Wall.h>

using namespace sf;

/**
* Klasa reprezentuj�ca pojedyncze drzwi kt�re mog� zosta� otwarte przez gracza za pomoc� odpowiedniego klucza, kt�ry musi mie� w ekwipunku
*/
class Door
{
    public:
        /**
        * Konstruktor klasy �aduj�cy tekstur� drzwi z pliku, ustawiaj�cy wska�nik na �cian� odpowiadaj�c� drzwiom i ustawiaj�cy warto�� atrybutu odpowiadaj�cego za ID klucza potrzebnego do otwarcia tych drzwi
        * @param texture_location �cie�ka do tekstury drzwi
        * @param wall Wska�nik na �cian� odpowiadaj�c� drzwiom
        * @param key_id ID klucza potrzebnego do otwarcia drzwi
        */
        Door(std::string texture_location,Wall* wall, int key_id);
        /**
        * Destruktor klasy
        */
        ~Door(){}
        /**
        * Funkcja wy�wietlaj�ca drzwi w oknie
        * @param window Okno w kt�rym maj� zosta� wy�wietlone drzwi
        */
        void DisplayDoor(RenderWindow& window);
        /**
        * Funkcja zwracaj�ca ID klucza potrzebnego do otwarcia drzwi
        * @return ID klucza potrzebnego do otwarcia drzwi
        */
        int get_key_ID() { return key_ID; }
        /**
        * Funkcja zwracaj�ca wska�nik na �cian� odpowiadaj�c� drzwiom
        * @return Wska�nik na �cian� odpowiadaj�c� drzwiom
        */
        Wall* get_wall() { return wall; }
        /**
        * Funkcja zwracaj�ca hitbox drzwi
        * @return Hitbox drzwi
        */
        RectangleShape get_box() { return box; }

    private:
        /**Tekstura drzwi*/
        Texture tex;
        /**Sprite drzwi s�u��cy do wy�wietlenia drzwi w oknie*/
        Sprite sp;
        /**ID klucza potrzebnego do otwarcia drzwi*/
        int key_ID;
        /**Wska�nik na �cian� odpowiadaj�c� drzwiom*/
        Wall *wall;
        /**Hitbox drzwi*/
        RectangleShape box;
};

#endif // DOOR_H