#ifndef SCREENS_H
#define SCREENS_H

#include "Loading_Screen.h"

/**
* Klasa reprezentuje zbiór ekranów, do których zaliczają się ekrany samouczka, przygody oraz ekran areny
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
        /**Wskaźnik na aktualny ekran na którym znajduje się postać gracza*/
        Screen *Actual_screen;
        /**Wskaźnik na aktualny ekran przygody zapamiętywany aby umieścić postać gracza na dobrym ekranie w przypadku kontynuacji przerwanej przygody*/
        Screen *Actual_adventure_screen;

        /**Wskaźnik na ekran areny*/
        Screen* arena_screen;
        /**Vector ekranów samouczka*/
        std::vector<Screen*> tutorial_screens;
        /**Vector ekranów aktualnego poziomu przygody*/
        std::vector<Screen*> adventure_screens;

        /**Wskaźnik na ekran ładowania*/
        Loading_Screen *loading_screen;

        /**
        * Funkcja która zwraca wskaźnik na ekran samouczka zgodny z podanym argumentem
        * @param ID ID ekranu samouczka na który ma zostać zwrócony wskaźnik
        * @return Wskaźnik na ekran samouczka o podanym ID
        */
        Screen* get_tutorial_screen_by_ID(int ID);
        /**
        * Funkcja wczytuje ekrany samouczka z plików konfiguracyjnych i ładuje je do Vector-a ekranów samouczka
        * @param window Okno w którym wyświetlany jest ekran ładowania
        */
        void load_tutorial_Screens(RenderWindow& window);
        /**
        * Funkcja wczytuje ekran areny z plików i ustawia atrybut arena_screen na ten ekran
        */
        void load_arena_Screen();
        /**
        * Funkcja tworzy nowy ekran ładowania i przypisuje jego adres do wskaźnika loading_screen
        */
        void load_loading_screen();
        /**
        * Funkcja ładuje informacje o interakcjach z drzwiami
        */
        void load_door_data();
        /**
        * Funkcja wyświetla aktualny ekran w oknie gry
        * @param window Okno w którym ma zostać wyświetlony ekran
        */
        void Display_Screens(RenderWindow &window);
        /**
        * Funkcja sprawdza czy postać gracza przemieściła się z jednego ekranu samouczka do innego i jeśli tak to wprowadza odpowiednie zmiany w atrybutach
        * @param player_hitbox Hitbox postaci gracza
        * @return true jeśli postać gracza dotarła do ostatniego ekranu samouczka (czyli go ukończyła), false jeśli nie
        */
        bool Check_tutorial_screen(RectangleShape &player_hitbox);
        /**
        * Funkcja sprawdza czy postać gracza przemieściła się z jednego ekranu przygody do innego i jeśli tak to wprowadza odpowiednie zmiany w atrybutach
        * @param player_hitbox Hitbox postaci gracza
        * @return true jeśli zmienił się aktualny ekran i obecny ekran jest odwiedzany po raz pierwszy, false jeśli dowolny z poprzednich warunków nie jest spełniony
        */
        bool Check_adventure_screen(RectangleShape& player_hitbox);
        /**
        * Funkcja zwalnia pamięć zaalokowaną przez wszystkie ekrany 
        */
        void delete_all_screens();
        /**
        * Funkcja zwalnia pamięć zaalokowaną przez wszystkie ekrany samouczka 
        */
        void delete_all_tutorial_screens();
        /**
        * Funkcja zwalnia pamięć zaalokowaną przez wszystkie ekrany przygody
        */
        void delete_all_adventure_screens();
        /**
        * Funkcja służy do odtworzenia dźwięku otwarcia drzwi oraz usunięcia ich z ekranu
        * @param d Wskaźnik do drzwi które mają zostać usunięte
        */
        void open_door(Door* d);

        /**Tekstury menu interakcji z drzwiami*/
        Texture door_menu_tex[2];
        /**Sprite menu interakcji z drzwiami*/
        Sprite door_menu_sp;
        /**Dźwięk otwierania drzwi*/
        Sound door_sound;
        /**Bufor przechowujący dźwięk otwierania drzwi*/
        SoundBuffer door_sb;
};

#endif // SCREENS_H
