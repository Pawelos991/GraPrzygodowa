#ifndef SCREEN_H
#define SCREEN_H

#include "Background.h"
#include "C_Objects.h"
#include "Characters.h"

class Screen : public Background,public C_Objects,public Characters
{
    public:
        Screen(std::string info_file);
        virtual ~Screen();
        int getID(){return ID;}
        int goRight(){return rightID;}
        int goLeft(){return leftID;}
        int goUp(){return upID;}
        int goDown(){return downID;}
        int getNumberOfConnections() { return howManyConnections; }
        void displayScreen(RenderWindow &window);
        Chest* check_chests(RectangleShape players_hitbox);
        Door* check_doors(RectangleShape players_hitbox);
        Missiles player_missiles;
        Missiles enemies_missiles;
        int removed;
        void clear_space();

    private:
        int ID,leftID,rightID,upID,downID,howManyConnections;
};

#endif // SCREEN_H
