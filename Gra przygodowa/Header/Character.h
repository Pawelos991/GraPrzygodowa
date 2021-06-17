#ifndef CHARACTER_H
#define CHARACTER_H

#include "Animations.h"

class Character
{
    public:
        Character();
        virtual ~Character();

    protected:
        Animations animations;
        int HP;
        int MaxHP;
        int is_dead; //0 - No, 1 - Yes
        int death_counter;
        int movement_indicator; //1 - Right, 2 - Left
        int is_attacking; //0 - No  1 - Yes
        RectangleShape HP_Red;
        SoundBuffer Attack_buffer;
        Sound Attack_Sound;
        SoundBuffer Death_buffer;
        Sound Death_sound;
        int missile_width;
        int missile_height;
        SoundBuffer Attack_hit;
        int damage;

};

template <class T>
void Hit_ptr(T* temp,int damage)
{
    temp->getHit(damage);
}

#endif // CHARACTER_H
