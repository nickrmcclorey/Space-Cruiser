#pragma once
#include <SFML/Graphics.hpp>

class Planet {
    public:
    sf::Vector2f position;
    int radius;
    double mass;
    sf::Color color;
    const double gravityStrength = 0.05;

    Planet(int x, int y, int rad) {
        position.x = x;
        position.y = y;
        radius = rad;
        mass = radius;
        color = sf::Color::Black;
    }

    Planet(int x, int y, int rad, sf::Color planetColor) {
        position.x = x;
        position.y = y;
        radius = rad;
        mass = radius;
        color = planetColor;
    }
};
