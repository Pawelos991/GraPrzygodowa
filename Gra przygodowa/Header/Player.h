#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"
#include "Character.h"
#include "Missiles.h"
#include "C_Objects.h"


class Player : private Character
{
    public:
        Player();
        ~Player(){}
        void movement(RenderWindow &window, int counter);
        Missile* attack(RenderWindow &window, int counter);
        void Display_HP_and_Mana(RenderWindow &window);
        void Set_Position_of_player(Vector2f new_position){hitbox.setPosition(new_position);}
        void Check_collision_with_enviornment(RenderWindow &window, std::vector<Wall*>& walls);
        void add_item_to_Inventory(int ID, Items &all_items);
        void remove_item_from_Inventory(int ID);
        bool is_item_in_Inventory(int ID);
        void Display_inventory(RenderWindow &window,int open);
        void Check_enemies_missiles(Missiles& enemies_missiles);
        RectangleShape getHitbox(){return hitbox;}
        void getHit(int damage){HP-=damage;}
        int is_player_dead(){return is_dead;}
        void heal();
        void set_GodMode();
        void set_NormalMode();
        void Respawn(){is_dead=0;}

        Missile* Maintenance(RenderWindow &window,int counter,std::vector<Wall*>& walls,bool open,std::vector<RectangleShape*>Slashes,Missiles& enemies_missiles);
        void Check_slashes(std::vector<RectangleShape*>Slashes);

        RectangleShape hitbox;

    private:
        Inventory inventory;
        int missile_indicator; //1 -Right, 2 - Left, 3 - Up, 4 - Down
        int MANA;
        int MaxMANA;
        int Speed; //Used in move function
        int speed_of_movement; //Variable
        int Mana_regen;
        SoundBuffer Drink_buffer;
        Sound Drink_sound;
        int colliders[4]; //0 - Right, 1 - Left, 2 - Up, 3 - Down  0-No collision, 1 - Collision
        bool is_inventory_open;
        RectangleShape HP_Black;
        RectangleShape MANA_Blue;
        RectangleShape MANA_Black;
        Texture HP_Tex;
        Texture Mana_Tex;
        Sprite HP_Sp;
        Sprite Mana_Sp;

};

#endif // PLAYER_H
