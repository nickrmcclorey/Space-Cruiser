#include <vector>
#include "planet.h"
#include "spaceship.h"
#include "scene.h"
#include "collision.h"

#define getDistanceSquared(distance) (pow(distance.x, 2) + pow(distance.y, 2));

#define distanceBetween(obj1, obj2) (sqrt(pow(obj1.x - obj2.x, 2) + pow(obj2.x - obj2.y, 2)))

#define getMagnitude(distance) (sqrt(pow(distance.x, 2) + pow(distance.y, 2)));

#define keyIsPressed(key) (sf::Keyboard::isKeyPressed(key))

void Scene::reset() {
    planets.clear();
    spaceship.velocity = sf::Vector2f(0, 0);

    Planet planet(0, 0, 100);
    planets.push_back(planet);
};

void Scene::update(int secondsEllapsed) {
    updateSpaceship(secondsEllapsed);
    updateAstroids(secondsEllapsed);
}

void Scene::updateSpaceship(int secondsEllapsed) {

        for (Planet planet : planets) {
            sf::Vector2f distance = planet.position - spaceship.position;
            double distanceSquared = getDistanceSquared(distance);
            double force = planet.gravityStrength * planet.mass / distanceSquared;
            double theta = atan2(distance.y, distance.x);
            double forceX = cos(theta) * force;
            double forceY = sin(theta) * force;
            spaceship.velocity.x += forceX * secondsEllapsed;
            spaceship.velocity.y += forceY * secondsEllapsed;

            if (sqrt(distanceSquared) < planet.radius) {
                spaceship.velocity.y = 0;
                spaceship.velocity.x = 0;
                return;
            }
        }

        if (keyIsPressed(sf::Keyboard::W)) {
            spaceship.velocity.y += cos(spaceship.rotation) * -0.02;
            spaceship.velocity.x += sin(spaceship.rotation) * 0.02;
        }

        if (keyIsPressed(sf::Keyboard::A)) {
            spaceship.rotation -= M_PI / 32;
        }

        if (keyIsPressed(sf::Keyboard::D)) {
            spaceship.rotation += M_PI / 32;
        }

        spaceship.position += spaceship.velocity * (float)secondsEllapsed;

        
        astroidMutex.lock();
        for (Astroid astroid : astroids) {
            sf::ConvexShape spaceshipShape = spaceship.polygon();
            auto spaceShipPosition = spaceship.position;
            if (distanceBetween(spaceship.position, spaceShipPosition) < 20 && Collision::shapesIntersect(&astroid, &spaceshipShape)) {
                spaceship.velocity = sf::Vector2f(0, 0);
            }
        }
        astroidMutex.unlock();
}

void Scene::updateAstroids(int time) {
    astroidMutex.lock();
    for (int k = 0; k < astroids.size(); k++) {
        astroids[k].move(astroids[k].velocity * (float)time);

        for (Planet planet : planets) {
            auto distance = planet.position - astroids[k].getPosition();
            int magnitude = getMagnitude(distance);

            if (magnitude < planet.radius) {
                astroids.erase(astroids.begin() + k);
                k--;
                break;
            }
        }

    }
    astroidMutex.unlock();
}

void Scene::drawToWindow(sf::RenderWindow* window) {
    window->draw(spaceship.polygon());
    
    for (Planet planet : planets) {
        window->draw(planet.getShape());
    }

    astroidMutex.lock();
    for (Astroid astroid : astroids) {
        window->draw(astroid);
    }
    astroidMutex.unlock();
}


Scene::Scene() {
    reset();
}
