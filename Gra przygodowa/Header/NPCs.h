#ifndef NPCS_H
#define NPCS_H

#include "NPC.h"

/**
* Klasa reprezentuje list� postaci niegrywalnych
*/
class NPCs
{
    public:
        /**
        * Konstruktor klasy ustawiaj�cy wska�nik na pierwszy element listy na nullptr
        */
        NPCs():head(nullptr){}
        /**
        * Desktruktor klasy 
        */
        virtual ~NPCs();
        /**
        * Funkcja dodaj�ca posta� niegrywaln� do listy
        * @param name Nazwa typu postaci niegrywalnej
        * @param position Pozycja w kt�rej ma zosta� umieszczona posta� niegrywalna
        */
        void add_npc(std::string name,Vector2f position);
        /**
        * Funkcja usuwa posta� niegrywaln� z listy
        * @param removed Wska�nik na posta� niegrywaln� kt�ra ma zosta� usuni�ta z listy
        */
        void remove_npc(NPC* removed);
        /**
        * Funkcja usuwa wszystkie postaci niegrywalne z listy
        */
        void remove_all_npcs();

        /**
        * Funkcja odpowiadaj�ca za utrzymanie ruchu wszystkich postaci niegrywalnych znajduj�cych si� na li�cie
        * @param window Okno w kt�rym maj� by� wy�wietlone postaci niegrywalne
        * @param counter Licznik klatek potrzebny do poprawnego wy�wietlania animacji
        * @param players_hitbox Hitbox postaci gracza
        */
        void Maintance(RenderWindow &window,int counter,RectangleShape players_hitbox);

    private:
        /**Wska�nik na pierwszy element listy postaci niegrywalnych*/
        NPC* head;
};

#endif // NPCS_H
