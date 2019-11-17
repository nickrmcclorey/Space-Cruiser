#include <SFML/Graphics.hpp>
#include <math.h>

class SpaceShip {
    public:
    double xPosition = 0;
    double yPosition = 0;
    double xVelocity = 0;
    double yVelocity = 0;
    double rotation = 0;
    
    sf::VertexArray polygon() {
        sf::VertexArray triangle(sf::Triangles, 3);

        double x = cos(3 * M_PI / 2 + rotation) * 20 + xPosition;
        double y = sin(3 * M_PI / 2 + rotation) * 20 + yPosition;
        triangle[0].position = sf::Vector2f(x, y);

        // bottom right
        x = cos(M_PI / 4 + rotation) * 20 + xPosition;
        y = sin(M_PI / 4 + rotation) * 20 + yPosition;
        triangle[1].position = sf::Vector2f(x, y);

        // bottom left
        x = cos(3 * M_PI / 4 + rotation) * 20 + xPosition;
        y = sin(3 * M_PI / 4 + rotation) * 20 + yPosition;
        triangle[2].position = sf::Vector2f(x, y);

        return triangle;
    }
};
