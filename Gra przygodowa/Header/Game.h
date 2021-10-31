#ifndef GAME_H
#define GAME_H

#include "Quests.h"
#include "Screens.h"
#include "Adventure_Creator.h"
#include "Map.h"
#include "Menu.h"
#include "Adventure_Stats.h"

/**
* Klasa reprezentuje ca�� gr�, dziedziczy po klasach Screens, Quests oraz Menu
*/
class Game : private Screens, private Quests, private Menu
{
    public:
        /**
        * Kosturktor klasy ustawiaj�cy podstawowe atrybuty
        */
        Game();
        /**
        * Destruktor klasy
        */
        virtual ~Game();
        /**
        * Jedyna dost�pna publicznie funkcja s�u��ca do w��czenia gry. Korzysta ona ze wszystkich innych funkcji dost�pnych w klasie
        */
        void run();
    private:
        /**
        * Funkcja przygotowuje odpowiednio posta� gracza, ekrany oraz map� w zale�no�ci od wybranego trybu gry
        * @param p Posta� gracza
        * @param window Okno w kt�rym wy�wietlana jest gra
        * @param adventure_creator Kreator przygody
        * @param map Mapa
        */
        void Prepare_game(Player &p, RenderWindow& window, Adventure_Creator& adventure_creator,Map& map);
        /**
        * Funkcja odpowiedzialna za liczenie punkt�w postaci gracza oraz dodawanie nowych przeciwnik�w w trybie areny gdy wszyscy obecni zostali pokonani
        * @param window Okno w kt�rym wy�wietlana jest gra
        */
        void ArenaMode(RenderWindow& window);
        /**
        * Funkcja wczytuje z plik�w konfiguracyjnych po jednym z ka�dego rodzaju przeciwnika, aby p�niej przy dodawaniu przeciwnik�w do ekran�w (tryb areny lub generacja poziomu w trybie przygody) korzysta� z tych w pami�ci podr�cznej
        */
        void LoadCacheEnemies();
        /**
        * Funkcja odpowiada za sprawdzenie, czy gracz wcisn�� jaki� przycisk wywo�uj�cy jakie� zdarzenie i je�li tak to je wywo�uje
        * @param window Okno w kt�rym wy�wietlana jest gra
        * @param p Posta� gracza
        * @param adventure_creator Kreator przygody
        * @param map Mapa
        */
        void GetKeyEvent(RenderWindow& window, Player& p, Adventure_Creator& adventure_creator, Map& map);
        /**
        * Funkcja odpowiadaj�ca za interaktywno�� skrzy�. Sprawdza czy posta� gracza koliduje z jak�� nieotwart� skrzyni� i je�li tak to j� otwiera i umieszcza przedmioty w ekwipunku postaci gracza
        * @param items Wszystkie przedmioty dost�pne w grze
        * @param p Posta� gracza
        */
        void MaintainChests(Items& items, Player& p);
        /**
        * Funkcja odpowiadaj�ca za interaktywno�� drzwi. Sprawdzw czy posta� gracza koliduje z jakimi� drzwiami i je�li tak to wy�wietla odpowiedni� informacj� (w zale�no�ci od tego czy posta� gracza ma klucz do tych drzwi, czy nie)
        * @param window Okno w kt�rym wy�wietlana jest gra
        * @param p Posta� gracza
        */
        void MaintainDoors(RenderWindow& window, Player& p);
        /**
        * Funkcja odpowiadaj�ca za wy�wietlanie cieni wok� postaci gracza. Funkcja jest u�ywana w przypadku poziom�w loch�w
        * @param window Okno w kt�rym wy�wietlana jest gra
        * @param p Posta� gracza
        */
        void DisplayShadows(RenderWindow& window, Player& p);
        /**
        * Funkcja odpowiedzialna za wy�wietlenie statystyk przygody postaci gracza. Wywo�ywana na ekranie zako�czenia przygody
        * @param window Okno w kt�rym wyswietlana jest gra
        */
        void DisplayStats(RenderWindow& window);
        /**
        * Funkcja usuwa wszystkie ekrany obecnego poziomu przygody i powoduje stworzenie kolejnego poziomu. Wywo�ywana w przypadku wej�cia postaci gracza w portal na nast�pny poziom
        * @param window Okno w kt�rym wy�wietlana jest gra
        * @param p Posta� gracza
        * @map Mapa
        * @param adventure_creator Kreator przygody
        */
        void NextLvl(RenderWindow& window, Player& p, Map& map, Adventure_Creator& adventure_creator);

        /**
        * Funkcja odpowiada za ca�� rozgrywk� odbywaj�c� si� w trybie samouczka. Korzysta z innych funkcji tej klasy
        * @param window Okno w kt�rym wy�wietlana jest gra
        * @param p Posta� gracza
        * @param items Wszystkie przedmioty dost�pne w grze
        * @param map Mapa
        */
        void Tutorial(RenderWindow& window, Player& p, Items& items, Map& map);
        /**
        * Funkcja odpowiada za ca�� rozgrywk� odbywaj�c� si� w trybie areny. Korzysta z innych funkcji tej klasy
        * @param window Okno w kt�rym wy�wietlana jest gra
        * @param p Posta� gracza
        */
        void Arena(RenderWindow& window, Player& p);
        /**
        * Funkcja odpowiada za ca�� rozgrywk� odbywaj�c� si� w trybie przygody. Korzysta z innych funkcji tej klasy
        * @param window Okno w kt�rym wy�wietlana jest gra
        * @param p Posta� gracza
        * @param items Wszystkie przedmioty dost�pne w grze
        * @param map Mapa
        * @param adventure_creator Kreator przygody
        */
        void Adventure(RenderWindow& window, Player& p, Items& items, Map& map, Adventure_Creator& adventure_creator);

        /**Czcionka tekstu wyniku w trybie areny*/
        Font Arena_font;
        /**Tekst wyniku w trybie areny*/
        Text Arena_text;
        /**Tablica k� s�u��cych jako cienie*/
        CircleShape shadows[5];
        /**Lista przeciwnik�w zawieraj�ca po jednym z ka�dego rodzaju, trzymana w pami�ci podr�cznej dla przyspieszenia dzia�ania gry*/
        Enemies cache_enemies;
        /**Statystyki przygody*/
        Adventure_Stats stats;
        /**Tryb gry wybrany przez gracza*/
        int gameMode; //0 - not chosen, 1 - Tutorial, 2 - Continue adventure, 3 - New adventure, 4 - Arena normal, 5 - Arena godmode
        /**Licznik klatek potrzebny do poprawnego wy�wietlania animacji i okre�lania up�ywaj�cego czasu w grze*/
        int counter; //FPS counter
        /**Licznik zab�jstw w trybie areny*/
        int kills; //Kills counter (arena)
        /**Licznik klatek potrzeny do wy�wietlenia powiadomienia o nowym zadaniu*/
        int quest_counter; //Counter of frames of display new quest
        /**Informacja o tym czy ekwipunek postaci gracza powinien by� otwarty*/
        bool is_inventory_open; 
        /**Informacja o tym czy przyj�te zadania s� wy�wietlane*/
        bool are_quests_displayed; 
        /**Informacja o tym czy muzyka jest wyciszona*/
        bool is_muted; 
        /**Informacja o tym czy tryb godmode jest w��czony*/
        bool is_godmode_on;
        /**Informacja o tym czy gra jest zatrzymana*/
        bool pause_game;
        /**Informacja o tym czy posta� gracza znajduje si� przy drzwiach*/
        bool standingByDoor;
        /**Informacja o tym czy posta� gracza pr�buje otworzy� drzwi*/
        bool tryingToOpenDoor;
        /**Informacja o tym czy ma�a mapa powinna by� wy�wietlona*/
        bool displaySmallMap;
        /**Informacja o tym czy du�a mapa powinna by� wy�wietlona*/
        bool displayBigMap;
        /**Informacja o tym czy samouczek zosta� uko�czony*/
        bool finishedTutorial;
        /**Informacja o tym czy przygoda zosta�a zacz�ta*/
        bool adventureStarted;
        /**Informacja o tym czy nale�y doda� nowe zadanie do przyj�tych zada� (wykorzystywane przy zmianie trybu gry)*/
        bool add_new_quest;
        /**Informacja o tym czy po jednym z ka�dego rodzaju przeciwnik�w zosta�o za�adowane do pami�ci podr�cznej*/
        bool cache_enemies_loaded;

};

#endif // GAME_H
