#include <vector>
#include "planet.h"
#include "spaceship.h"

class Scene {
    public:
    double gravity = 80000;
    SpaceShip spaceShip;
    std::vector<Planet> planets;

    void reset() {
        spaceShip.xPosition = 30;
        spaceShip.yPosition = 30;
    }

    Scene() {
        this->reset();
    }
};
