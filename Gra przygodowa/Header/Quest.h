#ifndef QUEST_H
#define QUEST_H

#include "Items.h"

class Quest
{
    public:
        Quest(int id,std::string Name, std::string Desc);
        virtual ~Quest();
        void complete(){done=1;}
        std::string getName(){return name;}
        std::string getDesc(){return description;}
        int is_done(){return done;} //0-no, 1-yes
        int getID(){return ID;}



    private:
        std::string name;
        std::string description;
        int ID;
        int done; // 0-not done, 1-done
};

#endif // QUEST_H
