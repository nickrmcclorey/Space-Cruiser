#pragma once
#include "scene.h"
#include <SFML/Graphics.hpp>

namespace space {

    class GameManager {
        public:
        Scene* scene;
        
        void updateScene(int seconds);
        void drawScene(sf::RenderWindow* window);
        GameManager();
        ~GameManager();
    };

}