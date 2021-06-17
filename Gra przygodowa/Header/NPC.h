#ifndef NPC_H
#define NPC_H

#include "Items.h"
#include "Character.h"
#include "Quest.h"

class NPC : private Character
{
    public:
        NPC(std::string type,Vector2f position);
        virtual ~NPC();
        void setNext(NPC *pnext){next=pnext;}
        NPC* getNext(){return next;}

        void Maintance(RenderWindow &window, int counter, RectangleShape players_hitbox);

    private:
        NPC* next;
        Font font;
        Text text;
        Texture cloudTex;
        Sprite Cloud;
        RectangleShape hitbox;


};

#endif // NPC_H
