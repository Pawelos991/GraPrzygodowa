#include "Quest.h"

Quest::Quest(int id,std::string Name, std::string Desc)
{
    ID=id;
    name=Name;
    description=Desc;
    done=0;

    Replace_withSpace(name);
    Replace_withSpace(description);
}

Quest::~Quest()
{
    //dtor
}
