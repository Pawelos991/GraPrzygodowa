#include "Door.h"

Door::Door(std::string texture_location, Wall* wall, int key_id)
{
    tex.loadFromFile(texture_location);
    sp.setTexture(tex);
    sp.setPosition(Vector2f(wall->box.getPosition().x-5, wall->box.getPosition().y-4));
    key_ID = key_id;
    this->wall = wall;
    box.setSize(Vector2f(wall->box.getSize().x + 10, wall->box.getSize().y + 8));
    box.setPosition(Vector2f(wall->box.getPosition().x-5, wall->box.getPosition().y-4));
}

void Door::DisplayDoor(RenderWindow& window)
{
    window.draw(sp);
}