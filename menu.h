#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Menu {
	public:
		void drawToWindow(sf::RenderWindow *window);
		Menu();
		~Menu();
	private:
		std::vector<sf::Text *> menuItems;
		sf::Font font;

		sf::Text* createText(std::string stringText, int xPosition);
};
