#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

class SpaceShip {
    public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    double rotation = 0;
    
    sf::VertexArray polygon() {
        sf::VertexArray triangle(sf::Triangles, 3);

        double x = cos(3 * M_PI / 2 + rotation) * 20 + position.x;
        double y = sin(3 * M_PI / 2 + rotation) * 20 + position.y;
        triangle[0].position = sf::Vector2f(x, y);

        // bottom right
        x = cos(M_PI / 4 + rotation) * 20 + position.x;
        y = sin(M_PI / 4 + rotation) * 20 + position.y;
        triangle[1].position = sf::Vector2f(x, y);

        // bottom left
        x = cos(3 * M_PI / 4 + rotation) * 20 + position.x;
        y = sin(3 * M_PI / 4 + rotation) * 20 + position.y;
        triangle[2].position = sf::Vector2f(x, y);

        sf::Clock clock;

        return triangle;
    }

};
