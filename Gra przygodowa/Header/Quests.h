#ifndef QUESTS_H
#define QUESTS_H

#include "Taken_Quests.h"
#include "Not_Taken_Quests.h"

class Quests: public Taken_Quests, public Not_Taken_Quests
{
    public:
        Quests();
        virtual ~Quests();

    protected:
        void prepare_quests();
        void add_t_quest(int id);
        void Display_quests(RenderWindow &window);
        void add_t_quest_display(int id, RenderWindow& window, int counter);

    private:
        Texture tex;
        Sprite sp;
};

#endif // QUESTS_H
