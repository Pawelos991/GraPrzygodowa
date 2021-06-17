#ifndef NC_OBJECT_H
#define NC_OBJECT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class NC_Object
{
    public:
        NC_Object(std::string location, Vector2f Position);
        void displayObject(RenderWindow &window);

    private:
        Texture pic;
        Sprite sp;
        Vector2f position;
};

#endif // NC_OBJECT_H
