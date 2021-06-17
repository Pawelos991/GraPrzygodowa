#ifndef SCREENS_H
#define SCREENS_H

#include "Screen.h"

class Screens
{
    public:

    protected:
        Screen *Actual_screen=nullptr;
        std::vector<Screen*> screens;
        void loadScreens();
        void Display_Screens(RenderWindow &window);
        void Check_screen(RectangleShape &player_hitbox);
        void delete_all_screens();
};

#endif // SCREENS_H
