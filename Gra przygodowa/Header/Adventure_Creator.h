#ifndef ADVENTURE_CREATOR_H
#define ADVENTURE_CREATOR_H

#include "Loading_Screen.h"

/**
* Klasa reprezentuje kreator przygody służący do komputerowej generacji poziomu przygody poprzez losową generację układu ekranów, generację ścian, przeciwników oraz skrzyń
*/
class Adventure_Creator 
{
	public:
		/**
		* Konstruktor klasy ustawiający podstawowe atrybuty
		* @param loading_screen Wskaźnik do ekranu ładowania na który zostanie ustawiony wskaźnik obiektu
		*/
		Adventure_Creator(Loading_Screen *loading_screen);
		/**
		* Destruktor klasy
		*/
		~Adventure_Creator();
		/**
		* Funkcja zwraca informację o tym, jakiego typu poziom został wygenerowany
		* @return Typ poziomu (1-Las, 2-Zamek, 3-Lochy, 4-Pustynia)
		*/
		int get_floor_type() { return floor_type; }
		/**
		* Funkcja zwraca informację o numerze aktualnego poziomu. Numeracja zaczyna się od poziomu 1 a kończy na poziomie 11 (ekran podsumowania)
		* @return Numer aktualnego poziomu
		*/
		int get_level() { return level; }
		/**
		* Funkcja zwraca vector wskaźników na ekrany przygody wygenerowane jako nowy poziom
		* @param window Okno w którym wyświetlana jest gra
		* @param cache_enemies Przeciwnicy przechowywani w pamięci podręcznej wykorzystywani przy generacji poziomu
		* @return Vector wskaźników na ekrany wygenerowane jako nowy poziom
		*/
		std::vector<Screen*> next_lvl(RenderWindow& window, Enemies& cache_enemies);
		/**
		* Funkcja zwraca vector wskaźników na ekrany przygody wygenerowane jako poziom
		* @param window Okno w którym wyświetlana jest gra
		* @param cache_enemies Przeciwnicy przechowywani w pamięci podręcznej wykorzystywani przy generacji poziomu
		* @return Vector wskaźników na ekrany wygenerowane jako poziom
		*/
		std::vector<Screen*> generate_level(RenderWindow &window, Enemies& cache_enemies);
		/**
		* Funkcja służy do przywrócenia atrybutów obiektu do wartości domyślnych (np. level = 1)
		*/
		void reset_creator();

	private:
		/**Wskaźnik na ekran ładowania*/
		Loading_Screen* loading_screen;
		/**Typ poziomu*/
		int floor_type; // 1 - Valley, 2 - Castle, 3 - Dungeon, 4 - Desert
		/**Ostatni wygenerowany typ poziomu*/
		int last_floor_type;
		/**Numer poziomu*/
		int level;
		/**Wskaźnik na portal*/
		Portal* portal;
		/**
		* Funkcja generująca ekran statystyk (potrzebna przy generacji 11 poziomu - poziomu podsumowania)
		* @param window Okno w którym wyświetlana jest gra
		* @return Vector wskaźników na ekrany wygenerowane jako poziom
		*/
		std::vector<Screen*> generate_stats_screen(RenderWindow& window);
		/**
		* Funkcja dodaje do vectora wskaźników na ekrany tyle nowych ekranów, ile podano jako argument
		* @param howManyScreens Liczba nowych ekranów na które wskaźniki mają zostać dodane do vectora
		*/
		void generate_screens(std::vector<Screen*>& screens, int howManyScreens);
		/**
		* Funkcja losuje pozycję dla każdego ekranu tak długo aż wylosuje niezajętą pozycję na której ekran będzie miał chociaż jeden inny ekran w sąsiedztwie a następnie przypisuje mu tą pozycję, tak robi z każdym ekranem w vectorze
		* @param screen Vector wskaźników na ekrany przygody
		*/
		void place_screens(std::vector<Screen*>& screens);
		/**
		* Funkcja służy do generacji połączeń między ekranami leżącymi obok siebie
		* @param screens Vector wskaźników na ekrany przygody
		*/
		void generate_connections(std::vector<Screen*>& screens);
		/**
		* Funkcja sprawdza czy w sąsiedztwie danej pozycji znajduje się chociaż jeden ekran
		* @param pos Pozycja której sąsiedztwo ma zostać sprawdzone
		* @param screens Vector wskaźników na ekrany przygody
		* @return true jeśli w sąsiedztwie pozycji znajduje się chociaż jeden ekran, false jeśli nie
		*/
		bool any_neighbour(Vector2f pos,std::vector<Screen*>& screens);
		/**
		* Funkcja zlicza połaczenia danego ekranu z innymi ekranami, a następnie uzupełnia odpowiedni atrybut ekranu
		* @param s Wskaźnik na ekran którego połączenia mają zostać zliczone
		*/
		void count_connections(Screen* s);
		/**
		* Funkcja znajduje ekran znajdujący się na podanej pozycji
		* @param pos Pozycja na której ma znajdować się poszukiwany ekran
		* @param screens Vector wskaźników na ekrany przygody
		* @return Wskaźnik na ekran znajdujący się na danej pozycji, nullptr jeśli na danej pozycji nie znajduje się żaden ekran zawarty w podanym vectorze wskaźników na ekrany
		*/
		Screen* find_screen_by_position(Vector2f pos, std::vector<Screen*>& screens);
		/**
		* Funkcja znajduje ekran o podanym ID
		* @param id ID poszukiwanego ekranu
		* @param screens Vector wskaźników na ekrany przygody
		* @return Wskaźnik na ekran o podanym ID, nullptr jeśli w podanym vectorze wskaźników na ekrany nie znajduje się żaden ekran o podanym ID
		*/
		Screen* find_screen_by_ID(int id, std::vector<Screen*>& screens);
		/**
		* Funkcja ładuje tło lochów i generuje ściany lochów w ekranach w zależności od ich połączeń z innymi ekranami
		* @param screens Vector wskaźników na ekrany przygody
		*/
		void generate_walls_dungeons(std::vector<Screen*>& screens);
		/**
		* Funkcja ładuje tło zamku i generuje ściany zamku w ekranach w zależności od ich połączeń z innymi ekranami
		* @param screens Vector wskaźników na ekrany przygody
		*/
		void generate_walls_castle(std::vector<Screen*>& screens);
		/**
		* Funkcja ładuje tło lasu i generuje ściany lasu w ekranach w zależności od ich połączeń z innymi ekranami
		* @param screens Vector wskaźników na ekrany przygody
		*/
		void generate_walls_forest(std::vector<Screen*>& screens);
		/**
		* Funkcja ładuje tło pustyni i generuje ściany pustyni w ekranach w zależności od ich połączeń z innymi ekranami
		* @param screens Vector wskaźników na ekrany przygody
		*/
		void generate_walls_desert(std::vector<Screen*>& screens);
		/**
		* Funkcja generuje przeciwników charakterystycznych dla poziomu zamku w losowych ekranach
		* @param screens Vector wskaźników na ekrany przygody
		* @param chestScreenID ID ekranu w którym znajduje się skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu w którym znajduje się portal do następnego poziomu
		* @param cache_enemies Przeciwnicy trzymani w pamięci podręcznej którzy są kopiowani do ekranów
		*/
		void generate_enemies_castle(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja generuje przeciwników charakterystycznych dla poziomu lasu w losowych ekranach
		* @param screens Vector wskaźników na ekrany przygody
		* @param chestScreenID ID ekranu w którym znajduje się skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu w którym znajduje się portal do następnego poziomu
		* @param cache_enemies Przeciwnicy trzymani w pamięci podręcznej którzy są kopiowani do ekranów
		*/
		void generate_enemies_forest(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja generuje przeciwników charakterystycznych dla poziomu pustyni w losowych ekranach
		* @param screens Vector wskaźników na ekrany przygody
		* @param chestScreenID ID ekranu na którym znajduje się skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu na którym znajduje się portal do następnego poziomu
		* @param cache_enemies Przeciwnicy trzymani w pamięci podręcznej którzy są kopiowani do ekranów
		*/
		void generate_enemies_desert(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja oblicza dystans w linii prostej w układzie współrzędnych pomiędzy dwoma pozycjami
		* @param pos1 Pozycja pierwsza (x,y)
		* @param pos2 Pozycja druga (x,y)
		* @return Odległość między pozycjami
		*/
		float getDistance(Vector2f pos1, Vector2f pos2);
		/**
		* Funkcja analizuje odległości między wszystkimi parami ekranów i wyznacza dwa najbardziej oddalone od siebie
		* @param screens Vector wskaźników na ekrany przygody
		* @return Vector wskaźników na dwa najbardziej oddalone od siebie ekrany
		*/
		std::vector<Screen*> find_two_furthest_screens(std::vector<Screen*>&screens);
		/**
		* Funkcja generująca drzwi na ekranie/-nach sąsiadującym/-cych z ekranem na którym znajduje się portal do następnego poziomu
		* @param screens Vector wskaźników na ekrany przygody
		* @param ID ID pierwszego z najbardziej oddalonych od siebie ekranów
		* @return ID klucza potrzebnego do otwarcia drzwi
		*/
		int generate_door(std::vector<Screen*>& screens, int ID);
		/**
		* Funkcja generująca skrzynię z kluczem do drzwi na drugim najbardziej oddalonym ekranie oraz skrzynie z miksturami na losowych innych ekranach
		* @param screens Vector wskaźników na ekrany przygody
		* @param ScreenID ID drugiego z najbardziej oddalonych od siebie ekranów
		* @param keyID ID klucza potrzebnego do otwarcia drzwi
		*/
		void generate_chests(std::vector<Screen*>& screens, int ScreenID, int keyID);
		/**
		* Funkcja generuje przeciwników na ekranie ze skrzynią, w której jest klucz do drzwi oraz na innych ekranach. Korzysta z innych funkcji do generacji przeciwników w tej klasie
		* @param screens Vector wskaźników na ekrany przygody
		* @param chestScreenID ID ekranu na którym znajduje się skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu na którym znajduje się portal
		* @param cache_enemies Przeciwnicy trzymani w pamięci podręcznej którzy są kopiowani do ekranów
		*/
		void generate_enemies(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja generuje postać niegrywalną na losowym ekranie każdego generowanego poziomu
		* @param screens Vector wskaźników na ekrany przygody
		*/
		void generate_NPCs(std::vector<Screen*>& screens);
};


#endif // ADVENTURE_CREATOR_H