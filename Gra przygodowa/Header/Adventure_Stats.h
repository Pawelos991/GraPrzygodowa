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

class Adventure_Stats
{
	public:
		Adventure_Stats();
		~Adventure_Stats();
		void display_stats(RenderWindow& window);
		void prepare_stats();
		void init_stats();
		void reset_stats();
		void update_time();
		void add_killed_minotaur();
		void add_killed_dwarf();
		void add_killed_archer();
		void add_killed_knight();
		void add_killed_snake();
		void add_killed_scorpion();
		void add_visited_room();
		void add_used_potion();
		void add_castle_level();
		void add_forest_level();
		void add_desert_level();
		void add_dungeon_level();
		void add_opened_chest();
		void add_level();
		void setStats();
		int getSeconds();
		int getMinutes();
		int getHours();
		int getRoomsVisited();
		int getPotionsUsed();
		int getAllKilledEnemies();
		int getMinotaursKilled();
		int getDwarfsKilled();
		int getArchersKilled();
		int getKnightsKilled();
		int getSnakesKilled();
		int getScorpionsKilled();
		int getCastleLevels();
		int getForestLevels();
		int getDesertLevels();
		int getDungeonLevels();
		int getOpenedChests();
		int getLevels();
		bool getStatsSet();

	private:
		int levels;
		int seconds;
		int minutes;
		int hours;
		int enemies_killed;
		int minotaurs_killed;
		int dwarfs_killed;
		int archers_killed;
		int knights_killed;
		int snakes_killed;
		int scorpions_killed;
		int rooms_visited;
		int potions_used;
		int castle_levels;
		int forest_levels;
		int desert_levels;
		int dungeon_levels;
		int opened_chests;
		bool stats_set;
		Font font;
		Text levels_text;
		Text seconds_text;
		Text minutes_text;
		Text hours_text;
		Text minotaurs_text;
		Text dwarfs_text;
		Text archers_text;
		Text knights_text;
		Text snakes_text;
		Text scorpions_text;
		Text rooms_text;
		Text potions_text;
		Text castle_text;
		Text forest_text;
		Text desert_text;
		Text dungeon_text;
		Text chests_text;
		Text all_enemies_text;
};

#endif // ADVENTURE_STATS_H