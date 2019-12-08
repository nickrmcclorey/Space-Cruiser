#include <vector>
#include "planet.h"
#include "spaceship.h"
#include "scene.h"
    
void Scene::reset() {
    planets.clear();
    spaceShip.position = sf::Vector2f(600, 600);

    Planet planet(0, 0, 100);
    planets.push_back(planet);
};

void Scene::update(sf::Vector2f position) {

}

Scene::Scene() {
    reset();
}
