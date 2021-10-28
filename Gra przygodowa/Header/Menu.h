#ifndef MENU_H
#define MENU_H

#include "Animations.h"

/**
* Klasa reprezentuj¹ca interaktywne menu gry
*/
class Menu 
{
	public:
		/**
		* Konstruktor klasy ustawiaj¹cy licznik klatek w menu na 0
		*/
		Menu() { counter = 0; }
		/**
		* Destruktor klasy
		*/
		~Menu(){}

	protected:
		/**
		* Funkcja wywo³uje funkcja ³adowania tekstur i przygotowuje ca³e menu
		*/
		void prepareMenu();
		/**
		* Funkcja ³aduje tekstury g³ównego menu z plików
		*/
		void loadMainMenuTextures();
		/**
		* Funkcja ³aduje tekstury menu wywo³ywanego wewn¹trz gry poprzez Esc z plików
		*/
		void loadInGameMenuTextures();
		/**
		* Funkcja ³aduje tekstury menu trybu gry z plików
		*/
		void loadGameModeMenuTextures();
		/**
		* Funkcja ³aduje tekstury menu areny z plików
		*/
		void loadArenaMenuTextures();
		/**
		* Funkcja ³aduje tekstury menu opcji z plików
		*/
		void loadOptionsMenuTextures();
		/**
		* Funkcja ³aduje tekstury menu rozdzielczoœci z plików
		*/
		void loadResolutionMenuTextures();
		/**
		* Funkcja ³aduje tekstury okna potwierdzenia z plików
		*/
		void loadConfirmMenuTextures();
		/**
		* Funkcja ³aduje tekstury menu przygody z plików
		*/
		void loadAdventureMenuTextures();

		/**
		* Funkcja odpowiada za funkcjonowanie ca³ego menu, wywo³uje pomniejsze funkcje odpowiedzialne za podmenu
		* @param window Okno w którym wyœwietlane jest menu
		* @param finishedTutorial Informacja o tym czy samouczek zosta³ ukoñczony
		* @param adventureStarted Informacja o tym czy przygoda zosta³a rozpoczêta
		* @return Wybór dokonany przez gracza (rozegranie samouczka/przygody/wybór areny/wyjœcie z gry)
		*/
		int mainMenu(RenderWindow& window, bool finishedTutorial, bool adventureStarted);
		/**
		* Funkcja odpowiada za podmenu wyboru trybu gry
		* @param window Okno w którym wyœwietlane jest menu
		* @param finishedTutorial Informacja o tym czy samouczek zosta³ ukoñczony
		* @param adventureStarted Informacja o tym czy przygoda zosta³a rozpoczêta
		* @return Wybór dokonany przez gracza (tryb gry)
		*/
		int gameModeMenu(RenderWindow& window, bool finishedTutorial, bool adventureStarted);
		/**
		* Funkcja odpowiada za podmenu opcji, mo¿na w nim zmieniæ rozdzielczoœæ okna, tryb wyswietlania i wy³¹czyæ lub w³¹czyæ muzykê w tle
		* @param window Okno w którym wyœwietlane jest menu
		*/
		void optionsMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za okienko potwierdzenia
		* @param window Okno w którym wyœwietlane jest menu
		* @return Informacja o tym czy gracz zatwierdzi³ wybór czy zrezygnowa³
		*/
		int confirmMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za podmenu wyboru rozdzielczoœci okna
		* @param window Okno w którym wyœwietlane jest menu
		*/
		void resolutionMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za podmenu wyboru trybu areny. Opcje to arena(normal), arena(godmode) lub powrót
		* @param window Okno w którym wyœwietlane jest menu
		* @return Informacja o tym jaki tryb areny zosta³ wybrany
		*/
		int arenaMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za wyœwietlanie menu wywo³ywanego z poziomu rozgrywki. Mo¿liwoœci to powrót do menu lub kontynuacja
		* @param window Okno w którym wyœwietlane jest menu
		* @return Infomacja o wyborze podjêtym przez gracza
		*/
		int inGameMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za wyœwietlenie menu przygody. Opje to kontynuacja przygody (jeœli zosta³a rozpoczêta), nowa przygoda lub powrót
		* @param window Okno w którym wyœwietlane jest menu 
		* @param adventureStarted Informacja o tym czy przygoda zosta³a rozpoczêta
		* @return Informacja o wyborze podjêtym przez gracza
		*/
		int adventureMenu(RenderWindow& window, bool adventureStarted);



	private:
		/**Animacje wyœwietlane w menu*/
		Animations menu_animations;

		/**Tekstura t³a menu*/
		Texture background_texture;
		/**Tekstury kafelków z mo¿liwym wyborem w g³ównym menu*/
		Texture main_menu_textures[6];
		/**Tekstury kafelków z mo¿liwym wyborem w menu wyboru trybu gry*/
		Texture gameMode_menu_textures[9];
		/**Tekstury kafelków z mo¿liwym wyborem w menu trybu areny*/
		Texture arena_menu_textures[6];
		/**Tekstury kafelków z mo¿liwym wyborem w menu wywo³ywanym z poziomu rozgrywki*/
		Texture inGame_menu_textures[4];
		/**Tekstury kafelków z mo¿liwym wyborem w menu opcji*/
		Texture options_menu_textures[9];
		/**Tekstury kafelków z mo¿liwym wyborem w menu wyboru rozdzielczoœci*/
		Texture resolution_menu_textures[8];
		/**Tekstury kafelków z mo¿liwym wyborem w oknie potwierdzenia*/
		Texture confirm_menu_textures[6];
		/**Tekstury kafelków z mo¿liwym wyborem w menu przygody*/
		Texture adventure_menu_textures[7];

		/**Sprite s³u¿¹cy do wyœwietlania kafelków opcji wyboru gracza*/
		Sprite menu_sprite;
		/**Sprite s³u¿¹cy do wyœwietlania t³a menu*/
		Sprite menu_background;
		/**Licznik klatek*/
		int counter; //Frame counter

		/**Informacja o tym czy okno jest wyœwietlane w trybie pe³noekranowym*/
		bool isFullscreen;
		/**Obecna rozdzielczoœæ okna*/
		Vector2u resolution;

		/**Muzyka w tle*/
		Sound music;
		/**Bufor przechowuj¹cy utwór muzyczny odtwarzany w tle*/
		SoundBuffer musicBuffer;
		/**Informacja o tym czy muzyka jest odtwarzana*/
		bool isMusicPlaying;


};

#endif // MENU_H