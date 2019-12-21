#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>
#include <math.h>

class Astroid : public sf::ConvexShape {
    public:
        const int pointCount = 8;
        sf::Vector2f velocity;

        Astroid () : sf::ConvexShape () {
            setPointCount(pointCount);
            std::minstd_rand0 generator(time(0));
            std::uniform_int_distribution<int> distanceDistribution(5, 25);

            for (int k = 0; k < pointCount; k++) {
                double theta = 2 * M_PI / pointCount * k;
                int distance = distanceDistribution(generator);
                double y = sin(theta) * distance;
                double x = cos(theta) * distance;
                setPoint(k, sf::Vector2f(x, y));
            }
        }

};
