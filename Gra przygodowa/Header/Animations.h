#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "Animation.h"

/**
*Klasa odpowiadająca za listę animacji danego obiektu lub postaci
*/
class Animations
{
    public:
        /**
        *Konstruktor klasy ustawiający wskaźnik na pierwszy element na nullptr
        */
        Animations():head(nullptr){}
        /**
        *Destruktor klasy
        */
        virtual ~Animations();
        /**
        *Funkcja dodająca animację o podanej nazwie do listy animacji
        *@param Name Nazwa animacji która ma zostać dodana do listy
        *@param ID ID animacji która ma zostać dodana do listy
        *@param Frames Liczba klatek animacji która ma zostać dodana do listy
        *@param Delay Odstęp miedzy kolejnymi klatkami animacji która ma zostać dodana do listy
        *@return Wskaźnik na animację dodaną do listy
        */
        Animation* add_animation(std::string Name, int ID,int Frames,float Delay);
        /**
        *Funkcja dodająca do listy kopię animacji znajdującej się pod adresem wskazywanym przez wskaźnik
        *@param added Wskaźnik na animację której kopia ma zostać dodana do listy
        */
        void add_animation(Animation* added);
        /**
        *Funkcja która usuwa z pamięci wszystkie animacji aby uniknąć wycieków pamięci
        */
        void delete_all_animations();
        /**
        *Funkcja która zwraca wskaźnik na animację o podanym ID o ile taka znajduje się w liście
        *@param ID ID szukanej animacji
        *@return Wskaźnik na animację jeśli jest taka w liście, nullptr jeśli takiej nie ma
        */
        Animation* find_animation(int ID);

        /**
        *Funkcja ładująca animacje do listy w oparciu o plik konfiguracyjny 
        *@param adress Ścieżka do pliku konfiguracyjnego zawierającego informacje potrzebne do załadowania animacji
        */
        void LoadAnimationsFromFile(std::string adress);

    private:
    /**Wskaźnik na pierwszy element listy*/
        Animation *head=nullptr;
};

#endif // ANIMATIONS_H
