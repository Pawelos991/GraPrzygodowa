#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Item
{
    public:
        Item(int IDc, std::string namec, std::string locations);
        virtual ~Item();
        void displayItem(RenderWindow &window, Vector2f location);
        Item *getNext(){return next;}
        void setNext(Item *pnext){next=pnext;}
        int getID(){return ID;}
        std::string getName(){return name;}
        std::string getLocation(){return location;}


    private:
        int ID;
        std::string location;
        Texture pic;
        std::string name;
        Item *next;
        Sprite sp;

};

#endif // ITEM_H
