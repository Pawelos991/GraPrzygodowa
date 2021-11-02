#ifndef NPC_H
#define NPC_H

#include "Items.h"
#include "Character.h"
#include "Quest.h"

/**
* Klasa reprezentuje pojedynczą postać niegrywalną, dziedziczy prywatnie po klasie Character
*/
class NPC : private Character
{
    public:
        /**
        * Konstruktor klasy ładujący wszystkie potrzebne informacje z plików
        * @param type Nazwa typu NPC po którym wyszukiwany jest w pliku konfiguracyjnym
        * @param position Pozycja w której ma zostać umieszczony NPC
        */
        NPC(std::string type,Vector2f position);
        /**
        * Destruktor klasy
        */
        virtual ~NPC();
        /**
        * Funkcja ustawiająca wskaźnik na inny obiekt tej klasy zgodnie z argumentem
        * @param pnext Wskaźnik zgodnie z którym ma zostać ustawiony wskaźnik obiektu
        */
        void setNext(NPC *pnext){next=pnext;}
        /**
        * Funkcja zwracająca wskaźnik na inny obiekt tej klasy
        * @return Wskaźnik na inny obiekt tej klasy
        */
        NPC* getNext(){return next;}

        /**
        * Funkcja odpowiadająca za utrzymanie ruchu postaci niegrywalnej
        * @param window Okno w którym wyświetlana jest postać niegrywalna
        * @param counter Licznik klatek potrzebny do poprawnego wyświetlania animacji
        * @param players_hitbox Hitbox postaci gracza potrzebny do ewentualnego wyświetlenia tekstu postaci niegrywalnej
        */
        void Maintance(RenderWindow &window, int counter, RectangleShape players_hitbox);
        /**
        * Funkcja zwalniająca pamięć zaalokowaną przez postać niegrywalną
        */
        void Empty_Memory();

    private:
        /**Wskaźnik na inny obiekt tej klasy*/
        NPC* next;
        /**Czcionka tekstu postaci niegrywalnej*/
        Font font;
        /**Tekst postaci niegrywalnej*/
        Text text;
        /**Tekstura dymku rozmowy*/
        Texture cloudTex;
        /**Sprite dymku rozmowy potrzebny do jego wyświetlenia*/
        Sprite Cloud;
        /**Hitbox postaci niegrywalnej*/
        RectangleShape hitbox;
};

#endif // NPC_H
