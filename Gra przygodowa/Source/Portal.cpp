#include "Portal.h"

Portal::Portal()
{
	tex.loadFromFile("Textures/Portal/Portal.png");
	sp.setTexture(tex);
	sp.setPosition(Vector2f(740,380));

	sb.loadFromFile("Sounds/Portal.wav");
	sound.setBuffer(sb);
}

void Portal::displayPortal(RenderWindow& window)
{
	window.draw(sp);
}

void Portal::playSound()
{
	sound.play();
}

bool Portal::doesPlayerCollide(RectangleShape players_hitbox)
{
	if (players_hitbox.getGlobalBounds().intersects(sp.getGlobalBounds()))
		return true;
	else
		return false;
}