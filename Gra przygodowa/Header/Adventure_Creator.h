#ifndef ADVENTURE_CREATOR_H
#define ADVENTURE_CREATOR_H

#include "Loading_Screen.h"

/**
* Klasa reprezentuje kreator przygody s�u��cy do komputerowej generacji poziomu przygody poprzez losow� generacj� uk�adu ekran�w, generacj� �cian, przeciwnik�w oraz skrzy�
*/
class Adventure_Creator 
{
	public:
		/**
		* Konstruktor klasy ustawiaj�cy podstawowe atrybuty
		* @param loading_screen Wska�nik do ekranu �adowania na kt�ry zostanie ustawiony wska�nik obiektu
		*/
		Adventure_Creator(Loading_Screen *loading_screen);
		/**
		* Destruktor klasy
		*/
		~Adventure_Creator();
		/**
		* Funkcja zwraca informacj� o tym, jakiego typu poziom zosta� wygenerowany
		* @return Typ poziomu (1-Las, 2-Zamek, 3-Lochy, 4-Pustynia)
		*/
		int get_floor_type() { return floor_type; }
		/**
		* Funkcja zwraca informacj� o numerze aktualnego poziomu. Numeracja zaczyna si� od poziomu 1 a ko�czy na poziomie 11 (ekran podsumowania)
		* @return Numer aktualnego poziomu
		*/
		int get_level() { return level; }
		/**
		* Funkcja zwraca vector wska�nik�w na ekrany przygody wygenerowane jako nowy poziom
		* @param window Okno w kt�rym wy�wietlana jest gra
		* @param cache_enemies Przeciwnicy przechowywani w pami�ci podr�cznej wykorzystywani przy generacji poziomu
		* @return Vector wska�nik�w na ekrany wygenerowane jako nowy poziom
		*/
		std::vector<Screen*> next_lvl(RenderWindow& window, Enemies& cache_enemies);
		/**
		* Funkcja zwraca vector wska�nik�w na ekrany przygody wygenerowane jako poziom
		* @param window Okno w kt�rym wy�wietlana jest gra
		* @param cache_enemies Przeciwnicy przechowywani w pami�ci podr�cznej wykorzystywani przy generacji poziomu
		* @return Vector wska�nik�w na ekrany wygenerowane jako poziom
		*/
		std::vector<Screen*> generate_level(RenderWindow &window, Enemies& cache_enemies);
		/**
		* Funkcja s�u�y do przywr�cenia atrybut�w obiektu do warto�ci domy�lnych (np. level = 1)
		*/
		void reset_creator();

	private:
		/**Wska�nik na ekran �adowania*/
		Loading_Screen* loading_screen;
		/**Typ poziomu*/
		int floor_type; // 1 - Valley, 2 - Castle, 3 - Dungeon, 4 - Desert
		/**Ostatni wygenerowany typ poziomu*/
		int last_floor_type;
		/**Numer poziomu*/
		int level;
		/**Wska�nik na portal*/
		Portal* portal;
		/**
		* Funkcja generuj�ca ekran statystyk (potrzebna przy generacji 11 poziomu - poziomu podsumowania)
		* @param window Okno w kt�rym wy�wietlana jest gra
		* @return Vector wska�nik�w na ekrany wygenerowane jako poziom
		*/
		std::vector<Screen*> generate_stats_screen(RenderWindow& window);
		/**
		* Funkcja dodaje do vectora wska�nik�w na ekrany tyle nowych ekran�w, ile podano jako argument
		* @param howManyScreens Liczba nowych ekran�w na kt�re wska�niki maj� zosta� dodane do vectora
		*/
		void generate_screens(std::vector<Screen*>& screens, int howManyScreens);
		/**
		* Funkcja losuje pozycj� dla ka�dego ekranu tak d�ugo a� wylosuje niezaj�t� pozycj� na kt�rej ekran b�dzie mia� chocia� jeden inny ekran w s�siedztwie a nast�pnie przypisuje mu t� pozycj�, tak robi z ka�dym ekranem w vectorze
		* @param screen Vector wska�nik�w na ekrany przygody
		*/
		void place_screens(std::vector<Screen*>& screens);
		/**
		* Funkcja s�u�y do generacji po��cze� mi�dzy ekranami le��cymi obok siebie
		* @param screens Vector wska�nik�w na ekrany przygody
		*/
		void generate_connections(std::vector<Screen*>& screens);
		/**
		* Funkcja sprawdza czy w s�siedztwie danej pozycji znajduje si� chocia� jeden ekran
		* @param pos Pozycja kt�rej s�siedztwo ma zosta� sprawdzone
		* @param screens Vector wska�nik�w na ekrany przygody
		* @return true je�li w s�siedztwie pozycji znajduje si� chocia� jeden ekran, false je�li nie
		*/
		bool any_neighbour(Vector2f pos,std::vector<Screen*>& screens);
		/**
		* Funkcja zlicza po�aczenia danego ekranu z innymi ekranami, a nast�pnie uzupe�nia odpowiedni atrybut ekranu
		* @param s Wska�nik na ekran kt�rego po��czenia maj� zosta� zliczone
		*/
		void count_connections(Screen* s);
		/**
		* Funkcja znajduje ekran znajduj�cy si� na podanej pozycji
		* @param pos Pozycja na kt�rej ma znajdowa� si� poszukiwany ekran
		* @param screens Vector wska�nik�w na ekrany przygody
		* @return Wska�nik na ekran znajduj�cy si� na danej pozycji, nullptr je�li na danej pozycji nie znajduje si� �aden ekran zawarty w podanym vectorze wska�nik�w na ekrany
		*/
		Screen* find_screen_by_position(Vector2f pos, std::vector<Screen*>& screens);
		/**
		* Funkcja znajduje ekran o podanym ID
		* @param id ID poszukiwanego ekranu
		* @param screens Vector wska�nik�w na ekrany przygody
		* @return Wska�nik na ekran o podanym ID, nullptr je�li w podanym vectorze wska�nik�w na ekrany nie znajduje si� �aden ekran o podanym ID
		*/
		Screen* find_screen_by_ID(int id, std::vector<Screen*>& screens);
		/**
		* Funkcja �aduje t�o loch�w i generuje �ciany loch�w w ekranach w zale�no�ci od ich po��cze� z innymi ekranami
		* @param screens Vector wska�nik�w na ekrany przygody
		*/
		void generate_walls_dungeons(std::vector<Screen*>& screens);
		/**
		* Funkcja �aduje t�o zamku i generuje �ciany zamku w ekranach w zale�no�ci od ich po��cze� z innymi ekranami
		* @param screens Vector wska�nik�w na ekrany przygody
		*/
		void generate_walls_castle(std::vector<Screen*>& screens);
		/**
		* Funkcja �aduje t�o lasu i generuje �ciany lasu w ekranach w zale�no�ci od ich po��cze� z innymi ekranami
		* @param screens Vector wska�nik�w na ekrany przygody
		*/
		void generate_walls_forest(std::vector<Screen*>& screens);
		/**
		* Funkcja �aduje t�o pustyni i generuje �ciany pustyni w ekranach w zale�no�ci od ich po��cze� z innymi ekranami
		* @param screens Vector wska�nik�w na ekrany przygody
		*/
		void generate_walls_desert(std::vector<Screen*>& screens);
		/**
		* Funkcja generuje przeciwnik�w charakterystycznych dla poziomu zamku w losowych ekranach
		* @param screens Vector wska�nik�w na ekrany przygody
		* @param chestScreenID ID ekranu w kt�rym znajduje si� skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu w kt�rym znajduje si� portal do nast�pnego poziomu
		* @param cache_enemies Przeciwnicy trzymani w pami�ci podr�cznej kt�rzy s� kopiowani do ekran�w
		*/
		void generate_enemies_castle(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja generuje przeciwnik�w charakterystycznych dla poziomu lasu w losowych ekranach
		* @param screens Vector wska�nik�w na ekrany przygody
		* @param chestScreenID ID ekranu w kt�rym znajduje si� skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu w kt�rym znajduje si� portal do nast�pnego poziomu
		* @param cache_enemies Przeciwnicy trzymani w pami�ci podr�cznej kt�rzy s� kopiowani do ekran�w
		*/
		void generate_enemies_forest(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja generuje przeciwnik�w charakterystycznych dla poziomu pustyni w losowych ekranach
		* @param screens Vector wska�nik�w na ekrany przygody
		* @param chestScreenID ID ekranu na kt�rym znajduje si� skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu na kt�rym znajduje si� portal do nast�pnego poziomu
		* @param cache_enemies Przeciwnicy trzymani w pami�ci podr�cznej kt�rzy s� kopiowani do ekran�w
		*/
		void generate_enemies_desert(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja oblicza dystans w linii prostej w uk�adzie wsp�rz�dnych pomi�dzy dwoma pozycjami
		* @param pos1 Pozycja pierwsza (x,y)
		* @param pos2 Pozycja druga (x,y)
		* @return Odleg�o�� mi�dzy pozycjami
		*/
		float getDistance(Vector2f pos1, Vector2f pos2);
		/**
		* Funkcja analizuje odleg�o�ci mi�dzy wszystkimi parami ekran�w i wyznacza dwa najbardziej oddalone od siebie
		* @param screens Vector wska�nik�w na ekrany przygody
		* @return Vector wska�nik�w na dwa najbardziej oddalone od siebie ekrany
		*/
		std::vector<Screen*> find_two_furthest_screens(std::vector<Screen*>&screens);
		/**
		* Funkcja generuj�ca drzwi na ekranie/-nach s�siaduj�cym/-cych z ekranem na kt�rym znajduje si� portal do nast�pnego poziomu
		* @param screens Vector wska�nik�w na ekrany przygody
		* @param ID ID pierwszego z najbardziej oddalonych od siebie ekran�w
		* @return ID klucza potrzebnego do otwarcia drzwi
		*/
		int generate_door(std::vector<Screen*>& screens, int ID);
		/**
		* Funkcja generuj�ca skrzyni� z kluczem do drzwi na drugim najbardziej oddalonym ekranie oraz skrzynie z miksturami na losowych innych ekranach
		* @param screens Vector wska�nik�w na ekrany przygody
		* @param ScreenID ID drugiego z najbardziej oddalonych od siebie ekran�w
		* @param keyID ID klucza potrzebnego do otwarcia drzwi
		*/
		void generate_chests(std::vector<Screen*>& screens, int ScreenID, int keyID);
		/**
		* Funkcja generuje przeciwnik�w na ekranie ze skrzyni�, w kt�rej jest klucz do drzwi oraz na innych ekranach. Korzysta z innych funkcji do generacji przeciwnik�w w tej klasie
		* @param screens Vector wska�nik�w na ekrany przygody
		* @param chestScreenID ID ekranu na kt�rym znajduje si� skrzynia z kluczem do drzwi
		* @param lastScreenID ID ekranu na kt�rym znajduje si� portal
		* @param cache_enemies Przeciwnicy trzymani w pami�ci podr�cznej kt�rzy s� kopiowani do ekran�w
		*/
		void generate_enemies(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		/**
		* Funkcja generuje posta� niegrywaln� na losowym ekranie ka�dego generowanego poziomu
		* @param screens Vector wska�nik�w na ekrany przygody
		*/
		void generate_NPCs(std::vector<Screen*>& screens);
};


#endif // ADVENTURE_CREATOR_H