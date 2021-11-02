#ifndef MENU_H
#define MENU_H

#include "Animations.h"

/**
* Klasa reprezentująca interaktywne menu gry
*/
class Menu 
{
	public:
		/**
		* Konstruktor klasy ustawiający licznik klatek w menu na 0
		*/
		Menu() { counter = 0; }
		/**
		* Destruktor klasy
		*/
		~Menu(){}

	protected:
		/**
		* Funkcja wywołuje funkcja ładowania tekstur i przygotowuje całe menu
		*/
		void prepareMenu();
		/**
		* Funkcja ładuje tekstury głównego menu z plików
		*/
		void loadMainMenuTextures();
		/**
		* Funkcja ładuje tekstury menu wywoływanego wewnątrz gry poprzez Esc z plików
		*/
		void loadInGameMenuTextures();
		/**
		* Funkcja ładuje tekstury menu trybu gry z plików
		*/
		void loadGameModeMenuTextures();
		/**
		* Funkcja ładuje tekstury menu areny z plików
		*/
		void loadArenaMenuTextures();
		/**
		* Funkcja ładuje tekstury menu opcji z plików
		*/
		void loadOptionsMenuTextures();
		/**
		* Funkcja ładuje tekstury menu rozdzielczości z plików
		*/
		void loadResolutionMenuTextures();
		/**
		* Funkcja ładuje tekstury okna potwierdzenia z plików
		*/
		void loadConfirmMenuTextures();
		/**
		* Funkcja ładuje tekstury menu przygody z plików
		*/
		void loadAdventureMenuTextures();

		/**
		* Funkcja odpowiada za funkcjonowanie całego menu, wywołuje pomniejsze funkcje odpowiedzialne za podmenu
		* @param window Okno w którym wyświetlane jest menu
		* @param finishedTutorial Informacja o tym czy samouczek został ukończony
		* @param adventureStarted Informacja o tym czy przygoda została rozpoczęta
		* @return Wybór dokonany przez gracza (rozegranie samouczka/przygody/wybór areny/wyjście z gry)
		*/
		int mainMenu(RenderWindow& window, bool finishedTutorial, bool adventureStarted);
		/**
		* Funkcja odpowiada za podmenu wyboru trybu gry
		* @param window Okno w którym wyświetlane jest menu
		* @param finishedTutorial Informacja o tym czy samouczek został ukończony
		* @param adventureStarted Informacja o tym czy przygoda została rozpoczęta
		* @return Wybór dokonany przez gracza (tryb gry)
		*/
		int gameModeMenu(RenderWindow& window, bool finishedTutorial, bool adventureStarted);
		/**
		* Funkcja odpowiada za podmenu opcji, można w nim zmienić rozdzielczość okna, tryb wyswietlania i wyłączyć lub włączyć muzykę w tle
		* @param window Okno w którym wyświetlane jest menu
		*/
		void optionsMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za okienko potwierdzenia
		* @param window Okno w którym wyświetlane jest menu
		* @return Informacja o tym czy gracz zatwierdził wybór czy zrezygnował
		*/
		int confirmMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za podmenu wyboru rozdzielczości okna
		* @param window Okno w którym wyświetlane jest menu
		*/
		void resolutionMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za podmenu wyboru trybu areny. Opcje to arena(normal), arena(godmode) lub powrót
		* @param window Okno w którym wyświetlane jest menu
		* @return Informacja o tym jaki tryb areny został wybrany
		*/
		int arenaMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za wyświetlanie menu wywoływanego z poziomu rozgrywki. Możliwości to powrót do menu lub kontynuacja
		* @param window Okno w którym wyświetlane jest menu
		* @return Infomacja o wyborze podjętym przez gracza
		*/
		int inGameMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za wyświetlenie menu przygody. Opje to kontynuacja przygody (jeśli została rozpoczęta), nowa przygoda lub powrót
		* @param window Okno w którym wyświetlane jest menu 
		* @param adventureStarted Informacja o tym czy przygoda została rozpoczęta
		* @return Informacja o wyborze podjętym przez gracza
		*/
		int adventureMenu(RenderWindow& window, bool adventureStarted);



	private:
		/**Animacje wyświetlane w menu*/
		Animations menu_animations;

		/**Tekstura tła menu*/
		Texture background_texture;
		/**Tekstury kafelków z możliwym wyborem w głównym menu*/
		Texture main_menu_textures[6];
		/**Tekstury kafelków z możliwym wyborem w menu wyboru trybu gry*/
		Texture gameMode_menu_textures[9];
		/**Tekstury kafelków z możliwym wyborem w menu trybu areny*/
		Texture arena_menu_textures[6];
		/**Tekstury kafelków z możliwym wyborem w menu wywoływanym z poziomu rozgrywki*/
		Texture inGame_menu_textures[4];
		/**Tekstury kafelków z możliwym wyborem w menu opcji*/
		Texture options_menu_textures[9];
		/**Tekstury kafelków z możliwym wyborem w menu wyboru rozdzielczości*/
		Texture resolution_menu_textures[8];
		/**Tekstury kafelków z możliwym wyborem w oknie potwierdzenia*/
		Texture confirm_menu_textures[6];
		/**Tekstury kafelków z możliwym wyborem w menu przygody*/
		Texture adventure_menu_textures[7];

		/**Sprite służący do wyświetlania kafelków opcji wyboru gracza*/
		Sprite menu_sprite;
		/**Sprite służący do wyświetlania tła menu*/
		Sprite menu_background;
		/**Licznik klatek*/
		int counter; //Frame counter

		/**Informacja o tym czy okno jest wyświetlane w trybie pełnoekranowym*/
		bool isFullscreen;
		/**Obecna rozdzielczość okna*/
		Vector2u resolution;

		/**Muzyka w tle*/
		Sound music;
		/**Bufor przechowujący utwór muzyczny odtwarzany w tle*/
		SoundBuffer musicBuffer;
		/**Informacja o tym czy muzyka jest odtwarzana*/
		bool isMusicPlaying;


};

#endif // MENU_H