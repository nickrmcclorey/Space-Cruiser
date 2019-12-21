#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "scene.h"
#include "gameManager.h"
#include "spaceship.h"
#include "camera.h"
#include "dynamicScene.h"
#include "menu.h"

#define keyIsPressed(key) (sf::Keyboard::isKeyPressed(key))

namespace space {

    GameManager::GameManager() {
        scene = new DynamicScene();
        scene->reset();
        view.setSize(1920, 1080);
    }

    GameManager::~GameManager() {
        delete scene;
    }

    void GameManager::updateScene(int secondsEllapsed) {
        
        if (keyIsPressed(sf::Keyboard::R)) {
            scene->reset();
        } else {
            scene->update(secondsEllapsed);
        }
    }

    void GameManager::drawToWindow(sf::RenderWindow* window) {
        window->clear();

        view.setCenter(scene->spaceShip.position);
        window->setView(view);
        scene->drawToWindow(window);

        window->setView(window->getDefaultView());
        menu.drawToWindow(window);

        window->display();
    }
}