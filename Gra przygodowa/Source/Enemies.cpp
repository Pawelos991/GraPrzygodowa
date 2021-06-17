#include "Enemies.h"

void Enemies::add_enemy(std::string Type,Vector2f position)
{
    Enemy* new_enemy=new Enemy(Type,position);
    if(head==nullptr)
    {
        head=new_enemy;
        return;
    }
    else
    {
        Enemy* temp=head;
        while(temp->getNext()!=nullptr)
            temp=temp->getNext();
        temp->setNext(new_enemy);
    }
}

void Enemies::delete_enemy(Enemy* deleted)
{
    if(deleted==head)
    {
        head=head->getNext();
        delete deleted;
        return;
    }
    else
    {
        Enemy* temp=head;
        while(temp->getNext()!=nullptr && temp->getNext()!=deleted)
            temp=temp->getNext();
        temp->setNext(deleted->getNext());
        delete deleted;
    }
}

void Enemies::delete_all_enemies()
{
    Enemy* temp=head;
    while(head!=nullptr)
    {
        temp=head->getNext();
        delete head;
        head=temp;
    }
}

std::vector<RectangleShape*> Enemies::Maintenance(RenderWindow &window, int counter, RectangleShape players_hitbox, int is_player_dead, Missiles& player_missiles, Missiles& enemies_missiles)
{
    std::vector<RectangleShape*> Slashes;
    Enemy* temp=head;
    RectangleShape* slash;
    Missile* missile_temp;
    int how_many=0;
    while(temp!=nullptr)
    {
        how_many++;
        slash=nullptr;
        missile_temp=player_missiles.getHead();
        if(temp->is_enemy_dead()==0)
        {
            while(missile_temp!=nullptr)
            {
                if(missile_temp->getHitbox().getGlobalBounds().intersects(temp->getHitbox().getGlobalBounds()))
                {
                    //temp->getHit(missile_temp->getDamageValue());
                    Hit_ptr(temp,missile_temp->getDamageValue());
                    player_missiles.delete_missile(missile_temp);
                    missile_temp=nullptr;
                }
                if(missile_temp!=nullptr)
                missile_temp=missile_temp->getNext();
            }
        }
        if(temp->Range()==0)
        {
            slash=temp->Maintance_Melee(window, counter,players_hitbox,is_player_dead);
            if(slash!=nullptr)
                Slashes.push_back(slash);
        }
        else
            temp->Maintance_Range(window,counter,players_hitbox,is_player_dead,enemies_missiles);

        temp=temp->getNext();
    }
    if(how_many>70)
        delete_enemy(head);
    return Slashes;
}

int Enemies::is_everyone_dead()
{
    Enemy*temp=head;
    int is_everyone_d=1; // 0 - No, 1 - Yes
    while(temp!=nullptr)
    {
        if(temp->is_enemy_dead()==0)
            is_everyone_d=0;
        temp=temp->getNext();
    }
    return is_everyone_d;
}

int Enemies::is_it_empty()
{
    if(head==nullptr)
        return 1;
    else
        return 0;
}
