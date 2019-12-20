#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>
#include <math.h>

class Astroid {
    public:
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::ConvexShape shape;
        double rotation;
        const int pointCount = 8;

        sf::ConvexShape getShape() {
            return shape;
        }

        Astroid() {
            shape.setPointCount(pointCount);
            std::minstd_rand0 generator(time(0));
            std::uniform_int_distribution<int> distanceDistribution(5, 25);

            for (int k = 0; k < pointCount; k++) {
                double theta = 2 * M_PI / pointCount * k;
                int distance = distanceDistribution(generator);
                double y = sin(theta) * distance;
                double x = cos(theta) * distance;
                shape.setPoint(k, sf::Vector2f(x, y));
            }
        }
};
