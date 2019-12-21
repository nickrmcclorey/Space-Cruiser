#include "menu.h"
#include <string>
#include <SFML/Graphics.hpp>

sf::Text* Menu::createText(std::string stringText, int xPosition) {
    sf::Text *text = new sf::Text(stringText, font);
    text->setFillColor(sf::Color::Black);
    text->setPosition(xPosition, 5);
    text->setScale(0.6, 0.6);

    return text;
}

void Menu::drawToWindow(sf::RenderWindow *window) {
    sf::RectangleShape menuBar;
    menuBar.setPosition(0, 0);
    menuBar.setSize(sf::Vector2f(1920, 30));
    menuBar.setFillColor(sf::Color::White);
    sf::Text text;
    text.setFillColor(sf::Color::Black);
    text.setString("Restart");
    text.setFont(font);
    text.setScale(0.6, 0.6);
    text.setPosition(5, 5);
    window->draw(menuBar);
    window->draw(*menuItems[0]);

}

Menu::Menu() {
    if (!font.loadFromFile("hack.ttf")) {
        std::string errorMessage = "Failed to load ttf file. :(";
        throw errorMessage;
    }

    menuItems.push_back(createText("Restart", 5));
}

Menu::~Menu() {
    for (int k = 0; k < menuItems.size(); k++) {
        delete menuItems[k];
    }
}
