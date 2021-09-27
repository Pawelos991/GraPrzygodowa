#ifndef GAME_H
#define GAME_H

#include "Quests.h"
#include "Screens.h"
#include "Adventure_Creator.h"
#include "Map.h"
#include "Menu.h"

class Game : private Screens, private Quests, private Menu
{
    public:
        Game();
        virtual ~Game();
        void run();
    private:
        void Prepare_game(Player &p, RenderWindow& window, Adventure_Creator& adventure_creator,Map& map);
        void ArenaMode(RenderWindow& window);
        void GetKeyEvent(RenderWindow& window, Player& p, Adventure_Creator& adventure_creator, Map& map);
        void MaintainChests(Items& items, Player& p);
        void MaintainDoors(RenderWindow& window, Player& p);
        void DisplayShadows(RenderWindow& window, Player& p);
        void NextLvl(RenderWindow& window, Player& p, Map& map, Adventure_Creator& adventure_creator);

        void Tutorial(RenderWindow& window, Player& p, Items& items, Map& map);
        void Arena(RenderWindow& window, Player& p);
        void Adventure(RenderWindow& window, Player& p, Items& items, Map& map, Adventure_Creator& adventure_creator);

        Font Arena_font;
        Text Arena_text;
        CircleShape shadows[5];
        int gameMode; //0 - not chosen, 1 - Tutorial, 2 - Continue adventure, 3 - New adventure, 4 - Arena normal, 5 - Arena godmode
        int counter; //FPS counter
        int kills; //Kills counter (arena)
        int movementindicator; // 1-right 2-left
        int quest_counter; //Counter of frames of display new quest
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
        bool adventureStarted;
        bool add_new_quest;

};

#endif // GAME_H
