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

void Inventory::clear_items()
{
    items.delete_all_items();
}

void Inventory::LoadBackground()
{
    texture.loadFromFile("Textures/Inventory/Background.png");
    sp.setTexture(texture);
}

void Inventory::Display_Inventory(RenderWindow &window)
{
    //sp.setPosition(Vector2f(window.getSize().x-sp.getGlobalBounds().width-30,window.getSize().y-sp.getGlobalBounds().height-30));
    sp.setPosition(Vector2f(890,470));
    int x,y;
    x=902;
    y=542;
    window.draw(sp);
    Item *temp=items.get_head();
    while(temp!=nullptr)
    {
        temp->displayItem(window,Vector2f(x,y));
        x+=70;
        if(x>1532)
        {
            x=902;
            y+=70;
        }

        temp=temp->getNext();
    }
}

bool Inventory::Is_there_an_item(int ID)
{
    Item* temp=items.find_item(ID);
    if(temp!=nullptr)
        return true;
    else
        return false;
}
