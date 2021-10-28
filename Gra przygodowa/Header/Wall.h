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

/**
*Klasa rezprezentująca pojedynczą ścianę, przez którą gracz nie może przeniknąć
*/
class Wall
{
    public:
        /**
        *Konstruktor klasy
        *@param location Ścieżka prowadząca do tekstury ściany
        *@param Position Miejsce, w którym ma zostać umieszczona ściana
        *@param SizeOfBox Wymiary (szerokość i wysokość) ściany
        */
        Wall(std::string location,Vector2f Position,Vector2f SizeOfBox);
        /**
        *Destruktor klasy
        */
        ~Wall(){}
        /**Obiekt klasy RectangleShape reprezentujący hitbox ściany*/
        RectangleShape box;
        /**
        *Funkcja odpowiedzialna za wyświetlenie ściany na ekranie
        *@param window Okno, w którym wyświetlona ma zostać ściana
        */
        void DisplayWall(RenderWindow &window);

    private:
        /**Obiekt przechowujący teksturę ściany*/
        Texture pic;
        /**Obiekt klasy Sprite służący do wyświetlania ściany*/
        Sprite sp;
};

#endif // WALL_H
