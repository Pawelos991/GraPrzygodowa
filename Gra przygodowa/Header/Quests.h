#ifndef QUESTS_H
#define QUESTS_H

#include "Taken_Quests.h"
#include "Not_Taken_Quests.h"

/**
* Klasa reprezentuje zbiór zadań z podziałem na przyjęte i nieprzyjęte przez postać gracza, dziedziczy po klasach Taken_Quests oraz Not_Taken_Quests
*/
class Quests: protected Taken_Quests, protected Not_Taken_Quests
{
    public:
        /**
        * Konstruktor klasy
        */
        Quests();
        /**
        * Destruktor klasy
        */
        virtual ~Quests();

    protected:
        /**
        * Funkcja przygotowująca zadania poprzez wczytanie z plików zadań nieprzyjętych i załadowanie ich do wektora zadań nieprzyjętych przez postać gracza
        */
        void prepare_quests();
        /**
        * Funkcja dodająca zadanie o podanym ID do zadań przyjętych przez gracza poprzez skopiowanie go z wektora zadań nieprzyjętych przez postać gracza
        * @param id ID zadania które ma zostać dodane do zadań przyjętych
        */
        void add_t_quest(int id);
        /**
        * Funkcja wyświetla obecne zadania w oknie
        * @param window Okno w którym mają zostać wyświetlone aktualne zadania
        */
        void Display_quests(RenderWindow &window);
        /**
        * Funkcja dodaje zadanie do listy zadań przyjętych i wyświetla na ekranie informację o tym, że zostało ono przyjęte przez postać gracza
        * @param id ID dodawanego zadania
        * @param window Okno w którym wyświetlone jest powiadomienie o dodaniu nowego zadania do przyjętych zadań
        * @param counter Licznik klatek potrzebny do poprawnego wyświetlenia powiadomienia o dodaniu nowego zadania do przyjętych zadań
        */
        void add_t_quest_display(int id, RenderWindow& window, int counter);

    private:
        /**Tekstura okienka w którym wyświetlane są przyjęte zadania*/
        Texture tex;
        /**Sprite okienka w którym wyświetlane są przyjęte zadania*/
        Sprite sp;
};

#endif // QUESTS_H
