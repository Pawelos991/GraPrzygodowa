#include "Not_Taken_Quests.h"
#include <string.h>

Not_Taken_Quests::Not_Taken_Quests()
{

}

Not_Taken_Quests::~Not_Taken_Quests()
{
    //dtor
}

void Not_Taken_Quests::load_quests()
{
    std::fstream fp;
    std::string name,desc;
    int id;
    fp.open("Data/Quests.txt");
    while(true)
    {
    if(fp.good());
    else
        break;
    fp>>id;
    fp>>name;
    fp>>desc;
    add_nt_quest(id,name,desc);
    }

    fp.close();
}

void Not_Taken_Quests::add_nt_quest(int id,std::string Name, std::string Desc)
{
    Quest *temp = new Quest(id,Name,Desc);
    not_taken_quests.push_back(temp);
}

void Not_Taken_Quests::remove_nt_quest(int id)
{
    int i=0;
    while(not_taken_quests[i]->getID()!=id)
        i++;
    not_taken_quests.erase(not_taken_quests.begin()+i);
}

void Not_Taken_Quests::remove_all_nt_quests()
{
    for (int i = 0; i < not_taken_quests.size(); i++)
    {
        delete not_taken_quests[i];
    }
        
    not_taken_quests.erase(not_taken_quests.begin(),not_taken_quests.end());
}
