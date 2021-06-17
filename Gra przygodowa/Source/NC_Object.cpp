#include "NC_Object.h"

NC_Object::NC_Object(std::string location, Vector2f Position)
{
    pic.loadFromFile(location);
    sp.setTexture(pic);
    sp.setPosition(Position);
}

void NC_Object::displayObject(RenderWindow &window)
{
    window.draw(sp);
}
