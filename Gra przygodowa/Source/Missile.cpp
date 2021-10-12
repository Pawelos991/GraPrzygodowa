#include "Missile.h"

Missile::Missile(int D, Vector2f P, Animation* animation,int Damage,int missile_width, int missile_height,SoundBuffer& buffer)
{
    Position=P;
    direction=D;
    if(direction==1 || direction==2)
        hitbox.setSize(Vector2f(missile_width,missile_height));
    else
        hitbox.setSize(Vector2f(missile_height,missile_width));
    Animation*added = new Animation(animation->getName(),animation->getID(),animation->getFrames(),animation->getDelay());
    added->CopyFromAnimation(animation);
    animations.add_animation(added);
    hitbox.setPosition(P);
    hit.setBuffer(buffer);
    hit.setVolume(20);
    next=nullptr;
    damage=Damage;
}

Missile::~Missile()
{

}

void Missile::setPosition(Vector2f newPosition)
{
    hitbox.setPosition(newPosition);
}

Vector2f Missile::GetPosition()
{
    Vector2f x = hitbox.getPosition();
    return x;
}

void Missile::Display_missile(RenderWindow &window, int counter)
{
    switch(direction)
    {
    case 1:
        animations.find_animation(12)->Display_animation(window, hitbox.getPosition(),counter);
        break;
    case 2:
        animations.find_animation(11)->Display_animation(window, hitbox.getPosition(),counter);
        break;
    case 3:
        animations.find_animation(9)->Display_animation(window, hitbox.getPosition(),counter);
        break;
    case 4:
        animations.find_animation(10)->Display_animation(window, hitbox.getPosition(),counter);
        break;
    }
}

void Missile::Empty_Memory()
{
    animations.delete_all_animations();
}