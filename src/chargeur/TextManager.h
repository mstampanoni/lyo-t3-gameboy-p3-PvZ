#pragma once
#include <SFML/Graphics.hpp>


class TextManager
{
public:
	TextManager();

	static TextManager* instantiate();
	static TextManager* getInstance();
	void initText();

	sf::Text text;

private:
	sf::Font font;
};
