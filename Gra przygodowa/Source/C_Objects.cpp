#include "C_Objects.h"

C_Objects::C_Objects()
{
    //ctor
}

Wall* C_Objects::add_wall(std::string location,Vector2f Position,Vector2f SizeOfBox)
{
    Wall* wall = new Wall(location, Position, SizeOfBox);
    walls.push_back(wall);
    return wall;
}

void C_Objects::add_chest(std::string location_closed,std::string location_open,Vector2f Position, Vector2f SizeOfBox, std::vector<int> Item_IDs)
{
    chests.push_back(new Chest(location_closed,location_open,Position,SizeOfBox,Item_IDs));
}

void C_Objects::add_door(std::string texture_location, Wall* wall, int key_id)
{
    doors.push_back(new Door(texture_location,wall,key_id));
}

void C_Objects::open_door(Door* door)
{
    int i = 0;
    while (walls[i] != door->get_wall())
        i++;
    delete walls[i];
    walls.erase(walls.begin() + i);
    i = 0;
    while (doors[i] != door)
        i++;
    delete doors[i];
    doors.erase(doors.begin() + i);
}

void C_Objects::clear_data_CO()
{
    for(int i=0;i<walls.size();i++)
        delete walls[i];

    for(int i=0;i<chests.size();i++)
        delete chests[i];

    for (int i = 0; i < doors.size(); i++)
        delete doors[i];
}

void C_Objects::display_CO(RenderWindow &window,bool is_everyone_dead)
{
    for(int i=0;i<walls.size();i++)
        walls[i]->DisplayWall(window);
    if (is_everyone_dead)
    {
        for (int i = 0; i < chests.size(); i++)
            chests[i]->DisplayChest(window);
        for (int i = 0; i < doors.size(); i++)
            doors[i]->DisplayDoor(window);
    }
}
