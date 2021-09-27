#ifndef SCREEN_H
#define SCREEN_H

#include "Background.h"
#include "C_Objects.h"
#include "Characters.h"
#include "Portal.h"

class Screen : public Background,public C_Objects,public Characters
{
    public:
        Screen(std::string info_file);
        Screen( int id );
        virtual ~Screen();
        
        void displayScreen(RenderWindow &window);

        Chest* check_chests(RectangleShape players_hitbox);
        Door* check_doors(RectangleShape players_hitbox);
        bool check_portal(RectangleShape players_hitbox);
        bool has_portal() { return !(portal == nullptr); }
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

        Vector2f getPosition() { return position; }
        void setPosition(Vector2f pos) { position = pos; }

        bool isVisited() { return visited; }
        void setVisited(bool v) { visited = v; }

        Portal* getPortal() { return portal; }
        void setPortal(Portal* p) { portal = p; }

    private:
        int ID,leftID,rightID,upID,downID,howManyConnections,removed;
        bool visited;
        Vector2f position;
        Portal* portal;
};

#endif // SCREEN_H
