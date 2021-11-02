#ifndef DOOR_H
#define DOOR_H

#include <Wall.h>

using namespace sf;

/**
* Klasa reprezentująca pojedyncze drzwi które mogą zostać otwarte przez gracza za pomocą odpowiedniego klucza, który musi mieć w ekwipunku
*/
class Door
{
    public:
        /**
        * Konstruktor klasy ładujący teksturę drzwi z pliku, ustawiający wskaźnik na ścianę odpowiadającą drzwiom i ustawiający wartość atrybutu odpowiadającego za ID klucza potrzebnego do otwarcia tych drzwi
        * @param texture_location Ścieżka do tekstury drzwi
        * @param wall Wskaźnik na ścianę odpowiadającą drzwiom
        * @param key_id ID klucza potrzebnego do otwarcia drzwi
        */
        Door(std::string texture_location,Wall* wall, int key_id);
        /**
        * Destruktor klasy
        */
        ~Door(){}
        /**
        * Funkcja wyświetlająca drzwi w oknie
        * @param window Okno w którym mają zostać wyświetlone drzwi
        */
        void DisplayDoor(RenderWindow& window);
        /**
        * Funkcja zwracająca ID klucza potrzebnego do otwarcia drzwi
        * @return ID klucza potrzebnego do otwarcia drzwi
        */
        int get_key_ID() { return key_ID; }
        /**
        * Funkcja zwracająca wskaźnik na ścianę odpowiadającą drzwiom
        * @return Wskaźnik na ścianę odpowiadającą drzwiom
        */
        Wall* get_wall() { return wall; }
        /**
        * Funkcja zwracająca hitbox drzwi
        * @return Hitbox drzwi
        */
        RectangleShape get_box() { return box; }

    private:
        /**Tekstura drzwi*/
        Texture tex;
        /**Sprite drzwi służący do wyświetlenia drzwi w oknie*/
        Sprite sp;
        /**ID klucza potrzebnego do otwarcia drzwi*/
        int key_ID;
        /**Wskaźnik na ścianę odpowiadającą drzwiom*/
        Wall *wall;
        /**Hitbox drzwi*/
        RectangleShape box;
};

#endif // DOOR_H