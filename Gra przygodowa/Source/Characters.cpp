#include "Characters.h"

Characters::Characters()
{
    //ctor
}

Characters::~Characters()
{
    enemies.delete_all_enemies();
    npcs.remove_all_npcs();
}
