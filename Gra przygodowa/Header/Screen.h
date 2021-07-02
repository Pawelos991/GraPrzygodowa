#ifndef SCREEN_H
#define SCREEN_H

#include "Background.h"
#include "C_Objects.h"
#include "Characters.h"

class Screen : public Background,public C_Objects,public Characters
{
    public:
        Screen(std::string info_file);
        Screen( int id );
        virtual ~Screen();
        
        void displayScreen(RenderWindow &window);

        Chest* check_chests(RectangleShape players_hitbox);
        Door* check_doors(RectangleShape players_hitbox);
        Missiles player_missiles;
        Missiles enemies_missiles;
        void clear_space();

        //Setters and getters
        int getID() { return ID; }
        void setID(int id) { ID = id; }

        int goRight() { return rightID; }
        void setRight(int r) { rightID = r; }

        int goLeft() { return leftID; }
        void setLeft(int l) { leftID = l; }

        int goUp() { return upID; }
        void setUp(int u) { upID = u; }

        int goDown() { return downID; }
        void setDown(int d) { downID = d; }

        int getNumberOfConnections() { return howManyConnections; }
        void setNumberOfConnections(int n) { howManyConnections = n; }

        int is_removed() { return removed; }
        void set_removed(bool rm) { removed = rm; }

        Sprite getBck() { return Bck; }
        void setBck(std::string pathToBck) { pic.loadFromFile(pathToBck); Bck.setTexture(pic); }

        std::vector<NC_Object*> get_NC_Objects() { return NC_Objects; }
        void set_NC_Objects(std::vector<NC_Object*>& nc) { NC_Objects = nc; }

        std::vector<Wall*> getWalls() { return walls; }
        void setWalls(std::vector<Wall*>& w) { walls = w; }

        std::vector<Door*> getDoors() { return doors; }
        void setDoors(std::vector<Door*>& d) { doors = d; }

        std::vector<Chest*> getChests() { return chests; }
        void setChests(std::vector<Chest*>& c) { chests = c; }

        Enemies getEnemies() { return enemies; }
        void setEnemies(Enemies& e) { enemies = e; }

        NPCs getNPCs() { return npcs; }
        void setNPCs(NPCs& n) { npcs = n; }

        Vector2f getPosition() { return position; }
        void setPosition(Vector2f pos) { position = pos; }

    private:
        int ID,leftID,rightID,upID,downID,howManyConnections,removed;
        Vector2f position;
};

#endif // SCREEN_H
