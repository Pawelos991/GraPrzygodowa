#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"
#include "Character.h"
#include "Missiles.h"
#include "C_Objects.h"

/**
* Klasa reprezentuje posta� gracza, dziedziczy po klasie Character
*/
class Player : private Character
{
    public:
        /**
        * Konstruktor klasy wczytuj�cy dane z plik�w
        */
        Player();
        /**
        * Destruktor klasy
        */
        ~Player(){}
        /**
        * Funkcja odpowiadaj�ca za ruch postaci gracza
        * @param window Okno w kt�rym wy�wietlana jest posta� gracza
        * @param counter Licznik klatek potrzebny do poprawnego wy�wietlania animacji
        */
        void movement(RenderWindow &window, int counter);
        /**
        * Funkcja odpowiada za zwr�cenie pocisku w przypadku wci�ni�cia przez gracza przycisku odpowiedzialnego za atak w momencie gdy ten jest mo�liwy
        * @param window Okno w kt�rym wy�wietlana jest posta� gracza
        * @param counter Licznik klatek potrzebny do poprawnego wy�wietlania animacji
        * @return Wska�nik na nowy pocisk je�li ten zosta� utworzony
        */
        Missile* attack(RenderWindow &window, int counter);
        /**
        * Funkcja wy�wietla paski �ycia oraz many postaci gracza w oknie
        * @param window Okno w kt�rym wy�wietlane s� paski �ycia oraz many
        */
        void Display_HP_and_Mana(RenderWindow &window);
        /**
        * Funkcja ustawiaj�ca pozycj� gracza zgodnie z zadan� pozycj�
        * @param new_position Pozycja na kt�rej ma zosta� ustawiona posta� gracza
        */
        void Set_Position_of_player(Vector2f new_position){hitbox.setPosition(new_position);}
        /**
        * Funkcja sprawdzaj�ca czy posta� koliduje z jakimi� elementami otoczenia
        * @param walls Wektor wska�nik�w na �ciany z kt�rymi mo�e kolidowa� gracz
        */
        void Check_collision_with_enviornment(std::vector<Wall*>& walls);
        /**
        * Funkcja dodaj�ca przedmiot do ekwipunku postaci gracza
        * @param ID ID dodawanego przedmiotu
        * @param all_items Lista wszystkich przedmiot�w dost�pnych w grze
        */
        void add_item_to_Inventory(int ID, Items &all_items);
        /**
        * Funkcja usuwaj�ca przedmiot z ekwipunku postaci gracza. Usuwany jest pierwszy przedmiot o takim ID jak podane jaki zostanie znaleziony w ekwipunku
        * @param ID ID przedmiotu kt�ry ma zosta� usuni�ty
        */
        void remove_item_from_Inventory(int ID);
        /**
        * Funkcja usuwaj�ca wszystkie przedmioty z ekwipunku postaci gracza
        */
        void clear_Inventory();
        /**
        * Funkcja sprawdzaj�ca czy w ekwipunku znajduje si� przedmiot o podanym ID
        * @param ID ID szukanego przedmiotu
        * @return true je�li w ekwipunku jest chocia� jeden przedmiot o podanym ID, false je�li w ekwipunku nie ma ani jednego przemiotu o podanym ID
        */
        bool is_item_in_Inventory(int ID);
        /**
        * Funkcja wy�wietlaj�ca ekwipunek postaci gracza w oknie
        * @param window Okno w kt�rym wyswielany jest ekwipunek postaci gracza
        * @param open Informacja o tym czy ekwipunek ma by� otwarty
        */
        void Display_inventory(RenderWindow &window,bool open);
        /**
        * Funkcja sprawdzaj�ca czy jakie� pociski przeciwnik�w trafi�y w posta� gracza i je�li tak to usuwa pocisk a postaci gracza zadaje obra�enia
        * @param enemies_missiles Lista pocisk�w przeciwnik�w
        */
        void Check_enemies_missiles(Missiles& enemies_missiles);
        /**
        * Funkcja zwracaj�ca hitbox gracza
        * @return Hitbox gracza
        */
        RectangleShape getHitbox(){return hitbox;}
        /**
        * Funkcja zadaj�ca postaci gracza obra�enia poprzez odj�cie podanej liczby punkt�w �ycia od liczby punkt�w �ycia postaci gracza
        * @param damage Warto�� obra�e� kt�re maj� zosta� zadane postaci gracza
        */
        void getHit(int damage){HP-=damage;}
        /**
        * Funkcja zwraca informacj� o tym czy posta� gracza jest martwa
        * @return true je�li posta� gracza jest martwa, false je�li posta� gracza nie jest martwa
        */
        bool is_player_dead(){return is_dead;}
        /**
        * Funkcja leczy posta� gracza - przywraca 20 punkt�w �ycia je�li gracz posiada >=20 mniej punkt�w �ycia ni� maksymalna ilo�� punkt�w �ycia, przywraca tyle punkt�w, ile brakuje do maksymalnej ilo�ci je�li brakuje mniej ni� 20 punkt�w �ycia
        * Uleczenie odbywa si� tylko je�li posta� gracza ma w ekwipunku przynajmniej jedn� mikstur� lecz�c�
        * @return true je�li postac gracza zosta�a uleczona, false je�li posta� gracza nie zosta�a uleczona
        */
        bool heal();
        /**
        * Funkcja ustawiaj�ca godmode na postaci gracza (bardzo wysoki poziom punkt�w zdrowia, zwi�kszona szybko�� poruszania si� i zwi�kszona szybko�� regenereacji many)
        */
        void set_GodMode();
        /**
        * Funkcja ustawiaj�ca normalne statystyki na postaci gracza (standardowy poziom punkt�w zdrowia, normalna szybko�� poruszania si� i standardowa szybko�� regenereacji many)
        */
        void set_NormalMode();
        /**
        * Funkcja wskrzeszaj�ca posta� gracza
        */
        void Respawn(){is_dead=0;}
        /**
        * Funkcja sprawdzaj�ca czy ci�cia wykonane przez przeciwnik�w trafi�y w posta� gracza i zadaj�ca obra�enia postaci gracza je�li tak
        * @param Slashes Wektor wska�nik�w na hitboxy cie� wykonanych przez przeciwnik�w
        */
        void Check_slashes(std::vector<RectangleShape*>Slashes);
        /**
        * Funkcja odpowiedzialna za utrzymanie ruchu postaci gracza, korzysta z innych funkcji tej klasy
        * @param window Okno w kt�rym wyswietlana jest posta� gracza
        * @param counter Licznik klatek potrzebny do poprawnego wy�wietlania animacji
        * @param walls Wektor wska�nik�w na �ciany z kt�rymi mo�e kolidowa� posta� gracza
        * @param open_inventory Informacja o tym czy ekwipunek powinien by� otwarty
        * @param Slashes Wektor wska�nik�w na hitboxy ci�� wykonanych przez przeciwnik�w
        * @param enemies_missiles Lista pocisk�w przeciwnik�w
        * @return Wska�nik na pocisk je�li ten zosta� stworzony, nullptr je�li pocisk nie zosta� stworzony
        */
        Missile* Maintenance(RenderWindow &window,int counter,std::vector<Wall*>& walls,bool open_inventory,std::vector<RectangleShape*>Slashes,Missiles& enemies_missiles);

        /**Hitbox postaci gracza*/
        RectangleShape hitbox;

    private:
        /**Ekwipunek postaci gracza*/
        Inventory inventory;
        /**Informacja o tym w jakim kierunku zostanie wystrzelony pocisk postaci gracza*/
        int missile_indicator; //1 -Right, 2 - Left, 3 - Up, 4 - Down
        /**Aktualna ilo�� many postaci gracza*/
        int MANA;
        /**Maksymalna ilo�� many postaci gracza*/
        int MaxMANA;
        /**Aktualna pr�dko�� poruszania si� postaci gracza*/
        int Speed; //Used in move function
        /**Maksymalna pr�dko�c poruszania si� postaci gracza*/
        int speed_of_movement; //Variable
        /**Szybko�� regeneracji many postaci gracza (jednostek/klatk�)*/
        int Mana_regen;
        /**Bufor przechowuj�cy d�wi�k picia*/
        SoundBuffer Drink_buffer;
        /**D�wi�k picia odtwarzany przy udanym u�yciu mikstury*/
        Sound Drink_sound;
        /**Informacje o tym czy posta� gracza koliduje z otoczeniem z kt�rej� ze stron*/
        bool colliders[4]; //0 - Right, 1 - Left, 2 - Up, 3 - Down  false-No collision, true - Collision
        /**Informacja o tym czy ekwipunek jest obecnie otwarty*/
        bool is_inventory_open;
        /**Czarny pasek wy�wietlany w miejscu brakuj�cej cz�ci paska zdrowia postaci gracza*/
        RectangleShape HP_Black;
        /**Niebieski pasek pokazuj�cy aktualn� ilo�� many postaci gracza*/
        RectangleShape MANA_Blue;
        /**Czarny pasek wy�wietlany w miejscu brakuj�cej cz�ci paska many postaci gracza*/
        RectangleShape MANA_Black;
        /**Tekstura ramki paska �ycia postaci gracza*/
        Texture HP_Tex;
        /**Tekstura ramki paska many postaci gracza*/
        Texture Mana_Tex;
        /**Sprite ramki paska �ycia postaci gracza*/
        Sprite HP_Sp;
        /**Sprite ramki paska many postaci gracza*/
        Sprite Mana_Sp;

};

#endif // PLAYER_H
