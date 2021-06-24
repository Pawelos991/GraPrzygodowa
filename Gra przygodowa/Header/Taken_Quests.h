#ifndef TAKEN_QUESTS_H
#define TAKEN_QUESTS_H

#include "Quest.h"

class Taken_Quests
{
    public:
        Taken_Quests();
        virtual ~Taken_Quests();

    protected:
        std::vector<Quest*> taken_quests;
        void add_t_quest(int id, std::vector<Quest*> &not_taken_quests);
        void remove_t_quest(int id);
        void remove_all_t_quests();
        void complete_quest(int id);
        void display_active_quests(RenderWindow &window, Vector2f position);
        void display_quest(RenderWindow& window, int id);
        void add_t_quest_display(RenderWindow& window, int id, std::vector<Quest*>& not_taken_quests);
        Font font;
        Text text;
        void getFont();
    private:
        Texture new_tex;
        Sprite new_sp;
        Texture end_tex;
        Sprite end_sp;
        Sound sound;
        SoundBuffer sb;
        Text te;
};

#endif // TAKEN_QUESTS_H
