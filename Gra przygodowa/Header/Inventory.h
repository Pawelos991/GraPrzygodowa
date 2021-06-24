#ifndef INVENTORY_H
#define INVENTORY_H

#include "Items.h"

class Inventory
{
    public:
        Inventory(){LoadBackground();}
        virtual ~Inventory(){items.delete_all_items();}
        Items items;
        void add_item_to_inventory(int ID, Items &all_items);
        void delete_item_from_inventory(int ID);
        void LoadBackground();
        void Display_Inventory(RenderWindow &window);
        bool Is_there_an_item(int ID);

    private:
        Texture texture;
        Sprite sp;

};

#endif // INVENTORY_H
