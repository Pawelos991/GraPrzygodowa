#ifndef NOT_TAKEN_QUESTS_H
#define NOT_TAKEN_QUESTS_H

#include "Quest.h"

/**
* Klasa reprezentuje zbiór zadań nieprzyjętych przez gracza
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
        * Funkcja wczytująca zadania z plików i ładująca je do wektora
        */
        void load_quests();
        /**
        * Funkcja dodająca zadanie do wektora zadań nieprzyjętych przez gracza
        * @param id ID zadania
        * @param Name Tytuł zadania
        * @param Desc Opis zadania
        */
        void add_nt_quest(int id,std::string Name, std::string Desc);
        /**
        * Funkcja usuwająca nieprzyjęte zadanie o podanym ID z wektora zadań nieprzyjętych
        * @param id ID zadania które ma zostać usunięte
        */
        void remove_nt_quest(int id);
        /**
        * Funkcja usuwająca wszystkie nieprzyjęte zadania z wektora zadań nieprzyjętych
        */
        void remove_all_nt_quests();

        /**Wektor zadań nieprzyjętych przez gracza*/
        std::vector<Quest*> not_taken_quests;

};

#endif // NOT_TAKEN_QUESTS_H
