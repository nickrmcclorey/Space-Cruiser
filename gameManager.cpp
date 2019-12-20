#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "scene.h"
#include "gameManager.h"
#include "spaceship.h"
#include "camera.h"
#include "dynamicScene.h"
#include "menu.h"

#define getMagnitude(distance) (pow(distance.x, 2) + pow(distance.y, 2));

#define keyIsPressed(key) (sf::Keyboard::isKeyPressed(key))

namespace space {

    GameManager::GameManager() {
        scene = new DynamicScene();
        scene->reset();
    }

    GameManager::~GameManager() {
        delete scene;
    }

    void GameManager::updateScene(int secondsEllapsed) {
        
        if (keyIsPressed(sf::Keyboard::R)) {
            scene->reset();
        } else {
            updateSpaceship(secondsEllapsed);
            scene->update(scene->spaceShip.position);
        }
    }

    void GameManager::updateSpaceship(int secondsEllapsed) {
        SpaceShip* spaceShip = &scene->spaceShip;

        for (Planet planet : scene->planets) {
            sf::Vector2f distance = planet.position - spaceShip->position;
            double distanceSquared = getMagnitude(distance);
            double force = planet.gravityStrength * planet.mass / distanceSquared;
            double theta = atan2(distance.y, distance.x);
            double forceX = cos(theta) * force;
            double forceY = sin(theta) * force;
            spaceShip->velocity.x += forceX * secondsEllapsed;
            spaceShip->velocity.y += forceY * secondsEllapsed;

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

        spaceShip->position += spaceShip->velocity * (float)secondsEllapsed;
    }

    void GameManager::drawScene(sf::RenderWindow* window) {
        camera::draw(scene, window);
        menu.draw(window);

    }
}