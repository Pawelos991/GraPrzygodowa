#ifndef NPCS_H
#define NPCS_H

#include "NPC.h"

class NPCs
{
    public:
        NPCs():head(nullptr){}
        virtual ~NPCs();
        void add_npc(std::string name,Vector2f position);
        void remove_npc(NPC* removed);
        void remove_all_npcs();

        void Maintance(RenderWindow &window,int counter,RectangleShape players_hitbox);

    private:
        NPC* head;
};

#endif // NPCS_H
