#ifndef SCREENS_H
#define SCREENS_H

#include "Loading_Screen.h"

class Screens
{
    public:

    protected:
        Screen *Actual_screen=nullptr;

        Screen* arena_screen = nullptr;
        std::vector<Screen*> tutorial_screens;
        std::vector<Screen*> adventure_screens;

        Loading_Screen *loading_screen;

        Texture door_menu_tex[2];
        Sprite door_menu_sp;
        Sound door_sound;
        SoundBuffer door_sb;


        bool generate_Screens();
        //bool 

        Screen* get_tutorial_screen_by_ID(int ID);
        void load_tutorial_Screens(RenderWindow& window);
        void load_arena_Screen();
        void load_loading_screen();
        void load_door_data();
        void Display_Screens(RenderWindow &window);
        void Check_screen(RectangleShape &player_hitbox);
        void delete_all_screens();
        void delete_all_tutorial_screens();
        void delete_all_adventure_screens();
        void open_door(Door* d);
};

#endif // SCREENS_H
