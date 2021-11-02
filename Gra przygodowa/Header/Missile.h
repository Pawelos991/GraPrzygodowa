#ifndef MISSILE_H
#define MISSILE_H

#include "Animations.h"

/**
* Klasa reprezentuje pojedynczy pocisk wystrzelony przez postać gracza lub przeciwnika
*/
class Missile
{
    public:
        /**
        * Konstruktor klasy ustawiający wartości atrybutów zgodnie z argumentami
        * @param D Kierunek w którym leci pocisk (1 - Prawo 2 - Lewo 3 - Do góry 4 - W dół)
        * @param P Pozycja startowa pocisku
        * @param animation Wskaźnik na animację lotu pocisku
        * @param Damage wartość obrażeń zadawanych przez pocisk w przypadku trafienia
        * @param missile_width Szerokość hitboxa pocisku
        * @param missile_height Wysokość hitboxa pocisku
        */
        Missile(int D, Vector2f P, Animation* animation,int Damage,int missile_width, int missile_height); // original size 128x100
        /**
        * Destruktor klasy
        */
        virtual ~Missile();
        /**
        * Funkcja zwracająca pozycję pocisku
        * @return Pozycja pocisku
        */
        Vector2f GetPosition();
        /**
        * Funkcja zwracająca kierunek w którym porusza się pocisk
        * @return Kierunek w którym porusza się pocisk
        */
        int GetDirection(){return direction;}
        /**
        * Funkcja zwracająca wskaźnik na inny obiekt tej klasy
        * @return Wskaźnika na inny obiekt tej klasy
        */
        Missile* getNext(){return next;}
        /**
        * Funkcja ustawiająca wskaźnik na inny obiekt tej klasy zgodnie z argumentem
        * @param pnext Wskaźnik na który ma zostać ustawiony wskaźnik obiektu
        */
        void setNext(Missile *pnext){next=pnext;}
        /**
        * Funkcja wyświetla pocisk w oknie
        * @param window Okno w którym ma zostać wyświetlony pocisk
        * @param counter Licznik klatek
        */
        void Display_missile(RenderWindow &window, int counter);
        /**
        * Funkcja ustawiająca pozycję obiektu zgodnie z argumentem
        * @param newPosition Pozycja na którą ma zostać ustawiona pozycja obiektu
        */
        void setPosition(Vector2f newPosition);
        /**
        * Funkcja która zwraca hitbox pocisku
        * @return Hitbox pocisku
        */
        RectangleShape getHitbox(){return hitbox;}
        /**
        * Funkcja która zwraca wartość obrażeń zadawanych przez pocisk 
        * @return Wartość obrażeń zadawanych przez pocisk
        */
        int getDamageValue(){return damage;}
        /**
        * Funkcja zwalniająca pamięć zaalokowaną przez pocisk
        */
        void Empty_Memory();

    private:
        /**Animacje pocisku*/
        Animations animations;
        /**Hitbox pocisku*/
        RectangleShape hitbox;
        /**Kierunek lotu pocisku (1 - Prawo 2 - Lewo 3 - Do góry 4 - W dół)*/
        int direction; //1 - Right 2 - Left 3 - Up 4 - Down
        /**Wartość obrażeń zadawanych przez pocisk w przypadku trafienia*/
        int damage;
        /**Pozycja pocisku*/
        Vector2f Position;
        /**Wskaźnik na inny obiekt tej klasy*/
        Missile* next;
};

#endif // MISSILE_H
