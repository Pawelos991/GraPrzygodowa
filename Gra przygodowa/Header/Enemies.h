#ifndef ENEMIES_H
#define ENEMIES_H

#include "Enemy.h"

class Enemies
{
    public:
        Enemies():head(nullptr){}
        ~Enemies(){delete_all_enemies();}
        void add_enemy(std::string Type,Vector2f position);
        void delete_enemy(Enemy* deleted);
        void delete_all_enemies();
        int is_everyone_dead(); // 0 - No  1 - Yes
        int is_it_empty(); // 0 - No 1 - Yes

        std::vector<RectangleShape*> Maintenance(RenderWindow &window, int counter, RectangleShape players_hitbox, int is_player_dead,Missiles& player_missiles, Missiles& enemies_missiles);

    private:
        Enemy* head;

};

#endif // ENEMIES_H
