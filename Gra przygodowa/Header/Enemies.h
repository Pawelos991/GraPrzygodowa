#ifndef ENEMIES_H
#define ENEMIES_H

#include "Enemy.h"
#include "Adventure_Stats.h"

/**
* Klasa reprezentuj�ca list� przeciwnik�w
*/
class Enemies
{
    public:
        /**
        * Konstruktor klasy ustawiaj�cy wska�nik na pierwszy element listy na nullptr
        */
        Enemies():head(nullptr){}
        /**
        * Destruktor klasy zwalaniaj�cy zaalokowan� pami�� poprzez usuni�cie przeciwnik�w znajduj�cych si� na li�cie
        */
        ~Enemies(){delete_all_enemies();}
        /**
        * Funkcja dodaj�ca przeciwnika do listy w oparciu o jego nazw� i pliki konfiguracyjne
        * @param Type Nazwa typu przeciwnika dodawanego do listy
        * @param position Pozycja w oknie w kt�rej ma zosta� umieszczony przeciwnik
        */
        void add_enemy(std::string Type,Vector2f position);
        /**
        * Funkcja dodaj�ca przeciwnika do listy w oparciu o istniej�cy obiekt przeciwnika
        * @param enemy Wska�nik na obiekt klasy Enemy z kt�rego kopiowane b�d� dane potrzebne do utworzenia nowego obiektu i dodania go do listy
        */
        void add_enemy(Enemy* enemy);
        /**
        * Funkcja usuwaj�ca przeciwnika z listy przeciwnik�w
        * @param deleted Wska�nik na usuwanego przeciwnika
        */
        void delete_enemy(Enemy* deleted);
        /**
        * Funkcja s�u��ca do usuni�cia wszystkich przeciwnik�w z listy
        */
        void delete_all_enemies();
        /**
        * Funkcja zwracaj�ca informacj� o tym czy wszyscy przeciwnicy z listy zostali pokonani
        * @return Informacja o tym czy wszyscy przeciwnicy z listy zostali pokonani
        */
        bool is_everyone_dead();
        /**
        * Funkcja zwracaj�ca informacj� o tym czy lista przeciwnik�w jest pusta
        * @return Informacja o tym czy lista przeciwnik�w jest pusta
        */
        bool is_it_empty();
        /**
        * Funkcja kt�ra aktualizuje statystyki przygody w oparciu o informacje o przeciwnikach znajduj�cych si� na li�cie
        * @param stats Statystyki kt�re maj� zosta� zaktualizowane
        */
        void update_adventure_stats(Adventure_Stats& stats);
        /**
        * Funkcja zwracaj�ca wska�nik na przeciwnika o podanej nazwie o ile ten znajduje si� na li�cie
        * @param name Nazwa szukanego przeciwnika
        * @return Wska�nik na znalezionego przeciwnika o ile taki zostanie znaleziony, nullptr je�li przeciwnik o podanej nazwie nie zostanie znaleziony na li�cie
        */
        Enemy* getEnemyByName(std::string name);

        /**
        * Funkcja odpowiadaj�ca za wszystko co robi� przeciwnicy. Utrzymanie ruchu przeciwnik�w
        * @param window Okno w kt�rym wy�wietlani s� przeciwnicy
        * @param counter Licznik klatek potrzebny do poprawnego wy�wietlania przeciwnik�w
        * @param players_hitbox Hitbox postaci gracza
        * @param is_player_dead Informacja o tym, czy posta� gracza jest martwa
        * @param player_missiles Lista pocisk�w postaci gracza
        * @param enemies_missiles Lista pocisk�w przeciwnik�w 
        */
        std::vector<RectangleShape*> Maintenance(RenderWindow &window, int counter, RectangleShape players_hitbox, bool is_player_dead,Missiles& player_missiles, Missiles& enemies_missiles);

    private:
        /**Wska�nik na pierwszy element listy*/
        Enemy* head;

};

#endif // ENEMIES_H
