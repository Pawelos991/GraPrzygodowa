#ifndef SCREENS_H
#define SCREENS_H

#include "Screen.h"

class Screens
{
    public:

    protected:
        Screen *Actual_screen=nullptr;
        std::vector<Screen*> screens;
        Texture door_menu_tex[2];
        Sprite door_menu_sp;
        Sound door_sound;
        SoundBuffer door_sb;


        void loadScreens();
        void Display_Screens(RenderWindow &window);
        void Check_screen(RectangleShape &player_hitbox);
        void delete_all_screens();
        void open_door(Door* d);
};

#endif // SCREENS_H
