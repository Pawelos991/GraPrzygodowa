#ifndef ADVENTURE_STATS_H
#define ADVENTURE_STATS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

/**
*Klasa reprezentująca statystyki gracza w trybie przygody
*/
class Adventure_Stats
{
	public:
		/**
		*Konstruktor klasy inicjalizujący atrybuty
		*/
		Adventure_Stats();
		/**
		*Destruktor klasy
		*/
		~Adventure_Stats();
		/**
		*Funkcja odpowiedzialna za wyświetlenie statystyk w oknie
		*@param window Okno w którym mają zostać wyświetlone statystyki
		*/
		void display_stats(RenderWindow& window);
		/**Funkcja ustawiająca odpowiednie wartości tekstów statystyk*/
		void prepare_stats();
		/**Funkcja inicjalizująca teksty statystyk i wartości liczbowe*/
		void init_stats();
		/**Funkcja resetująca wartości liczbowe statystyk*/
		void reset_stats();
		/**Funkcja dodająca 1 sekundę do całkowitego czasu*/
		void update_time();
		/**Funkcja dodająca 1 zabitego minotaura do statystyk*/
		void add_killed_minotaur();
		/**Funkcja dodająca 1 zabitego krasnoluda do statystyk*/
		void add_killed_dwarf();
		/**Funkcja dodająca 1 zabitego łucznika do statystyk*/
		void add_killed_archer();
		/**Funkcja dodająca 1 zabitego rycerza do statystyk*/
		void add_killed_knight();
		/**Funkcja dodająca 1 zabitego węża do statystyk*/
		void add_killed_snake();
		/**Funkcja dodająca 1 zabitego skorpiona do statystyk*/
		void add_killed_scorpion();
		/**Funkcja dodająca 1 odwiedzony pokój do statystyk*/
		void add_visited_room();
		/**Funkcja dodająca 1 użytą miksturę do statystyk*/
		void add_used_potion();
		/**Funkcja dodająca 1 ukończony poziom zamku do statystyk*/
		void add_castle_level();
		/**Funkcja dodająca 1 ukończony poziom lasu do statystyk*/
		void add_forest_level();
		/**Funkcja dodająca 1 ukończony poziom pustyni do statystyk*/
		void add_desert_level();
		/**Funkcja dodająca 1 ukończony poziom lochów do statystyk*/
		void add_dungeon_level();
		/**Funkcja dodająca 1 otwartą skrzynię do statystyk*/
		void add_opened_chest();
		/**Funkcja dodająca 1 ukończony poziom do statystyk*/
		void add_level();
		/**Funkcja ustawiająca atrybut stats_set na true oznaczający że statystyki zostały przygotowane do wyświetlenia*/
		void setStats();
		bool getStatsSet();

	private:
		/**Ilość ukończonych poziomów*/
		int levels;
		/**Ilość sekund czasu przejścia przygody*/
		int seconds;
		/**Ilość minut czasu przejścia przygody*/
		int minutes;
		/**Ilość godzin czasu przejścia przygody*/
		int hours;
		/**Ilość pokonanych przeciwników*/
		int enemies_killed;
		/**Ilość pokonanych minotaurów*/
		int minotaurs_killed;
		/**Ilość pokonanych krasnoludów*/
		int dwarfs_killed;
		/**Ilość pokonanych łuczników*/
		int archers_killed;
		/**Ilość pokonanych rycerzy*/
		int knights_killed;
		/**Ilość pokonanych węży*/
		int snakes_killed;
		/**Ilość pokonanych skorpionów*/
		int scorpions_killed;
		/**Ilość odwiedzonych pokojów*/
		int rooms_visited;
		/**Ilość użytych mikstur*/
		int potions_used;
		/**Ilość ukończonych poziomów zamku*/
		int castle_levels;
		/**Ilość ukończonych poziomów lasu*/
		int forest_levels;
		/**Ilość ukończonych poziomów pustyni*/
		int desert_levels;
		/**Ilość ukończonych poziomów lochów*/
		int dungeon_levels;
		/**Ilość otwartych skrzyń*/
		int opened_chests;
		/**Informacja czy statystyki zostały już przygotowane do wyświetlenia*/
		bool stats_set;
		/**Czcionka tekstu statystyk*/
		Font font;
		/**Tekst wyświetlający liczbę ukończonych poziomów*/
		Text levels_text;
		/**Tekst wyświetlajacy liczbę sekund czasu ukończenia przygody*/
		Text seconds_text;
		/**Tekst wyświetlający liczbę minut czasu ukończenia przygody*/
		Text minutes_text;
		/**Tekst wyświetlający liczbę godzin czasu ukończenia przygody*/
		Text hours_text;
		/**Tekst wyświetlający liczbę pokonanych minotaurów*/
		Text minotaurs_text;
		/**Tekst wyświetlający liczbę pokonanych krasnoludów*/
		Text dwarfs_text;
		/**Tekst wyświetlający liczbę pokonanych łuczników*/
		Text archers_text;
		/**Tekst wyświetlający liczbę pokonanych rycerzy*/
		Text knights_text;
		/**Tekst wyświetlający liczbę pokonanych węży*/
		Text snakes_text;
		/**Tekst wyświetlający liczbę pokonanych skorpionów*/
		Text scorpions_text;
		/**Tekst wyświetlający liczbę odwiedzonych pokojów*/
		Text rooms_text;
		/**Tekst wyświetlający liczbę użytych mikstur*/
		Text potions_text;
		/**Tekst wyświetlający liczbę ukończonych poziomów zamku*/
		Text castle_text;
		/**Tekst wyświetlający liczbę ukończonych poziomów lasu*/
		Text forest_text;
		/**Tekst wyświetlający liczbę ukończonych poziomów pustyni*/
		Text desert_text;
		/**Tekst wyświetlający liczbę ukończonych poziomów lochów*/
		Text dungeon_text;
		/**Tekst wyświetlający liczbę otwartych skrzyń*/
		Text chests_text;
		/**Tekst wyświetlający liczbę wszystkich pokonanych przeciwników*/
		Text all_enemies_text;
};

#endif // ADVENTURE_STATS_H