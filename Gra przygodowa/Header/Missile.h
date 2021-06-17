#ifndef MISSILE_H
#define MISSILE_H

#include "Animations.h"

class Missile
{
    public:
        Missile(int D, Vector2f P, Animation* animation,int Damage,int missile_width, int missile_height,SoundBuffer& buffer); // original size 128x100
        virtual ~Missile();
        Vector2f GetPosition();
        int GetDirection(){return direction;}
        Missile* getNext(){return next;}
        void setNext(Missile *pnext){next=pnext;}
        void Display_missile(RenderWindow &window, int counter);
        void setPosition(Vector2f newPosition);
        RectangleShape getHitbox(){return hitbox;}
        int getDamageValue(){return damage;}
        void play_sound(){hit.play();}
        Sound getSound(){return hit;}


    private:
        Animations animations;
        RectangleShape hitbox;
        int direction; //1 - Right 2 - Left 3 - Up 4 - Down
        int damage;
        Vector2f Position;
        Missile* next;
        SoundBuffer buffer;
        Sound hit;
};

#endif // MISSILE_H
