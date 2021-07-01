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

    sb.loadFromFile("Sounds/Firelink.wav");
    sound.setBuffer(sb);
    sound.setVolume(10);

    gameMode = 0;
    standingByDoor = false;
    counter = 0;
    movementindicator = 1;
    is_inventory_open = false;
    are_quests_displayed = false;
    is_muted = false;
    is_godmode_on = false;
    pause_game = false;
    tryingToOpenDoor = false;
    for (int i = 0; i < 5; i++)
    {
        shadows[i].setFillColor(Color(249, 215, 28, 10));
        shadows[i].setRadius((5-i)*100);
        shadows[i].setOutlineColor(Color(0, 0, 0, 150 + (5-i)*10));
        shadows[i].setOutlineThickness(2000-shadows[i].getRadius());
    }
    
}

Game::~Game()
{
    //dtor
}

void Game::Arena_pick(RenderWindow& window, Animations& menu_animations)
{
    int counter = 0;
    gameMode = 0;
    int actual_choice = 1; //1 - arena normal, 2 - arena godmode
    menu_background.setTexture(menu_textures[0]);
    menu_background.setPosition(Vector2f(0, 0));
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

void Game::Game_menu(RenderWindow &window,Animations &menu_animations)
{

    int counter=0;
    gameMode=0;
    int actual_choice=1; //1 - tutorial, 2 - new adventure, 3- arena, 4- exit
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
                        Arena_pick(window, menu_animations);
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

void Game::Prepare_game(Player &p,RenderWindow &window)
{
    if(gameMode==1) //Tutorial
    {
        p.Respawn();
        remove_all_t_quests();
        add_t_quest(1);
        p.set_NormalMode();
        p.getHit(40);
        p.hitbox.setPosition(Vector2f(400,400));
        Screen* sc = get_tutorial_screen_by_ID(1);
        if(sc==nullptr)
            load_tutorial_Screens(window);
        sc = get_tutorial_screen_by_ID(1);
        Actual_screen = sc;
    }

    else if (gameMode == 2) //New adventure
    {
        p.Respawn();
        remove_all_t_quests();
        add_t_quest(1);
        p.set_NormalMode();
        p.getHit(40);
        p.hitbox.setPosition(Vector2f(400, 400));
        Screen* sc = get_tutorial_screen_by_ID(7);
        if (sc == nullptr)
            load_tutorial_Screens(window);
        sc = get_tutorial_screen_by_ID(7);
        Actual_screen = sc;
    }

    else if(gameMode==3) //Arena normal
    {
        p.Respawn();
        remove_all_t_quests();
        add_t_quest(2);
        p.set_NormalMode();
        p.hitbox.setPosition(Vector2f(750,420));

        delete_all_tutorial_screens();
        if (arena_screen == nullptr)
            load_arena_Screen();
        Actual_screen = arena_screen;
    }
    else if(gameMode==4) //Arena godmode
    {
        p.Respawn();
        remove_all_t_quests();
        add_t_quest(2);
        p.set_GodMode();
        p.hitbox.setPosition(Vector2f(750,420));

        delete_all_tutorial_screens();
        if (arena_screen == nullptr)
            load_arena_Screen();
        Actual_screen = arena_screen;
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

    if (Actual_screen->enemies.is_everyone_dead())
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

void Game::GetKeyEvent(RenderWindow& window,Animations &menu_animations, Player &p)
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
            if (!is_inventory_open)
                is_inventory_open = true;
            else
                is_inventory_open = false;
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Q)
        {
            if (are_quests_displayed == false)
                are_quests_displayed = true;
            else
                are_quests_displayed = false;
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
        {
            if (inGameMenu(window, menu_animations) == 2)
            {
                Game_menu(window, menu_animations);
                Prepare_game(p,window);
            }
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
        {
            if (is_muted == false)
            {
                is_muted = true;
                sound.pause();
            }
            else
            {
                is_muted = false;
                sound.play();
            }
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
        {
            if (pause_game == false)
                pause_game = true;
            else
                pause_game = false;
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::O)
        {
            if (standingByDoor)
            {
                tryingToOpenDoor = true;
            }
        }
    }
}

void Game::MaintainChests(Items &items, Player &p)
{
    Chest* a = Actual_screen->check_chests(p.getHitbox());

    if (a != nullptr)
    {
        a->OpenChest();
        for (int i = 0; i < a->Items_IDs.size(); i++)
            p.add_item_to_Inventory(a->Items_IDs[i], items);
    }
}

void Game::MaintainDoors(RenderWindow &window,Player& p)
{
    Door* d = Actual_screen->check_doors(p.getHitbox());
    if (d != nullptr)
        standingByDoor = true;
    else
        standingByDoor = false;

    if (standingByDoor)
    {
        if (p.is_item_in_Inventory(d->get_key_ID()))
        {
            if (tryingToOpenDoor)
            {
                p.remove_item_from_Inventory(d->get_key_ID());
                open_door(d);
            }
            else
            {
                door_menu_sp.setTexture(door_menu_tex[1]);
                window.draw(door_menu_sp);
            }
            
        }
        else
        {
            door_menu_sp.setTexture(door_menu_tex[0]);
            window.draw(door_menu_sp);
        }
    }
}

void Game::run()
{

    RenderWindow window(VideoMode(1600,900),"Game");
    window.setFramerateLimit(60);
    load_loading_screen();

    /*RectangleShape rec;
    rec.setFillColor(Color::Blue);
    rec.setPosition(Vector2f(0, 0));
    rec.setSize(Vector2f(1600, 900));
    window.draw(rec);
    window.display();*/

    /*loading_screen->start_loading(window);
    loading_screen->set_loading(window, 0.5);*/

    sound.play();

    Player p;
    Items items;
    Animations menu_animations;
    menu_animations.LoadAnimationsFromFile("Data/Menu_Animations.txt");
    items.LoadItemsFromFile();
    load_door_data();
    prepare_quests();
    
    Game_menu(window,menu_animations);
    Prepare_game(p,window);

    while(window.isOpen())
    {    
        GetKeyEvent(window,menu_animations, p);

        if(pause_game==false)
        {
            counter++;
            if(counter==61)
            {
                counter=0;
            }

            window.clear(Color::White);

            Check_screen(p.hitbox);
            Display_Screens(window);



            Actual_screen->npcs.Maintance(window,counter,p.getHitbox());

            /*for (int i = 0; i < 5; i++)
            {
                shadows[i].setPosition(Vector2f(p.getHitbox().getPosition().x - 73 - ((4 - i) * 100), p.getHitbox().getPosition().y - 66 - ((4 - i) * 100)));
                window.draw(shadows[i]);
            }*/

            Missile *m = p.Maintenance(window, counter,Actual_screen->walls,is_inventory_open,
            Actual_screen->enemies.Maintenance(window,counter,p.getHitbox(),p.is_player_dead(),Actual_screen->player_missiles,Actual_screen->enemies_missiles),Actual_screen->enemies_missiles);
            Actual_screen->player_missiles.add_missile(m);

            

            

            if (are_quests_displayed)
                Display_quests(window);
            

            Actual_screen->player_missiles.maintenance(window, counter);
            Actual_screen->enemies_missiles.maintenance(window,counter);

            

            if(gameMode==3 || gameMode==4)
            {
                ArenaMode(window);  
            }

            MaintainChests(items, p);
            MaintainDoors(window, p);
        }
        
        
        window.display();
    }
    remove_all_nt_quests();
    remove_all_t_quests();
    delete_all_screens();
}
