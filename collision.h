#pragma once
#include "SFML/Graphics.hpp"

namespace Collision {
    enum Orientation {Clockwise, CounterClockwise, Collinear};

    bool shapesIntersect(const sf::Shape* shape1, const sf::Shape* shape2);
    bool linesIntersect(const sf::Vector2f start1, const sf::Vector2f end1, const sf::Vector2f start2, const sf::Vector2f end2);
    Orientation getOrientation(const sf::Vector2f p1, const sf::Vector2f p2, const sf::Vector2f p3);

    bool pointIsInsidePolygon(const sf::Vector2f point, const sf::Shape* polygon);
}
