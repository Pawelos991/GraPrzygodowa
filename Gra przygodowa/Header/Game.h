#ifndef GAME_H
#define GAME_H

#include "Quests.h"
#include "Screens.h"
#include "Adventure_Creator.h"
#include "Map.h"
#include "Menu.h"
#include "Adventure_Stats.h"

/**
* Klasa reprezentuje całą grę, dziedziczy po klasach Screens, Quests oraz Menu
*/
class Game : private Screens, private Quests, private Menu
{
    public:
        /**
        * Kosturktor klasy ustawiający podstawowe atrybuty
        */
        Game();
        /**
        * Destruktor klasy
        */
        virtual ~Game();
        /**
        * Jedyna dostępna publicznie funkcja służąca do włączenia gry. Korzysta ona ze wszystkich innych funkcji dostępnych w klasie
        */
        void run();
    private:
        /**
        * Funkcja przygotowuje odpowiednio postać gracza, ekrany oraz mapę w zależności od wybranego trybu gry
        * @param p Postać gracza
        * @param window Okno w którym wyświetlana jest gra
        * @param adventure_creator Kreator przygody
        * @param map Mapa
        */
        void Prepare_game(Player &p, RenderWindow& window, Adventure_Creator& adventure_creator,Map& map);
        /**
        * Funkcja odpowiedzialna za liczenie punktów postaci gracza oraz dodawanie nowych przeciwników w trybie areny gdy wszyscy obecni zostali pokonani
        * @param window Okno w którym wyświetlana jest gra
        */
        void ArenaMode(RenderWindow& window);
        /**
        * Funkcja wczytuje z plików konfiguracyjnych po jednym z każdego rodzaju przeciwnika, aby później przy dodawaniu przeciwników do ekranów (tryb areny lub generacja poziomu w trybie przygody) korzystać z tych w pamięci podręcznej
        */
        void LoadCacheEnemies();
        /**
        * Funkcja odpowiada za sprawdzenie, czy gracz wcisnął jakiś przycisk wywołujący jakieś zdarzenie i jeśli tak to je wywołuje
        * @param window Okno w którym wyświetlana jest gra
        * @param p Postać gracza
        * @param adventure_creator Kreator przygody
        * @param map Mapa
        */
        void GetKeyEvent(RenderWindow& window, Player& p, Adventure_Creator& adventure_creator, Map& map);
        /**
        * Funkcja odpowiadająca za interaktywność skrzyń. Sprawdza czy postać gracza koliduje z jakąś nieotwartą skrzynią i jeśli tak to ją otwiera i umieszcza przedmioty w ekwipunku postaci gracza
        * @param items Wszystkie przedmioty dostępne w grze
        * @param p Postać gracza
        */
        void MaintainChests(Items& items, Player& p);
        /**
        * Funkcja odpowiadająca za interaktywność drzwi. Sprawdzw czy postać gracza koliduje z jakimiś drzwiami i jeśli tak to wyświetla odpowiednią informację (w zależności od tego czy postać gracza ma klucz do tych drzwi, czy nie)
        * @param window Okno w którym wyświetlana jest gra
        * @param p Postać gracza
        */
        void MaintainDoors(RenderWindow& window, Player& p);
        /**
        * Funkcja odpowiadająca za wyświetlanie cieni wokół postaci gracza. Funkcja jest używana w przypadku poziomów lochów
        * @param window Okno w którym wyświetlana jest gra
        * @param p Postać gracza
        */
        void DisplayShadows(RenderWindow& window, Player& p);
        /**
        * Funkcja odpowiedzialna za wyświetlenie statystyk przygody postaci gracza. Wywoływana na ekranie zakończenia przygody
        * @param window Okno w którym wyswietlana jest gra
        */
        void DisplayStats(RenderWindow& window);
        /**
        * Funkcja usuwa wszystkie ekrany obecnego poziomu przygody i powoduje stworzenie kolejnego poziomu. Wywoływana w przypadku wejścia postaci gracza w portal na następny poziom
        * @param window Okno w którym wyświetlana jest gra
        * @param p Postać gracza
        * @map Mapa
        * @param adventure_creator Kreator przygody
        */
        void NextLvl(RenderWindow& window, Player& p, Map& map, Adventure_Creator& adventure_creator);

        /**
        * Funkcja odpowiada za całą rozgrywkę odbywającą się w trybie samouczka. Korzysta z innych funkcji tej klasy
        * @param window Okno w którym wyświetlana jest gra
        * @param p Postać gracza
        * @param items Wszystkie przedmioty dostępne w grze
        * @param map Mapa
        */
        void Tutorial(RenderWindow& window, Player& p, Items& items, Map& map);
        /**
        * Funkcja odpowiada za całą rozgrywkę odbywającą się w trybie areny. Korzysta z innych funkcji tej klasy
        * @param window Okno w którym wyświetlana jest gra
        * @param p Postać gracza
        */
        void Arena(RenderWindow& window, Player& p);
        /**
        * Funkcja odpowiada za całą rozgrywkę odbywającą się w trybie przygody. Korzysta z innych funkcji tej klasy
        * @param window Okno w którym wyświetlana jest gra
        * @param p Postać gracza
        * @param items Wszystkie przedmioty dostępne w grze
        * @param map Mapa
        * @param adventure_creator Kreator przygody
        */
        void Adventure(RenderWindow& window, Player& p, Items& items, Map& map, Adventure_Creator& adventure_creator);

        /**Czcionka tekstu wyniku w trybie areny*/
        Font Arena_font;
        /**Tekst wyniku w trybie areny*/
        Text Arena_text;
        /**Tablica kół służących jako cienie*/
        CircleShape shadows[5];
        /**Lista przeciwników zawierająca po jednym z każdego rodzaju, trzymana w pamięci podręcznej dla przyspieszenia działania gry*/
        Enemies cache_enemies;
        /**Statystyki przygody*/
        Adventure_Stats stats;
        /**Tryb gry wybrany przez gracza*/
        int gameMode; //0 - not chosen, 1 - Tutorial, 2 - Continue adventure, 3 - New adventure, 4 - Arena normal, 5 - Arena godmode
        /**Licznik klatek potrzebny do poprawnego wyświetlania animacji i określania upływającego czasu w grze*/
        int counter; //FPS counter
        /**Licznik zabójstw w trybie areny*/
        int kills; //Kills counter (arena)
        /**Licznik klatek potrzeny do wyświetlenia powiadomienia o nowym zadaniu*/
        int quest_counter; //Counter of frames of display new quest
        /**Informacja o tym czy ekwipunek postaci gracza powinien być otwarty*/
        bool is_inventory_open; 
        /**Informacja o tym czy przyjęte zadania są wyświetlane*/
        bool are_quests_displayed; 
        /**Informacja o tym czy muzyka jest wyciszona*/
        bool is_muted; 
        /**Informacja o tym czy tryb godmode jest włączony*/
        bool is_godmode_on;
        /**Informacja o tym czy gra jest zatrzymana*/
        bool pause_game;
        /**Informacja o tym czy postać gracza znajduje się przy drzwiach*/
        bool standingByDoor;
        /**Informacja o tym czy postać gracza próbuje otworzyć drzwi*/
        bool tryingToOpenDoor;
        /**Informacja o tym czy mała mapa powinna być wyświetlona*/
        bool displaySmallMap;
        /**Informacja o tym czy duża mapa powinna być wyświetlona*/
        bool displayBigMap;
        /**Informacja o tym czy samouczek został ukończony*/
        bool finishedTutorial;
        /**Informacja o tym czy przygoda została zaczęta*/
        bool adventureStarted;
        /**Informacja o tym czy należy dodać nowe zadanie do przyjętych zadań (wykorzystywane przy zmianie trybu gry)*/
        bool add_new_quest;
        /**Informacja o tym czy po jednym z każdego rodzaju przeciwników zostało załadowane do pamięci podręcznej*/
        bool cache_enemies_loaded;

};

#endif // GAME_H
