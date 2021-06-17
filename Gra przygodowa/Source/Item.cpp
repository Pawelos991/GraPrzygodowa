#include "Item.h"

Item::Item(int IDc, std::string namec, std::string locations)
{
    this->ID=IDc;
    this->name=namec;
    this->location=locations;
    this->pic.loadFromFile(location);
    this->sp.setTexture(pic);
    this->sp.setPosition(Vector2f(200,200));
}

Item::~Item()
{
    //dtor
}

void Item::displayItem(RenderWindow &window, Vector2f location)
{
    sp.setPosition(location);
    window.draw(sp);
}
