#ifndef NOT_TAKEN_QUESTS_H
#define NOT_TAKEN_QUESTS_H

#include "Quest.h"

class Not_Taken_Quests
{
    public:
        Not_Taken_Quests();
        virtual ~Not_Taken_Quests();

    protected:
        std::vector<Quest*> not_taken_quests;
        void load_quests();
        void add_nt_quest(int id,std::string Name, std::string Desc);
        void remove_nt_quest(int id);
        void remove_all_nt_quests();

};

#endif // NOT_TAKEN_QUESTS_H
