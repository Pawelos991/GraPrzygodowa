#ifndef ADVENTURE_CREATOR_H
#define ADVENTURE_CREATOR_H

#include "Loading_Screen.h"

/**
* Klasa reprezentuje kreator przygody s³u¿¹cy do komputerowej generacji poziomu przygody poprzez losow¹ generacjê uk³adu ekranów, generacjê œcian, przeciwników oraz skrzyñ
*/
class Adventure_Creator 
{
	public:
		/**
		* Konstruktor klasy ustawiaj¹cy podstawowe atrybuty
		* @param loading_screen WskaŸnik do ekranu ³adowania na który zostanie ustawiony wskaŸnik obiektu
		*/
		Adventure_Creator(Loading_Screen *loading_screen);
		/**
		* Destruktor klasy
		*/
		~Adventure_Creator();
		/**
		* Funkcja zwraca informacjê o tym, jakiego typu poziom zosta³ wygenerowany
		* @return Typ poziomu (1-Las, 2-Zamek, 3-Lochy, 4-Pustynia)
		*/
		int get_floor_type() { return floor_type; }
		/**
		* Funkcja zwraca informacjê o numerze aktualnego poziomu. Numeracja zaczyna siê od poziomu 1 a koñczy na poziomie 11 (ekran podsumowania)
		* @return Numer aktualnego poziomu
		*/
		int get_level() { return level; }
		/**
		* Funkcja zwraca vector wskaŸników na ekrany przygody wygenerowane jako nowy poziom
		* @param window Okno w którym wyœwietlana jest gra
		* @param cache_enemies Przeciwnicy przechowywani w pamiêci podrêcznej wykorzystywani przy generacji poziomu
		* @return Vector wskaŸników na ekrany wygenerowane jako nowy poziom
		*/
		std::vector<Screen*> next_lvl(RenderWindow& window, Enemies& cache_enemies);
		/**
		* Funkcja zwraca vector wskaŸników na ekrany przygody wygenerowane jako poziom
		* @param window Okno w którym wyœwietlana jest gra
		* @param cache_enemies Przeciwnicy przechowywani w pamiêci podrêcznej wykorzystywani przy generacji poziomu
		* @return Vector wskaŸników na ekrany wygenerowane jako poziom
		*/
		std::vector<Screen*> generate_level(RenderWindow &window, Enemies& cache_enemies);
		/**
		* Funkcja s³u¿y do przywrócenia atrybutów obiektu do wartoœci domyœlnych (np. level = 1)
		*/
		void reset_creator();

	private:
		/**WskaŸnik na ekran ³adowania*/
		Loading_Screen* loading_screen;
		/**Typ poziomu*/
		int floor_type; // 1 - Valley, 2 - Castle, 3 - Dungeon, 4 - Desert
		/**Ostatni wygenerowany typ poziomu*/
		int last_floor_type;
		/**Numer poziomu*/
		int level;
		/**WskaŸnik na portal*/
		Portal* portal;
		/**
		* Funkcja generuj¹ca ekran statystyk (potrzebna przy generacji 11 poziomu - poziomu podsumowania)
		* @param window Okno w którym wyœwietlana jest gra
		* @return Vector wskaŸników na ekrany wygenerowane jako poziom
		*/
		std::vector<Screen*> generate_stats_screen(RenderWindow& window);
		/**
		* Funkcja dodaje do vectora wskaŸników na ekrany tyle nowych ekranów, ile podano jako argument
		* @param howManyScreens Liczba nowych ekranów na które wskaŸniki maj¹ zostaæ dodane do vectora
		*/
		void generate_screens(std::vector<Screen*>& screens, int howManyScreens);
		/**
		* Funkcja losuje pozycjê dla ka¿dego ekranu tak d³ugo a¿ wylosuje niezajêt¹ pozycjê na której ekran bêdzie mia³ chocia¿ jeden inny ekran w s¹siedztwie a nastêpnie przypisuje mu t¹ pozycjê, tak robi z ka¿dym ekranem w vectorze
		* @param screen Vector wskaŸników na ekrany przygody
		*/
		void place_screens(std::vector<Screen*>& screens);
		/**
		* Funkcja s³u¿y do generacji po³¹czeñ miêdzy ekranami le¿¹cymi obok siebie
		* @param screens Vector wskaŸników na ekrany przygody
		*/
		void generate_connections(std::vector<Screen*>& screens);
		/**
		* Funkcja sprawdza czy w s¹siedztwie danej pozycji znajduje siê chocia¿ jeden ekran
		* @param pos Pozycja której s¹siedztwo ma zostaæ sprawdzone
		* @param screens Vector wskaŸników na ekrany przygody
		* @return true jeœli w s¹siedztwie pozycji znajduje siê chocia¿ jeden ekran, false jeœli nie
		*/
		bool any_neighbour(Vector2f pos,std::vector<Screen*>& screens);
		/**
		* Funkcja zlicza po³aczenia danego ekranu z innymi ekranami, a nastêpnie uzupe³nia odpowiedni atrybut ekranu
		* @param s WskaŸnik na ekran którego po³¹czenia maj¹ zostaæ zliczone
		*/
		void count_connections(Screen* s);
		/**
		* Funkcja znajduje ekran znajduj¹cy siê na podanej pozycji
		* @param pos Pozycja na której ma znajdowaæ siê poszukiwany ekran
		* @param screens Vector wskaŸników na ekrany przygody
		* @return WskaŸnik na ekran znajduj¹cy siê na danej pozycji, nullptr jeœli na danej pozycji nie znajduje siê ¿aden ekran zawarty w podanym vectorze wskaŸników na ekrany
		*/
		Screen* find_screen_by_position(Vector2f pos, std::vector<Screen*>& screens);
		/**
		* Funkcja znajduje ekran o podanym ID
		* @param id ID poszukiwanego ekranu
		* @param screens Vector wskaŸników na ekrany przygody
		* @return WskaŸnik na ekran o podanym ID, nullptr jeœli w podanym vectorze wskaŸników na ekrany nie znajduje siê ¿aden ekran o podanym ID
		*/
		Screen* find_screen_by_ID(int id, std::vector<Screen*>& screens);
		/**
		* Funkcja ³aduje t³o lochów i generuje œciany lochów w ekranach w zale¿noœci od ich po³¹czeñ z innymi ekranami
		* @param screens Vector wskaŸników na ekrany przygody
		*/
		void generate_walls_dungeons(std::vector<Screen*>& screens);
		/**
		* Funkcja ³aduje t³o zamku i generuje œciany zamku w ekranach w zale¿noœci od ich po³¹czeñ z innymi ekranami
		* @param screens Vector wskaŸników na ekrany przygody
		*/
		void generate_walls_castle(std::vector<Screen*>& screens);
		/**
		* Funkcja ³aduje t³o lasu i generuje œciany lasu w ekranach w zale¿noœci od ich po³¹czeñ z innymi ekranami
		* @param screens Vector wskaŸników na ekrany przygody
		*/
		void generate_walls_forest(std::vector<Screen*>& screens);
		/**
		* Funkcja ³aduje t³o pustyni i generuje œciany pustyni w ekranach w zale¿noœci od ich po³¹czeñ z innymi ekranami
		* @param screens Vector wskaŸników na ekrany przygody
		*/
		void generate_walls_desert(std::vector<Screen*>& screens);
		/**
		* Funkcja generuje przeciwników charakterystycznych dla poziomu zamku w losowych ekranach
		* @param screens Vector wskaŸników na ekrany przygody
		* @param chestScreenID ID ekranu w którym znajduje siê skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu w którym znajduje siê portal do nastêpnego poziomu
		* @param cache_enemies Przeciwnicy trzymani w pamiêci podrêcznej którzy s¹ kopiowani do ekranów
		*/
		void generate_enemies_castle(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja generuje przeciwników charakterystycznych dla poziomu lasu w losowych ekranach
		* @param screens Vector wskaŸników na ekrany przygody
		* @param chestScreenID ID ekranu w którym znajduje siê skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu w którym znajduje siê portal do nastêpnego poziomu
		* @param cache_enemies Przeciwnicy trzymani w pamiêci podrêcznej którzy s¹ kopiowani do ekranów
		*/
		void generate_enemies_forest(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja generuje przeciwników charakterystycznych dla poziomu pustyni w losowych ekranach
		* @param screens Vector wskaŸników na ekrany przygody
		* @param chestScreenID ID ekranu na którym znajduje siê skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu na którym znajduje siê portal do nastêpnego poziomu
		* @param cache_enemies Przeciwnicy trzymani w pamiêci podrêcznej którzy s¹ kopiowani do ekranów
		*/
		void generate_enemies_desert(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja oblicza dystans w linii prostej w uk³adzie wspó³rzêdnych pomiêdzy dwoma pozycjami
		* @param pos1 Pozycja pierwsza (x,y)
		* @param pos2 Pozycja druga (x,y)
		* @return Odleg³oœæ miêdzy pozycjami
		*/
		float getDistance(Vector2f pos1, Vector2f pos2);
		/**
		* Funkcja analizuje odleg³oœci miêdzy wszystkimi parami ekranów i wyznacza dwa najbardziej oddalone od siebie
		* @param screens Vector wskaŸników na ekrany przygody
		* @return Vector wskaŸników na dwa najbardziej oddalone od siebie ekrany
		*/
		std::vector<Screen*> find_two_furthest_screens(std::vector<Screen*>&screens);
		/**
		* Funkcja generuj¹ca drzwi na ekranie/-nach s¹siaduj¹cym/-cych z ekranem na którym znajduje siê portal do nastêpnego poziomu
		* @param screens Vector wskaŸników na ekrany przygody
		* @param ID ID pierwszego z najbardziej oddalonych od siebie ekranów
		* @return ID klucza potrzebnego do otwarcia drzwi
		*/
		int generate_door(std::vector<Screen*>& screens, int ID);
		/**
		* Funkcja generuj¹ca skrzyniê z kluczem do drzwi na drugim najbardziej oddalonym ekranie oraz skrzynie z miksturami na losowych innych ekranach
		* @param screens Vector wskaŸników na ekrany przygody
		* @param ScreenID ID drugiego z najbardziej oddalonych od siebie ekranów
		* @param keyID ID klucza potrzebnego do otwarcia drzwi
		*/
		void generate_chests(std::vector<Screen*>& screens, int ScreenID, int keyID);
		/**
		* Funkcja generuje przeciwników na ekranie ze skrzyni¹, w której jest klucz do drzwi oraz na innych ekranach. Korzysta z innych funkcji do generacji przeciwników w tej klasie
		* @param screens Vector wskaŸników na ekrany przygody
		* @param chestScreenID ID ekranu na którym znajduje siê skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu na którym znajduje siê portal
		* @param cache_enemies Przeciwnicy trzymani w pamiêci podrêcznej którzy s¹ kopiowani do ekranów
		*/
		void generate_enemies(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja generuje postaæ niegrywaln¹ na losowym ekranie ka¿dego generowanego poziomu
		* @param screens Vector wskaŸników na ekrany przygody
		*/
		void generate_NPCs(std::vector<Screen*>& screens);
};


#endif // ADVENTURE_CREATOR_H