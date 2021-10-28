#ifndef DOOR_H
#define DOOR_H

#include <Wall.h>

using namespace sf;

/**
* Klasa reprezentuj¹ca pojedyncze drzwi które mog¹ zostaæ otwarte przez gracza za pomoc¹ odpowiedniego klucza, który musi mieæ w ekwipunku
*/
class Door
{
    public:
        /**
        * Konstruktor klasy ³aduj¹cy teksturê drzwi z pliku, ustawiaj¹cy wskaŸnik na œcianê odpowiadaj¹c¹ drzwiom i ustawiaj¹cy wartoœæ atrybutu odpowiadaj¹cego za ID klucza potrzebnego do otwarcia tych drzwi
        * @param texture_location Œcie¿ka do tekstury drzwi
        * @param wall WskaŸnik na œcianê odpowiadaj¹c¹ drzwiom
        * @param key_id ID klucza potrzebnego do otwarcia drzwi
        */
        Door(std::string texture_location,Wall* wall, int key_id);
        /**
        * Destruktor klasy
        */
        ~Door(){}
        /**
        * Funkcja wyœwietlaj¹ca drzwi w oknie
        * @param window Okno w którym maj¹ zostaæ wyœwietlone drzwi
        */
        void DisplayDoor(RenderWindow& window);
        /**
        * Funkcja zwracaj¹ca ID klucza potrzebnego do otwarcia drzwi
        * @return ID klucza potrzebnego do otwarcia drzwi
        */
        int get_key_ID() { return key_ID; }
        /**
        * Funkcja zwracaj¹ca wskaŸnik na œcianê odpowiadaj¹c¹ drzwiom
        * @return WskaŸnik na œcianê odpowiadaj¹c¹ drzwiom
        */
        Wall* get_wall() { return wall; }
        /**
        * Funkcja zwracaj¹ca hitbox drzwi
        * @return Hitbox drzwi
        */
        RectangleShape get_box() { return box; }

    private:
        /**Tekstura drzwi*/
        Texture tex;
        /**Sprite drzwi s³u¿¹cy do wyœwietlenia drzwi w oknie*/
        Sprite sp;
        /**ID klucza potrzebnego do otwarcia drzwi*/
        int key_ID;
        /**WskaŸnik na œcianê odpowiadaj¹c¹ drzwiom*/
        Wall *wall;
        /**Hitbox drzwi*/
        RectangleShape box;
};

#endif // DOOR_H