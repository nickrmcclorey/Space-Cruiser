#include "menu.h"
#include <string>
#include <SFML/Graphics.hpp>

sf::Text Menu::createText(const sf::Font font, std::string stringText, int xPosition) {
    sf::Text text;
    text.setFillColor(sf::Color::White);
    text.setString(stringText);
    text.setFont(font);
    text.setPosition(xPosition, 5);
    return text;
}

void Menu::draw(sf::RenderWindow *window) {
    sf::Text text;
    text.setFillColor(sf::Color::White);
    text.setString("Restart");
    text.setFont(font);
    text.setPosition(5, 5);
    window->draw(text);
}

Menu::Menu() {
    if (!font.loadFromFile("college.ttf")) {
        std::string errorMessage = "Failed to load ttf file. :(";
        throw errorMessage;
    }

    menuItems.push_back(createText(font, "Restart", 5));
}
