#ifndef QUESTS_H
#define QUESTS_H

#include "Taken_Quests.h"
#include "Not_Taken_Quests.h"

/**
* Klasa reprezentuje zbiór zadañ z podzia³em na przyjête i nieprzyjête przez postaæ gracza, dziedziczy po klasach Taken_Quests oraz Not_Taken_Quests
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
        * Funkcja przygotowuj¹ca zadania poprzez wczytanie z plików zadañ nieprzyjêtych i za³adowanie ich do wektora zadañ nieprzyjêtych przez postaæ gracza
        */
        void prepare_quests();
        /**
        * Funkcja dodaj¹ca zadanie o podanym ID do zadañ przyjêtych przez gracza poprzez skopiowanie go z wektora zadañ nieprzyjêtych przez postaæ gracza
        * @param id ID zadania które ma zostaæ dodane do zadañ przyjêtych
        */
        void add_t_quest(int id);
        /**
        * Funkcja wyœwietla obecne zadania w oknie
        * @param window Okno w którym maj¹ zostaæ wyœwietlone aktualne zadania
        */
        void Display_quests(RenderWindow &window);
        /**
        * Funkcja dodaje zadanie do listy zadañ przyjêtych i wyœwietla na ekranie informacjê o tym, ¿e zosta³o ono przyjête przez postaæ gracza
        * @param id ID dodawanego zadania
        * @param window Okno w którym wyœwietlone jest powiadomienie o dodaniu nowego zadania do przyjêtych zadañ
        * @param counter Licznik klatek potrzebny do poprawnego wyœwietlenia powiadomienia o dodaniu nowego zadania do przyjêtych zadañ
        */
        void add_t_quest_display(int id, RenderWindow& window, int counter);

    private:
        /**Tekstura okienka w którym wyœwietlane s¹ przyjête zadania*/
        Texture tex;
        /**Sprite okienka w którym wyœwietlane s¹ przyjête zadania*/
        Sprite sp;
};

#endif // QUESTS_H
