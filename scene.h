#pragma once
#include <mutex>
#include <vector>
#include "planet.h"
#include "spaceship.h"
#include <list>
#include "astroid.h"
#include "controls/IControls.h"

class Scene {
    public:
        Spaceship spaceship;
		std::vector<Spaceship> spaceships;
        std::vector<Planet> planets;
        std::vector<Astroid> astroids;
        std::mutex astroidMutex;

        virtual void reset();
        virtual void update(int secondsEllapsed);
        virtual void addAstroid() = 0;
        void drawToWindow(sf::RenderWindow* window);
		void addSpaceship(Spaceship ship);
        Scene();

    protected:
        void updateSpaceship(int secondsEllapsed);
        void updateAstroids(int time);
};
