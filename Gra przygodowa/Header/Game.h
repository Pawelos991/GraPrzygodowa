#ifndef GAME_H
#define GAME_H

#include "Quests.h"
#include "Screens.h"
#include "Adventure_Creator.h"
#include "Map.h"
#include "Menu.h"
#include "Adventure_Stats.h"

/**
* Klasa reprezentuje ca³¹ grê, dziedziczy po klasach Screens, Quests oraz Menu
*/
class Game : private Screens, private Quests, private Menu
{
    public:
        /**
        * Kosturktor klasy ustawiaj¹cy podstawowe atrybuty
        */
        Game();
        /**
        * Destruktor klasy
        */
        virtual ~Game();
        /**
        * Jedyna dostêpna publicznie funkcja s³u¿¹ca do w³¹czenia gry. Korzysta ona ze wszystkich innych funkcji dostêpnych w klasie
        */
        void run();
    private:
        /**
        * Funkcja przygotowuje odpowiednio postaæ gracza, ekrany oraz mapê w zale¿noœci od wybranego trybu gry
        * @param p Postaæ gracza
        * @param window Okno w którym wyœwietlana jest gra
        * @param adventure_creator Kreator przygody
        * @param map Mapa
        */
        void Prepare_game(Player &p, RenderWindow& window, Adventure_Creator& adventure_creator,Map& map);
        /**
        * Funkcja odpowiedzialna za liczenie punktów postaci gracza oraz dodawanie nowych przeciwników w trybie areny gdy wszyscy obecni zostali pokonani
        * @param window Okno w którym wyœwietlana jest gra
        */
        void ArenaMode(RenderWindow& window);
        /**
        * Funkcja wczytuje z plików konfiguracyjnych po jednym z ka¿dego rodzaju przeciwnika, aby póŸniej przy dodawaniu przeciwników do ekranów (tryb areny lub generacja poziomu w trybie przygody) korzystaæ z tych w pamiêci podrêcznej
        */
        void LoadCacheEnemies();
        /**
        * Funkcja odpowiada za sprawdzenie, czy gracz wcisn¹³ jakiœ przycisk wywo³uj¹cy jakieœ zdarzenie i jeœli tak to je wywo³uje
        * @param window Okno w którym wyœwietlana jest gra
        * @param p Postaæ gracza
        * @param adventure_creator Kreator przygody
        * @param map Mapa
        */
        void GetKeyEvent(RenderWindow& window, Player& p, Adventure_Creator& adventure_creator, Map& map);
        /**
        * Funkcja odpowiadaj¹ca za interaktywnoœæ skrzyñ. Sprawdza czy postaæ gracza koliduje z jak¹œ nieotwart¹ skrzyni¹ i jeœli tak to j¹ otwiera i umieszcza przedmioty w ekwipunku postaci gracza
        * @param items Wszystkie przedmioty dostêpne w grze
        * @param p Postaæ gracza
        */
        void MaintainChests(Items& items, Player& p);
        /**
        * Funkcja odpowiadaj¹ca za interaktywnoœæ drzwi. Sprawdzw czy postaæ gracza koliduje z jakimiœ drzwiami i jeœli tak to wyœwietla odpowiedni¹ informacjê (w zale¿noœci od tego czy postaæ gracza ma klucz do tych drzwi, czy nie)
        * @param window Okno w którym wyœwietlana jest gra
        * @param p Postaæ gracza
        */
        void MaintainDoors(RenderWindow& window, Player& p);
        /**
        * Funkcja odpowiadaj¹ca za wyœwietlanie cieni wokó³ postaci gracza. Funkcja jest u¿ywana w przypadku poziomów lochów
        * @param window Okno w którym wyœwietlana jest gra
        * @param p Postaæ gracza
        */
        void DisplayShadows(RenderWindow& window, Player& p);
        /**
        * Funkcja odpowiedzialna za wyœwietlenie statystyk przygody postaci gracza. Wywo³ywana na ekranie zakoñczenia przygody
        * @param window Okno w którym wyswietlana jest gra
        */
        void DisplayStats(RenderWindow& window);
        /**
        * Funkcja usuwa wszystkie ekrany obecnego poziomu przygody i powoduje stworzenie kolejnego poziomu. Wywo³ywana w przypadku wejœcia postaci gracza w portal na nastêpny poziom
        * @param window Okno w którym wyœwietlana jest gra
        * @param p Postaæ gracza
        * @map Mapa
        * @param adventure_creator Kreator przygody
        */
        void NextLvl(RenderWindow& window, Player& p, Map& map, Adventure_Creator& adventure_creator);

        /**
        * Funkcja odpowiada za ca³¹ rozgrywkê odbywaj¹c¹ siê w trybie samouczka. Korzysta z innych funkcji tej klasy
        * @param window Okno w którym wyœwietlana jest gra
        * @param p Postaæ gracza
        * @param items Wszystkie przedmioty dostêpne w grze
        * @param map Mapa
        */
        void Tutorial(RenderWindow& window, Player& p, Items& items, Map& map);
        /**
        * Funkcja odpowiada za ca³¹ rozgrywkê odbywaj¹c¹ siê w trybie areny. Korzysta z innych funkcji tej klasy
        * @param window Okno w którym wyœwietlana jest gra
        * @param p Postaæ gracza
        */
        void Arena(RenderWindow& window, Player& p);
        /**
        * Funkcja odpowiada za ca³¹ rozgrywkê odbywaj¹c¹ siê w trybie przygody. Korzysta z innych funkcji tej klasy
        * @param window Okno w którym wyœwietlana jest gra
        * @param p Postaæ gracza
        * @param items Wszystkie przedmioty dostêpne w grze
        * @param map Mapa
        * @param adventure_creator Kreator przygody
        */
        void Adventure(RenderWindow& window, Player& p, Items& items, Map& map, Adventure_Creator& adventure_creator);

        /**Czcionka tekstu wyniku w trybie areny*/
        Font Arena_font;
        /**Tekst wyniku w trybie areny*/
        Text Arena_text;
        /**Tablica kó³ s³u¿¹cych jako cienie*/
        CircleShape shadows[5];
        /**Lista przeciwników zawieraj¹ca po jednym z ka¿dego rodzaju, trzymana w pamiêci podrêcznej dla przyspieszenia dzia³ania gry*/
        Enemies cache_enemies;
        /**Statystyki przygody*/
        Adventure_Stats stats;
        /**Tryb gry wybrany przez gracza*/
        int gameMode; //0 - not chosen, 1 - Tutorial, 2 - Continue adventure, 3 - New adventure, 4 - Arena normal, 5 - Arena godmode
        /**Licznik klatek potrzebny do poprawnego wyœwietlania animacji i okreœlania up³ywaj¹cego czasu w grze*/
        int counter; //FPS counter
        /**Licznik zabójstw w trybie areny*/
        int kills; //Kills counter (arena)
        /**Licznik klatek potrzeny do wyœwietlenia powiadomienia o nowym zadaniu*/
        int quest_counter; //Counter of frames of display new quest
        /**Informacja o tym czy ekwipunek postaci gracza powinien byæ otwarty*/
        bool is_inventory_open; 
        /**Informacja o tym czy przyjête zadania s¹ wyœwietlane*/
        bool are_quests_displayed; 
        /**Informacja o tym czy muzyka jest wyciszona*/
        bool is_muted; 
        /**Informacja o tym czy tryb godmode jest w³¹czony*/
        bool is_godmode_on;
        /**Informacja o tym czy gra jest zatrzymana*/
        bool pause_game;
        /**Informacja o tym czy postaæ gracza znajduje siê przy drzwiach*/
        bool standingByDoor;
        /**Informacja o tym czy postaæ gracza próbuje otworzyæ drzwi*/
        bool tryingToOpenDoor;
        /**Informacja o tym czy ma³a mapa powinna byæ wyœwietlona*/
        bool displaySmallMap;
        /**Informacja o tym czy du¿a mapa powinna byæ wyœwietlona*/
        bool displayBigMap;
        /**Informacja o tym czy samouczek zosta³ ukoñczony*/
        bool finishedTutorial;
        /**Informacja o tym czy przygoda zosta³a zaczêta*/
        bool adventureStarted;
        /**Informacja o tym czy nale¿y dodaæ nowe zadanie do przyjêtych zadañ (wykorzystywane przy zmianie trybu gry)*/
        bool add_new_quest;
        /**Informacja o tym czy po jednym z ka¿dego rodzaju przeciwników zosta³o za³adowane do pamiêci podrêcznej*/
        bool cache_enemies_loaded;

};

#endif // GAME_H
