#ifndef ENEMIES_H
#define ENEMIES_H

#include "Enemy.h"

class Enemies
{
    public:
        Enemies():head(nullptr){}
        ~Enemies(){delete_all_enemies();}
        void add_enemy(std::string Type,Vector2f position);
        void add_enemy(Enemy* enemy);
        void delete_enemy(Enemy* deleted);
        void delete_all_enemies();
        bool is_everyone_dead();
        bool is_it_empty();
        Enemy* getEnemyByName(std::string name);

        std::vector<RectangleShape*> Maintenance(RenderWindow &window, int counter, RectangleShape players_hitbox, int is_player_dead,Missiles& player_missiles, Missiles& enemies_missiles);

    private:
        Enemy* head;

};

#endif // ENEMIES_H
