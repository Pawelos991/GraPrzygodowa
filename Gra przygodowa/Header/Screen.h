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
        * Konstruktor klasy ładujący informacje z plików
        * @param info_file Ścieżka do pliku z informacjami na temat ekranu
        */
        Screen(std::string info_file);
        /**
        * Konstruktor klasy uzupełniający podstawowe informacje domyślnymi wartościami i ustawiający ID ekranu zgodnie z argumentem
        * @param id ID ekranu które ma zostać ustawione w odpowiednim atrybucie
        */
        Screen( int id );
        /**
        * Destruktor klasy
        */
        virtual ~Screen();
        
        /**
        * Funkcja wyświetlająca ekran (wraz ze wszystkimi jego elementami) w oknie
        * @param window Okno w którym ma być wyświetlony ekran
        */
        void displayScreen(RenderWindow &window);

        /**
        * Funkcja sprawdza czy postać gracza koliduje z którąś ze skrzyń na ekranie
        * @param players_hitbox Hitbox postaci gracza
        * @return Wskaźnik na skrzynię z którą koliduje postać gracza jeśli z jakąś koliduje, nullptr jeśli postać gracza nie koliduje z żadną skrzynią na ekranie
        */
        Chest* check_chests(RectangleShape players_hitbox);
        /**
        * Funkcja sprawdza czy postać gracza koliduje z jakimiś drzwiami na ekranie
        * @param players_hitbox Hitbox postaci gracza
        * @return Wskaźnik na drzwi z którymi koliduje postać gracza jeśli z jakimiś koliduje, nullptr jeśli postać gracza nie koliduje z żadnymi drzwiami na ekranie
        */
        Door* check_doors(RectangleShape players_hitbox);
        /**
        * Funkcja sprawdza czy postać gracza koliduje z portalem na ekranie
        * @param players_hitbox Hitbox postaci gracza
        * @return true jeśli postać gracza koliduje z portalem, nullptr jeśli postać gracza nie koliduje z portalem lub na ekranie nie ma portalu
        */
        bool check_portal(RectangleShape players_hitbox);
        /**
        * Funkcja zwraca informację o tym czy ekran ma portal
        * @return true jeśli ekran ma portal, false jeśli ekran nie ma portalu
        */
        bool has_portal() { return !(portal == nullptr); }
        /**Pociski wystrzelone przez gracza*/
        Missiles player_missiles;
        /**Pociski wystrzelone przez przeciwników*/
        Missiles enemies_missiles;
        /**
        * Funkcja zwalaniająca pamięć zaalokowaną przez ekran i jego części składowe
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
        * @param id ID na które ma zostać ustawiony atrybut ID ekranu
        */
        void setID(int id) { ID = id; }

        /**
        * Funkcja zwracająca informację o ID ekranu znajdującego się po prawej stronie od ekranu
        * @return ID ekranu znajdującego się po prawej stronie jeśli znajduje się tam jakiś ekran, 0 jeśli nie ma tam żadnego ekranu
        */
        int goRight() { return rightID; }
        /**
        * Funkcja ustawiająca ID ekranu znajdującego się po prawej stronie od ekranu zgodnie z argumentem
        * @param r ID ekranu znajdującego się po prawej stronie od ekranu
        */
        void setRight(int r) { rightID = r; }

        /**
        * Funkcja zwracająca informację o ID ekranu znajdującego się po lewej stronie od ekranu
        * @return ID ekranu znajdującego się po lewej stronie jeśli znajduje się tam jakiś ekran, 0 jeśli nie ma tam żadnego ekranu
        */
        int goLeft() { return leftID; }
        /**
        * Funkcja ustawiająca ID ekranu znajdującego się po lewej stronie od ekranu zgodnie z argumentem
        * @param l ID ekranu znajdującego się po lewej stronie od ekranu
        */
        void setLeft(int l) { leftID = l; }

        /**
        * Funkcja zwracająca informację o ID ekranu znajdującego się powyżej ekranu
        * @return ID ekranu znajdującego się powyżej jeśli znajduje się tam jakiś ekran, 0 jeśli nie ma tam żadnego ekranu
        */
        int goUp() { return upID; }
        /**
        * Funkcja ustawiająca ID ekranu znajdującego się powyżej ekranu zgodnie z argumentem
        * @param u ID ekranu znajdującego się powyżej ekranu
        */
        void setUp(int u) { upID = u; }

        /**
        * Funkcja zwracająca informację o ID ekranu znajdującego się poniżej ekranu
        * @return ID ekranu znajdującego się poniżej jeśli znajduje się tam jakiś ekran, 0 jeśli nie ma tam żadnego ekranu
        */
        int goDown() { return downID; }
        /**
        * Funkcja ustawiająca ID ekranu znajdującego się poniżej ekranu zgodnie z argumentem
        * @param d ID ekranu znajdującego się poniżej ekranu
        */
        void setDown(int d) { downID = d; }

        /**
        * Funkcja zwracająca informację o ilości połączeń ekranu z innymi ekranami
        * @return Ilość połączeń z innymi ekranami (np. jeśli z danego ekranu da się przejść do 2 innych ekranów to funkcja zwróci wartość 2)
        */
        int getNumberOfConnections() { return howManyConnections; }
        /**
        * Funkcja ustawia wartość atrybutu oznaczającego ilość połączeń ekranu z innymi ekranami zgodnie z argumentem
        * @param n Liczba połączeń która ma zostać ustawiona jako atrybut ekranu
        */
        void setNumberOfConnections(int n) { howManyConnections = n; }

        /**
        * Funkcja zwracająca informację o tym czy z ekranu zostały już raz usunięte ściany blokujące przejście do innych ekranów
        * @return Informacja o tym czy z ekranu zostały już raz usunięte ściany blokujące przejście do innych ekranów
        */
        bool is_removed() { return removed; }
        /**
        * Funkcja ustawiająca informację o tym czy z ekranu zostały już raz usunięte ściany blokujące przejście do innych ekranów zgodnie z argumentem
        * @param rm Informacja o tym czy z ekranu zostały już raz usunięte ściany blokujące przejście do innych ekranów zgodnie z którą ma zostać ustawiony atrybut obiektu
        */
        void set_removed(bool rm) { removed = rm; }

        /**
        * Funkcja zwracająca sprite tła ekranu
        * @return Sprite tła ekranu
        */
        Sprite getBck() { return Bck; }
        /**
        * Funkcja ustawiająca tło ekranu zgodnie z obrazkiem do którego podano ścieżkę jako argument
        * @param pathToBck Ścieżka do tekstury tła ekranu
        */
        void setBck(std::string pathToBck) { pic.loadFromFile(pathToBck); Bck.setTexture(pic); }

        /**
        * Funkcja zwracająca wektor wskaźników na obiekty niekolidujące z postacią gracza z ekranu
        * @return Wektor wskaźników na obiekty niekolidujące z postacią gracza z ekranu
        */
        std::vector<NC_Object*> get_NC_Objects() { return NC_Objects; }
        /**
        * Funkcja ustawia wektor wskaźników na obiekty niekolidujące z postacią gracza zgodnie z argumentem
        * @param nc Wektor wskaźników na obiekty niekolidujące z postacią gracza
        */
        void set_NC_Objects(std::vector<NC_Object*>& nc) { NC_Objects = nc; }

        /**
        * Funkcja zwraca wektor wskaźników na ściany
        * @return Wektor wskaźników na ściany
        */
        std::vector<Wall*> getWalls() { return walls; }
        /**
        * Funkcja ustawia wektor wskaźników na ściany zgodnie z argumentem
        * @param w Wektor wskaźników na ściany
        */
        void setWalls(std::vector<Wall*>& w) { walls = w; }

        /**
        * Funkcja zwraca wektor wskaźników na drzwi 
        * @return Wektor wskaźników na drzwi
        */
        std::vector<Door*> getDoors() { return doors; }
        /**
        * Funkcja ustawia wektor wskaźników na drzwi zgodnie z argumentem
        * @param d Wektor wskaźników na drzwi
        */
        void setDoors(std::vector<Door*>& d) { doors = d; }

        /**
        * Funkcja zwraca wektor wskaźników na skrzynie
        * @return Wektor wskaźników na skrzynie
        */
        std::vector<Chest*> getChests() { return chests; }
        /**
        * Funkcja ustawia wektor wskaźników na skrzynie zgodnie z argumentem
        * @param c Wektor wskaźników na skrzynie
        */
        void setChests(std::vector<Chest*>& c) { chests = c; }

        /**
        * Funkcja zwraca pozycję ekranu (współrzędne X i Y w układzie współrzędnych)
        * @return Pozycja ekranu
        */
        Vector2f getPosition() { return position; }
        /**
        * Funkcja ustawia pozycję ekranu zgodnie z argumentem
        * @param pos Pozycja która ma zostać ustawiona jako pozycja ekranu
        */
        void setPosition(Vector2f pos) { position = pos; }

        /**
        * Funkcja zwraca informację o tym czy ekran został odwiedzony przez postać gracza
        * @return Informacja o tym czy ekran został odwiedzony przez postać gracza
        */
        bool isVisited() { return visited; }
        /**
        * Funkcja ustawia atrybut odpowiedzialny z informację o tym, czy ekran został odwiedzony przez postać gracza zgodnie z argumentem
        * @param v Informacja o tym czy ekran został odwiedzony przez postać gracza
        */
        void setVisited(bool v) { visited = v; }

        /**
        * Funkcja zwraca wskaźnik na portal o ile ten znajduje sie na ekranie
        * @return Wskaźnik na portal o ile ten znajduje się na ekranie, nullptr jeśli na ekranie nie ma portalu
        */
        Portal* getPortal() { return portal; }
        /**
        * Funkcja ustawia wskaźnik na portal zgodnie z argumentem
        * @param p Wskaźnik na portal na który ma zostać ustawiony atrybut obiektu
        */
        void setPortal(Portal* p) { portal = p; }

    private:
        /**ID ekranue*/
        int ID;
        /**ID ekranu znajdującego się po lewej stronie od ekranu, 0 jeśli po lewej stronie nie ma żadnego ekranu*/
        int leftID;
        /**ID ekranu znajdującego się po prawej stronie od ekranu, 0 jeśli po prawej stronie nie ma żadnego ekranu*/
        int rightID;
        /**ID ekranu znajdującego się powyżej ekranu, 0 jeśli powyżej nie ma żadnego ekranu*/
        int upID;
        /**ID ekranu znajdującego się poniżej ekranu, 0 jeśli poniżej nie ma żadnego ekranu*/
        int downID;
        /**Informacja o tym z iloma innymi ekranami dany ekran ma połączenie*/
        int howManyConnections;
        /**Informacja o tym czy z ekranu zostały już raz usunięte ściany blokujące przejście do innych ekranów*/
        bool removed;
        /**Informacja o tym czy ekran został odwiedzony przez postać gracza*/
        bool visited;
        /**Pozycja ekranu w układzie współrzędnych (współrzędne X i Y)*/
        Vector2f position;
        /**Wskaźnik na portal znajdujący się na ekranie. Nullptr na ekranie nie ma portalu*/
        Portal* portal;
};

#endif // SCREEN_H
