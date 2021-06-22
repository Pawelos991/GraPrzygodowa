#include "Taken_Quests.h"

Taken_Quests::Taken_Quests()
{
}

Taken_Quests::~Taken_Quests()
{
    //dtor
}

void Taken_Quests::getFont()
{
    font.loadFromFile("Fonts/Arial.ttf");
    text.setFont(font);
}

void Taken_Quests::add_t_quest(int id, std::vector<Quest*> &not_taken_quests)
{
    int i=0;
    while(not_taken_quests[i]->getID()!=id)
        i++;
    taken_quests.push_back(not_taken_quests[i]);
}

void Taken_Quests::remove_t_quest(int id)
{
    int i=0;
    while(taken_quests[i]->getID()!=id)
        i++;
    taken_quests.erase(taken_quests.begin()+i);
}

void Taken_Quests::remove_all_t_quests()
{
    taken_quests.erase(taken_quests.begin(),taken_quests.end());
}

void Taken_Quests::complete_quest(int id)
{
    int i=0;
     while(taken_quests[i]->getID()!=id)
        i++;
    taken_quests[i]->complete();
}

void Taken_Quests::display_active_quests(RenderWindow &window, Vector2f position)
{
    int x,y;
    x=10;
    y=70;
    for(int i=0;i<taken_quests.size();i++)
    {
    text.setPosition(Vector2f(position.x+x,position.y+y));
    text.setString(taken_quests[i]->getName());
    text.setCharacterSize(30);
    text.setFillColor(Color::White);
    window.draw(text);
    x+=10;
    y+=35;
    text.setString(taken_quests[i]->getDesc());
    text.setPosition(Vector2f(position.x+x,position.y+y));
    text.setCharacterSize(20);
    text.setFillColor(Color::Black);
    window.draw(text);
    x-=10;
    y+=25;
    }

}

void Taken_Quests::display_new_quest(RenderWindow& window)
{
    Text te;
    te.setPosition(420, 450); 
    te.setString(taken_quests[taken_quests.size()-1]->getName());
    te.setCharacterSize(80);
    te.setFillColor(Color::Black);
    te.setFont(font);
    window.draw(te);
}