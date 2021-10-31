#ifndef SCREENS_H
#define SCREENS_H

#include "Loading_Screen.h"

/**
* Klasa reprezentuje zbiór ekranów, do których zaliczaj¹ siê ekrany samouczka, przygody oraz ekran areny
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
        /**WskaŸnik na aktualny ekran na którym znajduje siê postaæ gracza*/
        Screen *Actual_screen;
        /**WskaŸnik na aktualny ekran przygody zapamiêtywany aby umieœciæ postaæ gracza na dobrym ekranie w przypadku kontynuacji przerwanej przygody*/
        Screen *Actual_adventure_screen;

        /**WskaŸnik na ekran areny*/
        Screen* arena_screen;
        /**Vector ekranów samouczka*/
        std::vector<Screen*> tutorial_screens;
        /**Vector ekranów aktualnego poziomu przygody*/
        std::vector<Screen*> adventure_screens;

        /**WskaŸnik na ekran ³adowania*/
        Loading_Screen *loading_screen;

        /**
        * Funkcja która zwraca wskaŸnik na ekran samouczka zgodny z podanym argumentem
        * @param ID ID ekranu samouczka na który ma zostaæ zwrócony wskaŸnik
        * @return WskaŸnik na ekran samouczka o podanym ID
        */
        Screen* get_tutorial_screen_by_ID(int ID);
        /**
        * Funkcja wczytuje ekrany samouczka z plików konfiguracyjnych i ³aduje je do Vector-a ekranów samouczka
        * @param window Okno w którym wyœwietlany jest ekran ³adowania
        */
        void load_tutorial_Screens(RenderWindow& window);
        /**
        * Funkcja wczytuje ekran areny z plików i ustawia atrybut arena_screen na ten ekran
        */
        void load_arena_Screen();
        /**
        * Funkcja tworzy nowy ekran ³adowania i przypisuje jego adres do wskaŸnika loading_screen
        */
        void load_loading_screen();
        /**
        * Funkcja ³aduje informacje o interakcjach z drzwiami
        */
        void load_door_data();
        /**
        * Funkcja wyœwietla aktualny ekran w oknie gry
        * @param window Okno w którym ma zostaæ wyœwietlony ekran
        */
        void Display_Screens(RenderWindow &window);
        /**
        * Funkcja sprawdza czy postaæ gracza przemieœci³a siê z jednego ekranu samouczka do innego i jeœli tak to wprowadza odpowiednie zmiany w atrybutach
        * @param player_hitbox Hitbox postaci gracza
        * @return true jeœli postaæ gracza dotar³a do ostatniego ekranu samouczka (czyli go ukoñczy³a), false jeœli nie
        */
        bool Check_tutorial_screen(RectangleShape &player_hitbox);
        /**
        * Funkcja sprawdza czy postaæ gracza przemieœci³a siê z jednego ekranu przygody do innego i jeœli tak to wprowadza odpowiednie zmiany w atrybutach
        * @param player_hitbox Hitbox postaci gracza
        * @return true jeœli zmieni³ siê aktualny ekran i obecny ekran jest odwiedzany po raz pierwszy, false jeœli dowolny z poprzednich warunków nie jest spe³niony
        */
        bool Check_adventure_screen(RectangleShape& player_hitbox);
        /**
        * Funkcja zwalnia pamiêæ zaalokowan¹ przez wszystkie ekrany 
        */
        void delete_all_screens();
        /**
        * Funkcja zwalnia pamiêæ zaalokowan¹ przez wszystkie ekrany samouczka 
        */
        void delete_all_tutorial_screens();
        /**
        * Funkcja zwalnia pamiêæ zaalokowan¹ przez wszystkie ekrany przygody
        */
        void delete_all_adventure_screens();
        /**
        * Funkcja s³u¿y do odtworzenia dŸwiêku otwarcia drzwi oraz usuniêcia ich z ekranu
        * @param d WskaŸnik do drzwi które maj¹ zostaæ usuniête
        */
        void open_door(Door* d);

        /**Tekstury menu interakcji z drzwiami*/
        Texture door_menu_tex[2];
        /**Sprite menu interakcji z drzwiami*/
        Sprite door_menu_sp;
        /**DŸwiêk otwierania drzwi*/
        Sound door_sound;
        /**Bufor przechowuj¹cy dŸwiêk otwierania drzwi*/
        SoundBuffer door_sb;
};

#endif // SCREENS_H
