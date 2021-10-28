#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

/**
*Klasa reprezentuj¹ca pojedynczy przedmiot u¿ytkowy przechowywany w skrzyni lub ekwipunku gracza
*/
class Item
{
    public:
        /**
        *Konstruktor klasy inicjuj¹cy obiekt i wczytuj¹cy dane z plików
        * @param IDc ID przedmiotu
        * @param namec Nazwa przedmiotu
        * @param locations Œcie¿ka do tekstury przedmiotu
        */
        Item(int IDc, std::string namec, std::string locations);
        /**
        * Destruktor klasy
        */
        virtual ~Item();
        /**
        * Funkcja wyœwietlaj¹ca przedmiot w oknie
        * @param window Okno w którym ma zostaæ wyœwietlony przedmiot
        * @param location Miejsce w oknie w którym ma zostaæ wyœwietlony przedmiot
        */
        void displayItem(RenderWindow &window, Vector2f location);
        /**
        * Funkcja zwracaj¹ca wskaŸnik na kolejny obiekt tej klasy
        * @return WskaŸnik na kolejny obiekt tej klasy
        */
        Item *getNext(){return next;}
        /**
        * Funkcja ustawiaj¹ca wskaŸnik na kolejny obiekt tej klasy zgodnie z podanym wskaŸnikiem
        * @param pnext WskaŸnik na podstawie którego ma zostaæ ustawiony wskaŸnik obiektu
        */
        void setNext(Item *pnext){next=pnext;}
        /**
        * Funkcja zwracaj¹ca ID przedmiotu
        * @return ID przedmiotu
        */
        int getID(){return ID;}
        /**
        * Funkcja zwracaj¹ca nazwê przedmiotu
        * @return Nazwa przedmiotu
        */
        std::string getName(){return name;}
        /**
        * Funkcja zwracaj¹ca œcie¿kê do tekstury przedmiotu
        */
        std::string getLocation(){return location;}


    private:
        /**ID przedmiotu*/
        int ID;
        /**Œcie¿ka do tekstury przedmiotu*/
        std::string location;
        /**Tekstura przedmiotu która ³adowana jest z pliku*/
        Texture pic;
        /**Nazwa przedmiotu*/
        std::string name;
        /**WskaŸnik na kolejny obiekt tej klasy*/
        Item *next;
        /**Sprite przedmiotu s³u¿¹cy do wyœwietlania go w oknie*/
        Sprite sp;

};

#endif // ITEM_H
