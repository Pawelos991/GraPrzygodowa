#ifndef NOT_TAKEN_QUESTS_H
#define NOT_TAKEN_QUESTS_H

#include "Quest.h"

/**
* Klasa reprezentuje zbi�r zada� nieprzyj�tych przez gracza
*/
class Not_Taken_Quests
{
    public:
        /**
        * Konstruktor klasy
        */
        Not_Taken_Quests();
        /**
        * Destruktor klasy
        */
        virtual ~Not_Taken_Quests();

    protected: 
        /**
        * Funkcja wczytuj�ca zadania z plik�w i �aduj�ca je do wektora
        */
        void load_quests();
        /**
        * Funkcja dodaj�ca zadanie do wektora zada� nieprzyj�tych przez gracza
        * @param id ID zadania
        * @param Name Tytu� zadania
        * @param Desc Opis zadania
        */
        void add_nt_quest(int id,std::string Name, std::string Desc);
        /**
        * Funkcja usuwaj�ca nieprzyj�te zadanie o podanym ID z wektora zada� nieprzyj�tych
        * @param id ID zadania kt�re ma zosta� usuni�te
        */
        void remove_nt_quest(int id);
        /**
        * Funkcja usuwaj�ca wszystkie nieprzyj�te zadania z wektora zada� nieprzyj�tych
        */
        void remove_all_nt_quests();

        /**Wektor zada� nieprzyj�tych przez gracza*/
        std::vector<Quest*> not_taken_quests;

};

#endif // NOT_TAKEN_QUESTS_H
