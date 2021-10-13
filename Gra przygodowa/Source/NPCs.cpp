#include "NPCs.h"

NPCs::~NPCs()
{
    remove_all_npcs();
}

void NPCs::add_npc(std::string name,Vector2f position)
{
    NPC *temp=new NPC(name,position);
    if(head==nullptr)
    {
        head=temp;
        return;
    }
    else if(head->getNext()==nullptr)
    {
        head->setNext(temp);
        return;
    }
    else
    {
        NPC* temp2;
        temp2=head;
        while(temp2->getNext()!=nullptr)
            temp2=temp2->getNext();
        temp2->setNext(temp);
    }
}

void NPCs::remove_npc(NPC* removed)
{
    if(removed==head)
    {
        head=head->getNext();
        removed->Empty_Memory();
        delete removed;
        return;
    }
    else if(removed==head->getNext())
    {
        head->setNext(head->getNext()->getNext());
        removed->Empty_Memory();
        delete removed;
        return;
    }
    else
    {
        NPC*temp2;
        temp2=head;
        while(temp2->getNext()!=removed)
            temp2=temp2->getNext();
        temp2->setNext(temp2->getNext()->getNext());
        removed->Empty_Memory();
        delete removed;
    }
}

void NPCs::remove_all_npcs()
{
    NPC*temp;
    while(head!=nullptr)
    {
        temp=head->getNext();
        head->Empty_Memory();
        delete head;
        head=temp;
    }
}

void NPCs::Maintance(RenderWindow &window,int counter,RectangleShape players_hitbox)
{
    NPC *temp;
    temp=head;
    while(temp!=nullptr)
    {
        temp->Maintance(window,counter,players_hitbox);
        temp=temp->getNext();
    }
}
