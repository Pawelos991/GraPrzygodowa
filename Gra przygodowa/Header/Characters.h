#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "Player.h"
#include "Enemies.h"
#include "NPCs.h"

/**
*Klasa reprezentująca zbiór postaci (postaci niegrywalnych oraz przeciwników)
*/
class Characters
{
    public:
        /**
        *Konstruktor klasy
        */
        Characters();
        /**
        *Destruktor klasy
        */
        virtual ~Characters();
        /**Lista przeciwników*/
        Enemies enemies;
        /**Lista postaci niegrywalnych*/
        NPCs npcs;

};

#endif // CHARACTERS_H
