#ifndef SCREENS_H
#define SCREENS_H

#include "Loading_Screen.h"

/**
* Klasa reprezentuje zbi�r ekran�w, do kt�rych zaliczaj� si� ekrany samouczka, przygody oraz ekran areny
*/
class Screens
{
    public:
        /**
        * Konstruktor klasy
        */
        Screens(){}
        /**
        * Destruktor klasy
        */
        ~Screens(){}
    protected:
        /**Wska�nik na aktualny ekran na kt�rym znajduje si� posta� gracza*/
        Screen *Actual_screen;
        /**Wska�nik na aktualny ekran przygody zapami�tywany aby umie�ci� posta� gracza na dobrym ekranie w przypadku kontynuacji przerwanej przygody*/
        Screen *Actual_adventure_screen;

        /**Wska�nik na ekran areny*/
        Screen* arena_screen;
        /**Vector ekran�w samouczka*/
        std::vector<Screen*> tutorial_screens;
        /**Vector ekran�w aktualnego poziomu przygody*/
        std::vector<Screen*> adventure_screens;

        /**Wska�nik na ekran �adowania*/
        Loading_Screen *loading_screen;

        /**
        * Funkcja kt�ra zwraca wska�nik na ekran samouczka zgodny z podanym argumentem
        * @param ID ID ekranu samouczka na kt�ry ma zosta� zwr�cony wska�nik
        * @return Wska�nik na ekran samouczka o podanym ID
        */
        Screen* get_tutorial_screen_by_ID(int ID);
        /**
        * Funkcja wczytuje ekrany samouczka z plik�w konfiguracyjnych i �aduje je do Vector-a ekran�w samouczka
        * @param window Okno w kt�rym wy�wietlany jest ekran �adowania
        */
        void load_tutorial_Screens(RenderWindow& window);
        /**
        * Funkcja wczytuje ekran areny z plik�w i ustawia atrybut arena_screen na ten ekran
        */
        void load_arena_Screen();
        /**
        * Funkcja tworzy nowy ekran �adowania i przypisuje jego adres do wska�nika loading_screen
        */
        void load_loading_screen();
        /**
        * Funkcja �aduje informacje o interakcjach z drzwiami
        */
        void load_door_data();
        /**
        * Funkcja wy�wietla aktualny ekran w oknie gry
        * @param window Okno w kt�rym ma zosta� wy�wietlony ekran
        */
        void Display_Screens(RenderWindow &window);
        /**
        * Funkcja sprawdza czy posta� gracza przemie�ci�a si� z jednego ekranu samouczka do innego i je�li tak to wprowadza odpowiednie zmiany w atrybutach
        * @param player_hitbox Hitbox postaci gracza
        * @return true je�li posta� gracza dotar�a do ostatniego ekranu samouczka (czyli go uko�czy�a), false je�li nie
        */
        bool Check_tutorial_screen(RectangleShape &player_hitbox);
        /**
        * Funkcja sprawdza czy posta� gracza przemie�ci�a si� z jednego ekranu przygody do innego i je�li tak to wprowadza odpowiednie zmiany w atrybutach
        * @param player_hitbox Hitbox postaci gracza
        * @return true je�li zmieni� si� aktualny ekran i obecny ekran jest odwiedzany po raz pierwszy, false je�li dowolny z poprzednich warunk�w nie jest spe�niony
        */
        bool Check_adventure_screen(RectangleShape& player_hitbox);
        /**
        * Funkcja zwalnia pami�� zaalokowan� przez wszystkie ekrany 
        */
        void delete_all_screens();
        /**
        * Funkcja zwalnia pami�� zaalokowan� przez wszystkie ekrany samouczka 
        */
        void delete_all_tutorial_screens();
        /**
        * Funkcja zwalnia pami�� zaalokowan� przez wszystkie ekrany przygody
        */
        void delete_all_adventure_screens();
        /**
        * Funkcja s�u�y do odtworzenia d�wi�ku otwarcia drzwi oraz usuni�cia ich z ekranu
        * @param d Wska�nik do drzwi kt�re maj� zosta� usuni�te
        */
        void open_door(Door* d);

        /**Tekstury menu interakcji z drzwiami*/
        Texture door_menu_tex[2];
        /**Sprite menu interakcji z drzwiami*/
        Sprite door_menu_sp;
        /**D�wi�k otwierania drzwi*/
        Sound door_sound;
        /**Bufor przechowuj�cy d�wi�k otwierania drzwi*/
        SoundBuffer door_sb;
};

#endif // SCREENS_H
