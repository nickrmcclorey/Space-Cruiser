#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "gameManager.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Cruiser");
    space::GameManager gameManager;
    gameManager.scene.spaceShip.position = sf::Vector2f(600, 600);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        int sleepTime = 1000/60;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        gameManager.updateScene(sleepTime);
        gameManager.drawScene(&window);

    }

    return 0;
}
