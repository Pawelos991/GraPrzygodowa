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
        * Konstruktor klasy ³aduj¹cy informacje z plików
        * @param info_file Œcie¿ka do pliku z informacjami na temat ekranu
        */
        Screen(std::string info_file);
        /**
        * Konstruktor klasy uzupe³niaj¹cy podstawowe informacje domyœlnymi wartoœciami i ustawiaj¹cy ID ekranu zgodnie z argumentem
        * @param id ID ekranu które ma zostaæ ustawione w odpowiednim atrybucie
        */
        Screen( int id );
        /**
        * Destruktor klasy
        */
        virtual ~Screen();
        
        /**
        * Funkcja wyœwietlaj¹ca ekran (wraz ze wszystkimi jego elementami) w oknie
        * @param window Okno w którym ma byæ wyœwietlony ekran
        */
        void displayScreen(RenderWindow &window);

        /**
        * Funkcja sprawdza czy postaæ gracza koliduje z któr¹œ ze skrzyñ na ekranie
        * @param players_hitbox Hitbox postaci gracza
        * @return WskaŸnik na skrzyniê z któr¹ koliduje postaæ gracza jeœli z jak¹œ koliduje, nullptr jeœli postaæ gracza nie koliduje z ¿adn¹ skrzyni¹ na ekranie
        */
        Chest* check_chests(RectangleShape players_hitbox);
        /**
        * Funkcja sprawdza czy postaæ gracza koliduje z jakimiœ drzwiami na ekranie
        * @param players_hitbox Hitbox postaci gracza
        * @return WskaŸnik na drzwi z którymi koliduje postaæ gracza jeœli z jakimiœ koliduje, nullptr jeœli postaæ gracza nie koliduje z ¿adnymi drzwiami na ekranie
        */
        Door* check_doors(RectangleShape players_hitbox);
        /**
        * Funkcja sprawdza czy postaæ gracza koliduje z portalem na ekranie
        * @param players_hitbox Hitbox postaci gracza
        * @return true jeœli postaæ gracza koliduje z portalem, nullptr jeœli postaæ gracza nie koliduje z portalem lub na ekranie nie ma portalu
        */
        bool check_portal(RectangleShape players_hitbox);
        /**
        * Funkcja zwraca informacjê o tym czy ekran ma portal
        * @return true jeœli ekran ma portal, false jeœli ekran nie ma portalu
        */
        bool has_portal() { return !(portal == nullptr); }
        /**Pociski wystrzelone przez gracza*/
        Missiles player_missiles;
        /**Pociski wystrzelone przez przeciwników*/
        Missiles enemies_missiles;
        /**
        * Funkcja zwalaniaj¹ca pamiêæ zaalokowan¹ przez ekran i jego czêœci sk³adowe
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
        * @param id ID na które ma zostaæ ustawiony atrybut ID ekranu
        */
        void setID(int id) { ID = id; }

        /**
        * Funkcja zwracaj¹ca informacjê o ID ekranu znajduj¹cego siê po prawej stronie od ekranu
        * @return ID ekranu znajduj¹cego siê po prawej stronie jeœli znajduje siê tam jakiœ ekran, 0 jeœli nie ma tam ¿adnego ekranu
        */
        int goRight() { return rightID; }
        /**
        * Funkcja ustawiaj¹ca ID ekranu znajduj¹cego siê po prawej stronie od ekranu zgodnie z argumentem
        * @param r ID ekranu znajduj¹cego siê po prawej stronie od ekranu
        */
        void setRight(int r) { rightID = r; }

        /**
        * Funkcja zwracaj¹ca informacjê o ID ekranu znajduj¹cego siê po lewej stronie od ekranu
        * @return ID ekranu znajduj¹cego siê po lewej stronie jeœli znajduje siê tam jakiœ ekran, 0 jeœli nie ma tam ¿adnego ekranu
        */
        int goLeft() { return leftID; }
        /**
        * Funkcja ustawiaj¹ca ID ekranu znajduj¹cego siê po lewej stronie od ekranu zgodnie z argumentem
        * @param r ID ekranu znajduj¹cego siê po lewej stronie od ekranu
        */
        void setLeft(int l) { leftID = l; }

        /**
        * Funkcja zwracaj¹ca informacjê o ID ekranu znajduj¹cego siê powy¿ej ekranu
        * @return ID ekranu znajduj¹cego siê powy¿ej jeœli znajduje siê tam jakiœ ekran, 0 jeœli nie ma tam ¿adnego ekranu
        */
        int goUp() { return upID; }
        /**
        * Funkcja ustawiaj¹ca ID ekranu znajduj¹cego siê powy¿ej ekranu zgodnie z argumentem
        * @param r ID ekranu znajduj¹cego siê powy¿ej ekranu
        */
        void setUp(int u) { upID = u; }

        /**
        * Funkcja zwracaj¹ca informacjê o ID ekranu znajduj¹cego siê poni¿ej ekranu
        * @return ID ekranu znajduj¹cego siê poni¿ej jeœli znajduje siê tam jakiœ ekran, 0 jeœli nie ma tam ¿adnego ekranu
        */
        int goDown() { return downID; }
        /**
        * Funkcja ustawiaj¹ca ID ekranu znajduj¹cego siê poni¿ej ekranu zgodnie z argumentem
        * @param r ID ekranu znajduj¹cego siê poni¿ej ekranu
        */
        void setDown(int d) { downID = d; }

        /**
        * Funkcja zwracaj¹ca informacjê o iloœci po³¹czeñ ekranu z innymi ekranami
        * @return Iloœæ po³¹czeñ z innymi ekranami (np. jeœli z danego ekranu da siê przejœæ do 2 innych ekranów to funkcja zwróci wartoœæ 2)
        */
        int getNumberOfConnections() { return howManyConnections; }
        /**
        * Funkcja ustawia wartoœæ atrybutu oznaczaj¹cego iloœæ po³¹czeñ ekranu z innymi ekranami zgodnie z argumentem
        * @param n Liczba po³¹czeñ która ma zostaæ ustawiona jako atrybut ekranu
        */
        void setNumberOfConnections(int n) { howManyConnections = n; }

        /**
        * Funkcja zwracaj¹ca informacjê o tym czy z ekranu zosta³y ju¿ raz usuniête œciany blokuj¹ce przejœcie do innych ekranów
        * @return Informacja o tym czy z ekranu zosta³y ju¿ raz usuniête œciany blokuj¹ce przejœcie do innych ekranów
        */
        bool is_removed() { return removed; }
        /**
        * Funkcja ustawiaj¹ca informacjê o tym czy z ekranu zosta³y ju¿ raz usuniête œciany blokuj¹ce przejœcie do innych ekranów zgodnie z argumentem
        * @param rm Informacja o tym czy z ekranu zosta³y ju¿ raz usuniête œciany blokuj¹ce przejœcie do innych ekranów zgodnie z któr¹ ma zostaæ ustawiony atrybut obiektu
        */
        void set_removed(bool rm) { removed = rm; }

        /**
        * Funkcja zwracaj¹ca sprite t³a ekranu
        * @return Sprite t³a ekranu
        */
        Sprite getBck() { return Bck; }
        /**
        * Funkcja ustawiaj¹ca t³o ekranu zgodnie z obrazkiem do którego podano œcie¿kê jako argument
        * @param pathToBck Œcie¿ka do tekstury t³a ekranu
        */
        void setBck(std::string pathToBck) { pic.loadFromFile(pathToBck); Bck.setTexture(pic); }

        /**
        * Funkcja zwracaj¹ca wektor wskaŸników na obiekty niekoliduj¹ce z postaci¹ gracza z ekranu
        * @return Wektor wskaŸników na obiekty niekoliduj¹ce z postaci¹ gracza z ekranu
        */
        std::vector<NC_Object*> get_NC_Objects() { return NC_Objects; }
        /**
        * Funkcja ustawia wektor wskaŸników na obiekty niekoliduj¹ce z postaci¹ gracza zgodnie z argumentem
        * @param nc Wektor wskaŸników na obiekty niekoliduj¹ce z postaci¹ gracza
        */
        void set_NC_Objects(std::vector<NC_Object*>& nc) { NC_Objects = nc; }

        /**
        * Funkcja zwraca wektor wskaŸników na œciany
        * @return Wektor wskaŸników na œciany
        */
        std::vector<Wall*> getWalls() { return walls; }
        /**
        * Funkcja ustawia wektor wskaŸników na œciany zgodnie z argumentem
        * @param w Wektor wskaŸników na œciany
        */
        void setWalls(std::vector<Wall*>& w) { walls = w; }

        /**
        * Funkcja zwraca wektor wskaŸników na drzwi 
        * @return Wektor wskaŸników na drzwi
        */
        std::vector<Door*> getDoors() { return doors; }
        /**
        * Funkcja ustawia wektor wskaŸników na drzwi zgodnie z argumentem
        * @param d Wektor wskaŸników na drzwi
        */
        void setDoors(std::vector<Door*>& d) { doors = d; }

        /**
        * Funkcja zwraca wektor wskaŸników na skrzynie
        * @return Wektor wskaŸników na skrzynie
        */
        std::vector<Chest*> getChests() { return chests; }
        /**
        * Funkcja ustawia wektor wskaŸników na skrzynie zgodnie z argumentem
        * @param c Wektor wskaŸników na skrzynie
        */
        void setChests(std::vector<Chest*>& c) { chests = c; }

        /**
        * Funkcja zwraca pozycjê ekranu (wspó³rzêdne X i Y w uk³adzie wspó³rzêdnych)
        * @return Pozycja ekranu
        */
        Vector2f getPosition() { return position; }
        /**
        * Funkcja ustawia pozycjê ekranu zgodnie z argumentem
        * @param pos Pozycja która ma zostaæ ustawiona jako pozycja ekranu
        */
        void setPosition(Vector2f pos) { position = pos; }

        /**
        * Funkcja zwraca informacjê o tym czy ekran zosta³ odwiedzony przez postaæ gracza
        * @return Informacja o tym czy ekran zosta³ odwiedzony przez postaæ gracza
        */
        bool isVisited() { return visited; }
        /**
        * Funkcja ustawia atrybut odpowiedzialny z informacjê o tym, czy ekran zosta³ odwiedzony przez postaæ gracza zgodnie z argumentem
        * @param v Informacja o tym czy ekran zosta³ odwiedzony przez postaæ gracza
        */
        void setVisited(bool v) { visited = v; }

        /**
        * Funkcja zwraca wskaŸnik na portal o ile ten znajduje sie na ekranie
        * @return WskaŸnik na portal o ile ten znajduje siê na ekranie, nullptr jeœli na ekranie nie ma portalu
        */
        Portal* getPortal() { return portal; }
        /**
        * Funkcja ustawia wskaŸnik na portal zgodnie z argumentem
        * @param p WskaŸnik na portal na który ma zostaæ ustawiony atrybut obiektu
        */
        void setPortal(Portal* p) { portal = p; }

    private:
        /**ID ekranue*/
        int ID;
        /**ID ekranu znajduj¹cego siê po lewej stronie od ekranu, 0 jeœli po lewej stronie nie ma ¿adnego ekranu*/
        int leftID;
        /**ID ekranu znajduj¹cego siê po prawej stronie od ekranu, 0 jeœli po prawej stronie nie ma ¿adnego ekranu*/
        int rightID;
        /**ID ekranu znajduj¹cego siê powy¿ej ekranu, 0 jeœli powy¿ej nie ma ¿adnego ekranu*/
        int upID;
        /**ID ekranu znajduj¹cego siê poni¿ej ekranu, 0 jeœli poni¿ej nie ma ¿adnego ekranu*/
        int downID;
        /**Informacja o tym z iloma innymi ekranami dany ekran ma po³¹czenie*/
        int howManyConnections;
        /**Informacja o tym czy z ekranu zosta³y ju¿ raz usuniête œciany blokuj¹ce przejœcie do innych ekranów*/
        bool removed;
        /**Informacja o tym czy ekran zosta³ odwiedzony przez postaæ gracza*/
        bool visited;
        /**Pozycja ekranu w uk³adzie wspó³rzêdnych (wspó³rzêdne X i Y)*/
        Vector2f position;
        /**WskaŸnik na portal znajduj¹cy siê na ekranie. Nullptr na ekranie nie ma portalu*/
        Portal* portal;
};

#endif // SCREEN_H
