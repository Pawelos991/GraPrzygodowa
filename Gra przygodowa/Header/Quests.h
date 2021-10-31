#ifndef QUESTS_H
#define QUESTS_H

#include "Taken_Quests.h"
#include "Not_Taken_Quests.h"

/**
* Klasa reprezentuje zbi�r zada� z podzia�em na przyj�te i nieprzyj�te przez posta� gracza, dziedziczy po klasach Taken_Quests oraz Not_Taken_Quests
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
        * Funkcja przygotowuj�ca zadania poprzez wczytanie z plik�w zada� nieprzyj�tych i za�adowanie ich do wektora zada� nieprzyj�tych przez posta� gracza
        */
        void prepare_quests();
        /**
        * Funkcja dodaj�ca zadanie o podanym ID do zada� przyj�tych przez gracza poprzez skopiowanie go z wektora zada� nieprzyj�tych przez posta� gracza
        * @param id ID zadania kt�re ma zosta� dodane do zada� przyj�tych
        */
        void add_t_quest(int id);
        /**
        * Funkcja wy�wietla obecne zadania w oknie
        * @param window Okno w kt�rym maj� zosta� wy�wietlone aktualne zadania
        */
        void Display_quests(RenderWindow &window);
        /**
        * Funkcja dodaje zadanie do listy zada� przyj�tych i wy�wietla na ekranie informacj� o tym, �e zosta�o ono przyj�te przez posta� gracza
        * @param id ID dodawanego zadania
        * @param window Okno w kt�rym wy�wietlone jest powiadomienie o dodaniu nowego zadania do przyj�tych zada�
        * @param counter Licznik klatek potrzebny do poprawnego wy�wietlenia powiadomienia o dodaniu nowego zadania do przyj�tych zada�
        */
        void add_t_quest_display(int id, RenderWindow& window, int counter);

    private:
        /**Tekstura okienka w kt�rym wy�wietlane s� przyj�te zadania*/
        Texture tex;
        /**Sprite okienka w kt�rym wy�wietlane s� przyj�te zadania*/
        Sprite sp;
};

#endif // QUESTS_H
