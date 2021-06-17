#ifndef WALL_H
#define WALL_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Wall
{
    public:
        Wall(std::string location,Vector2f Position,Vector2f SizeOfBox);
        ~Wall(){}
        RectangleShape box;
        void DisplayWall(RenderWindow &window);

    private:
        Texture pic;
        Sprite sp;
};

#endif // WALL_H
