#ifndef ADVENTURE_STATS_H
#define ADVENTURE_STATS_H

class Adventure_Stats
{
	public:
		Adventure_Stats();
		~Adventure_Stats();
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

	private:
		int seconds;
		int minutes;
		int hours;
		int minotaurs_killed;
		int dwarfs_killed;
		int archers_killed;
		int knights_killed;
		int snakes_killed;
		int scorpions_killed;
		int rooms_visited;
		int potions_used;
};

#endif // ADVENTURE_STATS_H