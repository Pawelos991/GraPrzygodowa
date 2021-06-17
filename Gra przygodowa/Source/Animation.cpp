#include "Animation.h"


Animation::~Animation()
{
    //dtor
}

void Animation::setTexture(int number, Texture t)
{
    textures[number]=t;
}

Texture* Animation::getTexture(int number)
{
    return &textures[number];
}

void Animation::Display_animation(RenderWindow& window, Vector2f location, int counter)
{
    sp.setPosition(location);
    int one_pic_time=delay*0.06;
    int one_cycle=one_pic_time*frames;

    if(counter%one_cycle<one_pic_time)
        sp.setTexture(textures[0]);
    else if(counter%one_cycle>=one_pic_time && counter%one_cycle<2*one_pic_time)
        sp.setTexture(textures[1]);
    else if(counter%one_cycle>=2*one_pic_time && counter%one_cycle<3*one_pic_time)
        sp.setTexture(textures[2]);
    else if(counter%one_cycle>=3*one_pic_time && counter%one_cycle<4*one_pic_time)
        sp.setTexture(textures[3]);
    else if(counter%one_cycle>=4*one_pic_time && counter%one_cycle<5*one_pic_time)
        sp.setTexture(textures[4]);
    else if(counter%one_cycle>=5*one_pic_time && counter%one_cycle<6*one_pic_time)
        sp.setTexture(textures[5]);
    else if(counter%one_cycle>=6*one_pic_time && counter%one_cycle<7*one_pic_time)
        sp.setTexture(textures[6]);
    else if(counter%one_cycle>=7*one_pic_time && counter%one_cycle<8*one_pic_time)
        sp.setTexture(textures[7]);
    else if(counter%one_cycle>=8*one_pic_time && counter%one_cycle<9*one_pic_time)
        sp.setTexture(textures[8]);
    else if(counter%one_cycle>=9*one_pic_time && counter%one_cycle<10*one_pic_time)
        sp.setTexture(textures[9]);

    window.draw(sp);
}

void Animation::CopyFromAnimation(Animation *base)
{
    sp=base->getSprite();
    next=nullptr;
    for(int i=0;i<base->getFrames();i++)
        textures[i]=*base->getTexture(i);
    name=base->getName();
    ID=base->getID();
}
