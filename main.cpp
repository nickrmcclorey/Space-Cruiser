#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "scene.h"
#include "gameManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Cruiser");
    space::GameManager Game;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // GameManager.updateScene(20);
        // GameManager.drawScene(&window);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
