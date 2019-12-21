#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <thread>
#include <string>
#include <chrono>
#include "gameManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Cruiser");
    space::GameManager gameManager;
    sf::Clock clock;
    clock.restart();

    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        const int sleepTime = 1000/60;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        gameManager.updateScene(clock.getElapsedTime().asMilliseconds());
        gameManager.drawToWindow(&window);

        clock.restart();
    }

    return 0;
}
