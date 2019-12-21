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
        std::vector<Astroid> astroids;

        virtual void reset();
        virtual void update(int secondsEllapsed);
        virtual void addAstroid() = 0;
        void drawToWindow(sf::RenderWindow* window);
        Scene();

    protected:
        void updateSpaceShip(int secondsEllapsed);
        void updateAstroids(int time);
};
