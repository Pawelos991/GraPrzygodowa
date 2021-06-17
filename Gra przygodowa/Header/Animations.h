#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "Animation.h"

class Animations
{
    public:
        Animations():head(nullptr){}
        virtual ~Animations();
        Animation* add_animation(std::string Name, int ID,int Frames,float Delay);
        void add_animation(Animation* added);
        void delete_all_animations();
        Animation* find_animation(int ID);

        void LoadAnimationsFromFile(std::string adress);

    private:
        Animation *head=nullptr;
};

#endif // ANIMATIONS_H
