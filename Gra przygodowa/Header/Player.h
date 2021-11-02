#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"
#include "Character.h"
#include "Missiles.h"
#include "C_Objects.h"

/**
* Klasa reprezentuje postać gracza, dziedziczy po klasie Character
*/
class Player : private Character
{
    public:
        /**
        * Konstruktor klasy wczytujący dane z plików
        */
        Player();
        /**
        * Destruktor klasy
        */
        ~Player(){}
        /**
        * Funkcja odpowiadająca za ruch postaci gracza
        * @param window Okno w którym wyświetlana jest postać gracza
        * @param counter Licznik klatek potrzebny do poprawnego wyświetlania animacji
        */
        void movement(RenderWindow &window, int counter);
        /**
        * Funkcja odpowiada za zwrócenie pocisku w przypadku wciśnięcia przez gracza przycisku odpowiedzialnego za atak w momencie gdy ten jest możliwy
        * @param window Okno w którym wyświetlana jest postać gracza
        * @param counter Licznik klatek potrzebny do poprawnego wyświetlania animacji
        * @return Wskaźnik na nowy pocisk jeśli ten został utworzony
        */
        Missile* attack(RenderWindow &window, int counter);
        /**
        * Funkcja wyświetla paski życia oraz many postaci gracza w oknie
        * @param window Okno w którym wyświetlane są paski życia oraz many
        */
        void Display_HP_and_Mana(RenderWindow &window);
        /**
        * Funkcja ustawiająca pozycję gracza zgodnie z zadaną pozycją
        * @param new_position Pozycja na której ma zostać ustawiona postać gracza
        */
        void Set_Position_of_player(Vector2f new_position){hitbox.setPosition(new_position);}
        /**
        * Funkcja sprawdzająca czy postać koliduje z jakimiś elementami otoczenia
        * @param walls Wektor wskaźników na ściany z którymi może kolidować gracz
        */
        void Check_collision_with_enviornment(std::vector<Wall*>& walls);
        /**
        * Funkcja dodająca przedmiot do ekwipunku postaci gracza
        * @param ID ID dodawanego przedmiotu
        * @param all_items Lista wszystkich przedmiotów dostępnych w grze
        */
        void add_item_to_Inventory(int ID, Items &all_items);
        /**
        * Funkcja usuwająca przedmiot z ekwipunku postaci gracza. Usuwany jest pierwszy przedmiot o takim ID jak podane jaki zostanie znaleziony w ekwipunku
        * @param ID ID przedmiotu który ma zostać usunięty
        */
        void remove_item_from_Inventory(int ID);
        /**
        * Funkcja usuwająca wszystkie przedmioty z ekwipunku postaci gracza
        */
        void clear_Inventory();
        /**
        * Funkcja sprawdzająca czy w ekwipunku znajduje się przedmiot o podanym ID
        * @param ID ID szukanego przedmiotu
        * @return true jeśli w ekwipunku jest chociaż jeden przedmiot o podanym ID, false jeśli w ekwipunku nie ma ani jednego przemiotu o podanym ID
        */
        bool is_item_in_Inventory(int ID);
        /**
        * Funkcja wyświetlająca ekwipunek postaci gracza w oknie
        * @param window Okno w którym wyswielany jest ekwipunek postaci gracza
        * @param open Informacja o tym czy ekwipunek ma być otwarty
        */
        void Display_inventory(RenderWindow &window,bool open);
        /**
        * Funkcja sprawdzająca czy jakieś pociski przeciwników trafiły w postać gracza i jeśli tak to usuwa pocisk a postaci gracza zadaje obrażenia
        * @param enemies_missiles Lista pocisków przeciwników
        */
        void Check_enemies_missiles(Missiles& enemies_missiles);
        /**
        * Funkcja zwracająca hitbox gracza
        * @return Hitbox gracza
        */
        RectangleShape getHitbox(){return hitbox;}
        /**
        * Funkcja zadająca postaci gracza obrażenia poprzez odjęcie podanej liczby punktów życia od liczby punktów życia postaci gracza
        * @param damage Wartość obrażeń które mają zostać zadane postaci gracza
        */
        void getHit(int damage){HP-=damage;}
        /**
        * Funkcja zwraca informację o tym czy postać gracza jest martwa
        * @return true jeśli postać gracza jest martwa, false jeśli postać gracza nie jest martwa
        */
        bool is_player_dead(){return is_dead;}
        /**
        * Funkcja leczy postać gracza - przywraca 20 punktów życia jeśli gracz posiada >=20 mniej punktów życia niż maksymalna ilość punktów życia, przywraca tyle punktów, ile brakuje do maksymalnej ilości jeśli brakuje mniej niż 20 punktów życia
        * Uleczenie odbywa się tylko jeśli postać gracza ma w ekwipunku przynajmniej jedną miksturę leczącą
        * @return true jeśli postac gracza została uleczona, false jeśli postać gracza nie została uleczona
        */
        bool heal();
        /**
        * Funkcja ustawiająca godmode na postaci gracza (bardzo wysoki poziom punktów zdrowia, zwiększona szybkość poruszania się i zwiększona szybkość regenereacji many)
        */
        void set_GodMode();
        /**
        * Funkcja ustawiająca normalne statystyki na postaci gracza (standardowy poziom punktów zdrowia, normalna szybkość poruszania się i standardowa szybkość regenereacji many)
        */
        void set_NormalMode();
        /**
        * Funkcja wskrzeszająca postać gracza
        */
        void Respawn(){is_dead=0;}
        /**
        * Funkcja sprawdzająca czy cięcia wykonane przez przeciwników trafiły w postać gracza i zadająca obrażenia postaci gracza jeśli tak
        * @param Slashes Wektor wskaźników na hitboxy cieć wykonanych przez przeciwników
        */
        void Check_slashes(std::vector<RectangleShape*>Slashes);
        /**
        * Funkcja odpowiedzialna za utrzymanie ruchu postaci gracza, korzysta z innych funkcji tej klasy
        * @param window Okno w którym wyswietlana jest postać gracza
        * @param counter Licznik klatek potrzebny do poprawnego wyświetlania animacji
        * @param walls Wektor wskaźników na ściany z którymi może kolidować postać gracza
        * @param open_inventory Informacja o tym czy ekwipunek powinien być otwarty
        * @param Slashes Wektor wskaźników na hitboxy cięć wykonanych przez przeciwników
        * @param enemies_missiles Lista pocisków przeciwników
        * @return Wskaźnik na pocisk jeśli ten został stworzony, nullptr jeśli pocisk nie został stworzony
        */
        Missile* Maintenance(RenderWindow &window,int counter,std::vector<Wall*>& walls,bool open_inventory,std::vector<RectangleShape*>Slashes,Missiles& enemies_missiles);

        /**Hitbox postaci gracza*/
        RectangleShape hitbox;

    private:
        /**Ekwipunek postaci gracza*/
        Inventory inventory;
        /**Informacja o tym w jakim kierunku zostanie wystrzelony pocisk postaci gracza*/
        int missile_indicator; //1 -Right, 2 - Left, 3 - Up, 4 - Down
        /**Aktualna ilość many postaci gracza*/
        int MANA;
        /**Maksymalna ilość many postaci gracza*/
        int MaxMANA;
        /**Aktualna prędkość poruszania się postaci gracza*/
        int Speed; //Used in move function
        /**Maksymalna prędkośc poruszania się postaci gracza*/
        int speed_of_movement; //Variable
        /**Szybkość regeneracji many postaci gracza (jednostek/klatkę)*/
        int Mana_regen;
        /**Bufor przechowujący dźwięk picia*/
        SoundBuffer Drink_buffer;
        /**Dźwięk picia odtwarzany przy udanym użyciu mikstury*/
        Sound Drink_sound;
        /**Informacje o tym czy postać gracza koliduje z otoczeniem z którejś ze stron*/
        bool colliders[4]; //0 - Right, 1 - Left, 2 - Up, 3 - Down  false-No collision, true - Collision
        /**Informacja o tym czy ekwipunek jest obecnie otwarty*/
        bool is_inventory_open;
        /**Czarny pasek wyświetlany w miejscu brakującej części paska zdrowia postaci gracza*/
        RectangleShape HP_Black;
        /**Niebieski pasek pokazujący aktualną ilość many postaci gracza*/
        RectangleShape MANA_Blue;
        /**Czarny pasek wyświetlany w miejscu brakującej części paska many postaci gracza*/
        RectangleShape MANA_Black;
        /**Tekstura ramki paska życia postaci gracza*/
        Texture HP_Tex;
        /**Tekstura ramki paska many postaci gracza*/
        Texture Mana_Tex;
        /**Sprite ramki paska życia postaci gracza*/
        Sprite HP_Sp;
        /**Sprite ramki paska many postaci gracza*/
        Sprite Mana_Sp;

};

#endif // PLAYER_H
