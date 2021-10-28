#ifndef ANIMATION_H
#define ANIMATION_H

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
*Klasa reprezentująca pojedynczą animację złożoną z maksymalnie 10 klatek
*/
class Animation
{
    public:
        /**
        *Konstruktor klasy uzupełniający podstawowe informacje
        *@param Name Nazwa animacji
        *@param Id ID animacji
        *@param Frames Liczba klatek animacji
        *@param Delay Odstęp między kolejnymi klatkami animcji wyrażony w milisekundach
        */
        Animation(std::string Name,int Id,int Frames,int Delay):name(Name),ID(Id),frames(Frames),delay(Delay){}
        /**
        *Dekonstruktor klasy
        */
        virtual ~Animation();
        /**
        *Funkcja odpowiedzialna za wstawienie podanej tekstury w odpowiednie miejsce w tablicy tekstur
        *@param number Numer miejsca w tablicy, w które ma zostać wstawiona tekstura
        *@param t Tekstura do wstawienia w tablicy tekstur
        */
        void setTexture(int number, Texture t);
        /**
        *Funkcja zwraca teksturę z tablicy tekstur
        *@param number Numer miejsca tekstury w tablicy
        *@return Tekstura z podanego miejsca w tablicy tekstur
        */
        Texture* getTexture(int number);
        /**
        *Funkcja która ustawia wskaźnik na następny obiekt zgodnie z podanym wskaźnikiem
        *@param Next Wskaźnik na który ma zostać ustawiony wskaźnik obiektu
        */
        void setNext(Animation *Next){next=Next;}
        /**
        *Funkcja która zwraca wskaźnik na kolejny obiekt w oparciu o wskaźnik obiektu
        *@return Wskaźnik na kolejny obiekt
        */
        Animation* getNext(){return next;}
        /**
        *Funkcja która zwraca ID obiektu
        *@return ID obiektu
        */
        int getID(){return ID;}
        /**
        *Funkcja która zwraca sprite obiektu
        *@return Sprite obiektu
        */
        Sprite getSprite(){return sp;}
        /**
        *Funkcja która zwraca nazwę obiektu
        *@return Nazwa obiektu
        */
        std::string getName(){return name;}
        /**
        *Funkcja która uzupełnia dane obiektu kopiując je z podanego obiektu
        *@param base Wskaźnik na obiekt bazowy z którego obiekt ma skopiować dane
        */
        void CopyFromAnimation(Animation *base);
        /**
        *Funkcja która wyświetla animację w oknie
        *@param window Okno w którym ma zostać wyświetlona animacja
        *@param location Pozycja w której ma zostać wyświetlona animacja
        *@param counter Licznik przechowujący infomację o obecnej klatce sekundy
        */
        void Display_animation(RenderWindow& window, Vector2f location, int counter);
        /**
        *Funkcja zwracająca ilość klatek animacji
        *@return Liczba klatek animacji
        */
        int getFrames(){return frames;}
        /**
        *Funkcja zwracająca odstęp między poszczególnymi klatkami animacji
        *@return Odstęp między poszczególnymi klatkami animacji
        */
        int getDelay(){return delay;}

    private:
        /**Liczba klatek animacji*/
        int frames;
        /**Odstęp między poszczególnymi klatkami animacji*/
        int delay;
        /**Tablica tekstur poszczególnych klatek animacji*/
        Texture textures[10];
        /**Sprite w którym ustawiane są odpowiednie tekstury do wyświetlenia animacji*/
        Sprite sp;
        /**Wskaźnik na kolejny obiekt typu Animation*/
        Animation *next=nullptr;
        /**Nazwa obiektu*/
        std::string name;
        /**ID obiektu*/
        int ID;
};

#endif // ANIMATION_H
