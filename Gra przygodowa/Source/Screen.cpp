#include "Screen.h"

Screen::Screen(std::string info_file)
{
    std::ifstream fp;
    fp.open(info_file);
    int temp_1,temp_2,temp_3,temp_4,temp_5;
    std::string temp_string1,temp_string2;
    std::vector<int> item_ids;
    fp>>ID;
    fp>>rightID;
    fp>>leftID;
    fp>>upID;
    fp>>downID;
    fp>>howManyConnections;
    fp>>temp_string1;
    pic.loadFromFile(temp_string1);
    Bck.setTexture(pic);
    while(true)
    {
        if(fp.good());
        else
            break;
        fp>>temp_string1;
        if(temp_string1=="NC_Object")
        {
            fp>>temp_string1;
            fp>>temp_1;
            fp>>temp_2;
            Vector2f l(temp_1,temp_2);
            add_NC_Object(temp_string1,l);//Vector2f(temp_1,temp_2));
        }
        if(temp_string1=="Wall")
        {
            fp>>temp_string1;
            fp>>temp_1;
            fp>>temp_2;
            fp>>temp_3;
            fp>>temp_4;
            add_wall(temp_string1,Vector2f(temp_1,temp_2),Vector2f(temp_3,temp_4));

        }
        if (temp_string1 == "Door")
        {
            fp >> temp_string1;
            fp >> temp_1;
            fp >> temp_2;
            fp >> temp_3;
            fp >> temp_4;
            fp >> temp_5;
            Wall * wall = add_wall("Textures/Walls/Blank.png", Vector2f(temp_1, temp_2), Vector2f(temp_3, temp_4));
            add_door(temp_string1,wall, temp_5);
        }
        if(temp_string1=="Chest")
        {
            fp>>temp_string1;
            fp>>temp_string2;
            fp>>temp_1;
            fp>>temp_2;
            fp>>temp_3;
            fp>>temp_4;
            fp>>temp_5;
            for(int i=0;i<temp_5;i++)
            {
                int x;
                fp>>x;
                item_ids.push_back(x);
            }
            add_chest(temp_string1,temp_string2,Vector2f(temp_1,temp_2),Vector2f(temp_3,temp_4),item_ids);
            item_ids.clear();
        }
        if(temp_string1=="Enemy")
        {
            fp>>temp_string1;
            fp>>temp_1;
            fp>>temp_2;
            enemies.add_enemy(temp_string1,Vector2f(temp_1,temp_2));
        }
        if(temp_string1=="NPC")
        {
            fp>>temp_string1;
            fp>>temp_1;
            fp>>temp_2;
            npcs.add_npc(temp_string1,Vector2f(temp_1,temp_2));
        }
    }
    fp.close();
    removed=1;
}

Screen::~Screen()
{

}

void Screen::clear_space()
{
    clearData_Bck();
    clear_data_CO();
    enemies_missiles.delete_all_missiles();
    player_missiles.delete_all_missiles();
    enemies.delete_all_enemies();
    npcs.remove_all_npcs();
}

void Screen::displayScreen(RenderWindow &window)
{
    displayBackground(window);
    display_CO(window,enemies.is_everyone_dead());
}

Chest* Screen::check_chests(RectangleShape players_hitbox)
{
    if(enemies.is_everyone_dead())
    {
        for(int i=0;i<chests.size();i++)
        {
            if(players_hitbox.getGlobalBounds().intersects(chests[i]->box.getGlobalBounds())&& chests[i]->is_open==0)
                return chests[i];
        }
        return nullptr;
    }
    else
    {
        return nullptr;
    }

}

Door* Screen::check_doors(RectangleShape players_hitbox)
{
    if (enemies.is_everyone_dead())
    {
        for (int i = 0; i < doors.size(); i++)
        {
            if (players_hitbox.getGlobalBounds().intersects(doors[i]->get_box().getGlobalBounds()))
                return doors[i];
        }
        return nullptr;
    }
    else
    {
        return nullptr;
    }
}