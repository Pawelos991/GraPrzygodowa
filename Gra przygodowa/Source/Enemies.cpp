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

void Enemies::add_enemy(Enemy* enemy)
{
    if (head == nullptr)
    {
        head = enemy;
        return;
    }
    else
    {
        Enemy* temp = head;
        while (temp->getNext() != nullptr)
            temp = temp->getNext();
        temp->setNext(enemy);
    }
}

void Enemies::delete_enemy(Enemy* deleted)
{
    if(deleted==head)
    {
        head=head->getNext();
        deleted->Empty_Memory();
        delete deleted;
        return;
    }
    else
    {
        Enemy* temp=head;
        while(temp->getNext()!=nullptr && temp->getNext()!=deleted)
            temp=temp->getNext();
        temp->setNext(deleted->getNext());
        deleted->Empty_Memory();
        delete deleted;
    }
}

void Enemies::delete_all_enemies()
{
    Enemy* temp=head;
    while(head!=nullptr)
    {
        temp=head->getNext();
        head->Empty_Memory();
        delete head;
        head=temp;
    }
}

std::vector<RectangleShape*> Enemies::Maintenance(RenderWindow &window, int counter, RectangleShape players_hitbox, bool is_player_dead, Missiles& player_missiles, Missiles& enemies_missiles)
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
    if(how_many>20)
        delete_enemy(head);
    return Slashes;
}

bool Enemies::is_everyone_dead()
{
    Enemy*temp=head;
    bool is_everyone_d=true;
    while(temp!=nullptr)
    {
        if(temp->is_enemy_dead()==0)
            is_everyone_d=false;
        temp=temp->getNext();
    }
    return is_everyone_d;
}

bool Enemies::is_it_empty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}

Enemy* Enemies::getEnemyByName(std::string name)
{
    Enemy* temp = head;
    while (temp != nullptr)
    {
        if (temp->getType() == name)
            break;
        temp = temp->getNext();
    }
    return temp;
}

void Enemies::update_adventure_stats(Adventure_Stats& stats)
{
    Enemy* temp = head;
    while (temp != nullptr)
    {
        if (temp->is_enemy_dead() && !temp->getReportedDeath())
        {
            std::string enemy_type = temp->getType();
            if (enemy_type == "Minotaur")
                stats.add_killed_minotaur();
            else if (enemy_type == "Dwarf")
                stats.add_killed_dwarf();
            else if (enemy_type == "Archer")
                stats.add_killed_archer();
            else if (enemy_type == "Knight")
                stats.add_killed_knight();
            else if (enemy_type == "Snake")
                stats.add_killed_snake();
            else if (enemy_type == "Scorpion")
                stats.add_killed_scorpion();
            temp->setReportedDeath();
        }
        temp = temp->getNext();
    }
}