#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Animation
{
    public:
        Animation(std::string Name,int Id,int Frames,int Delay):name(Name),ID(Id),frames(Frames),delay(Delay){}
        virtual ~Animation();
        void setTexture(int number, Texture t);
        Texture* getTexture(int number);
        void setNext(Animation *Next){next=Next;}
        Animation* getNext(){return next;}
        int getID(){return ID;}
        Sprite getSprite(){return sp;}
        std::string getName(){return name;}
        void CopyFromAnimation(Animation *base);
        void Display_animation(RenderWindow& window, Vector2f location, int counter);
        int getFrames(){return frames;}
        int getDelay(){return delay;}

    private:
        int frames;
        int delay;
        Texture textures[10];
        Sprite sp;
        Animation *next=nullptr;
        std::string name;
        int ID;
};

#endif // ANIMATION_H
