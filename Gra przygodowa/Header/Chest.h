#ifndef CHEST_H
#define CHEST_H

#include "Items.h"

class Chest
{
    public:
        Chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs);
        virtual ~Chest();
        RectangleShape box;
        std::vector<int> Items_IDs;
        void DisplayChest(RenderWindow &window);
        void OpenChest();
        int is_open; //0-no, 1-yes

    private:
        Texture pic_open;
        Texture pic_closed;
        Sprite sp_open;
        Sprite sp_closed;
        Sound opening;
        SoundBuffer opening_buffer;

};

#endif // CHEST_H
