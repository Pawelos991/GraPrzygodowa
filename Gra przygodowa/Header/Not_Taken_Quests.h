#ifndef NOT_TAKEN_QUESTS_H
#define NOT_TAKEN_QUESTS_H

#include "Quest.h"

/**
* Klasa reprezentuje zbiór zadañ nieprzyjêtych przez gracza
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
        * Funkcja wczytuj¹ca zadania z plików i ³aduj¹ca je do wektora
        */
        void load_quests();
        /**
        * Funkcja dodaj¹ca zadanie do wektora zadañ nieprzyjêtych przez gracza
        * @param id ID zadania
        * @param Name Tytu³ zadania
        * @param Desc Opis zadania
        */
        void add_nt_quest(int id,std::string Name, std::string Desc);
        /**
        * Funkcja usuwaj¹ca nieprzyjête zadanie o podanym ID z wektora zadañ nieprzyjêtych
        * @param id ID zadania które ma zostaæ usuniête
        */
        void remove_nt_quest(int id);
        /**
        * Funkcja usuwaj¹ca wszystkie nieprzyjête zadania z wektora zadañ nieprzyjêtych
        */
        void remove_all_nt_quests();

        /**Wektor zadañ nieprzyjêtych przez gracza*/
        std::vector<Quest*> not_taken_quests;

};

#endif // NOT_TAKEN_QUESTS_H
