#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

class Spaceship {
    public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    double rotation = 0;
    bool destroyed = false;
    
    sf::ConvexShape polygon() {
        sf::ConvexShape triangle;
        triangle.setPointCount(3);

        double x = cos(3 * M_PI / 2 + rotation) * 20 + position.x;
        double y = sin(3 * M_PI / 2 + rotation) * 20 + position.y;
        triangle.setPoint(0, sf::Vector2f(x, y));

        // bottom right
        x = cos(M_PI / 4 + rotation) * 20 + position.x;
        y = sin(M_PI / 4 + rotation) * 20 + position.y;
        triangle.setPoint(1, sf::Vector2f(x, y));

        // bottom left
        x = cos(3 * M_PI / 4 + rotation) * 20 + position.x;
        y = sin(3 * M_PI / 4 + rotation) * 20 + position.y;
        triangle.setPoint(2, sf::Vector2f(x, y));

        sf::Clock clock;

        return triangle;
    }

};
