#ifndef MISSILES_H
#define MISSILES_H

#include "Missile.h"

class Missiles
{
    public:
        Missiles():head(nullptr){}
        ~Missiles(){delete_all_missiles();}
        void add_missile(Missile* added);
        void delete_missile(Missile* deleted);
        void delete_all_missiles();
        Missile* getHead(){return head;}

        void Display_all_missiles(RenderWindow &window, int counter);
        void Update_all_missiles(RenderWindow &window);
        void maintenance(RenderWindow&window, int counter);

    private:
        Missile *head;
};

#endif // MISSILES_H
