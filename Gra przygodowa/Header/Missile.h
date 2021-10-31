#ifndef MISSILE_H
#define MISSILE_H

#include "Animations.h"

/**
* Klasa reprezentuje pojedynczy pocisk wystrzelony przez postaæ gracza lub przeciwnika
*/
class Missile
{
    public:
        /**
        * Konstruktor klasy ustawiaj¹cy wartoœci atrybutów zgodnie z argumentami
        * @param D Kierunek w którym leci pocisk (1 - Prawo 2 - Lewo 3 - Do góry 4 - W dó³)
        * @param P Pozycja startowa pocisku
        * @param animation WskaŸnik na animacjê lotu pocisku
        * @param Damage wartoœæ obra¿eñ zadawanych przez pocisk w przypadku trafienia
        * @param missile_width Szerokoœæ hitboxa pocisku
        * @param missile_height Wysokoœæ hitboxa pocisku
        */
        Missile(int D, Vector2f P, Animation* animation,int Damage,int missile_width, int missile_height); // original size 128x100
        /**
        * Destruktor klasy
        */
        virtual ~Missile();
        /**
        * Funkcja zwracaj¹ca pozycjê pocisku
        * @return Pozycja pocisku
        */
        Vector2f GetPosition();
        /**
        * Funkcja zwracaj¹ca kierunek w którym porusza siê pocisk
        * @return Kierunek w którym porusza siê pocisk
        */
        int GetDirection(){return direction;}
        /**
        * Funkcja zwracaj¹ca wskaŸnik na inny obiekt tej klasy
        * @return WskaŸnika na inny obiekt tej klasy
        */
        Missile* getNext(){return next;}
        /**
        * Funkcja ustawiaj¹ca wskaŸnik na inny obiekt tej klasy zgodnie z argumentem
        * @param pnext WskaŸnik na który ma zostaæ ustawiony wskaŸnik obiektu
        */
        void setNext(Missile *pnext){next=pnext;}
        /**
        * Funkcja wyœwietla pocisk w oknie
        * @param window Okno w którym ma zostaæ wyœwietlony pocisk
        * @param counter Licznik klatek
        */
        void Display_missile(RenderWindow &window, int counter);
        /**
        * Funkcja ustawiaj¹ca pozycjê obiektu zgodnie z argumentem
        * @param newPosition Pozycja na któr¹ ma zostaæ ustawiona pozycja obiektu
        */
        void setPosition(Vector2f newPosition);
        /**
        * Funkcja która zwraca hitbox pocisku
        * @return Hitbox pocisku
        */
        RectangleShape getHitbox(){return hitbox;}
        /**
        * Funkcja która zwraca wartoœæ obra¿eñ zadawanych przez pocisk 
        * @return Wartoœæ obra¿eñ zadawanych przez pocisk
        */
        int getDamageValue(){return damage;}
        /**
        * Funkcja zwalniaj¹ca pamiêæ zaalokowan¹ przez pocisk
        */
        void Empty_Memory();

    private:
        /**Animacje pocisku*/
        Animations animations;
        /**Hitbox pocisku*/
        RectangleShape hitbox;
        /**Kierunek lotu pocisku (1 - Prawo 2 - Lewo 3 - Do góry 4 - W dó³)*/
        int direction; //1 - Right 2 - Left 3 - Up 4 - Down
        /**Wartoœæ obra¿eñ zadawanych przez pocisk w przypadku trafienia*/
        int damage;
        /**Pozycja pocisku*/
        Vector2f Position;
        /**WskaŸnik na inny obiekt tej klasy*/
        Missile* next;
};

#endif // MISSILE_H
