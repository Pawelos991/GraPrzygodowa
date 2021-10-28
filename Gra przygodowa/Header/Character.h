#ifndef CHARACTER_H
#define CHARACTER_H

#include "Animations.h"

/**
*Klasa reprezentująca pojedynczą postać w grze
*/
class Character
{
    public:
        /**
        *Konstruktor klasy
        */
        Character();
        /**
        *Destruktor klasy 
        */
        virtual ~Character();

    protected:
        /**Animacje danej postaci*/
        Animations animations;
        /**Obecna ilość punktów życia postaci*/
        int HP;
        /**Maksymalna ilość punktów życia postaci*/
        int MaxHP;
        /**Informacja czy postać jest martwa*/
        bool is_dead;
        /**Licznik klatek animacji śmierci postaci*/
        int death_counter;
        /**Infomacja o kierunku w którym porusza się postać*/
        int movement_indicator; //1 - Right, 2 - Left
        /**Informacja czy postać aktualnie wykonuje animację ataku*/
        bool is_attacking; //0 - No  1 - Yes
        /**Pasek reprezentujący część życia postaci*/
        RectangleShape HP_Red;
        /**Bufor dźwiękowy przychowujący dźwięk ataku postaci*/
        SoundBuffer Attack_buffer;
        /**Dźwięk ataku postaci*/
        Sound Attack_Sound;
        /**Bufor dźwiękowy przechowujący dźwięk śmierci postaci*/
        SoundBuffer Death_buffer;
        /**Dźwięk śmierci postaci*/
        Sound Death_sound;
        /**Szerokość pocisku wystrzeliwanego przez postać (jeśli jest typu zasięgowego)*/
        int missile_width;
        /**Wysokość pocisku wystrzeliwanego przez postać (jeśli jest typu zasiegowego)*/
        int missile_height;
        /**Tego chyba tu nie ma być !!!!!!!!!!!!*/
        SoundBuffer Attack_hit;
        /**Obrażenia zadawane przez postać w przypadku trafienia innej postaci*/
        int damage;

};

/**Wzór funkcji do zadania obrażeń postaci do której podawany jest wskaźnik*/
template <class T>
/**
*Funkcja zadająca obrażenia postaci do której podano wskaźnik
*@param temp Wskaźnik na postać której mają zostać zadane obrażenia
*@param damage Wartość obrażeń która ma zostać zadana postaci
*/
void Hit_ptr(T* temp,int damage)
{
    temp->getHit(damage);
}

#endif // CHARACTER_H
