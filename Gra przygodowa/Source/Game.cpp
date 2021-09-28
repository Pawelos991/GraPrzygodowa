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
    kills=-1;
    Arena_font.loadFromFile("Fonts/Arial.ttf");
    Arena_text.setFont(Arena_font);
    Arena_text.setCharacterSize(50);

    
    Actual_screen = nullptr;
    Actual_adventure_screen = nullptr;
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
    displaySmallMap = false;
    displayBigMap = false;
    finishedTutorial = true; //Change later
    adventureStarted = false;
    for (int i = 0; i < 5; i++)
    {
        shadows[i].setFillColor(Color(249, 215, 28, 10));
        shadows[i].setRadius((5-i)*150);
        shadows[i].setOutlineColor(Color(0, 0, 0, 150 + (5-i)*10));
        shadows[i].setOutlineThickness(2000-shadows[i].getRadius());
    }
    
}

Game::~Game()
{
    //dtor
}

void Game::Prepare_game(Player &p,RenderWindow &window,Adventure_Creator &adventure_creator, Map& map)
{
    if(gameMode==1) //Tutorial
    {
        p.Respawn();
        remove_all_t_quests();
        add_new_quest = true;
        p.set_NormalMode();
        p.getHit(40);
        p.hitbox.setPosition(Vector2f(400,400));

        displayBigMap = false;
        displaySmallMap = false;
        
        delete_all_tutorial_screens();
        load_tutorial_Screens(window);
        map.prepareMap(tutorial_screens);
        Actual_screen = get_tutorial_screen_by_ID(1);
        Actual_screen->setVisited(true);
        counter = 0;
        quest_counter = 0;
    }

    else if (gameMode == 2) //Continue adventure
    {
        p.Respawn();
        remove_all_t_quests();
        add_new_quest = true;
        p.set_NormalMode();
        p.hitbox.setPosition(Vector2f(773, 416));

        displayBigMap = false;
        displaySmallMap = false;

        map.prepareMap(adventure_screens);
        Actual_screen = Actual_adventure_screen;
        counter = 0;
        quest_counter = 0;
    }

    else if (gameMode == 3) //New adventure 
    {
        p.Respawn();
        remove_all_t_quests();
        add_new_quest = true;
        p.set_NormalMode();
        p.hitbox.setPosition(Vector2f(773, 416));
        p.clear_Inventory();

        displayBigMap = false;
        displaySmallMap = false;

        delete_all_adventure_screens();
        adventure_creator.reset_creator();
        adventure_screens = adventure_creator.generate_level(window);
        map.prepareMap(adventure_screens);

        if (adventure_screens[0]->has_portal())
            Actual_screen = adventure_screens[1];
        else
            Actual_screen = adventure_screens[0];

        Actual_screen->setVisited(true);
        Actual_adventure_screen = Actual_screen;
        adventureStarted = true;
        counter = 0;
        quest_counter = 0;
    }

    else if(gameMode==4) //Arena normal
    {
        p.Respawn();
        remove_all_t_quests();
        add_new_quest = true;
        p.set_NormalMode();
        p.hitbox.setPosition(Vector2f(750,120));

        delete_all_tutorial_screens();
        if (arena_screen == nullptr)
            load_arena_Screen();
        Actual_screen = arena_screen;
        counter = 0;
        quest_counter = 0;
    }
    else if(gameMode==5) //Arena godmode
    {
        p.Respawn();
        remove_all_t_quests();
        add_new_quest = true;
        p.set_GodMode();
        p.hitbox.setPosition(Vector2f(750,120));

        delete_all_tutorial_screens();
        if (arena_screen == nullptr)
            load_arena_Screen();
        Actual_screen = arena_screen;
        counter = 0;
        quest_counter = 0;
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
        if (counter % 4 == 0)
        {
            Actual_screen->enemies.add_enemy("Minotaur", Vector2f((counter % 12) * 100 + 100, 700));
        }
        else if (counter % 4 == 1)
        {
            Actual_screen->enemies.add_enemy("Dwarf", Vector2f((counter % 12) * 100 + 100, 700));
        }
        else if (counter % 4 == 2)
        {
            Actual_screen->enemies.add_enemy("Archer", Vector2f((counter % 12) * 100 + 100, 700));
        }
        else if (counter % 4 == 3)
        {
            Actual_screen->enemies.add_enemy("Snake", Vector2f((counter % 12) * 100 + 100, 700));
        }
    }
}

void Game::GetKeyEvent(RenderWindow& window,Player &p, Adventure_Creator &adventure_creator, Map& map)
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
            if (inGameMenu(window) == 2)
            {
                gameMode=mainMenu(window,finishedTutorial,adventureStarted);
                Prepare_game(p,window,adventure_creator,map);
            }
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
        {
            if (displayBigMap == false)
            {
                displayBigMap = true;
            }
            else
            {
                displayBigMap = false;;
            }
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::N)
        {
            if (displaySmallMap == false)
            {
                displaySmallMap = true;
            }
            else
            {
                displaySmallMap = false;;
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
                tryingToOpenDoor = false;
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

void Game::Tutorial(RenderWindow &window,Player &p,Items &items,Map &map)
{
    window.clear(Color::White);
    bool tutorial_finish = Check_tutorial_screen(p.hitbox);
    if (tutorial_finish)
        finishedTutorial = true;

    Display_Screens(window);

    if (Actual_screen->check_portal(p.getHitbox()))
    {
        Actual_screen->getPortal()->playSound();
    }

    Actual_screen->npcs.Maintance(window, counter, p.getHitbox());

    Missile* m = p.Maintenance(window, counter, Actual_screen->walls, is_inventory_open,
        Actual_screen->enemies.Maintenance(window, counter, p.getHitbox(), p.is_player_dead(), Actual_screen->player_missiles, Actual_screen->enemies_missiles), Actual_screen->enemies_missiles);
    Actual_screen->player_missiles.add_missile(m);

    Actual_screen->player_missiles.maintenance(window, counter);
    Actual_screen->enemies_missiles.maintenance(window, counter);

    if (are_quests_displayed)
        Display_quests(window);

    MaintainChests(items, p);
    MaintainDoors(window, p);
    if(displayBigMap)
        map.displayBigMap(tutorial_screens, window, Actual_screen->getID());
    else if(displaySmallMap)
        map.displaySmallMap(tutorial_screens, window, Actual_screen->getID());

    if (add_new_quest)
    {
        add_t_quest_display(1, window,quest_counter);
        quest_counter++;
        if (quest_counter == 120)
        {
            add_new_quest = false;
        }
    }
}

void Game::Arena(RenderWindow& window, Player& p)
{
    window.clear(Color::White);
    Check_adventure_screen(p.hitbox);

    Display_Screens(window);

    ArenaMode(window);

    Missile* m = p.Maintenance(window, counter, Actual_screen->walls, is_inventory_open,
        Actual_screen->enemies.Maintenance(window, counter, p.getHitbox(), p.is_player_dead(), Actual_screen->player_missiles, Actual_screen->enemies_missiles), Actual_screen->enemies_missiles);
    Actual_screen->player_missiles.add_missile(m);

    Actual_screen->player_missiles.maintenance(window, counter);
    Actual_screen->enemies_missiles.maintenance(window, counter);

    if (are_quests_displayed)
        Display_quests(window);

    if (add_new_quest)
    {
        add_t_quest_display(2, window, quest_counter);
        quest_counter++;
        if (quest_counter == 120)
        {
            add_new_quest = false;
        }
    }
}

void Game::Adventure(RenderWindow& window, Player& p, Items& items, Map& map, Adventure_Creator& adventure_creator)
{
    window.clear(Color::White);
    Check_adventure_screen(p.hitbox);

    Display_Screens(window);

    if (Actual_screen->check_portal(p.getHitbox()))
    {
        Actual_screen->getPortal()->playSound();
        NextLvl(window, p, map, adventure_creator);
    }
    else
    {
        Actual_screen->npcs.Maintance(window, counter, p.getHitbox());

        if (adventure_creator.get_floor_type() == 3)
            DisplayShadows(window, p);

        Missile* m = p.Maintenance(window, counter, Actual_screen->walls, is_inventory_open,
            Actual_screen->enemies.Maintenance(window, counter, p.getHitbox(), p.is_player_dead(), Actual_screen->player_missiles, Actual_screen->enemies_missiles), Actual_screen->enemies_missiles);
        Actual_screen->player_missiles.add_missile(m);

        Actual_screen->player_missiles.maintenance(window, counter);
        Actual_screen->enemies_missiles.maintenance(window, counter);

        if (are_quests_displayed)
            Display_quests(window);

        MaintainChests(items, p);
        MaintainDoors(window, p);
        if (displayBigMap)
            map.displayBigMap(adventure_screens, window, Actual_screen->getID());
        else if (displaySmallMap)
            map.displaySmallMap(adventure_screens, window, Actual_screen->getID());

        if (add_new_quest)
        {
            add_t_quest_display(adventure_creator.get_floor_type()+2, window, quest_counter);
            quest_counter++;
            if (quest_counter == 120)
            {
                add_new_quest = false;
            }
        }
    } 
}

void Game::NextLvl(RenderWindow& window, Player& p, Map& map, Adventure_Creator& adventure_creator)
{
    remove_all_t_quests();
    add_new_quest = true;
    quest_counter = 0;
    p.set_NormalMode();
    p.hitbox.setPosition(Vector2f(773, 416));

    delete_all_adventure_screens();
    adventure_screens = adventure_creator.next_lvl(window);
    map.prepareMap(adventure_screens);

    if (adventure_screens[0]->has_portal())
        Actual_screen = adventure_screens[1];
    else
        Actual_screen = adventure_screens[0];

    Actual_screen->setVisited(true);
    Actual_adventure_screen = Actual_screen;
    adventureStarted = true;
}

void Game::DisplayShadows(RenderWindow& window, Player& p)
{
    for (int i = 0; i < 5; i++)
    {
        //shadows[i].setPosition(Vector2f(p.getHitbox().getPosition().x - 73 - ((4 - i) * 200), p.getHitbox().getPosition().y - 66 - ((4 - i) * 200)));
        shadows[i].setPosition(Vector2f(p.getHitbox().getPosition().x - 123 - ((4 - i) * 150), p.getHitbox().getPosition().y - 116 - ((4 - i) * 150)));
        window.draw(shadows[i]);
    }
}

void Game::run()
{
    RenderWindow window(VideoMode(1600, 900), "Gra przygodowa - Pawel Mika");
    window.setFramerateLimit(60);
    Image img;
    img.loadFromFile("Textures/Menu/Icon.png");
    window.setIcon(img.getSize().x,img.getSize().y,img.getPixelsPtr());
    window.setPosition(Vector2i(0, 0));

    load_loading_screen();
    Adventure_Creator adventure_creator = Adventure_Creator(loading_screen);
    Map map = Map();
    Player p;
    Items items;
    items.LoadItemsFromFile();
    load_door_data();
    prepare_quests();
    
    prepareMenu();

    gameMode = mainMenu(window, finishedTutorial,adventureStarted);
    

    Prepare_game(p,window,adventure_creator,map);

    while(window.isOpen())
    {    
        GetKeyEvent(window,p,adventure_creator,map);

        if(pause_game==false)
        {
            counter++;
            if(counter==61)
            {
                counter=0;
            }

            if (gameMode == 1)
                Tutorial(window, p, items, map);
            else if (gameMode == 2 || gameMode == 3)
                Adventure(window, p, items, map,adventure_creator);
            else if (gameMode == 4 || gameMode == 5)
                Arena(window, p);
        }   
        window.display();
    }
    remove_all_nt_quests();
    remove_all_t_quests();
    delete_all_screens();
}