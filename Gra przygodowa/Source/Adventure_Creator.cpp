#include "Adventure_Creator.h"

Adventure_Creator::Adventure_Creator(Loading_Screen* loading_screen) 
{ 
	this->loading_screen = loading_screen; 
	floor_type = 0;
	level = 1;
	portal = new Portal();
	last_floor_type = 0;
	srand(time(NULL));
}

Adventure_Creator::~Adventure_Creator(){}

std::vector<Screen*> Adventure_Creator::generate_level(RenderWindow& window, Enemies &cache_enemies)
{
	std::vector<Screen*> adventure_screens;

	while (floor_type == last_floor_type)
		floor_type = rand() % 4 + 1;
	last_floor_type = floor_type;

	int screens_number = 5 + level * 3;

	loading_screen->set_loading(window, float(0), "Generowanie poziomu");
	generate_screens(adventure_screens,screens_number);
	loading_screen->set_loading(window, float(float(1)/float(4)), "Generowanie poziomu");
	place_screens(adventure_screens);
	loading_screen->set_loading(window, float(float(2)/float(4)), "Generowanie poziomu");
	generate_connections(adventure_screens);
	loading_screen->set_loading(window, float(float(3) / float(4)), "Generowanie poziomu");

	switch (floor_type)
	{
		case(1):
			generate_walls_valley(adventure_screens);
			break;
		case(2):
			generate_walls_castle(adventure_screens);
			break;
		case(3):
			generate_walls_dungeons(adventure_screens);
			break;
		case(4):
			generate_walls_desert(adventure_screens);
			break;
	}
	
	loading_screen->set_loading(window, float(1), "Generacja zakonczona");

	std::vector<Screen*> furthest_two = find_two_furthest_screens(adventure_screens);
	furthest_two[0]->setPortal(portal);
	int keyID = generate_door(adventure_screens, furthest_two[0]->getID());
	generate_chests(adventure_screens, furthest_two[1]->getID(), keyID);
	generate_NPCs(adventure_screens);
	generate_enemies(adventure_screens, furthest_two[1]->getID(), furthest_two[0]->getID(), cache_enemies);

	return adventure_screens;
}

std::vector<Screen*> Adventure_Creator::next_lvl(RenderWindow& window, Enemies &cache_enemies)
{
	level++;
	return generate_level(window, cache_enemies);
}

void Adventure_Creator::reset_creator()
{
	level = 1;
	floor_type = 1;
	last_floor_type = 0;
}

void Adventure_Creator::generate_screens(std::vector<Screen*>& screens, int howManyScreens)
{
	for (int i = 0; i < howManyScreens; i++)
		screens.push_back(new Screen(i+1));
}

void Adventure_Creator::place_screens(std::vector<Screen*>& screens)
{
	screens[0]->setPosition(Vector2f(0, 0));
	srand(time(NULL));
	for (int i = 1; i < screens.size(); i++)
	{
		bool next = false;
		while (next != true)
		{
			int x, y;
			x = rand() % 10 - 5;
			y = rand() % 10 - 5;
			Vector2f pos = Vector2f(x, y);
			if (find_screen_by_position(pos, screens) == nullptr)
			{
				if (any_neighbour(pos, screens))
				{
					screens[i]->setPosition(pos);
					next = true;
				}
			}
		}
	}
}

bool Adventure_Creator::any_neighbour(Vector2f pos, std::vector<Screen*>& screens)
{
	for (int i = 0; i < screens.size(); i++)
	{
		if (pos.x == screens[i]->getPosition().x && (pos.y == (screens[i]->getPosition().y + 1) || pos.y == (screens[i]->getPosition().y - 1))) //Neighbour higher or lower
			return true;
		else if (pos.y == screens[i]->getPosition().y && (pos.x == (screens[i]->getPosition().x + 1) || pos.x == (screens[i]->getPosition().x - 1))) //Neighbour right or left
			return true;
	}
	return false;
}

void Adventure_Creator::generate_connections(std::vector<Screen*>& screens)
{
	for (int i = 0; i < screens.size(); i++)
	{
		Screen* temp = nullptr;
		Vector2f pos = Vector2f(screens[i]->getPosition().x + 1, screens[i]->getPosition().y); //Position of neighbour to right
		temp = find_screen_by_position(pos,screens);
		if (temp != nullptr)
			screens[i]->setRight(temp->getID());
		else
			screens[i]->setRight(0);

		temp = nullptr;
		pos = Vector2f(screens[i]->getPosition().x - 1, screens[i]->getPosition().y); //Position of neighbour to left
		temp = find_screen_by_position(pos, screens);
		if (temp != nullptr)
			screens[i]->setLeft(temp->getID());
		else
			screens[i]->setLeft(0);

		temp = nullptr;
		pos = Vector2f(screens[i]->getPosition().x, screens[i]->getPosition().y+1); //Position of neighbour to up
		temp = find_screen_by_position(pos, screens);
		if (temp != nullptr)
			screens[i]->setUp(temp->getID());
		else
			screens[i]->setUp(0);

		temp = nullptr;
		pos = Vector2f(screens[i]->getPosition().x, screens[i]->getPosition().y - 1); //Position of neighbour to down
		temp = find_screen_by_position(pos, screens);
		if (temp != nullptr)
			screens[i]->setDown(temp->getID());
		else
			screens[i]->setDown(0);

		count_connections(screens[i]);
	}
}

void Adventure_Creator::count_connections(Screen* s)
{
	int counter = 0;
	if (s->goDown() != 0)
		counter++;
	if (s->goUp() != 0)
		counter++;
	if (s->goLeft() != 0)
		counter++;
	if (s->goRight() != 0)
		counter++;
	s->setNumberOfConnections(counter);
}

Screen* Adventure_Creator::find_screen_by_position(Vector2f pos, std::vector<Screen*>& screens)
{
	for (int i = 0; i < screens.size(); i++)
		if (screens[i]->getPosition() == pos)
			return screens[i];
	return nullptr;
}

Screen* Adventure_Creator::find_screen_by_ID(int id, std::vector<Screen*>& screens)
{
	for (int i = 0; i < screens.size(); i++)
		if (screens[i]->getID() == id)
			return screens[i];
	return nullptr;
}

void Adventure_Creator::generate_walls_dungeons(std::vector<Screen*>& screens)
{
	std::string pathToBck = "Textures/Backgrounds/Dirt.png";
	std::string pathToFullHorT = "Textures/Walls/Dirt/DirtWallFullHorTop.png";
	std::string pathToFullHorB = "Textures/Walls/Dirt/DirtWallFullHorBottom.png";
	std::string pathToHalfHorLT = "Textures/Walls/Dirt/DirtWallHalfHorLT.png";
	std::string pathToHalfHorLB = "Textures/Walls/Dirt/DirtWallHalfHorLB.png";
	std::string pathToHalfHorRT = "Textures/Walls/Dirt/DirtWallHalfHorRT.png";
	std::string pathToHalfHorRB = "Textures/Walls/Dirt/DirtWallHalfHorRB.png";
	std::string pathToFullVerL = "Textures/Walls/Dirt/DirtWallFullVerL.png";
	std::string pathToFullVerR = "Textures/Walls/Dirt/DirtWallFullVerR.png";
	std::string pathToHalfVerLT = "Textures/Walls/Dirt/DirtWallHalfVerLT.png";
	std::string pathToHalfVerLB = "Textures/Walls/Dirt/DirtWallHalfVerLB.png";
	std::string pathToHalfVerRT = "Textures/Walls/Dirt/DirtWallHalfVerRT.png";
	std::string pathToHalfVerRB = "Textures/Walls/Dirt/DirtWallHalfVerRB.png";

	for (int i = 0; i < screens.size(); i++)
	{
		screens[i]->setBck(pathToBck);

		std::vector<Wall*> walls;

		if (screens[i]->goUp() != 0) //There is a way up
		{
			walls.push_back(new Wall(pathToHalfHorLT, Vector2f(0, 0), Vector2f(750, 124)));
			walls.push_back(new Wall(pathToHalfHorRT, Vector2f(850, 0), Vector2f(750, 124)));
		}
		else //No way up
			walls.push_back(new Wall(pathToFullHorT, Vector2f(0, 0), Vector2f(1600, 124)));

		if (screens[i]->goDown() != 0) //There is a way down
		{
			walls.push_back(new Wall(pathToHalfHorLB, Vector2f(0, 776), Vector2f(750, 124)));
			walls.push_back(new Wall(pathToHalfHorRB, Vector2f(850, 776), Vector2f(750, 124)));
		}
		else //No way down
			walls.push_back(new Wall(pathToFullHorB, Vector2f(0, 776), Vector2f(1600, 124)));

		if (screens[i]->goRight() != 0) //There is a way to right
		{
			walls.push_back(new Wall(pathToHalfVerRT, Vector2f(1476, 0), Vector2f(124, 400)));
			walls.push_back(new Wall(pathToHalfVerRB, Vector2f(1476, 500), Vector2f(124, 400)));
		}
		else //No way to right
			walls.push_back(new Wall(pathToFullVerR, Vector2f(1476, 0), Vector2f(124, 900)));

		if (screens[i]->goLeft() != 0) //There is a way to left
		{
			walls.push_back(new Wall(pathToHalfVerLT, Vector2f(0, 0), Vector2f(124, 400)));
			walls.push_back(new Wall(pathToHalfVerLB, Vector2f(0, 500), Vector2f(124, 400)));
		}
		else //No way to left
			walls.push_back(new Wall(pathToFullVerL, Vector2f(0, 0), Vector2f(124, 900)));

		screens[i]->setWalls(walls);
	}
}

void Adventure_Creator::generate_walls_castle(std::vector<Screen*>& screens)
{
	std::string pathToBck = "Textures/Backgrounds/Stones.png";
	std::string pathToFullHor = "Textures/Walls/Stones/StoneWallFullHor.png";
	std::string pathToHalfHor = "Textures/Walls/Stones/StoneWallHalfHor.png";
	std::string pathToFullVerL = "Textures/Walls/Stones/StoneWallFullVerL.png";
	std::string pathToFullVerR = "Textures/Walls/Stones/StoneWallFullVerR.png";
	std::string pathToHalfVerLT = "Textures/Walls/Stones/StoneWallHalfVerLT.png";
	std::string pathToHalfVerLB = "Textures/Walls/Stones/StoneWallHalfVerLB.png";
	std::string pathToHalfVerRT = "Textures/Walls/Stones/StoneWallHalfVerRT.png";
	std::string pathToHalfVerRB = "Textures/Walls/Stones/StoneWallHalfVerRB.png";

	for (int i = 0; i < screens.size(); i++)
	{
		screens[i]->setBck(pathToBck);

		std::vector<Wall*> walls;

		if (screens[i]->goUp() != 0) //There is a way up
		{
			walls.push_back(new Wall(pathToHalfHor, Vector2f(0, 0), Vector2f(760, 219)));
			walls.push_back(new Wall(pathToHalfHor, Vector2f(840, 0), Vector2f(760, 219)));
		}
		else //No way up
			walls.push_back(new Wall(pathToFullHor, Vector2f(0, 0), Vector2f(1600, 219)));

		if (screens[i]->goDown() != 0) //There is a way down
		{
			walls.push_back(new Wall(pathToHalfHor, Vector2f(0, 681), Vector2f(760, 219)));
			walls.push_back(new Wall(pathToHalfHor, Vector2f(840, 681), Vector2f(760, 219)));
		}
		else //No way down
			walls.push_back(new Wall(pathToFullHor, Vector2f(0, 681), Vector2f(1600, 219)));

		if (screens[i]->goRight() != 0) //There is a way to right
		{
			walls.push_back(new Wall(pathToHalfVerRT, Vector2f(1329, 0), Vector2f(271, 400)));
			walls.push_back(new Wall(pathToHalfVerRB, Vector2f(1329, 500), Vector2f(271, 400)));
		}
		else //No way to right
			walls.push_back(new Wall(pathToFullVerR, Vector2f(1329, 0), Vector2f(271, 900)));

		if (screens[i]->goLeft() != 0) //There is a way to left
		{
			walls.push_back(new Wall(pathToHalfVerLT, Vector2f(0, 0), Vector2f(271, 400)));
			walls.push_back(new Wall(pathToHalfVerLB, Vector2f(0, 500), Vector2f(271, 400)));
		}
		else //No way to left
			walls.push_back(new Wall(pathToFullVerL, Vector2f(0, 0), Vector2f(271, 900)));

		screens[i]->setWalls(walls);
	}
}

void Adventure_Creator::generate_walls_valley(std::vector<Screen*>& screens)
{
	std::string pathToBck = "Textures/Backgrounds/Grass.png";
	std::string pathToFullHor = "Textures/Walls/Trees/TreeFullHor.png";
	std::string pathToHalfHor = "Textures/Walls/Trees/TreeHalfHor.png";
	std::string pathToFullVer = "Textures/Walls/Trees/TreeFullVer.png";
	std::string pathToHalfVer = "Textures/Walls/Trees/TreeHalfVer.png";

	for (int i = 0; i < screens.size(); i++)
	{
		screens[i]->setBck(pathToBck);

		std::vector<Wall*> walls;

		if (screens[i]->goUp() != 0) //There is a way up
		{
			walls.push_back(new Wall(pathToHalfHor, Vector2f(0, 0), Vector2f(760, 113)));
			walls.push_back(new Wall(pathToHalfHor, Vector2f(840, 0), Vector2f(760, 113)));
		}
		else //No way up
			walls.push_back(new Wall(pathToFullHor, Vector2f(0, 0), Vector2f(1600, 113)));

		if (screens[i]->goRight() != 0) //There is a way to right
		{
			walls.push_back(new Wall(pathToHalfVer, Vector2f(1510, 0), Vector2f(90, 400)));
			walls.push_back(new Wall(pathToHalfVer, Vector2f(1510, 500), Vector2f(90, 400)));
		}
		else //No way to right
			walls.push_back(new Wall(pathToFullVer, Vector2f(1510, 0), Vector2f(90, 900)));

		if (screens[i]->goLeft() != 0) //There is a way to left
		{
			walls.push_back(new Wall(pathToHalfVer, Vector2f(0, 0), Vector2f(90, 400)));
			walls.push_back(new Wall(pathToHalfVer, Vector2f(0, 500), Vector2f(90, 400)));
		}
		else //No way to left
			walls.push_back(new Wall(pathToFullVer, Vector2f(0, 0), Vector2f(90, 900)));

		if (screens[i]->goDown() != 0) //There is a way down
		{
			walls.push_back(new Wall(pathToHalfHor, Vector2f(0, 787), Vector2f(760, 113)));
			walls.push_back(new Wall(pathToHalfHor, Vector2f(840, 787), Vector2f(760, 113)));
		}
		else //No way down
			walls.push_back(new Wall(pathToFullHor, Vector2f(0, 787), Vector2f(1600, 113)));

		screens[i]->setWalls(walls);
	}
}

void Adventure_Creator::generate_walls_desert(std::vector<Screen*>& screens)
{
	std::string pathToBck = "Textures/Backgrounds/Sand.png";
	std::string pathToFullHorT = "Textures/Walls/Sand/SandWallFullHorTop.png";
	std::string pathToFullHorB = "Textures/Walls/Sand/SandWallFullHorBottom.png";
	std::string pathToHalfHorLT = "Textures/Walls/Sand/SandWallHalfHorLT.png";
	std::string pathToHalfHorLB = "Textures/Walls/Sand/SandWallHalfHorLB.png";
	std::string pathToHalfHorRT = "Textures/Walls/Sand/SandWallHalfHorRT.png";
	std::string pathToHalfHorRB = "Textures/Walls/Sand/SandWallHalfHorRB.png";
	std::string pathToFullVerL = "Textures/Walls/Sand/SandWallFullVerL.png";
	std::string pathToFullVerR = "Textures/Walls/Sand/SandWallFullVerR.png";
	std::string pathToHalfVerLT = "Textures/Walls/Sand/SandWallHalfVerLT.png";
	std::string pathToHalfVerLB = "Textures/Walls/Sand/SandWallHalfVerLB.png";
	std::string pathToHalfVerRT = "Textures/Walls/Sand/SandWallHalfVerRT.png";
	std::string pathToHalfVerRB = "Textures/Walls/Sand/SandWallHalfVerRB.png";

	for (int i = 0; i < screens.size(); i++)
	{
		screens[i]->setBck(pathToBck);

		std::vector<Wall*> walls;

		if (screens[i]->goUp() != 0) //There is a way up
		{
			walls.push_back(new Wall(pathToHalfHorLT, Vector2f(0, 0), Vector2f(750, 124)));
			walls.push_back(new Wall(pathToHalfHorRT, Vector2f(850, 0), Vector2f(750, 124)));
		}
		else //No way up
			walls.push_back(new Wall(pathToFullHorT, Vector2f(0, 0), Vector2f(1600, 124)));

		if (screens[i]->goDown() != 0) //There is a way down
		{
			walls.push_back(new Wall(pathToHalfHorLB, Vector2f(0, 776), Vector2f(750, 124)));
			walls.push_back(new Wall(pathToHalfHorRB, Vector2f(850, 776), Vector2f(750, 124)));
		}
		else //No way down
			walls.push_back(new Wall(pathToFullHorB, Vector2f(0, 776), Vector2f(1600, 124)));

		if (screens[i]->goRight() != 0) //There is a way to right
		{
			walls.push_back(new Wall(pathToHalfVerRT, Vector2f(1476, 0), Vector2f(124, 400)));
			walls.push_back(new Wall(pathToHalfVerRB, Vector2f(1476, 500), Vector2f(124, 400)));
		}
		else //No way to right
			walls.push_back(new Wall(pathToFullVerR, Vector2f(1476, 0), Vector2f(124, 900)));

		if (screens[i]->goLeft() != 0) //There is a way to left
		{
			walls.push_back(new Wall(pathToHalfVerLT, Vector2f(0, 0), Vector2f(124, 400)));
			walls.push_back(new Wall(pathToHalfVerLB, Vector2f(0, 500), Vector2f(124, 400)));
		}
		else //No way to left
			walls.push_back(new Wall(pathToFullVerL, Vector2f(0, 0), Vector2f(124, 900)));

		screens[i]->setWalls(walls);
	}
}

float Adventure_Creator::getDistance(Vector2f pos1, Vector2f pos2)
{
	return sqrt(((pos1.x - pos2.x) * (pos1.x - pos2.x)) + ((pos1.y - pos2.y) * (pos1.y - pos2.y)));
}

std::vector<Screen*> Adventure_Creator::find_two_furthest_screens(std::vector<Screen*>& screens)
{
	Screen* furthest_screens[2];
	furthest_screens[0] = screens[0];
	furthest_screens[1] = screens[1];
	for (int i = 0; i < screens.size()-1;i++)
	{
		for (int j = i+1; j < screens.size(); j++)
		{
			if (getDistance(furthest_screens[0]->getPosition(), furthest_screens[1]->getPosition()) < getDistance(screens[i]->getPosition(), screens[j]->getPosition()))
			{
				furthest_screens[0] = screens[i];
				furthest_screens[1] = screens[j];
			}
		}
	}
	std::vector<Screen*> furthest;
	furthest.push_back(furthest_screens[0]);
	furthest.push_back(furthest_screens[1]);
	return furthest;
}

int Adventure_Creator::generate_door(std::vector<Screen*>& screens, int ID)
{
	Screen* last = find_screen_by_ID(ID, screens);
	Screen* temp = nullptr;
	Wall* wall;
	Door* door;

	int keyID = rand() % 2 + 2;

	if (last->goLeft() != 0)
	{
		temp = find_screen_by_ID(last->goLeft(), screens);
		wall = new Wall("Textures/Walls/Blank.png", Vector2f(1532,390), Vector2f(60,110));
		door = new Door("Textures/Door/Door.png", wall, keyID);
		temp->walls.push_back(wall);
		temp->doors.push_back(door);
	}

	if (last->goRight() != 0)
	{
		temp = find_screen_by_ID(last->goRight(), screens);
		wall = new Wall("Textures/Walls/Blank.png", Vector2f(0, 390), Vector2f(60, 110));
		door = new Door("Textures/Door/Door.png", wall, keyID);
		temp->walls.push_back(wall);
		temp->doors.push_back(door);
	}

	if (last->goUp() != 0)
	{
		temp = find_screen_by_ID(last->goUp(), screens);
		wall = new Wall("Textures/Walls/Blank.png", Vector2f(770, 790), Vector2f(60, 110));
		door = new Door("Textures/Door/Door.png", wall, keyID);
		temp->walls.push_back(wall);
		temp->doors.push_back(door);
	}

	if (last->goDown() != 0)
	{
		temp = find_screen_by_ID(last->goDown(), screens);
		wall = new Wall("Textures/Walls/Blank.png", Vector2f(770, 0), Vector2f(60, 110));
		door = new Door("Textures/Door/Door.png", wall, keyID);
		temp->walls.push_back(wall);
		temp->doors.push_back(door);
	}

	return keyID;
}

void Adventure_Creator::generate_chests(std::vector<Screen*>& screens, int ScreenID, int keyID)
{
	//Generate the chest with key for door
	std::vector<int> item_ids;
	item_ids.push_back(keyID);
	int howManyPotions = rand() % 3 + 1;
	for(int i=0;i<howManyPotions;i++)
		item_ids.push_back(1);
	Chest* chest = new Chest("Textures/Chests/Chest_closed.png", "Textures/Chests/Chest_open.png", Vector2f(772, 422), Vector2f(56, 56), item_ids);
	Screen* temp = find_screen_by_ID(ScreenID, screens);
	temp->chests.push_back(chest);

	//Generate other chests
	int screen_for_chest = screens.size()-1;
	for (int i = 0; i < (level/2); i++)
	{
		screen_for_chest -= 3;
		if(screen_for_chest==ScreenID)
			screen_for_chest -= 1;
		Screen* temp2 = find_screen_by_ID(screen_for_chest,screens);
		item_ids.erase(item_ids.begin(), item_ids.begin() + item_ids.size() - 1);
		howManyPotions = rand() % 3 + 1;
		for (int i = 0; i < howManyPotions; i++)
			item_ids.push_back(1);
		chest = new Chest("Textures/Chests/Chest_closed.png", "Textures/Chests/Chest_open.png", Vector2f(772, 422), Vector2f(56, 56), item_ids);
		temp2->chests.push_back(chest);
	}
}

void Adventure_Creator::generate_enemies(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies)
{
	switch (floor_type)
	{
	case(1):
		generate_enemies_valley(screens, chestScreenID, lastScreenID, cache_enemies);
		break;
	case(2): //castle
		generate_enemies_castle(screens, chestScreenID, lastScreenID, cache_enemies);
		break;
	case(3): //dungeons
		break;
	case(4): //desert
		generate_enemies_desert(screens, chestScreenID, lastScreenID, cache_enemies);
		break;
	}
}

void Adventure_Creator::generate_enemies_castle(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies &cache_enemies)
{
	int startingScreenID = screens[0]->getID();
	for (int i = 0; i < level * 3 + 1; i++)
	{
		Screen* temp = screens[0];
		if (i == 0)
			temp = screens[chestScreenID-1];
		else
			while (temp->getID() == startingScreenID || temp->getID() == lastScreenID || temp->getID() == chestScreenID || !temp->enemies.is_it_empty())
			{
				int newID = rand() % (5 + level * 3);
				temp = screens[newID];
			}
		int howManyEnemies = 1;
		if (level >= 5)
		{
			howManyEnemies = rand() % 2 + 1;
		}
		for (int i = 0; i < howManyEnemies; i++)
		{
			if (temp->goRight() == 0)
			{
				Enemy* enemy_temp = cache_enemies.getEnemyByName("Archer");
				Enemy* new_enemy = new Enemy(enemy_temp, Vector2f(1450, 50 + i * 300));
				temp->enemies.add_enemy(new_enemy);
			}
			else if (temp->goLeft() == 0)
			{
				Enemy* enemy_temp = cache_enemies.getEnemyByName("Archer");
				Enemy* new_enemy = new Enemy(enemy_temp, Vector2f(80, 50 + i * 300));
				temp->enemies.add_enemy(new_enemy);
			}
			else 
			{
				Enemy* enemy_temp = cache_enemies.getEnemyByName("Knight");
				Enemy* new_enemy = new Enemy(enemy_temp, Vector2f(760, 350 + i * 100));
				temp->enemies.add_enemy(new_enemy);
			}
		}
	}
}

void Adventure_Creator::generate_enemies_valley(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies)
{
	int startingScreenID = screens[0]->getID();
	for (int i = 0; i < level * 3 + 1; i++)
	{
		Screen* temp = screens[0];
		if (i == 0)
			temp = screens[chestScreenID - 1];
		else
			while (temp->getID() == startingScreenID || temp->getID() == lastScreenID || temp->getID() == chestScreenID || !temp->enemies.is_it_empty())
			{
				int newID = rand() % (5 + level * 3);
				temp = screens[newID];
			}
		int howManyEnemies = 1;
		if (level >= 5)
		{
			howManyEnemies = rand() % 2 + 1;
		}
		for (int i = 0; i < howManyEnemies; i++)
		{
			int enemyType = rand() % 2;
			if (enemyType == 0)
			{
				Enemy* enemy_temp = cache_enemies.getEnemyByName("Minotaur");
				Enemy* new_enemy = new Enemy(enemy_temp, Vector2f(600 + i * 150, 400));
				temp->enemies.add_enemy(new_enemy);
			}
			else
			{
				Enemy* enemy_temp = cache_enemies.getEnemyByName("Dwarf");
				Enemy* new_enemy = new Enemy(enemy_temp, Vector2f(600 + i * 150, 400));
				temp->enemies.add_enemy(new_enemy);
			}
		}
	}
}

void Adventure_Creator::generate_enemies_desert(std::vector<Screen*>& screens, int chestScreenID, int lastScreenID, Enemies& cache_enemies)
{
	int startingScreenID = screens[0]->getID();
	for (int i = 0; i < level * 3 + 1; i++)
	{
		Screen* temp = screens[0];
		if (i == 0)
			temp = screens[chestScreenID - 1];
		else
			while (temp->getID() == startingScreenID || temp->getID() == lastScreenID || temp->getID() == chestScreenID || !temp->enemies.is_it_empty())
			{
				int newID = rand() % (5 + level * 3);
				temp = screens[newID];
			}
		int howManyEnemies = 1;
		if (level >= 5)
		{
			howManyEnemies = rand() % 2 + 1;
		}
		for (int i = 0; i < howManyEnemies; i++)
		{
			int enemyType = rand() % 2;
			if (enemyType == 0)
			{
				Enemy* enemy_temp = cache_enemies.getEnemyByName("Snake");
				Enemy* new_enemy = new Enemy(enemy_temp, Vector2f(600 + i * 150, 400));
				temp->enemies.add_enemy(new_enemy);
			}
			else
			{
				Enemy* enemy_temp = cache_enemies.getEnemyByName("Scorpion");
				Enemy* new_enemy = new Enemy(enemy_temp, Vector2f(600 + i * 150, 400));
				temp->enemies.add_enemy(new_enemy);
			}
		}
	}
}

void Adventure_Creator::generate_NPCs(std::vector<Screen*>& screens)
{
	int screen = rand() % ((level * 3) + 5);
	int npc_id = rand() % 3 + 1;
	NPCs npcs;
	Vector2f npc_position = Vector2f(600, 400);
	Vector2f wall_position = Vector2f(605, 404);
	Vector2f wall_size = Vector2f(69, 80);
	screens[screen]->walls.push_back(new Wall("Textures/NPCs/Sunbro/WALL.png", wall_position, wall_size));
	std::string name;

	switch (npc_id)
	{
	case(1):
		name = "Sunbro_Advice_1";
		break;
	case(2):
		name = "Sunbro_Advice_2";
		break;
	case(3):
		name = "Sunbro_Advice_3";
		break;
	}

	screens[screen]->npcs.add_npc(name, npc_position);
}