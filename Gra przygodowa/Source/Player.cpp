#include "Player.h"

Player::Player()
{
    animations.LoadAnimationsFromFile("Data/Player_Animations.txt");
    HP=60;
    MANA=60;
    MaxHP=60;
    MaxMANA=60;
    hitbox.setSize(Vector2f(62,74));
    hitbox.setPosition(Vector2f(400,400));
    colliders[0]=0;
    colliders[1]=0;
    colliders[2]=0;
    colliders[3]=0;
    is_attacking=0;
    is_inventory_open=0;
    is_dead=0;
    death_counter=0;
    speed_of_movement=4;
    Mana_regen=1;
    damage=10;
    movement_indicator=1;
    missile_width=32;
    missile_height=25;
    HP_Red.setFillColor(Color::Red);
    HP_Black.setFillColor(Color::Black);
    MANA_Blue.setFillColor(Color::Blue);
    MANA_Black.setFillColor(Color::Black);
    HP_Red.setSize(Vector2f(240,20));
    MANA_Blue.setSize(Vector2f(243,30));
    HP_Red.setPosition(Vector2f(20,18));
    MANA_Blue.setPosition(Vector2f(19,105));

    HP_Tex.loadFromFile("Textures/Player/Bars/HP.png");
    Mana_Tex.loadFromFile("Textures/Player/Bars/MANA.png");
    HP_Sp.setTexture(HP_Tex);
    Mana_Sp.setTexture(Mana_Tex);
    HP_Sp.setPosition(Vector2f(10,10));
    Mana_Sp.setPosition(Vector2f(10,95));


    Attack_buffer.loadFromFile("Sounds/fireball.wav");
    Attack_Sound.setBuffer(Attack_buffer);
    Death_buffer.loadFromFile("Sounds/Mage_Death.wav");
    Death_sound.setBuffer(Death_buffer);
    Attack_buffer.loadFromFile("Sounds/fireball.wav");
    Drink_buffer.loadFromFile("Sounds/Drink.wav");
    Drink_sound.setBuffer(Drink_buffer);
    Attack_Sound.setVolume(20);
    Death_sound.setVolume(20);
}

void Player::movement(RenderWindow &window, int counter)
{
    /*Speed=2;
    if(Keyboard::isKeyPressed(Keyboard::LShift))
        Speed+=2;
    if(!Keyboard::isKeyPressed(Keyboard::LShift)&&Speed!=2)
        Speed-=2;*/
    if(is_attacking==1)
        Speed=0;
    else
        Speed=speed_of_movement;
    if(Keyboard::isKeyPressed(Keyboard::D)&& colliders[0]==0)
    {
        movement_indicator=1;
        hitbox.move(Speed,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::A)&& colliders[1]==0)
    {
        movement_indicator=2;
        hitbox.move(-Speed,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::W)&& colliders[2]==0)
    {
        hitbox.move(0,-Speed);
    }
    if(Keyboard::isKeyPressed(Keyboard::S)&& colliders[3]==0)
    {
        hitbox.move(0,Speed);
    }

    if(is_attacking==0)
    {
        if(Keyboard::isKeyPressed(Keyboard::W)||Keyboard::isKeyPressed(Keyboard::S)||Keyboard::isKeyPressed(Keyboard::A)||Keyboard::isKeyPressed(Keyboard::D))
        {
            switch(movement_indicator)
            {
            case 1:
                animations.find_animation(2)->Display_animation(window,hitbox.getPosition(),counter);
                break;
            case 2:
                animations.find_animation(1)->Display_animation(window,hitbox.getPosition(),counter);
                break;
            }
        }
        else
        {
    switch(movement_indicator)
            {
            case 1:
                animations.find_animation(4)->Display_animation(window,hitbox.getPosition(),counter);
                break;
            case 2:
                animations.find_animation(3)->Display_animation(window,hitbox.getPosition(),counter);
                break;
            }
        }
    }
}

 void Player::set_GodMode()
 {
     speed_of_movement=10;
     MaxHP=100000;
     HP=100000;
     Mana_regen=10;
 }

void Player::set_NormalMode()
{
    speed_of_movement=4;
    MaxHP=60;
    HP=60;
    Mana_regen=1;
}

void Player::Check_collision_with_enviornment(RenderWindow &window, std::vector<Wall*>& walls)
{
    int collision_right,collision_left,collision_up,collision_down;
    collision_right=0;
    collision_left=0;
    collision_down=0;
    collision_up=0;
    //Collision with edges of screen
    /*if(hitbox.getPosition().x+hitbox.getSize().x>window.getSize().x)
        collision_right=1;
    else
        collision_right=0;
    if(hitbox.getPosition().x<0)
        collision_left=1;
    else
        collision_left=0;
    if(hitbox.getPosition().y+hitbox.getSize().y>window.getSize().y)
        collision_down=1;
    else
        collision_down=0;
    if(hitbox.getPosition().y<0)
        collision_up=1;
    else
        collision_up=0;*/
    //Collision with Colliding Objects
    for (int i=0; i<walls.size();i++)
    {
       if(hitbox.getPosition().x+hitbox.getGlobalBounds().width+3>=walls[i]->box.getPosition().x && hitbox.getPosition().x+hitbox.getGlobalBounds().width<walls[i]->box.getPosition().x +
           walls[i]->box.getGlobalBounds().width && hitbox.getPosition().y+hitbox.getGlobalBounds().height>walls[i]->box.getPosition().y
           && hitbox.getPosition().y<walls[i]->box.getPosition().y+walls[i]->box.getGlobalBounds().height)
            collision_right=1;
        if(hitbox.getPosition().x-3<=walls[i]->box.getPosition().x+walls[i]->box.getGlobalBounds().width && hitbox.getPosition().x>walls[i]->box.getPosition().x
           && hitbox.getPosition().y+hitbox.getGlobalBounds().height>walls[i]->box.getPosition().y
           && hitbox.getPosition().y<walls[i]->box.getPosition().y+walls[i]->box.getGlobalBounds().height)
           collision_left=1;
        if(hitbox.getPosition().x+hitbox.getGlobalBounds().width>walls[i]->box.getPosition().x && hitbox.getPosition().x<walls[i]->box.getPosition().x+walls[i]->box.getGlobalBounds().width
           && hitbox.getPosition().y>=walls[i]->box.getPosition().y+3
           && hitbox.getPosition().y<=walls[i]->box.getPosition().y+walls[i]->box.getGlobalBounds().height+3)
               collision_up=1;
        if(hitbox.getPosition().x+hitbox.getGlobalBounds().width>walls[i]->box.getPosition().x && hitbox.getPosition().x<walls[i]->box.getPosition().x+walls[i]->box.getGlobalBounds().width
           && hitbox.getPosition().y+hitbox.getGlobalBounds().height>=walls[i]->box.getPosition().y-3
           && hitbox.getPosition().y<=walls[i]->box.getPosition().y-3)
               collision_down=1;
    }
    colliders[0]=collision_right;
    colliders[1]=collision_left;
    colliders[2]=collision_up;
    colliders[3]=collision_down;
}

Missile* Player::Maintenance(RenderWindow &window,int counter,std::vector<Wall*>& walls,int open,std::vector <RectangleShape*>Slashes,Missiles& enemies_missiles)
{
    Missile *m=nullptr;
    if(HP<=0)
        is_dead=1;
    if(is_dead!=1)
    {
        Check_enemies_missiles(enemies_missiles);
        m=attack(window, counter);
        Check_collision_with_enviornment(window, walls);
        movement(window, counter);
        Check_slashes(Slashes);
        Display_HP_and_Mana(window);
        Display_inventory(window,open);
        if(MANA<60)
            MANA+=Mana_regen;
    }
    if(is_dead==1 && death_counter==0)
        Death_sound.play();
    if(is_dead==1 && death_counter<48)
    {
        if(movement_indicator==1)
            animations.find_animation(7)->Display_animation(window,hitbox.getPosition(),death_counter);
        else
            animations.find_animation(8)->Display_animation(window,hitbox.getPosition(),death_counter);
        death_counter++;
    }
    else if(is_dead==1 && death_counter>=48)
    {
        if(movement_indicator==1)
            animations.find_animation(13)->Display_animation(window,hitbox.getPosition(),counter);
        else
            animations.find_animation(14)->Display_animation(window,hitbox.getPosition(),counter);
    }
    return m;
}

void Player::Display_inventory(RenderWindow &window,int open)
{
    if(open==1 && is_inventory_open==0)
    {
        is_inventory_open=1;
        inventory.Display_Inventory(window);
    }
    else if(is_inventory_open==1&&open!=0)
        inventory.Display_Inventory(window);
    else
    {
        is_inventory_open=0;
    }
}

void Player::heal()
{
    if(inventory.Is_there_an_item(1)==1)
    {
        inventory.delete_item_from_inventory(1);
        Drink_sound.play();
        if(HP<=40)
            HP+=20;
        else
            HP=60;
    }
}

void Player::add_item_to_Inventory(int ID, Items &all_items)
{
    inventory.add_item_to_inventory(ID,all_items);
}

void Player::remove_item_from_Inventory(int ID)
{
    inventory.delete_item_from_inventory(ID);
}

Missile* Player::attack(RenderWindow &window, int counter)
{
    Missile *m=nullptr;
    int k;
    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        is_attacking=1;
        animations.find_animation(6)->Display_animation(window,hitbox.getPosition(),counter);
        if(MANA>50)
        {
            MANA-=50;
            missile_indicator=1;
            m = new Missile(missile_indicator,Vector2f(hitbox.getPosition().x+hitbox.getSize().x,hitbox.getPosition().y+(hitbox.getSize().y/12)),animations.find_animation(12),damage,missile_width,missile_height,Attack_hit);
        }
    }
    else if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        is_attacking=1;
        animations.find_animation(5)->Display_animation(window,hitbox.getPosition(),counter);
        if(MANA>50)
        {
            MANA-=50;
            missile_indicator=2;
            m = new Missile(missile_indicator,Vector2f(hitbox.getPosition().x,hitbox.getPosition().y+(hitbox.getSize().y/12)),animations.find_animation(11),damage, missile_width,missile_height,Attack_hit);
        }
    }
    else if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        is_attacking=1;
        switch(movement_indicator)
        {
        case 1:
            animations.find_animation(6)->Display_animation(window,hitbox.getPosition(),counter);
            k=1;
            break;
        case 2:
            animations.find_animation(5)->Display_animation(window,hitbox.getPosition(),counter);
            k=1/100;
            break;
        }
        if(MANA>50)
        {
            MANA-=50;
            missile_indicator=3;
            m = new Missile(missile_indicator,Vector2f(hitbox.getPosition().x+(hitbox.getSize().x*k),hitbox.getPosition().y),animations.find_animation(9),damage, missile_width,  missile_height,Attack_hit);
        }
    }
    else if(Keyboard::isKeyPressed(Keyboard::Down))
    {
        is_attacking=1;
        switch(movement_indicator)
        {
        case 1:
            animations.find_animation(6)->Display_animation(window,hitbox.getPosition(),counter);
            k=1;
            break;
        case 2:
            animations.find_animation(5)->Display_animation(window,hitbox.getPosition(),counter);
            k=1/100;
            break;
        }
        if(MANA>50)
        {
            MANA-=50;
            missile_indicator=4;
            is_attacking=1;
            m = new Missile(missile_indicator,Vector2f(hitbox.getPosition().x+(hitbox.getSize().x*k),hitbox.getPosition().y+hitbox.getSize().y/10),animations.find_animation(10),damage, missile_width,  missile_height,Attack_hit);
        }
    }
    if(!Keyboard::isKeyPressed(Keyboard::Up)&&!Keyboard::isKeyPressed(Keyboard::Right)&&!Keyboard::isKeyPressed(Keyboard::Left)&&!Keyboard::isKeyPressed(Keyboard::Down))
        is_attacking=0;
    if(m!=nullptr)
        Attack_Sound.play();
    return m;
}

void Player::Check_slashes(std::vector<RectangleShape*>Slashes)
{
    for(int i=0; i<Slashes.size();i++)
    {
        if(Slashes[i]->getGlobalBounds().intersects(hitbox.getGlobalBounds()))
        {
            //getHit(10);
            Hit_ptr(this,10);
            Slashes.erase(Slashes.begin()+i);
        }
    }
    Slashes.erase(Slashes.begin(),Slashes.end());
}

void Player::Check_enemies_missiles(Missiles& enemies_missiles)
{
    Missile*temp=nullptr;
    temp=enemies_missiles.getHead();
            while(temp!=nullptr)
            {
                if(temp->getHitbox().getGlobalBounds().intersects(hitbox.getGlobalBounds()))
                {
                    getHit(temp->getDamageValue());
                    temp->play_sound();//??
                    enemies_missiles.delete_missile(temp);
                    temp=nullptr;
                }
                if(temp!=nullptr)
                temp=temp->getNext();
            }
}

void Player::Display_HP_and_Mana(RenderWindow &window)
{
    int maxsize=240;
    window.draw(HP_Red);
    window.draw(MANA_Blue);
    HP_Black.setPosition(HP_Red.getPosition().x+HP_Red.getGlobalBounds().width-((MaxHP-HP)*(HP_Red.getGlobalBounds().width)/MaxHP),HP_Red.getPosition().y);
    HP_Black.setSize(Vector2f((MaxHP-HP)*((HP_Red.getGlobalBounds().width)/MaxHP),HP_Red.getGlobalBounds().height));
    MANA_Black.setPosition(MANA_Blue.getPosition().x+MANA_Blue.getGlobalBounds().width-((MaxMANA-MANA)*(MANA_Blue.getGlobalBounds().width)/MaxMANA),MANA_Blue.getPosition().y);
    MANA_Black.setSize(Vector2f((MaxMANA-MANA)*((MANA_Blue.getGlobalBounds().width)/MaxMANA),MANA_Blue.getGlobalBounds().height));
    window.draw(HP_Black);
    window.draw(MANA_Black);
    window.draw(HP_Sp);
    window.draw(Mana_Sp);
}
