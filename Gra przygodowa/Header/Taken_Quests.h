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
        void display_new_quest(RenderWindow& window);
        Font font;
        Text text;
        void getFont();
};

#endif // TAKEN_QUESTS_H
