#ifndef GAME_H
#define GAME_H

#include "Quests.h"
#include "Screens.h"
#include "Adventure_Creator.h"
#include "Map.h"

class Game : private Screens, private Quests
{
    public:
        Game();
        virtual ~Game();
        void run();
    private:
        void Game_menu(RenderWindow &window,Animations &menu_animations);
        void Arena_pick(RenderWindow& window, Animations& menu_animations);
        void Prepare_game(Player &p, RenderWindow& window, Adventure_Creator& adventure_creator,Map& map);
        int inGameMenu(RenderWindow &window,Animations &menu_animations); //1 - resume, 2 - go to menu
        void ArenaMode(RenderWindow& window);
        void GetKeyEvent(RenderWindow& window, Animations& menu_animations, Player& p, Adventure_Creator& adventure_creator, Map& map);
        void MaintainChests(Items& items, Player& p);
        void MaintainDoors(RenderWindow& window, Player& p);
        void DisplayShadows(RenderWindow& window, Player& p);

        void Tutorial(RenderWindow& window, Player& p, Items& items, Map& map);
        void Arena(RenderWindow& window, Player& p);
        void Adventure(RenderWindow& window, Player& p, Items& items, Map& map);

        Texture menu_textures[18];
        Sprite menu_sprite;
        Sprite menu_background;
        Font Arena_font;
        Text Arena_text;
        Sound sound;
        SoundBuffer sb;
        CircleShape shadows[5];
        int gameMode; //0 - not chosen, 1 - Tutorial, 2 - New adventure, 3 - Arena normal, 4 - Arena godmode, 5 - Exit
        int counter; //FPS counter
        int kills; //Kills counter (arena)
        int movementindicator; // 1-right 2-left
        bool is_inventory_open; 
        bool are_quests_displayed; 
        bool is_muted; 
        bool is_godmode_on;
        bool pause_game;
        bool standingByDoor;
        bool tryingToOpenDoor;
        bool displaySmallMap;
        bool displayBigMap;
        bool finishedTutorial;

};

#endif // GAME_H
