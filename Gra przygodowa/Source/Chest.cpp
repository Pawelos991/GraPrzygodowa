#include "Chest.h"

Chest::Chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs)
{
    pic_closed.loadFromFile(location_closed);
    sp_closed.setTexture(pic_closed);
    sp_closed.setPosition(Position);
    pic_open.loadFromFile(location_open);
    sp_open.setTexture(pic_open);
    sp_open.setPosition(Position);
    box.setPosition(Position);
    box.setSize(SizeOfBox);
    opening_buffer.loadFromFile("Sounds/Chest_open.wav");
    opening.setBuffer(opening_buffer);
    is_open=false;
    Items_IDs=Item_IDs;
}

Chest::~Chest()
{

}

void Chest::DisplayChest(RenderWindow &window)
{
    if(is_open==false)
        window.draw(sp_closed);
    else
        window.draw(sp_open);
}

void Chest::OpenChest()
{
    if(is_open==false)
    {
         opening.play();
         is_open=true;
    }
}
