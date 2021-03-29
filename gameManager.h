#pragma once
#include "scene.h"
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <thread>


namespace space {
    
    enum GameState {Active, Paused, GameOver, Closing};

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

            void drawToWindow(sf::RenderWindow* window);
            GameState updateGameState();

    };


}
