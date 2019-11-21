#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "scene.h"
#include "gameManager.h"
#include "spaceship.h"

namespace space {

    GameManager::GameManager() {

    }

    void GameManager::updateScene(int timeEllapsed) {
        SpaceShip* spaceShip = &scene.spaceShip;
        for (Planet planet : scene.planets) {
            double dx = planet.xPosition - spaceShip->xPosition;
            double dy = planet.yPosition - spaceShip->yPosition;
            double distanceSquared = pow(dx, 2) + pow(dy, 2);
            double force = planet.gravityStrength * planet.mass / distanceSquared;
            double theta = atan2(dy, dx);
            double forceX = cos(theta) * force;
            double forceY = sin(theta) * force;
            spaceShip->xVelocity += forceX * timeEllapsed;
            spaceShip->yVelocity += forceY * timeEllapsed;

            if (sqrt(distanceSquared) < planet.radius) {
                spaceShip->yVelocity = 0;
                spaceShip->xVelocity = 0;
                return;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            spaceShip->yVelocity += cos(spaceShip->rotation) * -0.02;
            spaceShip->xVelocity += sin(spaceShip->rotation) * 0.02;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            spaceShip->rotation -= M_PI / 32;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            spaceShip->rotation += M_PI / 32;
        }

        spaceShip->xPosition += spaceShip->xVelocity * timeEllapsed;
        spaceShip->yPosition += spaceShip->yVelocity * timeEllapsed;
    }

    void GameManager::drawScene(sf::RenderWindow* window) {
        
        window->clear();
        window->draw(scene.spaceShip.polygon());
        
        for (Planet planet : scene.planets) {
            sf::CircleShape shape(planet.radius);
            shape.setFillColor(sf::Color::Green);
            shape.setPosition(planet.xPosition - planet.radius, planet.yPosition - planet.radius);
            window->draw(shape);
        }

        window->display();
    }

}