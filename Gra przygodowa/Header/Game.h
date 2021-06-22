#ifndef GAME_H
#define GAME_H

#include "Quests.h"
#include "Screens.h"
#include "Characters.h"

class Game : private Screens, private Quests
{
    public:
        Game();
        virtual ~Game();
        void run();
    private:
        void Game_menu(RenderWindow &window,Animations &menu_animations);
        //void Arena_pick(RenderWindow& window, Animations& menu_animations);
        void Prepare_game(Player &p);
        int inGameMenu(RenderWindow &window,Animations &menu_animations); //1 - resume, 2 - go to menu
        void ArenaMode(RenderWindow& window);
        void GetKeyEvent(RenderWindow& window, int& is_inventory_open, int& are_quests_displayed, Animations& menu_animations, Player& p, int& is_muted, int& pause_game, Sound& sound);
        void addQuest(RenderWindow &window, int id);

        int gameMode; //0 - not chosen, 1 - Tutorial, 2 - New adventure, 3 - Arena normal, 4 - Arena godmode, 5 - Exit
        int kills;
        Texture menu_textures[17];
        Sprite menu_sprite;
        Sprite menu_background;
        Font Arena_font;
        Text Arena_text;

};

#endif // GAME_H
