#ifndef DOOR_H
#define DOOR_H

#include <Wall.h>

using namespace sf;

class Door
{
public:
    Door(std::string texture_location,Wall* wall, int key_id);
    ~Door(){}
    void DisplayDoor(RenderWindow& window);
    int get_key_ID() { return key_ID; }
    Wall* get_wall() { return wall; }
    RectangleShape get_box() { return box; }

private:
    Texture tex;
    Sprite sp;
    int key_ID;
    Wall *wall;
    RectangleShape box;
};

#endif // DOOR_H