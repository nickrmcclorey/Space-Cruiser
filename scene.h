#pragma once
#include <vector>
#include "planet.h"
#include "spaceship.h"
#include <list>
#include "astroid.h"

class Scene {
    public:
        double gravity;
        SpaceShip spaceShip;
        std::vector<Planet> planets;
        std::list<Astroid> astroids;

        virtual void reset();
        virtual void update(sf::Vector2f position);
        Scene();
};
