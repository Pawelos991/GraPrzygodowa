#include "C_Objects.h"

C_Objects::C_Objects()
{
    //ctor
}

void C_Objects::add_wall(std::string location,Vector2f Position,Vector2f SizeOfBox)
{
    walls.push_back(new Wall(location,Position,SizeOfBox));
}

void C_Objects::add_chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs)
{
    chests.push_back(new Chest(location_closed,location_open,Position,SizeOfBox,Item_IDs));
}

void C_Objects::clear_data_CO()
{
    for(int i=0;i<walls.size();i++)
        delete walls[i];

    for(int i=0;i<chests.size();i++)
        delete chests[i];
}

void C_Objects::display_CO(RenderWindow &window,int is_everyone_dead)
{
    for(int i=0;i<walls.size();i++)
        walls[i]->DisplayWall(window);
    if(is_everyone_dead==1)
        for(int i=0;i<chests.size();i++)
        chests[i]->DisplayChest(window);
}
