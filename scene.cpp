#include <vector>
#include "planet.h"
#include "spaceship.h"
#include "scene.h"
#include "collision.h"

#define getMagnitude(distance) (sqrt(pow(distance.x, 2) + pow(distance.y, 2)));

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
            double distanceSquared = getDistanceSquared(planet.position, spaceship.position);
            double magnitude = sqrt(distanceSquared);
            double force = planet.gravityStrength * planet.mass / distanceSquared;
            double forceX = force * distance.x / magnitude;
            double forceY = force * distance.y  / magnitude;
            spaceship.velocity.x += forceX * secondsEllapsed;
            spaceship.velocity.y += forceY * secondsEllapsed;

            if (Collision::shapeIntersectsCircle(spaceship.polygon(), planet.position, planet.radius)) {
                spaceship.velocity.y = 0;
                spaceship.velocity.x = 0;
                spaceship.destroyed = true;
                return;
            }
        }

        if (spaceship.controls->forward()) {
            spaceship.velocity.y += cos(spaceship.rotation) * -0.02;
            spaceship.velocity.x += sin(spaceship.rotation) * 0.02;
        }

        if (spaceship.controls->left()) {
            spaceship.rotation -= M_PI / 32;
        }

        if (spaceship.controls->right()) {
            spaceship.rotation += M_PI / 32;
        }

        spaceship.position += spaceship.velocity * (float)secondsEllapsed;

        astroidMutex.lock();
        for (Astroid astroid : astroids) {
            if (distanceBetween(spaceship.position, astroid.getPosition()) < 20 && Collision::shapesIntersect(astroid, spaceship.polygon())) {
                spaceship.velocity = sf::Vector2f(0, 0);
                spaceship.destroyed = true;
            }
        }
        astroidMutex.unlock();
}

void Scene::addSpaceship(Spaceship ship) {
	spaceships.push_back(ship);	
}

void Scene::updateAstroids(int time) {
    astroidMutex.lock();
    for (int k = 0; k < astroids.size(); k++) {

        for (Planet planet : planets) {
            if (Collision::shapeIntersectsCircle(astroids[k], planet.position, planet.radius)) {
                astroids.erase(astroids.begin() + k);
                k--;
                break;
            }
        }

        astroids[k].move(astroids[k].velocity * (float)time);
        // astroids[k].rotate(0.5);
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
    spaceship.controls = new ClientControls();
}

Scene::~Scene() {
    delete spaceship.controls;
}