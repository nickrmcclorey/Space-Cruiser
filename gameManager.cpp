#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "scene.h"
#include "gameManager.h"
#include "spaceship.h"
#include "camera.h"
#include "dynamicScene.h"

namespace space {

    GameManager::GameManager() {
        scene = new DynamicScene();
        scene->reset();
    }

    GameManager::~GameManager() {
        delete scene;
    }

    void GameManager::updateScene(int timeEllapsed) {
        SpaceShip* spaceShip = &scene->spaceShip;
        for (Planet planet : scene->planets) {
            double dx = planet.position.x - spaceShip->position.x;
            double dy = planet.position.y - spaceShip->position.y;
            double distanceSquared = pow(dx, 2) + pow(dy, 2);
            double force = planet.gravityStrength * planet.mass / distanceSquared;
            double theta = atan2(dy, dx);
            double forceX = cos(theta) * force;
            double forceY = sin(theta) * force;
            spaceShip->velocity.x += forceX * timeEllapsed;
            spaceShip->velocity.y += forceY * timeEllapsed;

            if (sqrt(distanceSquared) < planet.radius) {
                spaceShip->velocity.y = 0;
                spaceShip->velocity.x = 0;
                return;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            spaceShip->velocity.y += cos(spaceShip->rotation) * -0.02;
            spaceShip->velocity.x += sin(spaceShip->rotation) * 0.02;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            spaceShip->rotation -= M_PI / 32;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            spaceShip->rotation += M_PI / 32;
        }

        spaceShip->position += spaceShip->velocity * (float)timeEllapsed;
        scene->update(spaceShip->position);
    }

    void GameManager::drawScene(sf::RenderWindow* window) {
        camera::draw(scene, window);
    }

}