#ifndef MISSILE_H
#define MISSILE_H

#include "Animations.h"

/**
* Klasa reprezentuje pojedynczy pocisk wystrzelony przez posta� gracza lub przeciwnika
*/
class Missile
{
    public:
        /**
        * Konstruktor klasy ustawiaj�cy warto�ci atrybut�w zgodnie z argumentami
        * @param D Kierunek w kt�rym leci pocisk (1 - Prawo 2 - Lewo 3 - Do g�ry 4 - W d�)
        * @param P Pozycja startowa pocisku
        * @param animation Wska�nik na animacj� lotu pocisku
        * @param Damage warto�� obra�e� zadawanych przez pocisk w przypadku trafienia
        * @param missile_width Szeroko�� hitboxa pocisku
        * @param missile_height Wysoko�� hitboxa pocisku
        */
        Missile(int D, Vector2f P, Animation* animation,int Damage,int missile_width, int missile_height); // original size 128x100
        /**
        * Destruktor klasy
        */
        virtual ~Missile();
        /**
        * Funkcja zwracaj�ca pozycj� pocisku
        * @return Pozycja pocisku
        */
        Vector2f GetPosition();
        /**
        * Funkcja zwracaj�ca kierunek w kt�rym porusza si� pocisk
        * @return Kierunek w kt�rym porusza si� pocisk
        */
        int GetDirection(){return direction;}
        /**
        * Funkcja zwracaj�ca wska�nik na inny obiekt tej klasy
        * @return Wska�nika na inny obiekt tej klasy
        */
        Missile* getNext(){return next;}
        /**
        * Funkcja ustawiaj�ca wska�nik na inny obiekt tej klasy zgodnie z argumentem
        * @param pnext Wska�nik na kt�ry ma zosta� ustawiony wska�nik obiektu
        */
        void setNext(Missile *pnext){next=pnext;}
        /**
        * Funkcja wy�wietla pocisk w oknie
        * @param window Okno w kt�rym ma zosta� wy�wietlony pocisk
        * @param counter Licznik klatek
        */
        void Display_missile(RenderWindow &window, int counter);
        /**
        * Funkcja ustawiaj�ca pozycj� obiektu zgodnie z argumentem
        * @param newPosition Pozycja na kt�r� ma zosta� ustawiona pozycja obiektu
        */
        void setPosition(Vector2f newPosition);
        /**
        * Funkcja kt�ra zwraca hitbox pocisku
        * @return Hitbox pocisku
        */
        RectangleShape getHitbox(){return hitbox;}
        /**
        * Funkcja kt�ra zwraca warto�� obra�e� zadawanych przez pocisk 
        * @return Warto�� obra�e� zadawanych przez pocisk
        */
        int getDamageValue(){return damage;}
        /**
        * Funkcja zwalniaj�ca pami�� zaalokowan� przez pocisk
        */
        void Empty_Memory();

    private:
        /**Animacje pocisku*/
        Animations animations;
        /**Hitbox pocisku*/
        RectangleShape hitbox;
        /**Kierunek lotu pocisku (1 - Prawo 2 - Lewo 3 - Do g�ry 4 - W d�)*/
        int direction; //1 - Right 2 - Left 3 - Up 4 - Down
        /**Warto�� obra�e� zadawanych przez pocisk w przypadku trafienia*/
        int damage;
        /**Pozycja pocisku*/
        Vector2f Position;
        /**Wska�nik na inny obiekt tej klasy*/
        Missile* next;
};

#endif // MISSILE_H
