#include <vector>
#include "SFML/Graphics.hpp"
#include "dynamicScene.h"
#include "scene.h"
#include "planet.h"
#include <random>
#include <math.h>
#include "astroid.h"

void DynamicScene::update(int secondsEllapsed) {
    updateSpaceShip(secondsEllapsed);

    sf::Vector2i newQuadrant((int)spaceShip.position.x, (int)spaceShip.position.y);
    newQuadrant.x /= quadrantWidth;
    newQuadrant.y /= quadrantWidth;
    
    if (spaceShip.position.x < 0) {
        newQuadrant.x--;
    };

    if (spaceShip.position.y < 0) {
        newQuadrant.y--;
    }

    if (newQuadrant != currentQuadrant) {
        currentQuadrant = newQuadrant;
        refresh();
    }
}

void DynamicScene::reset() {
    refresh();
    Astroid astroid;
    astroid.setPosition(20, 20);
    astroids.push_back(astroid);
    spaceShip.position = sf::Vector2f(0, 0);
    spaceShip.velocity = sf::Vector2f(0, 0);
}

bool planetsIntersect(Planet planet, std::vector<Planet> planetList) {
    for (Planet sample : planetList) {
        auto distance = sample.position - planet.position;
        auto minimumDistance = planet.radius + sample.radius;
        if (sqrt(pow(distance.x, 2) + pow(distance.y, 2)) < minimumDistance) {
            return true;
        }
    }

    return false;
}

std::vector<Planet> DynamicScene::planetsInQuadrant(sf::Vector2i quadrant) {

    std::minstd_rand0 generator (quadrant.x + quadrant.y * 10);
    std::uniform_int_distribution<int> planetPositioner(1, quadrantWidth);
    std::normal_distribution<float> planetSize(100, 20);

    std::vector<Planet> planets;
    for (int k = 0; k < 7; k++) {
        int x = planetPositioner(generator);
        int y = planetPositioner(generator);
        int size = planetSize(generator);
        Planet planet(x + quadrant.x * quadrantWidth, y + quadrant.y * quadrantWidth, size);
        if (!planetsIntersect(planet, planets)) {
            planets.push_back(planet);
        }
    }

    return planets;
}


void DynamicScene::refresh() {
    planets.clear();
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            sf::Vector2i quad(row - 1, col - 1);
            std::vector<Planet> planetsInQuad = planetsInQuadrant(currentQuadrant + quad);
            for (Planet planet : planetsInQuad) {
                planets.push_back(planet);
            }
        }
    }

}
