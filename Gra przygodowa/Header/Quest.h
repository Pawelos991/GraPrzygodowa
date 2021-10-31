#ifndef QUEST_H
#define QUEST_H

#include "Items.h"

/**
* Klasa reprezentuje pojedyncze zadanie
*/
class Quest
{
    public:
        /**
        * Konstruktor klasy ustawiaj�cy odpowiednie atrybuty zgodnie z argumentami i zast�puj�cy znaki '_' przerwami w tytule i opisie zadania
        * @param id ID zadania
        * @param Name Tytu� zadania
        * @param Desc Opis zadania
        */
        Quest(int id,std::string Name, std::string Desc);
        /**
        * Destruktor klasy
        */
        virtual ~Quest();
        /**
        * Funkcja zwracaj�ca tytu� zadania
        * @return Tytu� zadania
        */
        std::string getName(){return name;}
        /**
        * Funkcja zwracaj�ca opis zadania
        * @return Opis zadania
        */
        std::string getDesc(){return description;}
        /**
        * Funkcja zwracaj�ca ID zadania
        * @return ID zadania
        */
        int getID(){return ID;}



    private:
        /**Tytu� zadania*/
        std::string name;
        /**Opis zadania*/
        std::string description;
        /**ID zadania*/
        int ID;
};

#endif // QUEST_H
