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
*Klasa reprezentuj�ca pojedynczy przedmiot u�ytkowy przechowywany w skrzyni lub ekwipunku gracza
*/
class Item
{
    public:
        /**
        *Konstruktor klasy inicjuj�cy obiekt i wczytuj�cy dane z plik�w
        * @param IDc ID przedmiotu
        * @param namec Nazwa przedmiotu
        * @param locations �cie�ka do tekstury przedmiotu
        */
        Item(int IDc, std::string namec, std::string locations);
        /**
        * Destruktor klasy
        */
        virtual ~Item();
        /**
        * Funkcja wy�wietlaj�ca przedmiot w oknie
        * @param window Okno w kt�rym ma zosta� wy�wietlony przedmiot
        * @param location Miejsce w oknie w kt�rym ma zosta� wy�wietlony przedmiot
        */
        void displayItem(RenderWindow &window, Vector2f location);
        /**
        * Funkcja zwracaj�ca wska�nik na kolejny obiekt tej klasy
        * @return Wska�nik na kolejny obiekt tej klasy
        */
        Item *getNext(){return next;}
        /**
        * Funkcja ustawiaj�ca wska�nik na kolejny obiekt tej klasy zgodnie z podanym wska�nikiem
        * @param pnext Wska�nik na podstawie kt�rego ma zosta� ustawiony wska�nik obiektu
        */
        void setNext(Item *pnext){next=pnext;}
        /**
        * Funkcja zwracaj�ca ID przedmiotu
        * @return ID przedmiotu
        */
        int getID(){return ID;}
        /**
        * Funkcja zwracaj�ca nazw� przedmiotu
        * @return Nazwa przedmiotu
        */
        std::string getName(){return name;}
        /**
        * Funkcja zwracaj�ca �cie�k� do tekstury przedmiotu
        */
        std::string getLocation(){return location;}


    private:
        /**ID przedmiotu*/
        int ID;
        /**�cie�ka do tekstury przedmiotu*/
        std::string location;
        /**Tekstura przedmiotu kt�ra �adowana jest z pliku*/
        Texture pic;
        /**Nazwa przedmiotu*/
        std::string name;
        /**Wska�nik na kolejny obiekt tej klasy*/
        Item *next;
        /**Sprite przedmiotu s�u��cy do wy�wietlania go w oknie*/
        Sprite sp;

};

#endif // ITEM_H
