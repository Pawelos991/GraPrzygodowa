#include "Screens.h"

void Screens::loadScreens()
{

    std::ifstream fp;
    std::string temp;
    try
    {
        fp.open("Data/Screens.txt");
        if(fp.good()==false)
            throw 1;
    }
    catch(int x)
    {
        if(x==1)
            std::cout<<"Brak pliku lub niepoprawny plik Data/Screens.txt"<<std::endl;
    }

    while(true)
    {
        if(fp.good());
        else
            break;
        fp>>temp;
        screens.push_back(new Screen(temp));
    }
    fp.close();
    Actual_screen=screens[0];
}

void Screens::Display_Screens(RenderWindow &window)
{
    Actual_screen->displayScreen(window);
    if(Actual_screen->removed!=0 && Actual_screen->enemies.is_it_empty()==0 && Actual_screen->enemies.is_everyone_dead()==1)
    {
        for(int i=0;i<Actual_screen->getNumberOfConnections()-1;i++)
            Actual_screen->walls.pop_back();
        Actual_screen->removed=0;
    }
}

void Screens::Check_screen(RectangleShape &player_hitbox)
{
    Screen *temp=nullptr;
    int i=0;
    if(player_hitbox.getPosition().x>=1600)
    {
        while (screens[i]->getID()!=Actual_screen->goRight())
            i++;
        Actual_screen=screens[i];
        player_hitbox.setPosition(Vector2f(0,player_hitbox.getPosition().y));
        return;
    }
    if(player_hitbox.getPosition().x<0-player_hitbox.getGlobalBounds().width)
    {
        while (screens[i]->getID()!=Actual_screen->goLeft())
            i++;
        Actual_screen=screens[i];
        player_hitbox.setPosition(Vector2f(1600,player_hitbox.getPosition().y));
        return;
    }
    if(player_hitbox.getPosition().y>900)
    {
        while (screens[i]->getID()!=Actual_screen->goDown())
            i++;
        Actual_screen=screens[i];
        player_hitbox.setPosition(Vector2f(player_hitbox.getPosition().x,0));
        return;
    }
    if(player_hitbox.getPosition().y<0-player_hitbox.getGlobalBounds().height)
    {
       while (screens[i]->getID()!=Actual_screen->goUp())
            i++;
        Actual_screen=screens[i];
        player_hitbox.setPosition(Vector2f(player_hitbox.getPosition().x,900));
        return;
    }
}

void Screens::delete_all_screens()
{
    for(int i=0;i<screens.size();i++)
    {
        screens[i]->clear_space();
        delete screens[i];
    }
}
