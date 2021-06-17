#include "Background.h"

void Background::displayBackground(RenderWindow &window)
{
    window.draw(Bck);
    for(int i=0;i<NC_Objects.size();i++)
        NC_Objects[i]->displayObject(window);
}

void Background::clearData_Bck()
{
    for(int i=0;i<NC_Objects.size();i++)
        delete NC_Objects[i];
}

void Background::add_NC_Object(std::string location,Vector2f Position)
{
    NC_Objects.push_back(new NC_Object(location, Position));
}
