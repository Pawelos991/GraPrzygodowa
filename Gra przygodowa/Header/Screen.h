#ifndef SCREEN_H
#define SCREEN_H

#include "Background.h"
#include "C_Objects.h"
#include "Characters.h"
#include "Portal.h"

/**
* Klasa reprezentuje pojedynczy ekran w grze, dziedziczy po klasach Background, C_Objects oraz Characters
*/
class Screen : public Background,public C_Objects,public Characters
{
    public:
        /**
        * Konstruktor klasy �aduj�cy informacje z plik�w
        * @param info_file �cie�ka do pliku z informacjami na temat ekranu
        */
        Screen(std::string info_file);
        /**
        * Konstruktor klasy uzupe�niaj�cy podstawowe informacje domy�lnymi warto�ciami i ustawiaj�cy ID ekranu zgodnie z argumentem
        * @param id ID ekranu kt�re ma zosta� ustawione w odpowiednim atrybucie
        */
        Screen( int id );
        /**
        * Destruktor klasy
        */
        virtual ~Screen();
        
        /**
        * Funkcja wy�wietlaj�ca ekran (wraz ze wszystkimi jego elementami) w oknie
        * @param window Okno w kt�rym ma by� wy�wietlony ekran
        */
        void displayScreen(RenderWindow &window);

        /**
        * Funkcja sprawdza czy posta� gracza koliduje z kt�r�� ze skrzy� na ekranie
        * @param players_hitbox Hitbox postaci gracza
        * @return Wska�nik na skrzyni� z kt�r� koliduje posta� gracza je�li z jak�� koliduje, nullptr je�li posta� gracza nie koliduje z �adn� skrzyni� na ekranie
        */
        Chest* check_chests(RectangleShape players_hitbox);
        /**
        * Funkcja sprawdza czy posta� gracza koliduje z jakimi� drzwiami na ekranie
        * @param players_hitbox Hitbox postaci gracza
        * @return Wska�nik na drzwi z kt�rymi koliduje posta� gracza je�li z jakimi� koliduje, nullptr je�li posta� gracza nie koliduje z �adnymi drzwiami na ekranie
        */
        Door* check_doors(RectangleShape players_hitbox);
        /**
        * Funkcja sprawdza czy posta� gracza koliduje z portalem na ekranie
        * @param players_hitbox Hitbox postaci gracza
        * @return true je�li posta� gracza koliduje z portalem, nullptr je�li posta� gracza nie koliduje z portalem lub na ekranie nie ma portalu
        */
        bool check_portal(RectangleShape players_hitbox);
        /**
        * Funkcja zwraca informacj� o tym czy ekran ma portal
        * @return true je�li ekran ma portal, false je�li ekran nie ma portalu
        */
        bool has_portal() { return !(portal == nullptr); }
        /**Pociski wystrzelone przez gracza*/
        Missiles player_missiles;
        /**Pociski wystrzelone przez przeciwnik�w*/
        Missiles enemies_missiles;
        /**
        * Funkcja zwalaniaj�ca pami�� zaalokowan� przez ekran i jego cz�ci sk�adowe
        */
        void clear_space();

        //Setters and getters
        /**
        * Funkcja zwraca ID ekranu
        * @return ID ekranu
        */
        int getID() { return ID; }
        /**
        * Funkcja ustawia ID ekranu zgodnie z argumentem
        * @param id ID na kt�re ma zosta� ustawiony atrybut ID ekranu
        */
        void setID(int id) { ID = id; }

        /**
        * Funkcja zwracaj�ca informacj� o ID ekranu znajduj�cego si� po prawej stronie od ekranu
        * @return ID ekranu znajduj�cego si� po prawej stronie je�li znajduje si� tam jaki� ekran, 0 je�li nie ma tam �adnego ekranu
        */
        int goRight() { return rightID; }
        /**
        * Funkcja ustawiaj�ca ID ekranu znajduj�cego si� po prawej stronie od ekranu zgodnie z argumentem
        * @param r ID ekranu znajduj�cego si� po prawej stronie od ekranu
        */
        void setRight(int r) { rightID = r; }

        /**
        * Funkcja zwracaj�ca informacj� o ID ekranu znajduj�cego si� po lewej stronie od ekranu
        * @return ID ekranu znajduj�cego si� po lewej stronie je�li znajduje si� tam jaki� ekran, 0 je�li nie ma tam �adnego ekranu
        */
        int goLeft() { return leftID; }
        /**
        * Funkcja ustawiaj�ca ID ekranu znajduj�cego si� po lewej stronie od ekranu zgodnie z argumentem
        * @param r ID ekranu znajduj�cego si� po lewej stronie od ekranu
        */
        void setLeft(int l) { leftID = l; }

        /**
        * Funkcja zwracaj�ca informacj� o ID ekranu znajduj�cego si� powy�ej ekranu
        * @return ID ekranu znajduj�cego si� powy�ej je�li znajduje si� tam jaki� ekran, 0 je�li nie ma tam �adnego ekranu
        */
        int goUp() { return upID; }
        /**
        * Funkcja ustawiaj�ca ID ekranu znajduj�cego si� powy�ej ekranu zgodnie z argumentem
        * @param r ID ekranu znajduj�cego si� powy�ej ekranu
        */
        void setUp(int u) { upID = u; }

        /**
        * Funkcja zwracaj�ca informacj� o ID ekranu znajduj�cego si� poni�ej ekranu
        * @return ID ekranu znajduj�cego si� poni�ej je�li znajduje si� tam jaki� ekran, 0 je�li nie ma tam �adnego ekranu
        */
        int goDown() { return downID; }
        /**
        * Funkcja ustawiaj�ca ID ekranu znajduj�cego si� poni�ej ekranu zgodnie z argumentem
        * @param r ID ekranu znajduj�cego si� poni�ej ekranu
        */
        void setDown(int d) { downID = d; }

        /**
        * Funkcja zwracaj�ca informacj� o ilo�ci po��cze� ekranu z innymi ekranami
        * @return Ilo�� po��cze� z innymi ekranami (np. je�li z danego ekranu da si� przej�� do 2 innych ekran�w to funkcja zwr�ci warto�� 2)
        */
        int getNumberOfConnections() { return howManyConnections; }
        /**
        * Funkcja ustawia warto�� atrybutu oznaczaj�cego ilo�� po��cze� ekranu z innymi ekranami zgodnie z argumentem
        * @param n Liczba po��cze� kt�ra ma zosta� ustawiona jako atrybut ekranu
        */
        void setNumberOfConnections(int n) { howManyConnections = n; }

        /**
        * Funkcja zwracaj�ca informacj� o tym czy z ekranu zosta�y ju� raz usuni�te �ciany blokuj�ce przej�cie do innych ekran�w
        * @return Informacja o tym czy z ekranu zosta�y ju� raz usuni�te �ciany blokuj�ce przej�cie do innych ekran�w
        */
        bool is_removed() { return removed; }
        /**
        * Funkcja ustawiaj�ca informacj� o tym czy z ekranu zosta�y ju� raz usuni�te �ciany blokuj�ce przej�cie do innych ekran�w zgodnie z argumentem
        * @param rm Informacja o tym czy z ekranu zosta�y ju� raz usuni�te �ciany blokuj�ce przej�cie do innych ekran�w zgodnie z kt�r� ma zosta� ustawiony atrybut obiektu
        */
        void set_removed(bool rm) { removed = rm; }

        /**
        * Funkcja zwracaj�ca sprite t�a ekranu
        * @return Sprite t�a ekranu
        */
        Sprite getBck() { return Bck; }
        /**
        * Funkcja ustawiaj�ca t�o ekranu zgodnie z obrazkiem do kt�rego podano �cie�k� jako argument
        * @param pathToBck �cie�ka do tekstury t�a ekranu
        */
        void setBck(std::string pathToBck) { pic.loadFromFile(pathToBck); Bck.setTexture(pic); }

        /**
        * Funkcja zwracaj�ca wektor wska�nik�w na obiekty niekoliduj�ce z postaci� gracza z ekranu
        * @return Wektor wska�nik�w na obiekty niekoliduj�ce z postaci� gracza z ekranu
        */
        std::vector<NC_Object*> get_NC_Objects() { return NC_Objects; }
        /**
        * Funkcja ustawia wektor wska�nik�w na obiekty niekoliduj�ce z postaci� gracza zgodnie z argumentem
        * @param nc Wektor wska�nik�w na obiekty niekoliduj�ce z postaci� gracza
        */
        void set_NC_Objects(std::vector<NC_Object*>& nc) { NC_Objects = nc; }

        /**
        * Funkcja zwraca wektor wska�nik�w na �ciany
        * @return Wektor wska�nik�w na �ciany
        */
        std::vector<Wall*> getWalls() { return walls; }
        /**
        * Funkcja ustawia wektor wska�nik�w na �ciany zgodnie z argumentem
        * @param w Wektor wska�nik�w na �ciany
        */
        void setWalls(std::vector<Wall*>& w) { walls = w; }

        /**
        * Funkcja zwraca wektor wska�nik�w na drzwi 
        * @return Wektor wska�nik�w na drzwi
        */
        std::vector<Door*> getDoors() { return doors; }
        /**
        * Funkcja ustawia wektor wska�nik�w na drzwi zgodnie z argumentem
        * @param d Wektor wska�nik�w na drzwi
        */
        void setDoors(std::vector<Door*>& d) { doors = d; }

        /**
        * Funkcja zwraca wektor wska�nik�w na skrzynie
        * @return Wektor wska�nik�w na skrzynie
        */
        std::vector<Chest*> getChests() { return chests; }
        /**
        * Funkcja ustawia wektor wska�nik�w na skrzynie zgodnie z argumentem
        * @param c Wektor wska�nik�w na skrzynie
        */
        void setChests(std::vector<Chest*>& c) { chests = c; }

        /**
        * Funkcja zwraca pozycj� ekranu (wsp�rz�dne X i Y w uk�adzie wsp�rz�dnych)
        * @return Pozycja ekranu
        */
        Vector2f getPosition() { return position; }
        /**
        * Funkcja ustawia pozycj� ekranu zgodnie z argumentem
        * @param pos Pozycja kt�ra ma zosta� ustawiona jako pozycja ekranu
        */
        void setPosition(Vector2f pos) { position = pos; }

        /**
        * Funkcja zwraca informacj� o tym czy ekran zosta� odwiedzony przez posta� gracza
        * @return Informacja o tym czy ekran zosta� odwiedzony przez posta� gracza
        */
        bool isVisited() { return visited; }
        /**
        * Funkcja ustawia atrybut odpowiedzialny z informacj� o tym, czy ekran zosta� odwiedzony przez posta� gracza zgodnie z argumentem
        * @param v Informacja o tym czy ekran zosta� odwiedzony przez posta� gracza
        */
        void setVisited(bool v) { visited = v; }

        /**
        * Funkcja zwraca wska�nik na portal o ile ten znajduje sie na ekranie
        * @return Wska�nik na portal o ile ten znajduje si� na ekranie, nullptr je�li na ekranie nie ma portalu
        */
        Portal* getPortal() { return portal; }
        /**
        * Funkcja ustawia wska�nik na portal zgodnie z argumentem
        * @param p Wska�nik na portal na kt�ry ma zosta� ustawiony atrybut obiektu
        */
        void setPortal(Portal* p) { portal = p; }

    private:
        /**ID ekranue*/
        int ID;
        /**ID ekranu znajduj�cego si� po lewej stronie od ekranu, 0 je�li po lewej stronie nie ma �adnego ekranu*/
        int leftID;
        /**ID ekranu znajduj�cego si� po prawej stronie od ekranu, 0 je�li po prawej stronie nie ma �adnego ekranu*/
        int rightID;
        /**ID ekranu znajduj�cego si� powy�ej ekranu, 0 je�li powy�ej nie ma �adnego ekranu*/
        int upID;
        /**ID ekranu znajduj�cego si� poni�ej ekranu, 0 je�li poni�ej nie ma �adnego ekranu*/
        int downID;
        /**Informacja o tym z iloma innymi ekranami dany ekran ma po��czenie*/
        int howManyConnections;
        /**Informacja o tym czy z ekranu zosta�y ju� raz usuni�te �ciany blokuj�ce przej�cie do innych ekran�w*/
        bool removed;
        /**Informacja o tym czy ekran zosta� odwiedzony przez posta� gracza*/
        bool visited;
        /**Pozycja ekranu w uk�adzie wsp�rz�dnych (wsp�rz�dne X i Y)*/
        Vector2f position;
        /**Wska�nik na portal znajduj�cy si� na ekranie. Nullptr na ekranie nie ma portalu*/
        Portal* portal;
};

#endif // SCREEN_H
