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
        * Konstruktor klasy ustawiający odpowiednie atrybuty zgodnie z argumentami i zastępujący znaki '_' przerwami w tytule i opisie zadania
        * @param id ID zadania
        * @param Name Tytuł zadania
        * @param Desc Opis zadania
        */
        Quest(int id,std::string Name, std::string Desc);
        /**
        * Destruktor klasy
        */
        virtual ~Quest();
        /**
        * Funkcja zwracająca tytuł zadania
        * @return Tytuł zadania
        */
        std::string getName(){return name;}
        /**
        * Funkcja zwracająca opis zadania
        * @return Opis zadania
        */
        std::string getDesc(){return description;}
        /**
        * Funkcja zwracająca ID zadania
        * @return ID zadania
        */
        int getID(){return ID;}



    private:
        /**Tytuł zadania*/
        std::string name;
        /**Opis zadania*/
        std::string description;
        /**ID zadania*/
        int ID;
};

#endif // QUEST_H
