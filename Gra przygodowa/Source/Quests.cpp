#include "Quests.h"

Quests::Quests()
{
    //ctor
}

Quests::~Quests()
{
    remove_all_nt_quests();
    remove_all_t_quests();
}

void Quests::prepare_quests()
{
    load_quests();
    getFont();
    tex.loadFromFile("Textures/Quests/Background.png");
    sp.setTexture(tex);
    sp.setPosition(10,600);
}

void Quests::add_t_quest(int id)
{
    Taken_Quests::add_t_quest(id,not_taken_quests);
}

void Quests::add_t_quest_display(int id, RenderWindow& window, int counter)
{
    Taken_Quests::add_t_quest_display(window, id, not_taken_quests,counter);
}

 void Quests::Display_quests(RenderWindow &window)
 {
     window.draw(sp);
     display_active_quests(window,sp.getPosition());
 }
