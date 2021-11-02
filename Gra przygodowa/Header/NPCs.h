#ifndef NPCS_H
#define NPCS_H

#include "NPC.h"

/**
* Klasa reprezentuje listę postaci niegrywalnych
*/
class NPCs
{
    public:
        /**
        * Konstruktor klasy ustawiający wskaźnik na pierwszy element listy na nullptr
        */
        NPCs():head(nullptr){}
        /**
        * Desktruktor klasy 
        */
        virtual ~NPCs();
        /**
        * Funkcja dodająca postać niegrywalną do listy
        * @param name Nazwa typu postaci niegrywalnej
        * @param position Pozycja w której ma zostać umieszczona postać niegrywalna
        */
        void add_npc(std::string name,Vector2f position);
        /**
        * Funkcja usuwa postać niegrywalną z listy
        * @param removed Wskaźnik na postać niegrywalną która ma zostać usunięta z listy
        */
        void remove_npc(NPC* removed);
        /**
        * Funkcja usuwa wszystkie postaci niegrywalne z listy
        */
        void remove_all_npcs();

        /**
        * Funkcja odpowiadająca za utrzymanie ruchu wszystkich postaci niegrywalnych znajdujących się na liście
        * @param window Okno w którym mają być wyświetlone postaci niegrywalne
        * @param counter Licznik klatek potrzebny do poprawnego wyświetlania animacji
        * @param players_hitbox Hitbox postaci gracza
        */
        void Maintance(RenderWindow &window,int counter,RectangleShape players_hitbox);

    private:
        /**Wskaźnik na pierwszy element listy postaci niegrywalnych*/
        NPC* head;
};

#endif // NPCS_H
