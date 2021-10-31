#ifndef NPCS_H
#define NPCS_H

#include "NPC.h"

/**
* Klasa reprezentuje listê postaci niegrywalnych
*/
class NPCs
{
    public:
        /**
        * Konstruktor klasy ustawiaj¹cy wskaŸnik na pierwszy element listy na nullptr
        */
        NPCs():head(nullptr){}
        /**
        * Desktruktor klasy 
        */
        virtual ~NPCs();
        /**
        * Funkcja dodaj¹ca postaæ niegrywaln¹ do listy
        * @param name Nazwa typu postaci niegrywalnej
        * @param position Pozycja w której ma zostaæ umieszczona postaæ niegrywalna
        */
        void add_npc(std::string name,Vector2f position);
        /**
        * Funkcja usuwa postaæ niegrywaln¹ z listy
        * @param removed WskaŸnik na postaæ niegrywaln¹ która ma zostaæ usuniêta z listy
        */
        void remove_npc(NPC* removed);
        /**
        * Funkcja usuwa wszystkie postaci niegrywalne z listy
        */
        void remove_all_npcs();

        /**
        * Funkcja odpowiadaj¹ca za utrzymanie ruchu wszystkich postaci niegrywalnych znajduj¹cych siê na liœcie
        * @param window Okno w którym maj¹ byæ wyœwietlone postaci niegrywalne
        * @param counter Licznik klatek potrzebny do poprawnego wyœwietlania animacji
        * @param players_hitbox Hitbox postaci gracza
        */
        void Maintance(RenderWindow &window,int counter,RectangleShape players_hitbox);

    private:
        /**WskaŸnik na pierwszy element listy postaci niegrywalnych*/
        NPC* head;
};

#endif // NPCS_H
