#ifndef ADVENTURE_CREATOR_H
#define ADVENTURE_CREATOR_H

#include "Loading_Screen.h"

class Adventure_Creator 
{
	public:
		Adventure_Creator(Loading_Screen *loading_screen);
		~Adventure_Creator();
		int get_adventure_phase() { return adventure_phase; }
		std::vector<Screen*> generate_adventure(RenderWindow &window);

	private:
		Loading_Screen* loading_screen;
		int adventure_phase;
		void generate_screens(std::vector<Screen*>& screens);
		void place_screens(std::vector<Screen*>& screens);
		void generate_connections(std::vector<Screen*>& screens);
		bool any_neighbour(Vector2f pos,std::vector<Screen*>& screens);
		void count_connections(Screen* s);
		Screen* find_screen_by_position(Vector2f pos, std::vector<Screen*>& screens);
		Screen* find_screen_by_ID(int id, std::vector<Screen*>& screens);
		void generate_walls_dungeons(std::vector<Screen*>& screens);
		void generate_walls_castle(std::vector<Screen*>& screens);
		void generate_walls_valley(std::vector<Screen*>& screens);

};


#endif // ADVENTURE_CREATOR_H