#ifndef MENU_H
#define MENU_H

#include "Animations.h"

/**
* Klasa reprezentuj�ca interaktywne menu gry
*/
class Menu 
{
	public:
		/**
		* Konstruktor klasy ustawiaj�cy licznik klatek w menu na 0
		*/
		Menu() { counter = 0; }
		/**
		* Destruktor klasy
		*/
		~Menu(){}

	protected:
		/**
		* Funkcja wywo�uje funkcja �adowania tekstur i przygotowuje ca�e menu
		*/
		void prepareMenu();
		/**
		* Funkcja �aduje tekstury g��wnego menu z plik�w
		*/
		void loadMainMenuTextures();
		/**
		* Funkcja �aduje tekstury menu wywo�ywanego wewn�trz gry poprzez Esc z plik�w
		*/
		void loadInGameMenuTextures();
		/**
		* Funkcja �aduje tekstury menu trybu gry z plik�w
		*/
		void loadGameModeMenuTextures();
		/**
		* Funkcja �aduje tekstury menu areny z plik�w
		*/
		void loadArenaMenuTextures();
		/**
		* Funkcja �aduje tekstury menu opcji z plik�w
		*/
		void loadOptionsMenuTextures();
		/**
		* Funkcja �aduje tekstury menu rozdzielczo�ci z plik�w
		*/
		void loadResolutionMenuTextures();
		/**
		* Funkcja �aduje tekstury okna potwierdzenia z plik�w
		*/
		void loadConfirmMenuTextures();
		/**
		* Funkcja �aduje tekstury menu przygody z plik�w
		*/
		void loadAdventureMenuTextures();

		/**
		* Funkcja odpowiada za funkcjonowanie ca�ego menu, wywo�uje pomniejsze funkcje odpowiedzialne za podmenu
		* @param window Okno w kt�rym wy�wietlane jest menu
		* @param finishedTutorial Informacja o tym czy samouczek zosta� uko�czony
		* @param adventureStarted Informacja o tym czy przygoda zosta�a rozpocz�ta
		* @return Wyb�r dokonany przez gracza (rozegranie samouczka/przygody/wyb�r areny/wyj�cie z gry)
		*/
		int mainMenu(RenderWindow& window, bool finishedTutorial, bool adventureStarted);
		/**
		* Funkcja odpowiada za podmenu wyboru trybu gry
		* @param window Okno w kt�rym wy�wietlane jest menu
		* @param finishedTutorial Informacja o tym czy samouczek zosta� uko�czony
		* @param adventureStarted Informacja o tym czy przygoda zosta�a rozpocz�ta
		* @return Wyb�r dokonany przez gracza (tryb gry)
		*/
		int gameModeMenu(RenderWindow& window, bool finishedTutorial, bool adventureStarted);
		/**
		* Funkcja odpowiada za podmenu opcji, mo�na w nim zmieni� rozdzielczo�� okna, tryb wyswietlania i wy��czy� lub w��czy� muzyk� w tle
		* @param window Okno w kt�rym wy�wietlane jest menu
		*/
		void optionsMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za okienko potwierdzenia
		* @param window Okno w kt�rym wy�wietlane jest menu
		* @return Informacja o tym czy gracz zatwierdzi� wyb�r czy zrezygnowa�
		*/
		int confirmMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za podmenu wyboru rozdzielczo�ci okna
		* @param window Okno w kt�rym wy�wietlane jest menu
		*/
		void resolutionMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za podmenu wyboru trybu areny. Opcje to arena(normal), arena(godmode) lub powr�t
		* @param window Okno w kt�rym wy�wietlane jest menu
		* @return Informacja o tym jaki tryb areny zosta� wybrany
		*/
		int arenaMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za wy�wietlanie menu wywo�ywanego z poziomu rozgrywki. Mo�liwo�ci to powr�t do menu lub kontynuacja
		* @param window Okno w kt�rym wy�wietlane jest menu
		* @return Infomacja o wyborze podj�tym przez gracza
		*/
		int inGameMenu(RenderWindow& window);
		/**
		* Funkcja odpowiada za wy�wietlenie menu przygody. Opje to kontynuacja przygody (je�li zosta�a rozpocz�ta), nowa przygoda lub powr�t
		* @param window Okno w kt�rym wy�wietlane jest menu 
		* @param adventureStarted Informacja o tym czy przygoda zosta�a rozpocz�ta
		* @return Informacja o wyborze podj�tym przez gracza
		*/
		int adventureMenu(RenderWindow& window, bool adventureStarted);



	private:
		/**Animacje wy�wietlane w menu*/
		Animations menu_animations;

		/**Tekstura t�a menu*/
		Texture background_texture;
		/**Tekstury kafelk�w z mo�liwym wyborem w g��wnym menu*/
		Texture main_menu_textures[6];
		/**Tekstury kafelk�w z mo�liwym wyborem w menu wyboru trybu gry*/
		Texture gameMode_menu_textures[9];
		/**Tekstury kafelk�w z mo�liwym wyborem w menu trybu areny*/
		Texture arena_menu_textures[6];
		/**Tekstury kafelk�w z mo�liwym wyborem w menu wywo�ywanym z poziomu rozgrywki*/
		Texture inGame_menu_textures[4];
		/**Tekstury kafelk�w z mo�liwym wyborem w menu opcji*/
		Texture options_menu_textures[9];
		/**Tekstury kafelk�w z mo�liwym wyborem w menu wyboru rozdzielczo�ci*/
		Texture resolution_menu_textures[8];
		/**Tekstury kafelk�w z mo�liwym wyborem w oknie potwierdzenia*/
		Texture confirm_menu_textures[6];
		/**Tekstury kafelk�w z mo�liwym wyborem w menu przygody*/
		Texture adventure_menu_textures[7];

		/**Sprite s�u��cy do wy�wietlania kafelk�w opcji wyboru gracza*/
		Sprite menu_sprite;
		/**Sprite s�u��cy do wy�wietlania t�a menu*/
		Sprite menu_background;
		/**Licznik klatek*/
		int counter; //Frame counter

		/**Informacja o tym czy okno jest wy�wietlane w trybie pe�noekranowym*/
		bool isFullscreen;
		/**Obecna rozdzielczo�� okna*/
		Vector2u resolution;

		/**Muzyka w tle*/
		Sound music;
		/**Bufor przechowuj�cy utw�r muzyczny odtwarzany w tle*/
		SoundBuffer musicBuffer;
		/**Informacja o tym czy muzyka jest odtwarzana*/
		bool isMusicPlaying;


};

#endif // MENU_H