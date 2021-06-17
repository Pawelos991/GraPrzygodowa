#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "Player.h"
#include "Enemies.h"
#include "NPCs.h"

class Characters
{
    public:
        Characters();
        virtual ~Characters();
        Enemies enemies;
        NPCs npcs;

};

#endif // CHARACTERS_H
