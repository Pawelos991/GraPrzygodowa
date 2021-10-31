#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"
#include "Character.h"
#include "Missiles.h"
#include "C_Objects.h"

/**
* Klasa reprezentuje postaæ gracza, dziedziczy po klasie Character
*/
class Player : private Character
{
    public:
        /**
        * Konstruktor klasy wczytuj¹cy dane z plików
        */
        Player();
        /**
        * Destruktor klasy
        */
        ~Player(){}
        /**
        * Funkcja odpowiadaj¹ca za ruch postaci gracza
        * @param window Okno w którym wyœwietlana jest postaæ gracza
        * @param counter Licznik klatek potrzebny do poprawnego wyœwietlania animacji
        */
        void movement(RenderWindow &window, int counter);
        /**
        * Funkcja odpowiada za zwrócenie pocisku w przypadku wciœniêcia przez gracza przycisku odpowiedzialnego za atak w momencie gdy ten jest mo¿liwy
        * @param window Okno w którym wyœwietlana jest postaæ gracza
        * @param counter Licznik klatek potrzebny do poprawnego wyœwietlania animacji
        * @return WskaŸnik na nowy pocisk jeœli ten zosta³ utworzony
        */
        Missile* attack(RenderWindow &window, int counter);
        /**
        * Funkcja wyœwietla paski ¿ycia oraz many postaci gracza w oknie
        * @param window Okno w którym wyœwietlane s¹ paski ¿ycia oraz many
        */
        void Display_HP_and_Mana(RenderWindow &window);
        /**
        * Funkcja ustawiaj¹ca pozycjê gracza zgodnie z zadan¹ pozycj¹
        * @param new_position Pozycja na której ma zostaæ ustawiona postaæ gracza
        */
        void Set_Position_of_player(Vector2f new_position){hitbox.setPosition(new_position);}
        /**
        * Funkcja sprawdzaj¹ca czy postaæ koliduje z jakimiœ elementami otoczenia
        * @param walls Wektor wskaŸników na œciany z którymi mo¿e kolidowaæ gracz
        */
        void Check_collision_with_enviornment(std::vector<Wall*>& walls);
        /**
        * Funkcja dodaj¹ca przedmiot do ekwipunku postaci gracza
        * @param ID ID dodawanego przedmiotu
        * @param all_items Lista wszystkich przedmiotów dostêpnych w grze
        */
        void add_item_to_Inventory(int ID, Items &all_items);
        /**
        * Funkcja usuwaj¹ca przedmiot z ekwipunku postaci gracza. Usuwany jest pierwszy przedmiot o takim ID jak podane jaki zostanie znaleziony w ekwipunku
        * @param ID ID przedmiotu który ma zostaæ usuniêty
        */
        void remove_item_from_Inventory(int ID);
        /**
        * Funkcja usuwaj¹ca wszystkie przedmioty z ekwipunku postaci gracza
        */
        void clear_Inventory();
        /**
        * Funkcja sprawdzaj¹ca czy w ekwipunku znajduje siê przedmiot o podanym ID
        * @param ID ID szukanego przedmiotu
        * @return true jeœli w ekwipunku jest chocia¿ jeden przedmiot o podanym ID, false jeœli w ekwipunku nie ma ani jednego przemiotu o podanym ID
        */
        bool is_item_in_Inventory(int ID);
        /**
        * Funkcja wyœwietlaj¹ca ekwipunek postaci gracza w oknie
        * @param window Okno w którym wyswielany jest ekwipunek postaci gracza
        * @param open Informacja o tym czy ekwipunek ma byæ otwarty
        */
        void Display_inventory(RenderWindow &window,bool open);
        /**
        * Funkcja sprawdzaj¹ca czy jakieœ pociski przeciwników trafi³y w postaæ gracza i jeœli tak to usuwa pocisk a postaci gracza zadaje obra¿enia
        * @param enemies_missiles Lista pocisków przeciwników
        */
        void Check_enemies_missiles(Missiles& enemies_missiles);
        /**
        * Funkcja zwracaj¹ca hitbox gracza
        * @return Hitbox gracza
        */
        RectangleShape getHitbox(){return hitbox;}
        /**
        * Funkcja zadaj¹ca postaci gracza obra¿enia poprzez odjêcie podanej liczby punktów ¿ycia od liczby punktów ¿ycia postaci gracza
        * @param damage Wartoœæ obra¿eñ które maj¹ zostaæ zadane postaci gracza
        */
        void getHit(int damage){HP-=damage;}
        /**
        * Funkcja zwraca informacjê o tym czy postaæ gracza jest martwa
        * @return true jeœli postaæ gracza jest martwa, false jeœli postaæ gracza nie jest martwa
        */
        bool is_player_dead(){return is_dead;}
        /**
        * Funkcja leczy postaæ gracza - przywraca 20 punktów ¿ycia jeœli gracz posiada >=20 mniej punktów ¿ycia ni¿ maksymalna iloœæ punktów ¿ycia, przywraca tyle punktów, ile brakuje do maksymalnej iloœci jeœli brakuje mniej ni¿ 20 punktów ¿ycia
        * Uleczenie odbywa siê tylko jeœli postaæ gracza ma w ekwipunku przynajmniej jedn¹ miksturê lecz¹c¹
        * @return true jeœli postac gracza zosta³a uleczona, false jeœli postaæ gracza nie zosta³a uleczona
        */
        bool heal();
        /**
        * Funkcja ustawiaj¹ca godmode na postaci gracza (bardzo wysoki poziom punktów zdrowia, zwiêkszona szybkoœæ poruszania siê i zwiêkszona szybkoœæ regenereacji many)
        */
        void set_GodMode();
        /**
        * Funkcja ustawiaj¹ca normalne statystyki na postaci gracza (standardowy poziom punktów zdrowia, normalna szybkoœæ poruszania siê i standardowa szybkoœæ regenereacji many)
        */
        void set_NormalMode();
        /**
        * Funkcja wskrzeszaj¹ca postaæ gracza
        */
        void Respawn(){is_dead=0;}
        /**
        * Funkcja sprawdzaj¹ca czy ciêcia wykonane przez przeciwników trafi³y w postaæ gracza i zadaj¹ca obra¿enia postaci gracza jeœli tak
        * @param Slashes Wektor wskaŸników na hitboxy cieæ wykonanych przez przeciwników
        */
        void Check_slashes(std::vector<RectangleShape*>Slashes);
        /**
        * Funkcja odpowiedzialna za utrzymanie ruchu postaci gracza, korzysta z innych funkcji tej klasy
        * @param window Okno w którym wyswietlana jest postaæ gracza
        * @param counter Licznik klatek potrzebny do poprawnego wyœwietlania animacji
        * @param walls Wektor wskaŸników na œciany z którymi mo¿e kolidowaæ postaæ gracza
        * @param open_inventory Informacja o tym czy ekwipunek powinien byæ otwarty
        * @param Slashes Wektor wskaŸników na hitboxy ciêæ wykonanych przez przeciwników
        * @param enemies_missiles Lista pocisków przeciwników
        * @return WskaŸnik na pocisk jeœli ten zosta³ stworzony, nullptr jeœli pocisk nie zosta³ stworzony
        */
        Missile* Maintenance(RenderWindow &window,int counter,std::vector<Wall*>& walls,bool open_inventory,std::vector<RectangleShape*>Slashes,Missiles& enemies_missiles);

        /**Hitbox postaci gracza*/
        RectangleShape hitbox;

    private:
        /**Ekwipunek postaci gracza*/
        Inventory inventory;
        /**Informacja o tym w jakim kierunku zostanie wystrzelony pocisk postaci gracza*/
        int missile_indicator; //1 -Right, 2 - Left, 3 - Up, 4 - Down
        /**Aktualna iloœæ many postaci gracza*/
        int MANA;
        /**Maksymalna iloœæ many postaci gracza*/
        int MaxMANA;
        /**Aktualna prêdkoœæ poruszania siê postaci gracza*/
        int Speed; //Used in move function
        /**Maksymalna prêdkoœc poruszania siê postaci gracza*/
        int speed_of_movement; //Variable
        /**Szybkoœæ regeneracji many postaci gracza (jednostek/klatkê)*/
        int Mana_regen;
        /**Bufor przechowuj¹cy dŸwiêk picia*/
        SoundBuffer Drink_buffer;
        /**DŸwiêk picia odtwarzany przy udanym u¿yciu mikstury*/
        Sound Drink_sound;
        /**Informacje o tym czy postaæ gracza koliduje z otoczeniem z którejœ ze stron*/
        bool colliders[4]; //0 - Right, 1 - Left, 2 - Up, 3 - Down  false-No collision, true - Collision
        /**Informacja o tym czy ekwipunek jest obecnie otwarty*/
        bool is_inventory_open;
        /**Czarny pasek wyœwietlany w miejscu brakuj¹cej czêœci paska zdrowia postaci gracza*/
        RectangleShape HP_Black;
        /**Niebieski pasek pokazuj¹cy aktualn¹ iloœæ many postaci gracza*/
        RectangleShape MANA_Blue;
        /**Czarny pasek wyœwietlany w miejscu brakuj¹cej czêœci paska many postaci gracza*/
        RectangleShape MANA_Black;
        /**Tekstura ramki paska ¿ycia postaci gracza*/
        Texture HP_Tex;
        /**Tekstura ramki paska many postaci gracza*/
        Texture Mana_Tex;
        /**Sprite ramki paska ¿ycia postaci gracza*/
        Sprite HP_Sp;
        /**Sprite ramki paska many postaci gracza*/
        Sprite Mana_Sp;

};

#endif // PLAYER_H
