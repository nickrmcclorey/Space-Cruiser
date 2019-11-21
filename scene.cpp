#include <vector>
#include "planet.h"
#include "spaceship.h"
#include "scene.h"

    
    void Scene::reset() {
        planets.clear();

        Planet planet(0, 0, 100);
        planets.push_back(planet);
    };

    Scene::Scene() {
        this->reset();
    }
