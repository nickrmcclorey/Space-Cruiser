#include <vector>
#include "planet.h"
#include "spaceship.h"
#include "scene.h"

#define getMagnitude(distance) (pow(distance.x, 2) + pow(distance.y, 2));

#define keyIsPressed(key) (sf::Keyboard::isKeyPressed(key))

void Scene::reset() {
    planets.clear();
    spaceShip.position = sf::Vector2f(600, 600);

    Planet planet(0, 0, 100);
    planets.push_back(planet);
};

void Scene::update(int secondsEllapsed) {
    updateSpaceShip(secondsEllapsed);
}

void Scene::updateSpaceShip(int secondsEllapsed) {

        for (Planet planet : planets) {
            sf::Vector2f distance = planet.position - spaceShip.position;
            double distanceSquared = getMagnitude(distance);
            double force = planet.gravityStrength * planet.mass / distanceSquared;
            double theta = atan2(distance.y, distance.x);
            double forceX = cos(theta) * force;
            double forceY = sin(theta) * force;
            spaceShip.velocity.x += forceX * secondsEllapsed;
            spaceShip.velocity.y += forceY * secondsEllapsed;

            if (sqrt(distanceSquared) < planet.radius) {
                spaceShip.velocity.y = 0;
                spaceShip.velocity.x = 0;
                return;
            }
        }

        if (keyIsPressed(sf::Keyboard::W)) {
            spaceShip.velocity.y += cos(spaceShip.rotation) * -0.02;
            spaceShip.velocity.x += sin(spaceShip.rotation) * 0.02;
        }

        if (keyIsPressed(sf::Keyboard::A)) {
            spaceShip.rotation -= M_PI / 32;
        }

        if (keyIsPressed(sf::Keyboard::D)) {
            spaceShip.rotation += M_PI / 32;
        }

        spaceShip.position += spaceShip.velocity * (float)secondsEllapsed;
}

void Scene::drawToWindow(sf::RenderWindow* window) {
    window->draw(spaceShip.polygon());
    
    for (Planet planet : planets) {
        window->draw(planet.getShape());
    }

    for (Astroid astroid : astroids) {
        window->draw(astroid);
    }
}


Scene::Scene() {
    reset();
}
