#include <vector>
#include "SFML/Graphics.hpp"
#include "dynamicScene.h"
#include "scene.h"
#include "planet.h"
#include <iostream>

void DynamicScene::update(sf::Vector2f position) {
    
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
    Planet planet(300 + quadrant.x * 2000, 300 + quadrant.y * 2000, 100);
    planets.push_back(planet);
    return planets;
}

void DynamicScene::refresh() {
    std::cout << "inside" << std::endl;
    planets.clear();
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            sf::Vector2i quad(row - 1, col - 1);
            for (Planet planet : planetsInQuadrant(currentQuadrant + quad)) {
                planets.push_back(planet);
                std::cout << "planet position: " << planet.position.x << ", " << planet.position.y << std::endl;
            }
        }
    }
}