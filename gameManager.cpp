#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <thread>
#include <iostream>
#include "scene.h"
#include "gameManager.h"
#include "spaceship.h"
#include "camera.h"
#include "dynamicScene.h"
#include "menu.h"

#define keyIsPressed(key) (sf::Keyboard::isKeyPressed(key))

namespace space {

    void spawnAstroids(Scene* scene, GameState* gameState) {

        std::minstd_rand0 generator (time(0));
        std::exponential_distribution<double> distribution(1.5);

        std::chrono::duration<double> timeToNextAstroid(distribution(generator));
        std::chrono::time_point nextAstroidSpawnTime = std::chrono::system_clock::now() + timeToNextAstroid;

        while (*gameState != GameState::Closing) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/6));
            if (std::chrono::system_clock::now() > nextAstroidSpawnTime) {
                //spawn astroid
                scene->addAstroid();
                std::cout << "spawned astroid" << std::endl;
                // set up next time interval
                std::chrono::duration<double> nextAstroid(distribution(generator));
                nextAstroidSpawnTime = (std::chrono::system_clock::now() + nextAstroid);
            }

        }
    }

    GameManager::GameManager() {
        scene = new DynamicScene();
        scene->reset();
        view.setSize(1920, 1080);
    }

    GameManager::~GameManager() {
        delete scene;
    }

    void GameManager::run() {
        sf::Clock clock;
        clock.restart();
        sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Cruiser");
        std::thread astroidSpawner(spawnAstroids, scene, &gameState);


        while (window.isOpen()) {
            
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            const int sleepTime = 1000/60;
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

            updateGameState();
            updateScene(clock.getElapsedTime().asMilliseconds());
            drawToWindow(&window);

            clock.restart();
        }

        gameState = GameState::Closing;
        astroidSpawner.join();
    }

    void GameManager::updateGameState() {
        if (keyIsPressed(sf::Keyboard::Escape)) {
            if (gameState == GameState::Paused) {
                gameState = GameState::Active;
            } else if (gameState == GameState::Active) {
                gameState = GameState::Paused;
            }
        }
    }

    void GameManager::updateScene(int secondsEllapsed) {
        
        if (gameState == GameState::Paused) {
            return;
        }
        
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