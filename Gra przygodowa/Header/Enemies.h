#ifndef ENEMIES_H
#define ENEMIES_H

#include "Enemy.h"
#include "Adventure_Stats.h"

/**
* Klasa reprezentująca listę przeciwników
*/
class Enemies
{
    public:
        /**
        * Konstruktor klasy ustawiający wskaźnik na pierwszy element listy na nullptr
        */
        Enemies():head(nullptr){}
        /**
        * Destruktor klasy zwalaniający zaalokowaną pamięć poprzez usunięcie przeciwników znajdujących się na liście
        */
        ~Enemies(){delete_all_enemies();}
        /**
        * Funkcja dodająca przeciwnika do listy w oparciu o jego nazwę i pliki konfiguracyjne
        * @param Type Nazwa typu przeciwnika dodawanego do listy
        * @param position Pozycja w oknie w której ma zostać umieszczony przeciwnik
        */
        void add_enemy(std::string Type,Vector2f position);
        /**
        * Funkcja dodająca przeciwnika do listy w oparciu o istniejący obiekt przeciwnika
        * @param enemy Wskaźnik na obiekt klasy Enemy z którego kopiowane będą dane potrzebne do utworzenia nowego obiektu i dodania go do listy
        */
        void add_enemy(Enemy* enemy);
        /**
        * Funkcja usuwająca przeciwnika z listy przeciwników
        * @param deleted Wskaźnik na usuwanego przeciwnika
        */
        void delete_enemy(Enemy* deleted);
        /**
        * Funkcja służąca do usunięcia wszystkich przeciwników z listy
        */
        void delete_all_enemies();
        /**
        * Funkcja zwracająca informację o tym czy wszyscy przeciwnicy z listy zostali pokonani
        * @return Informacja o tym czy wszyscy przeciwnicy z listy zostali pokonani
        */
        bool is_everyone_dead();
        /**
        * Funkcja zwracająca informację o tym czy lista przeciwników jest pusta
        * @return Informacja o tym czy lista przeciwników jest pusta
        */
        bool is_it_empty();
        /**
        * Funkcja która aktualizuje statystyki przygody w oparciu o informacje o przeciwnikach znajdujących się na liście
        * @param stats Statystyki które mają zostać zaktualizowane
        */
        void update_adventure_stats(Adventure_Stats& stats);
        /**
        * Funkcja zwracająca wskaźnik na przeciwnika o podanej nazwie o ile ten znajduje się na liście
        * @param name Nazwa szukanego przeciwnika
        * @return Wskaźnik na znalezionego przeciwnika o ile taki zostanie znaleziony, nullptr jeśli przeciwnik o podanej nazwie nie zostanie znaleziony na liście
        */
        Enemy* getEnemyByName(std::string name);

        /**
        * Funkcja odpowiadająca za wszystko co robią przeciwnicy. Utrzymanie ruchu przeciwników
        * @param window Okno w którym wyświetlani są przeciwnicy
        * @param counter Licznik klatek potrzebny do poprawnego wyświetlania przeciwników
        * @param players_hitbox Hitbox postaci gracza
        * @param is_player_dead Informacja o tym, czy postać gracza jest martwa
        * @param player_missiles Lista pocisków postaci gracza
        * @param enemies_missiles Lista pocisków przeciwników 
        */
        std::vector<RectangleShape*> Maintenance(RenderWindow &window, int counter, RectangleShape players_hitbox, bool is_player_dead,Missiles& player_missiles, Missiles& enemies_missiles);

    private:
        /**Wskaźnik na pierwszy element listy*/
        Enemy* head;

};

#endif // ENEMIES_H
