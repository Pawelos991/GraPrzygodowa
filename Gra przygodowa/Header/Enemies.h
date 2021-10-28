#ifndef ENEMIES_H
#define ENEMIES_H

#include "Enemy.h"
#include "Adventure_Stats.h"

/**
* Klasa reprezentuj¹ca listê przeciwników
*/
class Enemies
{
    public:
        /**
        * Konstruktor klasy ustawiaj¹cy wskaŸnik na pierwszy element listy na nullptr
        */
        Enemies():head(nullptr){}
        /**
        * Destruktor klasy zwalaniaj¹cy zaalokowan¹ pamiêæ poprzez usuniêcie przeciwników znajduj¹cych siê na liœcie
        */
        ~Enemies(){delete_all_enemies();}
        /**
        * Funkcja dodaj¹ca przeciwnika do listy w oparciu o jego nazwê i pliki konfiguracyjne
        * @param Type Nazwa typu przeciwnika dodawanego do listy
        * @param position Pozycja w oknie w której ma zostaæ umieszczony przeciwnik
        */
        void add_enemy(std::string Type,Vector2f position);
        /**
        * Funkcja dodaj¹ca przeciwnika do listy w oparciu o istniej¹cy obiekt przeciwnika
        * @param enemy WskaŸnik na obiekt klasy Enemy z którego kopiowane bêd¹ dane potrzebne do utworzenia nowego obiektu i dodania go do listy
        */
        void add_enemy(Enemy* enemy);
        /**
        * Funkcja usuwaj¹ca przeciwnika z listy przeciwników
        * @param deleted WskaŸnik na usuwanego przeciwnika
        */
        void delete_enemy(Enemy* deleted);
        /**
        * Funkcja s³u¿¹ca do usuniêcia wszystkich przeciwników z listy
        */
        void delete_all_enemies();
        /**
        * Funkcja zwracaj¹ca informacjê o tym czy wszyscy przeciwnicy z listy zostali pokonani
        * @return Informacja o tym czy wszyscy przeciwnicy z listy zostali pokonani
        */
        bool is_everyone_dead();
        /**
        * Funkcja zwracaj¹ca informacjê o tym czy lista przeciwników jest pusta
        * @return Informacja o tym czy lista przeciwników jest pusta
        */
        bool is_it_empty();
        /**
        * Funkcja która aktualizuje statystyki przygody w oparciu o informacje o przeciwnikach znajduj¹cych siê na liœcie
        * @param stats Statystyki które maj¹ zostaæ zaktualizowane
        */
        void update_adventure_stats(Adventure_Stats& stats);
        /**
        * Funkcja zwracaj¹ca wskaŸnik na przeciwnika o podanej nazwie o ile ten znajduje siê na liœcie
        * @param name Nazwa szukanego przeciwnika
        * @return WskaŸnik na znalezionego przeciwnika o ile taki zostanie znaleziony, nullptr jeœli przeciwnik o podanej nazwie nie zostanie znaleziony na liœcie
        */
        Enemy* getEnemyByName(std::string name);

        /**
        * Funkcja odpowiadaj¹ca za wszystko co robi¹ przeciwnicy. Utrzymanie ruchu przeciwników
        * @param window Okno w którym wyœwietlani s¹ przeciwnicy
        * @param counter Licznik klatek potrzebny do poprawnego wyœwietlania przeciwników
        * @param players_hitbox Hitbox postaci gracza
        * @param is_player_dead Informacja o tym, czy postaæ gracza jest martwa
        * @param player_missiles Lista pocisków postaci gracza
        * @param enemies_missiles Lista pocisków przeciwników 
        */
        std::vector<RectangleShape*> Maintenance(RenderWindow &window, int counter, RectangleShape players_hitbox, bool is_player_dead,Missiles& player_missiles, Missiles& enemies_missiles);

    private:
        /**WskaŸnik na pierwszy element listy*/
        Enemy* head;

};

#endif // ENEMIES_H
