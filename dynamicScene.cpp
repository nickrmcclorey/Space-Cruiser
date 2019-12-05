#include <vector>
#include "SFML/Graphics.hpp"
#include "dynamicScene.h"
#include "scene.h"
#include "planet.h"
#include <iostream>
#include <random>
#include <string>

void DynamicScene::update(sf::Vector2f position) {
    
    sf::Vector2i newQuadrant((int)position.x, (int)position.y);
    newQuadrant.x /= quadrantWidth;
    newQuadrant.y /= quadrantWidth;
    
    if (position.x < 0) {
        newQuadrant.x--;
    };

    if (position.y < 0) {
        newQuadrant.y--;
    }

    if (newQuadrant != currentQuadrant) {
        std::cout << "spaceship position" << std::endl;
        std::cout << position.x << "," << position.y << std::endl;
        std::cout << newQuadrant.x << "," << newQuadrant.y << std::endl;
        currentQuadrant = newQuadrant;
        refresh();
    }
}

void DynamicScene::reset() {
    refresh();
}

std::vector<Planet> DynamicScene::planetsInQuadrant(sf::Vector2i quadrant) {

    std::minstd_rand0 generator (quadrant.x + quadrant.y * 10);
    // std::uniform_int_distribution<int> numPlanetsGenerator(1, 6);
    std::uniform_int_distribution<int> planetPositioner(1, quadrantWidth);
    // int numPlanets = numPlanetsGenerator(generator);
    

    std::vector<Planet> planets;
    for (int k = 0; k < 10; k++) {
        int x = planetPositioner(generator);
        int y = planetPositioner(generator);
        std::cout << "(" << x << ", " << y << ")" << std::endl;
        Planet planet(x + quadrant.x * quadrantWidth, y + quadrant.y * quadrantWidth, 100);
        planets.push_back(planet);
    }

    return planets;
}

void DynamicScene::refresh() {
    std::cout << "inside" << std::endl << std::endl;
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
