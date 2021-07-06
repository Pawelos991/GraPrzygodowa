#ifndef PORTAL_H
#define PORTAL_H

#include "Wall.h"

class Portal 
{
	public:
		Portal();
		~Portal(){}
		void displayPortal(RenderWindow& window);
		void playSound();
		bool doesPlayerCollide(RectangleShape players_hitbox);

	private:
		Sound sound;
		SoundBuffer sb;
		Texture tex;
		Sprite sp;

};

#endif //PORTAL_H