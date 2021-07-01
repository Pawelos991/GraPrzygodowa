#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H

#include "Screen.h"

class Loading_Screen
{
public:
    Loading_Screen();
    virtual ~Loading_Screen();
    void start_loading(RenderWindow &window);
    void set_loading(RenderWindow &window,float perc);

private:
    Texture background_texture;
    Sprite background_sprite;
    RectangleShape loading_bar;
};

#endif // LOADING_SCREEN_H
