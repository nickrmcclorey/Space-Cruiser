#include <SFML/Graphics.hpp>
#include <vector>

class Menu {
	public:
		void draw(sf::RenderWindow *window);
		Menu();
	private:
		std::vector<sf::Text> menuItems;
		sf::Font font;

		sf::Text createText(const sf::Font font, std::string stringText, int xPosition);
};
