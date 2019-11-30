#include <vector>
#include "scene.h"
#include "planet.h"
#include "SFML/Graphics.hpp"


class DynamicScene : Scene {
    public:
        void updateQuadrant(sf::Vector2f position);
        void reset();
    private:
        std::vector<Planet> quadrants[3][3];
        sf::Vector2i currentQuadrant;
        std::vector<Planet> planetsInQuadrant(sf::Vector2i quadrant);
        void refresh();

};