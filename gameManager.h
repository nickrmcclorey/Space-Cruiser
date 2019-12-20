#pragma once
#include "scene.h"
#include "menu.h"
#include <SFML/Graphics.hpp>

namespace space {

    class GameManager {
        public:
            Scene* scene;
            Menu menu;
            
            void updateScene(int secondsEllapsed);
            void drawScene(sf::RenderWindow* window);
            GameManager();
            ~GameManager();

        private:
            void updateSpaceship(int secondsEllapsed);
    };

}