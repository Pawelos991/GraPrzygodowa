#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Missiles.h"
#include <math.h>

/**
*Klasa reprezentująca przeciwnika w grze dziedziczy prywatnie po klasie Character
*/
class Enemy : private Character
{
    public:
        /**
        *Konstruktor klasy ładująca wszystkie informacje z plików konfiguracyjnych
        *@param Type Nazwa rodzaju przeciwnika
        *@param position Pozycja na ekranie w której po utworzeniu ma się pojawić przeciwnik 
        */
        Enemy(std::string Type,Vector2f position);
        /**
        *Konstruktor klasy tworzący obiekt w oparciu o inny obiekt kopiując z niego wszystkie potrzebne dane
        *@param base Wskaźnik na obiekt na podstawie którego stworzony ma zostać nowy obiekt klasy
        *@param position Pozycja na ekranie w której po utworzeniu ma się pojawić przeciwnik
        */
        Enemy(Enemy* base, Vector2f position);
        /**
        *Destruktor klasy
        */
        virtual ~Enemy();
        /**
        *Funkcja odpowiadająca za wszystko co robi przeciwnik typu bliskiego
        *@param window Okno w którym wyświetlany jest przeciwnik
        *@param counter Licznik klatek potrzebny do poprawnego wyświetlania animacji
        *@param players_hitbox Hitbox gracza potrzebny do odpowiedniej nawigacji oraz ewentualnego wykonania ataku
        *@param is_player_dead Informacja czy postać gracza żyje
        *@return Hitbox ataku przeciwnika jeśli ten wykonuje atak. Nullptr jeśli przeciwnik nie wykonuje ataku
        */
        RectangleShape* Maintance_Melee(RenderWindow &window, int counter, RectangleShape players_hitbox, bool is_player_dead);
        /**
        *Funkcja odpowiadająca za decyzję o wykonaniu ataku w kierunku gracza
        *@param players_hitbox Hitbox gracza potrzebny do obliczenia czy atak dosięgnie gracza
        *@param is_player_dead Informacja czy postać gracza żyje
        *@return Hitbox ataku przeciwnika jeśli ten wykonuje atak. Nullptr jeśli przeciwnik nie wykonuje ataku
        */
        RectangleShape* Swing(RectangleShape players_hitbox, bool is_player_dead);
        /**
        *Funkcja zwracająca wskaźnik na kolejny obiekt tej klasy
        *@return Wskaźnik na kolejny obiekt tej klasy
        */
        Enemy* getNext() { return next; }
        /**
        *Funkcja odpowiadająca za wszystko co robi przeciwnik typu zasięgowego
        *@param window Okno w którym wyświetlany jest przeciwnik
        *@param counter Licznik klatek potrzebny do poprawnego wyświetlania animacji
        *@param players_hitbox Hitbox gracza potrzebny do odpowiedniej nawigacji oraz ewentualnego wykonania ataku
        *@param is_player_dead Informacja czy postać gracza żyje
        *@param enemies_missiles Lista pocisków wystrzelonych przez przeciwników
        */
        void Maintance_Range(RenderWindow& window, int counter, RectangleShape players_hitbox, bool is_player_dead, Missiles& enemies_missiles);
        /**
        *Funkcja wyświetlająca pasek życia przeciwnika
        *@param window Okno w którym ma zostać wyświetlony pasek życia przeciwnika
        */
        void Display_HP(RenderWindow &window);
        /**
        *Funkcja odpowiedzialna za podążanie przeciwnika za postacią gracza
        *@param players_hitbox Hitbox postaci gracza
        *@param counter Licznik klatek potrzebny do poprawnego wyświetlenia animacji
        *@param window Okno w którym ma zostać wyświetlony przeciwnik
        */
        void Follow_player(RectangleShape players_hitbox, int counter, RenderWindow& window);  
        /**
        *Funkcja ustawiająca wartość wskaźnika na kolejny obiekt tej klasy zgodnie z podanym wskaźnikiem
        *@param pnext Wskaźnik na kolejny obiekt tej klasy
        */  
        void setNext(Enemy *pnext){next=pnext;}
        /**
        *Funkcja odpowiedzialna za sprawdzenie czy ewentualny atak bliskiego zasięgu dosięgnie postać gracza. Jeśli tak, ustawia atrybut is_attacking na true
        *@param players_hitbox Hitbox postaci gracza
        *@param is_player_dead Informacja czy postać gracza żyje
        */
        void Check_Swing(RectangleShape players_hitbox, bool is_player_dead);
        /**
        *Funkcja odpowiedzialna za sprawdzenie czy ewentualny atak zasięgowy trafi w postać gracza. Jeśli tak, ustawia atrybut is_attacking na true
        *@param players_hitbox Hitbox postaci gracza
        *@param is_player_dead Informacja czy postać gracza żyje
        */ 
        void Range_Attack(RectangleShape players_hitbox, bool is_player_dead);
        /**
        *Funkcja zadająca obrażenia przeciwnikowi poprzez odjęcie odpowiedniej ilości punktów życia od punktów życia przeciwnika
        *@param damage Ilość punktów życia które mają zostać odjęte od punktów życia przeciwnika
        */
        void getHit(int damage){HP-=damage;}

        /**
        *Funkcja zwalniająca pamięć zaalokowaną przez obiekt tej klasy
        */
        void Empty_Memory();

        /**
        *Funkcja zwracająca hitbox przeciwnika
        *@return Hitbox przeciwnika
        */
        RectangleShape getHitbox(){return hitbox;}
        /**
        *Funkcja zwracająca listę animacji przeciwnika
        *@return Lista animacji przeciwnika
        */
        Animations getAnimations() { return animations; }
        /**
        *Funkcja zwracająca bufor dźwieku ataku przeciwnika
        *@return Bufor dźwięku ataku przeciwnika
        */
        SoundBuffer getAttackBuffer() { return Attack_buffer; }
        /**
        *Funkcja zwracająca bufor dźwięku śmierci przeciwnika
        *@return Bufor dźwięku śmierci przeciwnika
        */
        SoundBuffer getDeathBuffer() { return Death_buffer; }
        /**
        *Funkcja zwracająca nazwę rodzaju przeciwnika
        *@return Nazwa rodzaju przeciwnika
        */
        std::string getType() { return type; }
        /**
        *Funkcja zwracająca informację czy przeciwnik jest martwy
        *@return Informacja czy przeciwnik jest martwy 
        */
        bool is_enemy_dead(){return is_dead;}
        /**
        *Funkcja zwracająca informację o typie przeciwnika (zasięgowy lub bliski)
        *@return 0 jeśli przeciwnik jest typu bliskiego, 1 jeśli przeciwnik jest typu zasięgowego
        */
        int Range(){return range;}
        /**
        *Funkcja zwracająca szerokość hitboxa ataku
        @return Szerokość hitboxa ataku
        */
        int getSwingWidth() { return Swing_width; }
        /**
        *Funkcja zwraca liczbę klatek przez które ma być wyświetlana animacja ataku
        *@return Liczba klatek przez które ma być wyświetlana animacja ataku
        */
        int getAttackCounterMax() { return Attack_counter_max; }
        /**
        *Funkcja zwraca informację o ile pikseli w lewo ma zostać przesunięta animacja ataku przeciwnika
        *@return Liczba pikseli o które animacja ataku przeciwnika ma zostać przesunięta w lewo
        */
        int getAttackLeft() { return Attack_left; }
        /**
        *Funkcja zwraca informację o ile pikseli w górę ma zostać przesunięta animacja ataku przeciwnika
        *@return Liczba pikseli o które animacja ataku przeciwnika ma zostać przesunięta w górę
        */
        int getAttackUp() { return Attack_up; }
        /**
        *Funkcja zwraca maksymalną ilość punktów życia przeciwnika
        *@return Maksymalna ilość punktów życia przeciwnika
        */
        int getMaxHp() { return MaxHP; }
        /**
        *Funkcja zwraca szerokość pocisku wystrzeliwanego przez przeciwnika
        *@return Szerokość pocisku wystrzeliwanego przez przeciwnika
        */
        int getMissileWidth() { return missile_width; }
        /**
        *Funkcja zwraca wysokość pocisku wystrzeliwanego przez przeciwnika
        *@return Wysokość pocisku wystrzeliwanego przez przeciwnika
        */
        int getMissileHeight() { return missile_height; }
        /**
        *Funkcja zwraca ilość zadawanych obrażeń przez przeciwnika w przypadku trafienia postaci gracza
        *@return Ilość zadawanych obrażeń w przypadku trafienia
        */
        int getDamage() { return damage; }
        /**
        *Funkcja zwraca numer klatki animacji ataku w której sprawdzane jest trafienie w postać gracza
        *@return Numer klatki animacji w której sprawdzane jest trafienie w postać gracza
        */
        int getAttackFrame() { return Attack_frame; }
        /**
        *Funkcja ustawia wartość attrybutu reported_death na true
        */
        void setReportedDeath() { reported_death = true; }
        /**
        *Funkcja zwraca wartość atrybutu reported_death
        *@return Wartość atrybutu reported_death
        *@see reported_death
        */
        bool getReportedDeath() { return reported_death; }
        

    private:
        /**Nazwa rodzaju przeciwnika*/
        std::string type;
        /**Hitbox przeciwnika*/
        RectangleShape hitbox;
        /**Szerokość hitboxa ataku bliskiego zasięgu*/
        int Swing_width;
        /**Licznik klatek animacji ataku*/
        int Attack_counter;
        /**Liczba klatek przez które ma być wyświetona animacja ataku*/
        int Attack_counter_max;
        /**Numer klatki animacji ataku w której ma zostać sprawdzone trafienie w postać gracza*/
        int Attack_frame;
        /**Ilość pikseli o które animacja ataku ma zostać przesunięta w lewo*/
        int Attack_left;
        /**Ilość pikseli o które animacja ataku ma zostać przesunięta w górę*/
        int Attack_up;
        /**Informacja o rodzaju przeciwnika (zasięgowy lub bliskiego zasięgu)*/
        int range; //0 - Melee  1 - Range
        /**Informacja o tym czy śmierć przeciwnika została już zgłoszona*/
        bool reported_death;
        /**Wskaźnik na kolejny obiekt tej klasy*/
        Enemy *next;
};

#endif // ENEMY_H
