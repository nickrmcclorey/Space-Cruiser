#include <vector>
#include "SFML/Graphics.hpp"
#include "dynamicScene.h"
#include "scene.h"
#include "planet.h"

void DynamicScene::updateQuadrant(sf::Vector2f position) {
    
    sf::Vector2i newQuadrant((int)position.x, (int)position.y);
    newQuadrant.x /= 2000;
    newQuadrant.y /= 2000;

    if (newQuadrant != currentQuadrant) {
        currentQuadrant = newQuadrant;
        refresh();
    }
}

void DynamicScene::reset() {
    
    // for (int row = 0; row < 3; row++) {
    //     for (int col = 0; col < 3; col++) {
    //         quadrants[row][col].clear();
    //     }
    // }

    refresh();
}

std::vector<Planet> DynamicScene::planetsInQuadrant(sf::Vector2i quadrant) {
    std::vector<Planet> planets;
        Planet planet(300, 300, 100);
        planets.push_back(planet);
    return planets;
}

void DynamicScene::refresh() {
    planets.clear();
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            sf::Vector2i quad(row, col);
            for (Planet planet : planetsInQuadrant(currentQuadrant + quad)) {
                planets.push_back(planet);
            }
        }
    }
}