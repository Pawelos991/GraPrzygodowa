#include "Enemy.h"

Enemy::Enemy(std::string Type,Vector2f position):type(Type)
{
    std::ifstream fp;
    std::string Name,animation_location,death_s,attack_s,attack_hit_s;
    int Range,maxhp,width,height,swing_frames,swing_w,attack_shift_left,attack_shift_up,Missile_Width,Missile_Height,dmg,attack_frame;
    try
    {
        fp.open("Data/Enemy_Data.txt");
        if(fp.good()==false)
            throw 1;
    }
    catch(int x)
    {
        if (x==1)
            std::cout<<"Brak pliku lub niepoprawny plik Data/Enemy_Data.txt"<<std::endl;
    }

    while(true)
    {
        if(fp.good());
        else
            break;
        fp>>Name;
        fp>>maxhp;
        fp>>dmg;
        fp>>Range;
        fp>>animation_location;
        fp>>width;
        fp>>height;
        fp>>swing_frames;
        fp>>attack_frame;
        fp>>swing_w;
        fp>>attack_shift_left;
        fp>>attack_shift_up;
        fp>>death_s;
        fp>>attack_s;
        fp>>Missile_Width;
        fp>>Missile_Height;
        if(Range==1)
            fp>>attack_hit_s;
        if(Name==type)
            break;
    }
    fp.close();

    animations.LoadAnimationsFromFile(animation_location);
    hitbox.setSize(Vector2f(width,height));
    hitbox.setPosition(position);
    damage=dmg;
    MaxHP=maxhp;
    HP=MaxHP;
    HP_Red.setSize(Vector2f(MaxHP,10));
    HP_Red.setFillColor(Color::Red);
    is_dead=0;
    range=Range;
    death_counter=0;
    is_attacking=0;
    Attack_counter=0;
    movement_indicator=2;
    Attack_counter_max=swing_frames;
    Attack_frame = attack_frame;
    Swing_width=swing_w;
    Attack_left=attack_shift_left;
    Attack_up=attack_shift_up;
    missile_width=Missile_Width;
    missile_height=Missile_Height;
    Attack_buffer.loadFromFile(attack_s);
    Death_buffer.loadFromFile(death_s);
    Attack_Sound.setBuffer(Attack_buffer);
    Death_sound.setBuffer(Death_buffer);
    Attack_Sound.setVolume(20);
    Death_sound.setVolume(20);
    if(Range==1)
        Attack_hit.loadFromFile(attack_hit_s);
    next=nullptr;
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::Maintance_Range(RenderWindow &window, int counter, RectangleShape players_hitbox, int is_player_dead,Missiles& enemies_missiles)
{
    Missile* M=nullptr;

    if(HP<=0)
        is_dead=1;
    if(is_dead==0)
    {
    if(is_attacking==1)
    {
        if(Attack_counter<Attack_counter_max)
        {
            if(Attack_counter==Attack_frame)
            {
                if(movement_indicator==1)
                    M= new Missile(movement_indicator,Vector2f(hitbox.getPosition().x-missile_width,hitbox.getPosition().y+(hitbox.getGlobalBounds().height/2)-missile_height),animations.find_animation(12),10,missile_width,missile_height,Attack_hit);
                else
                    M= new Missile(movement_indicator,Vector2f(hitbox.getPosition().x-missile_width,hitbox.getPosition().y+(hitbox.getGlobalBounds().height/2)-missile_height),animations.find_animation(11),10,missile_width,missile_height,Attack_hit);
                enemies_missiles.add_missile(M);
                Attack_Sound.play();
            }
            if(movement_indicator==1)
                animations.find_animation(7)->Display_animation(window,Vector2f(hitbox.getPosition().x,hitbox.getPosition().y-Attack_up),Attack_counter);
            else
                animations.find_animation(8)->Display_animation(window,Vector2f(hitbox.getPosition().x-Attack_left,hitbox.getPosition().y-Attack_up),Attack_counter);
            Attack_counter++;
        }
        else if(Attack_counter<2*Attack_counter_max)
        {
            Follow_player(players_hitbox,counter, window);
            Attack_counter++;
        }
        else
        {
            is_attacking=0;
            Attack_counter=0;
        }
    }
    else
    {
    Range_Attack(players_hitbox,is_player_dead);
    Follow_player(players_hitbox,counter, window);
    }
    Display_HP(window);
    }
    else if(is_dead==1 && death_counter<=60)
    {
        if(death_counter==0)
            Death_sound.play();
        if(movement_indicator==1)
            animations.find_animation(3)->Display_animation(window,hitbox.getPosition(),death_counter);
        else
            animations.find_animation(4)->Display_animation(window,hitbox.getPosition(),death_counter);
        death_counter++;
    }
    else if(is_dead==1 && death_counter>60)
    {
        if(movement_indicator==1)
            animations.find_animation(5)->Display_animation(window,hitbox.getPosition(),death_counter);
        else
            animations.find_animation(6)->Display_animation(window,hitbox.getPosition(),death_counter);
    }
}

RectangleShape* Enemy::Maintance_Melee(RenderWindow &window, int counter, RectangleShape players_hitbox, int is_player_dead)
{
    RectangleShape* Hitp=nullptr;

    if(HP<=0)
        is_dead=1;
    if(is_dead==0)
    {
    if(is_attacking==1)
    {
        if(Attack_counter==0)
            Attack_Sound.play();
        if(Attack_counter<Attack_counter_max)
        {
            if (Attack_counter == Attack_frame)
            {
                Hitp = Swing(players_hitbox, is_player_dead);
            }
            Attack_counter++;
            if(movement_indicator==1)
                animations.find_animation(7)->Display_animation(window,Vector2f(hitbox.getPosition().x,hitbox.getPosition().y-Attack_up),Attack_counter);
            else
                animations.find_animation(8)->Display_animation(window,Vector2f(hitbox.getPosition().x-Attack_left,hitbox.getPosition().y-Attack_up),Attack_counter);
        }
        else
        {
            is_attacking=0;
            Attack_counter=0;
        }
    }
    else
    {
        Check_Swing(players_hitbox,is_player_dead);
        Follow_player(players_hitbox,counter, window);
        }
        Display_HP(window);
    }
    else if(is_dead==1 && death_counter<=60)
    {
        if(death_counter==0)
            Death_sound.play();
        if(movement_indicator==1)
            animations.find_animation(3)->Display_animation(window,hitbox.getPosition(),death_counter);
        else
            animations.find_animation(4)->Display_animation(window,hitbox.getPosition(),death_counter);
        death_counter++;
    }
    else if(is_dead==1 && death_counter>60)
    {
        if(movement_indicator==1)
            animations.find_animation(5)->Display_animation(window,hitbox.getPosition(),death_counter);
        else
            animations.find_animation(6)->Display_animation(window,hitbox.getPosition(),death_counter);
    }
    return Hitp;
}


void Enemy::Follow_player(RectangleShape players_hitbox, int counter, RenderWindow& window)
{
    int distance_x,distance_y;
    if(players_hitbox.getPosition().x>hitbox.getPosition().x)
        distance_x=players_hitbox.getPosition().x-hitbox.getPosition().x+hitbox.getGlobalBounds().width;
    else
        distance_x=players_hitbox.getPosition().x-hitbox.getPosition().x;
    if(players_hitbox.getPosition().y>hitbox.getPosition().y)
        distance_y=players_hitbox.getPosition().y+players_hitbox.getGlobalBounds().height-hitbox.getPosition().y;
    else
        distance_y=players_hitbox.getPosition().y-hitbox.getPosition().y;

    int total_distance=sqrt(distance_x*distance_x+distance_y*distance_y);

    if(distance_x>=0) //Need to move right
    {
        movement_indicator=1;
    }
    else if(distance_x<0) //Need to move left
    {
        movement_indicator=2;
    }

    if(range==1)
    {

    //just move in Y
        if(distance_y>4) //Need to move down
        {
            hitbox.move(0,2);
        }
        else if(distance_y<-4) //Need to move up
        {
            hitbox.move(0,-2);
        }
        if(movement_indicator==1 && (distance_y>4||distance_y<-4))
            animations.find_animation(1)->Display_animation(window, hitbox.getPosition(),counter);
        else if(movement_indicator==2 && (distance_y>4||distance_y<-4))
            animations.find_animation(2)->Display_animation(window, hitbox.getPosition(),counter);
        else if(movement_indicator==1 && (distance_y<=4&&distance_y>=-4))
            animations.find_animation(9)->Display_animation(window,hitbox.getPosition(),counter);
        else if(movement_indicator==2 && (distance_y<=4&&distance_y>=-4))
            animations.find_animation(10)->Display_animation(window,hitbox.getPosition(),counter);
    }

    else if((total_distance<900&&total_distance>10)||(HP<MaxHP&&total_distance>10))
    {
        //move in X
            if(distance_x>4) //Need to move right
            {
                movement_indicator=1;
                hitbox.move(2,0);
            }
            else if(distance_x<-4) //Need to move left
            {
                movement_indicator=2;
                hitbox.move(-2,0);
            }

         //move in Y
            if(distance_y>4) //Need to move down
            {
                hitbox.move(0,2);
            }
            else if(distance_y<-4) //Need to move up
            {
                hitbox.move(0,-2);
            }

        if(movement_indicator==1)
            animations.find_animation(1)->Display_animation(window, hitbox.getPosition(),counter);
        if(movement_indicator==2)
            animations.find_animation(2)->Display_animation(window, hitbox.getPosition(),counter);
    }
    else
    {
        if(movement_indicator==1)
            animations.find_animation(9)->Display_animation(window,hitbox.getPosition(),counter);
        else
            animations.find_animation(10)->Display_animation(window,hitbox.getPosition(),counter);
    }


}

void Enemy::Display_HP(RenderWindow &window)
{
    int maxsize=MaxHP;
    HP_Red.setSize(Vector2f(HP*(maxsize/MaxHP),10));
    HP_Red.setPosition(Vector2f(hitbox.getPosition().x,hitbox.getPosition().y-10));
    window.draw(HP_Red);
}

RectangleShape* Enemy::Swing(RectangleShape players_hitbox,int is_player_dead) //0 - No, 1 - Yes
{
    RectangleShape* Hitp=new RectangleShape(Vector2f(3*Swing_width,hitbox.getGlobalBounds().height));
    Hitp->setPosition(hitbox.getPosition().x+hitbox.getGlobalBounds().width,hitbox.getPosition().y);
    if (Hitp->getGlobalBounds().intersects(players_hitbox.getGlobalBounds()) && is_player_dead==0)
    {
        return Hitp;
    }
    else
    {
        Hitp->setPosition(hitbox.getPosition().x-Swing_width,hitbox.getPosition().y);
        if (Hitp->getGlobalBounds().intersects(players_hitbox.getGlobalBounds()) && is_player_dead==0)
        {
            return Hitp;
        }
    }
    delete Hitp;
    Hitp=nullptr;
    return Hitp;

}

void Enemy::Check_Swing(RectangleShape players_hitbox, int is_player_dead)
{
    RectangleShape* Hitp = new RectangleShape(Vector2f(3 * Swing_width, hitbox.getGlobalBounds().height));
    Hitp->setPosition(hitbox.getPosition().x + hitbox.getGlobalBounds().width, hitbox.getPosition().y);
    if (Hitp->getGlobalBounds().intersects(players_hitbox.getGlobalBounds()) && is_player_dead == 0)
    {
        is_attacking = 1;
        Attack_counter = 0;
    }
    else
    {
        Hitp->setPosition(hitbox.getPosition().x - Swing_width, hitbox.getPosition().y);
        if (Hitp->getGlobalBounds().intersects(players_hitbox.getGlobalBounds()) && is_player_dead == 0)
        {
            is_attacking = 1;
            Attack_counter = 0;
        }
    }
}

void Enemy::Range_Attack(RectangleShape players_hitbox,int is_player_dead)
{
    if(is_player_dead==0)
    {
        if(hitbox.getPosition().y+(hitbox.getGlobalBounds().height/2)> players_hitbox.getPosition().y &&hitbox.getPosition().y+(hitbox.getGlobalBounds().height/2)<players_hitbox.getPosition().y+players_hitbox.getGlobalBounds().height)
        {
            is_attacking=1;
            Attack_counter=0;
        }
    }
}
