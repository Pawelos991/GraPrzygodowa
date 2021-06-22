#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

Game::Game()
{
    std::ifstream fp;
    fp.open("Data/Menu_info.txt");
    std::string location;
    int i=0;
    while(true)
    {
        if(fp.good());
        else
            break;
        fp>>location;
        menu_textures[i].loadFromFile(location);
        i++;
    }
    fp.close();
    kills=-1;
    Arena_font.loadFromFile("Fonts/Arial.ttf");
    Arena_text.setFont(Arena_font);
    Arena_text.setCharacterSize(50);
    gameMode = 0;
    
}

Game::~Game()
{
    //dtor
}

void Game::Game_menu(RenderWindow &window,Animations &menu_animations)
{

    int counter=0;
    gameMode=0;
    int actual_choice=1; //1 - tutorial, 2 - arena, 3- arena godmode, 4- exit
    menu_background.setTexture(menu_textures[0]);
    menu_background.setPosition(Vector2f(0,0));
    while(window.isOpen())
    {
        counter++;
        if(counter==61)
        {
            counter=0;
        }
    window.clear(Color::White);
    window.draw(menu_background);
    menu_sprite.setPosition(Vector2f(557,100));
    for(int i=1;i<5;i++)
    {
        if(actual_choice==i)
            menu_sprite.setTexture(menu_textures[i+4]);
        else
            menu_sprite.setTexture(menu_textures[i]);
        window.draw(menu_sprite);
        menu_sprite.move(0,191);
    }
    menu_animations.find_animation(1)->Display_animation(window,Vector2f(50,125),counter);
    menu_animations.find_animation(2)->Display_animation(window,Vector2f(1000,50),counter);
    Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();
            if(event.type==Event::KeyPressed && event.key.code==Keyboard::Up &&actual_choice>1)
                actual_choice--;
            if(event.type==Event::KeyPressed && event.key.code==Keyboard::Down &&actual_choice<4)
                actual_choice++;
            if(event.type==Event::KeyPressed && event.key.code==Keyboard::Enter)
                {
                if (actual_choice == 4)
                    gameMode = 5;
                else
                    gameMode = actual_choice;

                    if (gameMode == 3)
                    {
                        actual_choice = 1;
                        while (window.isOpen())
                        {
                            counter++;
                            if (counter == 61)
                            {
                                counter = 0;
                            }
                            window.clear(Color::White);
                            window.draw(menu_background);
                            menu_sprite.setPosition(Vector2f(557, 291));
                            for (int i = 1; i < 3; i++)
                            {
                                if (actual_choice == i)
                                    menu_sprite.setTexture(menu_textures[i + 14]);
                                else
                                    menu_sprite.setTexture(menu_textures[i + 12]);
                                window.draw(menu_sprite);
                                menu_sprite.move(0, 191);
                            }
                            menu_animations.find_animation(1)->Display_animation(window, Vector2f(50, 125), counter);
                            menu_animations.find_animation(2)->Display_animation(window, Vector2f(1000, 50), counter);
                            Event event;
                            while (window.pollEvent(event))
                            {
                                if (event.type == Event::Closed)
                                    window.close();
                                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice > 1)
                                    actual_choice--;
                                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down && actual_choice < 2)
                                    actual_choice++;
                                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
                                {
                                    gameMode = actual_choice + 2;

                                    return;
                                }
                            }
                            window.display();
                        }
                    }

                    if (gameMode == 5)
                    {
                        window.close();
                    }
                    

                    return;
                }
        }
    window.display();
    }

}

int Game::inGameMenu(RenderWindow &window,Animations &menu_animations)
{
    int counter=0;
    int actual_choice=1; //1 - resume, 2 - exit to menu
    menu_background.setTexture(menu_textures[0]);
    menu_background.setPosition(Vector2f(0,0));
    while(window.isOpen())
    {
        counter++;
        if(counter==61)
        {
            counter=0;
        }
    window.clear(Color::White);
    window.draw(menu_background);
    menu_sprite.setPosition(Vector2f(557,200));
    for(int i=9;i<11;i++)
    {
        if(actual_choice==(i-8))
            menu_sprite.setTexture(menu_textures[i+2]);
        else
            menu_sprite.setTexture(menu_textures[i]);
        window.draw(menu_sprite);
        menu_sprite.move(0,191);
    }
    menu_animations.find_animation(1)->Display_animation(window,Vector2f(50,125),counter);
    menu_animations.find_animation(2)->Display_animation(window,Vector2f(1000,50),counter);
     Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();
            if(event.type==Event::KeyPressed && event.key.code==Keyboard::Up &&actual_choice>1)
                actual_choice--;
            if(event.type==Event::KeyPressed && event.key.code==Keyboard::Down &&actual_choice<2)
                actual_choice++;
            if(event.type==Event::KeyPressed && event.key.code==Keyboard::Escape)
                return 1;
            if(event.type==Event::KeyPressed && event.key.code==Keyboard::Enter)
                {
                    return actual_choice;
                }
        }
    window.display();
    }
}

void Game::Prepare_game(Player &p)
{
    if(gameMode==1) //Tutorial
    {
        p.Respawn();
        remove_all_t_quests();
        add_t_quest(1);
        p.set_NormalMode();
        p.getHit(40);
        p.hitbox.setPosition(Vector2f(400,400));
        Actual_screen=screens[0];
    }

    else if (gameMode == 2) //New adventure
    {
        p.Respawn();
        remove_all_t_quests();
        add_t_quest(1);
        p.set_NormalMode();
        p.getHit(40);
        p.hitbox.setPosition(Vector2f(400, 400));
        Actual_screen = screens[0];
    }

    else if(gameMode==3) //Arena normal
    {
        p.Respawn();
        remove_all_t_quests();
        add_t_quest(2);
        p.set_NormalMode();
        p.hitbox.setPosition(Vector2f(750,420));
        Actual_screen=screens[9];
    }
    else if(gameMode==4) //Arena godmode
    {
        p.Respawn();
        remove_all_t_quests();
        add_t_quest(2);
        p.set_GodMode();
        p.hitbox.setPosition(Vector2f(750,420));
        Actual_screen=screens[9];
    }
}

void Game::ArenaMode(RenderWindow &window)
{
    Arena_text.setString("Punkty: ");
    Arena_text.setPosition(Vector2f(1250,130));
    window.draw(Arena_text);
    Arena_text.setString(std::to_string(kills));
    Arena_text.move(170,0);
    window.draw(Arena_text);
}

void Game::GetKeyEvent(RenderWindow& window, int &is_inventory_open, int &are_quests_displayed, Animations &menu_animations, Player &p, int &is_muted, int &pause_game,Sound &sound)
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::H)
            p.heal();
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::I)
        {
            if (is_inventory_open == 0)
                is_inventory_open = 1;
            else
                is_inventory_open = 0;
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Q)
        {
            if (are_quests_displayed == 0)
                are_quests_displayed = 1;
            else
                are_quests_displayed = 0;
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
        {
            if (inGameMenu(window, menu_animations) == 2)
            {
                Game_menu(window, menu_animations);
                Prepare_game(p);
            }
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
        {
            if (is_muted == 0)
            {
                is_muted = 1;
                sound.pause();
            }
            else
            {
                is_muted = 0;
                sound.play();
            }
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
        {
            if (pause_game == 0)
                pause_game = 1;
            else
                pause_game = 0;
        }
    }
}

void Game::addQuest(RenderWindow& window, int id)
{
    Texture tex;
    Sprite sp;
    tex.loadFromFile("Textures/Quests/New_quest.png");
    sp.setTexture(tex);
    sp.setPosition(400, 250);
    Sound sound;
    SoundBuffer sb;
    sb.loadFromFile("Sounds/New_Quest.wav");
    sound.setBuffer(sb);
    sound.setVolume(10);
    sound.play();
    for (int i = 0; i < 120; i++)
    {
        window.draw(sp);
        Taken_Quests::display_new_quest(window);
        window.display();
    }
}

void Game::run()
{

    RenderWindow window(VideoMode(1600,900),"Game");
    window.setFramerateLimit(60);

    Sound sound;
    SoundBuffer sb;
    sb.loadFromFile("Sounds/Firelink.wav");
    sound.setBuffer(sb);
    sound.setVolume(10);
    sound.play();
    
    Player p;
    Items items;
    Animations menu_animations;

    items.LoadItemsFromFile();
    loadScreens();
    prepare_quests();
    menu_animations.LoadAnimationsFromFile("Data/Menu_Animations.txt");

    Game_menu(window,menu_animations);
    Prepare_game(p);

    int counter=0; //FPS counter
    int movementindicator=1; // 1-right 2-left
    int is_inventory_open=0; //1-Yes, 0-No
    int are_quests_displayed=0; //1-Yes, 0-No
    int is_muted=0; //0-No 1-Yes

    int is_godmode_on=0;//0-No,1-Yes

    int pause_game=0;//0-No, 1-Yes

    while(window.isOpen())
    {    
        GetKeyEvent(window, is_inventory_open, are_quests_displayed, menu_animations, p, is_muted, pause_game,sound);
        
        if (pause_game == 1)
        {
            addQuest(window, 1);
            pause_game = 0;
        }
        

        if(pause_game==0)
        {
            counter++;
            if(counter==61)
            {
                counter=0;
            }

            window.clear(Color::White);

            Check_screen(p.hitbox);
            Display_Screens(window);


            Chest* a=Actual_screen->check_chests(p.getHitbox());

            if(a!=nullptr)
            {
               a->OpenChest();
               for(int i=0;i<a->Items_IDs.size();i++)
                p.add_item_to_Inventory(a->Items_IDs[i],items);
            }

            Actual_screen->npcs.Maintance(window,counter,p.getHitbox());
            Missile *m = p.Maintenance(window, counter,Actual_screen->walls,is_inventory_open,
            Actual_screen->enemies.Maintenance(window,counter,p.getHitbox(),p.is_player_dead(),Actual_screen->player_missiles,Actual_screen->enemies_missiles),Actual_screen->enemies_missiles);
            Actual_screen->player_missiles.add_missile(m);
            Actual_screen->player_missiles.maintenance(window, counter);
            Actual_screen->enemies_missiles.maintenance(window,counter);

            if(gameMode==2 || gameMode==3)
            {
                ArenaMode(window);
                if (Actual_screen->enemies.is_everyone_dead() == 1)
                {
                    kills++;
                    if (counter % 3 == 0)
                    {
                        Actual_screen->enemies.add_enemy("Minotaur", Vector2f((counter % 12) * 100 + 100, 700));
                    }
                    if (counter % 3 == 1)
                    {
                        Actual_screen->enemies.add_enemy("Dwarf", Vector2f((counter % 12) * 100 + 100, 700));
                    }
                    if (counter % 3 == 2)
                    {
                        Actual_screen->enemies.add_enemy("Archer", Vector2f((counter % 12) * 100 + 100, 700));
                    }
                }
            }
        }
        if(are_quests_displayed==1)
            Display_quests(window);

        window.display();
    }
    remove_all_nt_quests();
    remove_all_t_quests();
    delete_all_screens();
}
