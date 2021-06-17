#include "Inventory.h"


void Inventory::add_item_to_inventory(int ID, Items &all_items)
{
    Item *temp = new Item(all_items.find_item(ID)->getID(),all_items.find_item(ID)->getName(),all_items.find_item(ID)->getLocation());
    items.add_item(temp);
}

void Inventory::delete_item_from_inventory(int ID)
{
    items.delete_item(ID);
}

void Inventory::LoadBackground()
{
    texture.loadFromFile("Textures/Inventory/Background.png");
    sp.setTexture(texture);
}

void Inventory::Display_Inventory(RenderWindow &window)
{
    sp.setPosition(Vector2f(window.getSize().x-sp.getGlobalBounds().width-30,window.getSize().y-sp.getGlobalBounds().height-30));
    int x,y;
    x=sp.getPosition().x+12;
    y=sp.getPosition().y+72;
    window.draw(sp);
    Item *temp=items.get_head();
    while(temp!=nullptr)
    {
        temp->displayItem(window,Vector2f(x,y));
        x+=70;
        if(x>window.getSize().x-70)
        {
            x=sp.getPosition().x+12;
            y+=70;
        }

        temp=temp->getNext();
    }
}

int Inventory::Is_there_an_item(int ID)
{
    Item* temp=items.find_item(ID);
    if(temp!=nullptr)
        return 1;
    else
        return 0;
}
