#include <vector>
#include <math.h>
#include "SFML/Graphics.hpp"
#include "dynamicScene.h"
#include "scene.h"
#include "planet.h"
#include <random>
#include "astroid.h"

void DynamicScene::update(int secondsEllapsed) {
    updateSpaceship(secondsEllapsed);
    updateAstroids(secondsEllapsed);

    sf::Vector2i newQuadrant((int)spaceship.position.x, (int)spaceship.position.y);
    newQuadrant.x /= quadrantWidth;
    newQuadrant.y /= quadrantWidth;
    
    if (spaceship.position.x < 0) {
        newQuadrant.x--;
    };

    if (spaceship.position.y < 0) {
        newQuadrant.y--;
    }

    if (newQuadrant != currentQuadrant) {
        currentQuadrant = newQuadrant;
        refresh();
    }

    updateAstroids(secondsEllapsed);
    // astroids that wander too far from the spaceship.position get deleted
    astroidMutex.lock();
    for (int k = 0; k < astroids.size(); k++) {
        auto distance = spaceship.position - astroids[k].getPosition();
        if (abs(distance.x) > quadrantWidth * 3 / 2 || abs(distance.y) > quadrantWidth * 3 / 2) {
            astroids.erase(astroids.begin() + k);
            k--;
        }
    }
    astroidMutex.unlock();
}

void DynamicScene::reset() {
    refresh();
    astroidMutex.lock();
    astroids.clear();
    astroidMutex.unlock();
    spaceship.position = sf::Vector2f(0, 0);
    spaceship.velocity = sf::Vector2f(0, 0);
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

void DynamicScene::addAstroid() {
    static std::minstd_rand0 generator;
    std::uniform_int_distribution<int> uniformDist(0, 500);
    std::normal_distribution<float> normalDist(0.f, 0.5);

    Astroid astroid;
    int x = uniformDist(generator) + (quadrantWidth / 2);
    int y = uniformDist(generator) + (quadrantWidth / 2);
    x *= (x % 2 == 0) ? 1 : -1;
    y *= (y % 2 == 0) ? 1 : -1;
    astroid.setPosition(x, y);
    astroid.move(spaceship.position);

    auto distance = spaceship.position - astroid.getPosition();
    sf::Vector2f velocity(normalDist(generator), normalDist(generator));
    velocity.x = (distance.x > 0) ? abs(velocity.x) : -1 * abs(velocity.x);
    velocity.y = (distance.y > 0) ? abs(velocity.y) : -1 * abs(velocity.y);
    astroid.velocity = velocity;

    astroidMutex.lock();
    astroids.push_back(astroid);
    astroidMutex.unlock();
}
