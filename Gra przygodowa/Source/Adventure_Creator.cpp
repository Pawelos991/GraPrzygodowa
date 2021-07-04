#include "Adventure_Creator.h"

Adventure_Creator::Adventure_Creator(Loading_Screen* loading_screen) { this->loading_screen = loading_screen; adventure_phase = 1; }

Adventure_Creator::~Adventure_Creator(){}

std::vector<Screen*> Adventure_Creator::generate_adventure(RenderWindow& window)
{
	std::vector<Screen*> adventure_screens;

	loading_screen->set_loading(window, float(0), "Generowanie przygody");
	generate_screens(adventure_screens);
	loading_screen->set_loading(window, float(float(1)/float(4)), "Generowanie przygody");
	place_screens(adventure_screens);
	loading_screen->set_loading(window, float(float(2)/float(4)), "Generowanie przygody");
	generate_connections(adventure_screens);
	loading_screen->set_loading(window, float(float(3) / float(4)), "Generowanie przygody");
	//generate_walls_castle(adventure_screens);
	generate_walls_valley(adventure_screens);
	loading_screen->set_loading(window, float(1), "Generacja zakonczona");

	return adventure_screens;
}

void Adventure_Creator::generate_screens(std::vector<Screen*>& screens)
{
	for (int i = 0; i < 10; i++)
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
	for (int i = 0; i < screens.size(); i++)
	{

	}
}

void Adventure_Creator::generate_walls_castle(std::vector<Screen*>& screens)
{
	std::string pathToBck = "Textures/Backgrounds/Stones.png";
	std::string pathToFullHor = "Textures/Walls/StoneWallFullHor.png";
	std::string pathToHalfHor = "Textures/Walls/StoneWallHalfHor.png";
	std::string pathToFullVerL = "Textures/Walls/StoneWallFullVerL.png";
	std::string pathToFullVerR = "Textures/Walls/StoneWallFullVerR.png";
	std::string pathToHalfVerLT = "Textures/Walls/StoneWallHalfVerLT.png";
	std::string pathToHalfVerLB = "Textures/Walls/StoneWallHalfVerLB.png";
	std::string pathToHalfVerRT = "Textures/Walls/StoneWallHalfVerRT.png";
	std::string pathToHalfVerRB = "Textures/Walls/StoneWallHalfVerRB.png";

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
	std::string pathToFullHor = "Textures/Walls/TreeFullHor.png";
	std::string pathToHalfHor = "Textures/Walls/TreeHalfHor.png";
	std::string pathToFullVer = "Textures/Walls/TreeFullVer.png";
	std::string pathToHalfVer = "Textures/Walls/TreeHalfVer.png";

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