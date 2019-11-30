#pragma once
#include <vector>
#include "planet.h"
#include "spaceship.h"

class Scene {
    public:
    double gravity;
    SpaceShip spaceShip;
    std::vector<Planet> planets;

    virtual void reset();
    virtual void update(sf::Vector2f position);
    Scene();
};
