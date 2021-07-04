#include "Missiles.h"

void Missiles::add_missile(Missile* added)
{
    if(added==nullptr)
        return;
    added->setNext(nullptr);
    if(head==nullptr)
    {
        head=added;
        return;
    }
    else
    {
        Missile *temp=head;
        while(temp->getNext()!=nullptr)
            temp=temp->getNext();
        temp->setNext(added);
        return;
    }
}

void Missiles::delete_all_missiles()
{
    Missile*temp;
    while(head!=nullptr)
    {
        temp=head->getNext();
        delete head;
        head=temp;
    }
}

void Missiles::delete_missile(Missile* deleted)
{
    if(head==deleted)
    {
        head=head->getNext();
        delete deleted;
        return;
    }
    else
    {
        Missile* temp=head;
        while(temp->getNext()!=deleted)
            temp=temp->getNext();
        temp->setNext(deleted->getNext());
        delete deleted;
        return;
    }
}

void Missiles::Update_all_missiles(RenderWindow &window)
{
    Missile *temp=head;
    while(temp!=nullptr)
    {
        int direction = temp->GetDirection();
        switch(direction)
        {
        case 1:
            temp->setPosition(Vector2f(temp->GetPosition().x+7,temp->GetPosition().y));
            break;
        case 2:
            temp->setPosition(Vector2f(temp->GetPosition().x-7,temp->GetPosition().y));
            break;
        case 3:
            temp->setPosition(Vector2f(temp->GetPosition().x,temp->GetPosition().y-7));
            break;
        case 4:
            temp->setPosition(Vector2f(temp->GetPosition().x,temp->GetPosition().y+7));
        }
        Missile *temp2;
        temp2=temp->getNext();
        /*if(temp->GetPosition().x<0-temp->getHitbox().getSize().x||temp->GetPosition().x>window.getSize().x+temp->getHitbox().getSize().x||temp->GetPosition().y<0-temp->getHitbox().getSize().y||temp->GetPosition().y>window.getSize().y+temp->getHitbox().getSize().y)
        {
            delete_missile(temp);
        }*/

        if (temp->GetPosition().x < 0 - temp->getHitbox().getSize().x || temp->GetPosition().x>1600 || temp->GetPosition().y < 0 - temp->getHitbox().getSize().y || temp->GetPosition().y>900)
        {
            delete_missile(temp);
        }

        temp=temp2;
    }
}

void Missiles::Display_all_missiles(RenderWindow &window, int counter)
{
    Missile* temp=head;
    while(temp!=nullptr)
    {
        temp->Display_missile(window, counter);
        temp=temp->getNext();
    }
}

void Missiles::maintenance(RenderWindow&window, int counter)
{
    Update_all_missiles(window);
    Display_all_missiles(window, counter);
}
