#include "Wall.h"

Wall::Wall(std::string location,Vector2f Position,Vector2f SizeOfBox)
{
    box.setSize(SizeOfBox);
    box.setPosition(Position);
    pic.loadFromFile(location);
    sp.setTexture(pic);
    sp.setPosition(Position);
}

void Wall::DisplayWall(RenderWindow &window)
{
    window.draw(sp);
}
