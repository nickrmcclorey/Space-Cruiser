#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "scene.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Cruiser");
    sf::CircleShape shape(70);
    shape.setFillColor(sf::Color::Magenta);
    shape.setPosition(50, 50);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        shape.move(40, 40);
    }

    return 0;
}
