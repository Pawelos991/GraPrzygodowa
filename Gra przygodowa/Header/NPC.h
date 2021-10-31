#ifndef NPC_H
#define NPC_H

#include "Items.h"
#include "Character.h"
#include "Quest.h"

/**
* Klasa reprezentuje pojedyncz¹ postaæ niegrywaln¹, dziedziczy prywatnie po klasie Character
*/
class NPC : private Character
{
    public:
        /**
        * Konstruktor klasy ³aduj¹cy wszystkie potrzebne informacje z plików
        * @param type Nazwa typu NPC po którym wyszukiwany jest w pliku konfiguracyjnym
        * @param position Pozycja w której ma zostaæ umieszczony NPC
        */
        NPC(std::string type,Vector2f position);
        /**
        * Destruktor klasy
        */
        virtual ~NPC();
        /**
        * Funkcja ustawiaj¹ca wskaŸnik na inny obiekt tej klasy zgodnie z argumentem
        * @param pnext WskaŸnik zgodnie z którym ma zostaæ ustawiony wskaŸnik obiektu
        */
        void setNext(NPC *pnext){next=pnext;}
        /**
        * Funkcja zwracaj¹ca wskaŸnik na inny obiekt tej klasy
        * @return WskaŸnik na inny obiekt tej klasy
        */
        NPC* getNext(){return next;}

        /**
        * Funkcja odpowiadaj¹ca za utrzymanie ruchu postaci niegrywalnej
        * @param window Okno w którym wyœwietlana jest postaæ niegrywalna
        * @param counter Licznik klatek potrzebny do poprawnego wyœwietlania animacji
        * @param players_hitbox Hitbox postaci gracza potrzebny do ewentualnego wyœwietlenia tekstu postaci niegrywalnej
        */
        void Maintance(RenderWindow &window, int counter, RectangleShape players_hitbox);
        /**
        * Funkcja zwalniaj¹ca pamiêæ zaalokowan¹ przez postaæ niegrywaln¹
        */
        void Empty_Memory();

    private:
        /**WskaŸnik na inny obiekt tej klasy*/
        NPC* next;
        /**Czcionka tekstu postaci niegrywalnej*/
        Font font;
        /**Tekst postaci niegrywalnej*/
        Text text;
        /**Tekstura dymku rozmowy*/
        Texture cloudTex;
        /**Sprite dymku rozmowy potrzebny do jego wyœwietlenia*/
        Sprite Cloud;
        /**Hitbox postaci niegrywalnej*/
        RectangleShape hitbox;
};

#endif // NPC_H
