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

        void Tutorial(RenderWindow& window, Player& p, Items& items, Map& map);
        void Arena(RenderWindow& window, Player& p);
        void Adventure(RenderWindow& window, Player& p, Items& items, Map& map);

        Font Arena_font;
        Text Arena_text;
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
        bool adventureStarted;

};

#endif // GAME_H
