#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "NC_Object.h"

class Background
{
    public:

    protected:
        std::vector <NC_Object*> NC_Objects;
        Sprite Bck;
        Texture pic;
        void displayBackground(RenderWindow &window);
        void add_NC_Object(std::string location,Vector2f Position);
        void clearData_Bck();
};

#endif // BACKGROUND_H
