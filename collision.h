#pragma once
#include "SFML/Graphics.hpp"

#define getDistanceSquared(pos1, pos2) (pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2))

#define distanceBetween(pos1, pos2) (sqrt(getDistanceSquared(pos1, pos2)))

namespace Collision {
    enum Orientation {Clockwise, CounterClockwise, Collinear};

    bool shapesIntersect(const sf::Shape& shape1, const sf::Shape& shape2);
    bool linesIntersect(const sf::Vector2f start1, const sf::Vector2f end1, const sf::Vector2f start2, const sf::Vector2f end2);
    Orientation getOrientation(const sf::Vector2f p1, const sf::Vector2f p2, const sf::Vector2f p3);
    bool pointIsInsidePolygon(const sf::Vector2f point, const sf::Shape& polygon);
    bool shapeIntersectsCircle(const sf::Shape& shape1, const sf::Vector2f centerOfCircle, double radius);
}
