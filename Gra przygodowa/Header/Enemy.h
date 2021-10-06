#ifndef ENEMY_H
#define ENEMY_H

#include "Items.h"
#include "Character.h"
#include "C_Objects.h"
#include "Missiles.h"
#include <math.h>

class Enemy : private Character
{
    public:
        Enemy(std::string Type,Vector2f position);
        Enemy(Enemy* base, Vector2f position);
        virtual ~Enemy();
        RectangleShape* Maintance_Melee(RenderWindow &window, int counter, RectangleShape players_hitbox, int is_player_dead);
        RectangleShape* Swing(RectangleShape players_hitbox, int is_player_dead);
        Enemy* getNext() { return next; }
        void Maintance_Range(RenderWindow& window, int counter, RectangleShape players_hitbox, int is_player_dead, Missiles& enemies_missiles);
        void Display_HP(RenderWindow &window);
        void Follow_player(RectangleShape players_hitbox, int counter, RenderWindow& window);    
        void setNext(Enemy *pnext){next=pnext;}
        void Check_Swing(RectangleShape players_hitbox, int is_player_dead);      
        void Range_Attack(RectangleShape players_hitbox,int is_player_dead);
        void getHit(int damage){HP-=damage;}

        RectangleShape getHitbox(){return hitbox;}
        Animations getAnimations() { return animations; }
        SoundBuffer getAttackBuffer() { return Attack_buffer; }
        SoundBuffer getDeathBuffer() { return Death_buffer; }
        SoundBuffer getAttackHit() { return Attack_hit; }
        std::string getType() { return type; }
        int is_enemy_dead(){return is_dead;}
        int Range(){return range;}
        int getSwingWidth() { return Swing_width; }
        int getAttackCounterMax() { return Attack_counter_max; }
        int getAttackLeft() { return Attack_left; }
        int getAttackUp() { return Attack_up; }
        int getMaxHp() { return MaxHP; }
        int getMissileWidth() { return missile_width; }
        int getMissileHeight() { return missile_height; }
        int getDamage() { return damage; }
        int getAttackFrame() { return Attack_frame; }
        

    private:
        std::string type;
        RectangleShape hitbox;
        int Swing_width;
        int Attack_counter;
        int Attack_counter_max;
        int Attack_frame;
        int Attack_left;
        int Attack_up;
        int range; //0 - Melee  1 - Range
        Enemy *next;
};

#endif // ENEMY_H
