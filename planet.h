#pragma once
#include <SFML/Graphics.hpp>

class Planet {
    public:
    int xPosition;
    int yPosition;
    int radius;
    double mass;
    sf::Color color;
    const double gravityStrength = 0.05;

    Planet(int x, int y, int rad) {
        xPosition = x;
        yPosition = y;
        radius = rad;
        mass = radius;
        color = sf::Color::Black;
    }

    Planet(int x, int y, int rad, sf::Color planetColor) {
        xPosition = x;
        yPosition = y;
        radius = rad;
        mass = radius;
        color = planetColor;
    }
};
