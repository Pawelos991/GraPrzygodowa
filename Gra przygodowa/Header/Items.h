#ifndef ITEMS_H
#define ITEMS_H

#include "Item.h"

class Items
{
    public:
        Items():head(nullptr){};
        ~Items(){delete_all_items();};
        void delete_all_items();
        void delete_item(int ID);
        void add_item(Item *added);
        void add_item(int IDc, std::string namec, std::string location);
        Item* find_item(int ID);
        Item* get_head(){return head;}
        std::vector<int> Item_ids();

        void LoadItemsFromFile();

    private:
        Item *head;

};

void Replace_withSpace(std::string &to_replace);

#endif // ITEMS_H
