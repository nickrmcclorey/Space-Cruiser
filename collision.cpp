#include "SFML/Graphics.hpp"
#include "collision.h"
#include "math.h"

namespace Collision {

    bool pointIsInsidePolygon(const sf::Vector2f point, const sf::Shape& polygon) {
        
        float maxX = polygon.getPoint(0).x;
        for (int k = 1; k < polygon.getPointCount(); k++) {
            maxX = std::max(maxX, polygon.getPoint(k).x + polygon.getPosition().x);
        }

        maxX += 1;
        sf::Vector2f pointOutsidePolygon(maxX, 0);
        int intersectionCount = 0;

        for (int k = 0; k < polygon.getPointCount(); k++) {
            auto start = polygon.getPoint(k % polygon.getPointCount()) + polygon.getPosition();
            auto end = polygon.getPoint((k + 1) % polygon.getPointCount()) + polygon.getPosition();

            if (linesIntersect(point, pointOutsidePolygon, start, end)) {
                intersectionCount++;
            }
        }

        return (intersectionCount % 2 == 1);
    }

    bool shapesIntersect(const sf::Shape& shape1, const sf::Shape& shape2) {
        for (int k1 = 0; k1 < shape1.getPointCount(); k1++) {
            auto start1 = shape1.getPoint(k1 % shape1.getPointCount()) + shape1.getPosition();
            auto end1 = shape1.getPoint((k1 + 1) % shape1.getPointCount()) + shape1.getPosition();

            for (int k2 = 0; k2 < shape2.getPointCount(); k2++) {
                auto start2 = shape2.getPoint(k2 % shape2.getPointCount()) + shape2.getPosition();
                auto end2 = shape2.getPoint((k2 + 1) % shape2.getPointCount()) + shape2.getPosition();

                if (linesIntersect(start1, end1, start2, end2)) {
                    return true;
                }
            }
        }

        // return pointIsInsidePolygon(shape1.getPoint(0), shape2);
        return false;
    }

    bool linesIntersect(const sf::Vector2f start1, const sf::Vector2f end1, const sf::Vector2f start2, const sf::Vector2f end2) {
        if (getOrientation(start1, end1, start2) != getOrientation(start1, end1, end2)
             && getOrientation(start2, end2, start1) != getOrientation(start2, end2, end1)) {
                    // std::cout << "start1: (" << start1.x << ", " << start1.y << ")" << std::endl;
                    // std::cout << "end1: (" << end1.x << ", " << end1.y << ")" << std::endl;
                    // std::cout << "start2: (" << start2.x << ", " << start2.y << ")" << std::endl;
                    // std::cout << "end2: (" << end2.x << ", " << end2.y << ")\n" << std::endl;
                    // std::cout << "getOrientation(start1, end1, start2): " << getOrientation(start1, end1, start2) << std::endl;
                    // std::cout << "getOrientation(start1, end1, end2): " << getOrientation(start1, end1, end2) << std::endl;
                    // std::cout << "getOrientation(start2, end2, start1): " << getOrientation(start2, end2, start1) << std::endl;
                    // std::cout << "getOrientation(start2, end2, end2): " << getOrientation(start2, end2, end1) << std::endl;
                    return true;
        }
        return false;
    }

    // https://www.geeksforgeeks.org/orientation-3-ordered-points/
    Orientation getOrientation(const sf::Vector2f p1, const sf::Vector2f p2, const sf::Vector2f p3) {
        
        double value = (p2.y - p1.y)*(p3.x - p2.x) - (p3.y - p2.y)*(p2.x - p1.x);

        if (value == 0.f) {
            return Orientation::Collinear;
        } else if (value > 0) {
            return Orientation::Clockwise;
        } else {
            return Orientation::CounterClockwise;
        }
    }

    bool shapeIntersectsCircle(const sf::Shape& polygon, const sf::Vector2f centerOfCircle, const double radius) {
        for (int k = 0; k < polygon.getPointCount(); k++) {
            auto point = polygon.getPoint(k) + polygon.getPosition();
            if (distanceBetween(point, centerOfCircle) < radius) {
                return true;
            }
        }

        return false;
    }


}
