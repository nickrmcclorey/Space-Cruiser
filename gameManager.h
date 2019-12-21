#pragma once
#include "scene.h"
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <thread>


namespace space {
    
    enum GameState {Active, Paused, Closing};

    class GameManager {
        public:
            void run();
            GameManager();
            ~GameManager();

        private:
            Scene* scene;
            Menu menu;
            sf::View view;
            GameState gameState;

            void updateScene(int secondsEllapsed);
            void drawToWindow(sf::RenderWindow* window);
            void updateGameState();

    };


}
