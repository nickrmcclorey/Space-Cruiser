#pragma once
#include "scene.h"
#include "menu.h"
#include <SFML/Graphics.hpp>

namespace space {

    class GameManager {
        public:
            void updateScene(int secondsEllapsed);
            void drawToWindow(sf::RenderWindow* window);
            GameManager();
            ~GameManager();

        private:
            Scene* scene;
            Menu menu;
            sf::View view;
    };

}