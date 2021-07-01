#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H

#include "Screen.h"

class Loading_Screen
{
public:
    Loading_Screen();
    virtual ~Loading_Screen();
    void start_loading(RenderWindow &window);
    void set_loading(RenderWindow& window, float perc, std::string message);

private:
    Texture background_texture;
    Sprite background_sprite;
    RectangleShape loading_bar;
    Font font;
    Text text;
};

#endif // LOADING_SCREEN_H
