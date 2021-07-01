#include "Loading_Screen.h"

Loading_Screen::Loading_Screen()
{
	background_texture.loadFromFile("Textures/Backgrounds/Loading.png");
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(Vector2f(0, 0));
	loading_bar.setFillColor(Color::Blue);
	loading_bar.setPosition(Vector2f(123, 376));
	font.loadFromFile("Fonts/Arial.ttf");
	text.setFont(font);
	text.setCharacterSize(70);
	text.setFillColor(Color::White);
	/*text.setOutlineThickness(5);
	text.setOutlineColor(Color::Black);*/
	text.setPosition(Vector2f(300,600));
}

Loading_Screen::~Loading_Screen(){}

void Loading_Screen::start_loading(RenderWindow& window)
{
	window.clear(Color::White);
	window.draw(background_sprite);
	loading_bar.setSize(Vector2f(0, 0));
	window.draw(loading_bar);
	window.display();
}

void Loading_Screen::set_loading(RenderWindow& window, float perc, std::string message)
{
	window.clear(Color::White);
	window.draw(background_sprite);
	loading_bar.setSize(Vector2f(1367*perc, 103));
	window.draw(loading_bar);
	text.setString(message);
	window.draw(text);
	window.display();
}