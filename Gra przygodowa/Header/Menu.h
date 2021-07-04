#include "Animations.h"

class Menu 
{
	public:
		Menu() { counter = 0; }
		~Menu(){}

	protected:
		void prepareMenu();
		void loadMainMenuTextures();
		void loadInGameMenuTextures();
		void loadGameModeMenuTextures();
		void loadArenaMenuTextures();
		void loadOptionsMenuTextures();
		void loadResolutionMenuTextures();
		void loadConfirmMenuTextures();
		void loadAdventureMenuTextures();

		int mainMenu(RenderWindow& window, bool finishedTutorial, bool adventureStarted);
		int gameModeMenu(RenderWindow& window, bool finishedTutorial, bool adventureStarted);
		void optionsMenu(RenderWindow& window);
		int confirmMenu(RenderWindow& window);
		void resolutionMenu(RenderWindow& window);
		int arenaMenu(RenderWindow& window);
		int inGameMenu(RenderWindow& window);
		int adventureMenu(RenderWindow& window, bool adventureStarted);



	private:
		Animations menu_animations;

		Texture background_texture;
		Texture main_menu_textures[6];
		Texture gameMode_menu_textures[9];
		Texture arena_menu_textures[6];
		Texture inGame_menu_textures[4];
		Texture options_menu_textures[9];
		Texture resolution_menu_textures[8];
		Texture confirm_menu_textures[6];
		Texture adventure_menu_textures[7];

		Sprite menu_sprite;
		Sprite menu_background;
		int counter; //Frame counter

		bool isFullscreen;
		Vector2u resolution;

		Sound music;
		SoundBuffer musicBuffer;
		bool isMusicPlaying;


};