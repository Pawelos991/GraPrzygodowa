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
        void Prepare_game(Player &p);
        int inGameMenu(RenderWindow &window,Animations &menu_animations); //1 - resume, 2 - go to menu
        void ArenaMode(RenderWindow &window);

        int gameMode; //0 - not chosen, 1 - Tutorial, 2 - Arena normal, 3 - Arena godmode, 4 - Exit
        int kills;
        Texture menu_textures[13];
        Sprite menu_sprite;
        Sprite menu_background;
        Font Arena_font;
        Text Arena_text;

};

#endif // GAME_H
