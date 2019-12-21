#pragma once
#include <vector>
#include "planet.h"
#include "spaceship.h"
#include <list>
#include "astroid.h"

class Scene {
    public:
        SpaceShip spaceShip;
        std::vector<Planet> planets;
        std::list<Astroid> astroids;

        virtual void reset();
        virtual void update(int secondsEllapsed);
        void drawToWindow(sf::RenderWindow* window);
        Scene();

    protected:
        void updateSpaceShip(int secondsEllapsed);
};
