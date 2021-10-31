#ifndef NPC_H
#define NPC_H

#include "Items.h"
#include "Character.h"
#include "Quest.h"

/**
* Klasa reprezentuje pojedyncz� posta� niegrywaln�, dziedziczy prywatnie po klasie Character
*/
class NPC : private Character
{
    public:
        /**
        * Konstruktor klasy �aduj�cy wszystkie potrzebne informacje z plik�w
        * @param type Nazwa typu NPC po kt�rym wyszukiwany jest w pliku konfiguracyjnym
        * @param position Pozycja w kt�rej ma zosta� umieszczony NPC
        */
        NPC(std::string type,Vector2f position);
        /**
        * Destruktor klasy
        */
        virtual ~NPC();
        /**
        * Funkcja ustawiaj�ca wska�nik na inny obiekt tej klasy zgodnie z argumentem
        * @param pnext Wska�nik zgodnie z kt�rym ma zosta� ustawiony wska�nik obiektu
        */
        void setNext(NPC *pnext){next=pnext;}
        /**
        * Funkcja zwracaj�ca wska�nik na inny obiekt tej klasy
        * @return Wska�nik na inny obiekt tej klasy
        */
        NPC* getNext(){return next;}

        /**
        * Funkcja odpowiadaj�ca za utrzymanie ruchu postaci niegrywalnej
        * @param window Okno w kt�rym wy�wietlana jest posta� niegrywalna
        * @param counter Licznik klatek potrzebny do poprawnego wy�wietlania animacji
        * @param players_hitbox Hitbox postaci gracza potrzebny do ewentualnego wy�wietlenia tekstu postaci niegrywalnej
        */
        void Maintance(RenderWindow &window, int counter, RectangleShape players_hitbox);
        /**
        * Funkcja zwalniaj�ca pami�� zaalokowan� przez posta� niegrywaln�
        */
        void Empty_Memory();

    private:
        /**Wska�nik na inny obiekt tej klasy*/
        NPC* next;
        /**Czcionka tekstu postaci niegrywalnej*/
        Font font;
        /**Tekst postaci niegrywalnej*/
        Text text;
        /**Tekstura dymku rozmowy*/
        Texture cloudTex;
        /**Sprite dymku rozmowy potrzebny do jego wy�wietlenia*/
        Sprite Cloud;
        /**Hitbox postaci niegrywalnej*/
        RectangleShape hitbox;
};

#endif // NPC_H
