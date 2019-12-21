#pragma once
#include <vector>
#include "scene.h"
#include "planet.h"
#include "SFML/Graphics.hpp"


class DynamicScene : public Scene {
    public:
        virtual void update(int secondsEllapsed);
        virtual void reset();
    private:
        const int quadrantWidth = 2000;
        sf::Vector2i currentQuadrant;
        std::vector<Planet> planetsInQuadrant(sf::Vector2i quadrant);
        void refresh();

};