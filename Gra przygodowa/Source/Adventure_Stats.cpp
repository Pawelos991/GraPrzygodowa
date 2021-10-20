#include "Adventure_Stats.h"

Adventure_Stats::Adventure_Stats()
{
	seconds = 0;
	minutes = 0;
	hours = 0;
	minotaurs_killed = 0;
	dwarfs_killed = 0;
	archers_killed = 0;
	knights_killed = 0;
	snakes_killed = 0;
	scorpions_killed = 0;
	rooms_visited = 0;
	potions_used = 0;
}

Adventure_Stats::~Adventure_Stats(){}

void Adventure_Stats::reset_stats()
{
	seconds = 0;
	minutes = 0;
	hours = 0;
	minotaurs_killed = 0;
	dwarfs_killed = 0;
	archers_killed = 0;
	knights_killed = 0;
	snakes_killed = 0;
	scorpions_killed = 0;
	rooms_visited = 0;
	potions_used = 0;
}

void Adventure_Stats::update_time()
{
	seconds += 1;
	if (seconds == 60)
	{
		minutes += 1;
		seconds = 0;
	}
	if (minutes == 60)
	{
		hours += 1;
		minutes = 0;
	}
}

void Adventure_Stats::add_killed_minotaur()
{
	minotaurs_killed += 1;
}

void Adventure_Stats::add_killed_dwarf()
{
	dwarfs_killed += 1;
}
void Adventure_Stats::add_killed_archer()
{
	archers_killed += 1;
}

void Adventure_Stats::add_killed_knight()
{
	knights_killed += 1;
}

void Adventure_Stats::add_killed_snake()
{
	snakes_killed += 1;
}

void Adventure_Stats::add_killed_scorpion()
{
	scorpions_killed += 1;
}

void Adventure_Stats::add_visited_room()
{
	rooms_visited += 1;
}

void Adventure_Stats::add_used_potion()
{
	potions_used += 1;
}

int Adventure_Stats::getSeconds()
{
	return seconds;
}

int Adventure_Stats::getMinutes()
{
	return minutes;
}

int Adventure_Stats::getHours()
{
	return hours;
}

int Adventure_Stats::getRoomsVisited()
{
	return rooms_visited;
}

int Adventure_Stats::getPotionsUsed()
{
	return potions_used;
}

int Adventure_Stats::getAllKilledEnemies()
{
	return minotaurs_killed + dwarfs_killed + archers_killed + knights_killed + snakes_killed + scorpions_killed;
}

int Adventure_Stats::getMinotaursKilled()
{
	return minotaurs_killed;
}

int Adventure_Stats::getDwarfsKilled()
{
	return dwarfs_killed;
}

int Adventure_Stats::getArchersKilled()
{
	return archers_killed;
}

int Adventure_Stats::getKnightsKilled()
{
	return knights_killed;
}

int Adventure_Stats::getSnakesKilled()
{
	return snakes_killed;
}

int Adventure_Stats::getScorpionsKilled()
{
	return scorpions_killed;
}

