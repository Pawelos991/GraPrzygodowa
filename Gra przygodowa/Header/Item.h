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
*Klasa reprezentująca pojedynczy przedmiot użytkowy przechowywany w skrzyni lub ekwipunku gracza
*/
class Item
{
    public:
        /**
        *Konstruktor klasy inicjujący obiekt i wczytujący dane z plików
        * @param IDc ID przedmiotu
        * @param namec Nazwa przedmiotu
        * @param locations Ścieżka do tekstury przedmiotu
        */
        Item(int IDc, std::string namec, std::string locations);
        /**
        * Destruktor klasy
        */
        virtual ~Item();
        /**
        * Funkcja wyświetlająca przedmiot w oknie
        * @param window Okno w którym ma zostać wyświetlony przedmiot
        * @param location Miejsce w oknie w którym ma zostać wyświetlony przedmiot
        */
        void displayItem(RenderWindow &window, Vector2f location);
        /**
        * Funkcja zwracająca wskaźnik na kolejny obiekt tej klasy
        * @return Wskaźnik na kolejny obiekt tej klasy
        */
        Item *getNext(){return next;}
        /**
        * Funkcja ustawiająca wskaźnik na kolejny obiekt tej klasy zgodnie z podanym wskaźnikiem
        * @param pnext Wskaźnik na podstawie którego ma zostać ustawiony wskaźnik obiektu
        */
        void setNext(Item *pnext){next=pnext;}
        /**
        * Funkcja zwracająca ID przedmiotu
        * @return ID przedmiotu
        */
        int getID(){return ID;}
        /**
        * Funkcja zwracająca nazwę przedmiotu
        * @return Nazwa przedmiotu
        */
        std::string getName(){return name;}
        /**
        * Funkcja zwracająca ścieżkę do tekstury przedmiotu
        */
        std::string getLocation(){return location;}


    private:
        /**ID przedmiotu*/
        int ID;
        /**Ścieżka do tekstury przedmiotu*/
        std::string location;
        /**Tekstura przedmiotu która ładowana jest z pliku*/
        Texture pic;
        /**Nazwa przedmiotu*/
        std::string name;
        /**Wskaźnik na kolejny obiekt tej klasy*/
        Item *next;
        /**Sprite przedmiotu służący do wyświetlania go w oknie*/
        Sprite sp;

};

#endif // ITEM_H
