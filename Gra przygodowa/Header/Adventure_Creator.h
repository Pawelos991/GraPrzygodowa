#ifndef ADVENTURE_CREATOR_H
#define ADVENTURE_CREATOR_H

#include "Loading_Screen.h"

class Adventure_Creator 
{
	public:
		Adventure_Creator(Loading_Screen *loading_screen);
		~Adventure_Creator();
		int get_floor_type() { return floor_type; }
		int get_level() { return level; }
		std::vector<Screen*> next_lvl(RenderWindow& window, Enemies& cache_enemies);
		std::vector<Screen*> generate_level(RenderWindow &window, Enemies& cache_enemies);
		void reset_creator();

	private:
		Loading_Screen* loading_screen;
		int floor_type; // 1 - Valley, 2 - Castle, 3 - Dungeon, 4 - Desert
		int last_floor_type;
		int level;
		Portal* portal;
		void generate_screens(std::vector<Screen*>& screens, int howManyScreens);
		void place_screens(std::vector<Screen*>& screens);
		void generate_connections(std::vector<Screen*>& screens);
		bool any_neighbour(Vector2f pos,std::vector<Screen*>& screens);
		void count_connections(Screen* s);
		Screen* find_screen_by_position(Vector2f pos, std::vector<Screen*>& screens);
		Screen* find_screen_by_ID(int id, std::vector<Screen*>& screens);
		void generate_walls_dungeons(std::vector<Screen*>& screens);
		void generate_walls_castle(std::vector<Screen*>& screens);
		void generate_walls_valley(std::vector<Screen*>& screens);
		void generate_walls_desert(std::vector<Screen*>& screens);
		void generate_enemies_castle(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		void generate_enemies_valley(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		void generate_enemies_desert(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		float getDistance(Vector2f pos1, Vector2f pos2);
		std::vector<Screen*> find_two_furthest_screens(std::vector<Screen*>&screens);
		int generate_door(std::vector<Screen*>& screens, int ID);
		void generate_chests(std::vector<Screen*>& screens, int ScreenID, int keyID);
		void generate_enemies(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies);
		void generate_NPCs(std::vector<Screen*>& screens);

};


#endif // ADVENTURE_CREATOR_H