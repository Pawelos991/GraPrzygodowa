#include "Screens.h"

void Screens::load_tutorial_Screens(RenderWindow &window)
{
    loading_screen->start_loading(window);
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
    int i = 0;
    loading_screen->set_loading(window, float(float(i) / 13), "Wczytywanie danych z plików");
    while(true)
    {
        if(fp.good());
        else
            break;
        fp>>temp;
        tutorial_screens.push_back(new Screen(temp));
        i++;
        loading_screen->set_loading(window, float(float(i)/13),"Wczytywanie danych z plików");
    }
    fp.close();
    Actual_screen= tutorial_screens[0];

}

void Screens::load_arena_Screen()
{
    arena_screen = new Screen("Data/Screens/Arena_Screen.txt");
}

void Screens::load_door_data()
{
    //Loading door_menu textures
    door_menu_tex[0].loadFromFile("Textures/Door/Menu/1.png");
    door_menu_tex[1].loadFromFile("Textures/Door/Menu/2.png");
    door_menu_sp.setTexture(door_menu_tex[0]);
    door_menu_sp.setPosition(Vector2f(452, 342));
    door_sb.loadFromFile("Sounds/Door_Open.wav");
    door_sound.setBuffer(door_sb);
}

void Screens::load_loading_screen()
{
    loading_screen = new Loading_Screen();
}

void Screens::Display_Screens(RenderWindow &window)
{
    Actual_screen->displayScreen(window);
    if(Actual_screen->is_removed()!=true && Actual_screen->enemies.is_it_empty()==0 && Actual_screen->enemies.is_everyone_dead())
    {
        for(int i=0;i<Actual_screen->getNumberOfConnections()-1;i++)
            Actual_screen->walls.pop_back();
        Actual_screen->set_removed(true);
    }
}

bool Screens::Check_tutorial_screen(RectangleShape &player_hitbox)
{
    Screen *temp=nullptr;
    int i=0;
    if(player_hitbox.getPosition().x>=1600)
    {
        while (tutorial_screens[i]->getID()!=Actual_screen->goRight())
            i++;
        Actual_screen= tutorial_screens[i];
        tutorial_screens[i]->setVisited(true);
        player_hitbox.setPosition(Vector2f(-54,player_hitbox.getPosition().y));
    }
    else if(player_hitbox.getPosition().x<0-player_hitbox.getGlobalBounds().width)
    {
        while (tutorial_screens[i]->getID()!=Actual_screen->goLeft())
            i++;
        Actual_screen= tutorial_screens[i];
        tutorial_screens[i]->setVisited(true);
        player_hitbox.setPosition(Vector2f(1600,player_hitbox.getPosition().y));
    }
    else if(player_hitbox.getPosition().y>900)
    {
        while (tutorial_screens[i]->getID()!=Actual_screen->goDown())
            i++;
        Actual_screen= tutorial_screens[i];
        tutorial_screens[i]->setVisited(true);
        player_hitbox.setPosition(Vector2f(player_hitbox.getPosition().x,-68));
    }
    else if(player_hitbox.getPosition().y<0-player_hitbox.getGlobalBounds().height)
    {
       while (tutorial_screens[i]->getID()!=Actual_screen->goUp())
            i++;
        Actual_screen= tutorial_screens[i];
        tutorial_screens[i]->setVisited(true);
        player_hitbox.setPosition(Vector2f(player_hitbox.getPosition().x,900));
    }
    if (Actual_screen->getID() == 9)
        return true;
    else
        return false;
}

bool Screens::Check_adventure_screen(RectangleShape& player_hitbox)
{
    Screen* temp = nullptr;
    int i = 0;
    if (player_hitbox.getPosition().x >= 1600)
    {
        while (adventure_screens[i]->getID() != Actual_screen->goRight())
            i++;
        Actual_screen = adventure_screens[i];
        Actual_adventure_screen = Actual_screen;
        player_hitbox.setPosition(Vector2f(-54, player_hitbox.getPosition().y));
        if (!Actual_screen->isVisited())
        {
            Actual_screen->setVisited(true);
            return true;
        }
    }
    else if (player_hitbox.getPosition().x < 0 - player_hitbox.getGlobalBounds().width)
    {
        while (adventure_screens[i]->getID() != Actual_screen->goLeft())
            i++;
        Actual_screen = adventure_screens[i];
        Actual_adventure_screen = Actual_screen;
        player_hitbox.setPosition(Vector2f(1600, player_hitbox.getPosition().y));
        if (!Actual_screen->isVisited())
        {
            Actual_screen->setVisited(true);
            return true;
        }
    }
    else if (player_hitbox.getPosition().y > 900)
    {
        while (adventure_screens[i]->getID() != Actual_screen->goDown())
            i++;
        Actual_screen = adventure_screens[i];
        Actual_adventure_screen = Actual_screen;
        player_hitbox.setPosition(Vector2f(player_hitbox.getPosition().x, -68));
        if (!Actual_screen->isVisited())
        {
            Actual_screen->setVisited(true);
            return true;
        }
    }
    else if (player_hitbox.getPosition().y < 0 - player_hitbox.getGlobalBounds().height)
    {
        while (adventure_screens[i]->getID() != Actual_screen->goUp())
            i++;
        Actual_screen = adventure_screens[i];
        Actual_adventure_screen = Actual_screen;
        player_hitbox.setPosition(Vector2f(player_hitbox.getPosition().x, 900));
        if (!Actual_screen->isVisited())
        {
           Actual_screen->setVisited(true);
            return true;
        }
    }
    return false;
}

void Screens::delete_all_screens()
{
    delete_all_tutorial_screens();
    delete_all_adventure_screens();

    if (arena_screen != nullptr)
    {
        arena_screen->clear_space();
        delete arena_screen;
    }
    
}

void Screens::delete_all_tutorial_screens()
{
    for (int i = 0; i < tutorial_screens.size(); i++)
    {
        tutorial_screens[i]->clear_space();
        delete tutorial_screens[i];
    }
    tutorial_screens.clear();
}

void Screens::delete_all_adventure_screens()
{
    for (int i = 0; i < adventure_screens.size(); i++)
    {
        adventure_screens[i]->clear_space();
        delete adventure_screens[i];
    }
    adventure_screens.clear();
}

void Screens::open_door(Door* d)
{
    door_sound.play();
    Actual_screen->open_door(d);
}

Screen* Screens::get_tutorial_screen_by_ID(int ID)
{
    for (int i = 0; i < tutorial_screens.size(); i++)
        if (tutorial_screens[i]->getID() == ID)
            return tutorial_screens[i];
    return nullptr;
}