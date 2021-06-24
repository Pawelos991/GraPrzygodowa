#ifndef C_OBJECTS_H
#define C_OBJECTS_H

#include "Chest.h"
#include "Door.h"

class C_Objects
{
    public:
        C_Objects();
        virtual ~C_Objects(){}
        std::vector <Wall*> walls;
        std::vector <Chest*> chests;
        std::vector <Door*> doors;
        void open_door(Door* door);

    protected:
        Wall* add_wall(std::string location,Vector2f Position,Vector2f SizeOfBox);
        void add_chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs);
        void add_door(std::string texture_location, Wall* wall, int key_id);
        void clear_data_CO();
        void display_CO(RenderWindow &window, bool is_everyone_dead);

};

#endif // C_OBJECTS_H
