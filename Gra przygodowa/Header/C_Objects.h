#ifndef C_OBJECTS_H
#define C_OBJECTS_H

#include "Chest.h"
#include "Wall.h"

class C_Objects
{
    public:
        C_Objects();
        virtual ~C_Objects(){}
        std::vector <Wall*> walls;
        std::vector <Chest*> chests;

    protected:
        void add_wall(std::string location,Vector2f Position,Vector2f SizeOfBox);
        void add_chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs);
        void clear_data_CO();
        void display_CO(RenderWindow &window, int is_everyone_dead);

};

#endif // C_OBJECTS_H
