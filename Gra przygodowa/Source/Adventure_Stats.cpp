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
	castle_levels = 0;
	forest_levels = 0;
	desert_levels = 0;
	dungeon_levels = 0;
	opened_chests = 0;
	levels = 0;
	stats_set = false;
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
	castle_levels = 0;
	forest_levels = 0;
	desert_levels = 0;
	dungeon_levels = 0;
	opened_chests = 0;
	levels = 0;
	stats_set = false;
}

void Adventure_Stats::display_stats(RenderWindow& window)
{
	window.draw(levels_text);
	window.draw(seconds_text);
	window.draw(minutes_text);
	window.draw(hours_text);
	window.draw(minotaurs_text);
	window.draw(dwarfs_text);
	window.draw(archers_text);
	window.draw(knights_text);
	window.draw(snakes_text);
	window.draw(scorpions_text);
	window.draw(rooms_text);
	window.draw(potions_text);
	window.draw(chests_text);
	window.draw(castle_text);
	window.draw(forest_text);
	window.draw(desert_text);
	window.draw(dungeon_text);
}

void Adventure_Stats::prepare_stats()
{
	levels_text.setString(std::to_string(levels));
	seconds_text.setString(std::to_string(seconds));
	minutes_text.setString(std::to_string(minutes));
	hours_text.setString(std::to_string(hours));
	minotaurs_text.setString(std::to_string(minotaurs_killed));
	dwarfs_text.setString(std::to_string(dwarfs_killed));
	archers_text.setString(std::to_string(archers_killed));
	knights_text.setString(std::to_string(knights_killed));
	snakes_text.setString(std::to_string(snakes_killed));
	scorpions_text.setString(std::to_string(scorpions_killed));
	rooms_text.setString(std::to_string(rooms_visited));
	potions_text.setString(std::to_string(potions_used));
	chests_text.setString(std::to_string(opened_chests));
	castle_text.setString(std::to_string(castle_levels));
	forest_text.setString(std::to_string(forest_levels));
	desert_text.setString(std::to_string(desert_levels));
	dungeon_text.setString(std::to_string(dungeon_levels));
}

void Adventure_Stats::init_stats()
{
	reset_stats();
	font.loadFromFile("Fonts/TCM.TTF");
	levels_text.setFont(font);
	levels_text.setCharacterSize(35);
	levels_text.setFillColor(Color::White);
	levels_text.setPosition(Vector2f(431,290));

	seconds_text.setFont(font);
	seconds_text.setCharacterSize(35);
	seconds_text.setFillColor(Color::White);
	seconds_text.setPosition(Vector2f(681, 224));

	minutes_text.setFont(font);
	minutes_text.setCharacterSize(35);
	minutes_text.setFillColor(Color::White);
	minutes_text.setPosition(Vector2f(595, 224));

	hours_text.setFont(font);
	hours_text.setCharacterSize(35);
	hours_text.setFillColor(Color::White);
	hours_text.setPosition(Vector2f(525, 224));

	minotaurs_text.setFont(font);
	minotaurs_text.setCharacterSize(35);
	minotaurs_text.setFillColor(Color::White);
	minotaurs_text.setPosition(Vector2f(1327, 327));

	dwarfs_text.setFont(font);
	dwarfs_text.setCharacterSize(35);
	dwarfs_text.setFillColor(Color::White);
	dwarfs_text.setPosition(Vector2f(1337, 368));

	archers_text.setFont(font);
	archers_text.setCharacterSize(35);
	archers_text.setFillColor(Color::White);
	archers_text.setPosition(Vector2f(1297, 411));

	knights_text.setFont(font);
	knights_text.setCharacterSize(35);
	knights_text.setFillColor(Color::White);
	knights_text.setPosition(Vector2f(1292, 451));

	snakes_text.setFont(font);
	snakes_text.setCharacterSize(35);
	snakes_text.setFillColor(Color::White);
	snakes_text.setPosition(Vector2f(1269, 494));

	scorpions_text.setFont(font);
	scorpions_text.setCharacterSize(35);
	scorpions_text.setFillColor(Color::White);
	scorpions_text.setPosition(Vector2f(1321, 535));

	rooms_text.setFont(font);
	rooms_text.setCharacterSize(35);
	rooms_text.setFillColor(Color::White);
	rooms_text.setPosition(Vector2f(450, 529));

	potions_text.setFont(font);
	potions_text.setCharacterSize(35);
	potions_text.setFillColor(Color::White);
	potions_text.setPosition(Vector2f(373, 651));

	castle_text.setFont(font);
	castle_text.setCharacterSize(35);
	castle_text.setFillColor(Color::White);
	castle_text.setPosition(Vector2f(459, 325));

	forest_text.setFont(font);
	forest_text.setCharacterSize(35);
	forest_text.setFillColor(Color::White);
	forest_text.setPosition(Vector2f(438, 367));

	desert_text.setFont(font);
	desert_text.setCharacterSize(35);
	desert_text.setFillColor(Color::White);
	desert_text.setPosition(Vector2f(463, 451));

	dungeon_text.setFont(font);
	dungeon_text.setCharacterSize(35);
	dungeon_text.setFillColor(Color::White);
	dungeon_text.setPosition(Vector2f(473, 410));

	chests_text.setFont(font);
	chests_text.setCharacterSize(35);
	chests_text.setFillColor(Color::White);
	chests_text.setPosition(Vector2f(406, 593));

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

void Adventure_Stats::add_castle_level()
{
	castle_levels += 1;
}

void Adventure_Stats::add_forest_level()
{
	forest_levels += 1;
}

void Adventure_Stats::add_desert_level()
{
	desert_levels += 1;
}

void Adventure_Stats::add_dungeon_level()
{
	dungeon_levels += 1;
}

void Adventure_Stats::add_opened_chest()
{
	opened_chests += 1;
}

void Adventure_Stats::add_level()
{
	levels += 1;
}

void Adventure_Stats::setStats()
{
	stats_set = true;
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

int Adventure_Stats::getCastleLevels()
{
	return castle_levels;
}

int Adventure_Stats::getForestLevels()
{
	return forest_levels;
}

int Adventure_Stats::getDesertLevels()
{
	return desert_levels;
}

int Adventure_Stats::getDungeonLevels()
{
	return dungeon_levels;
}

int Adventure_Stats::getOpenedChests()
{
	return opened_chests;
}

int Adventure_Stats::getLevels()
{
	return levels;
}

bool Adventure_Stats::getStatsSet()
{
	return stats_set;
}