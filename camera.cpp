#include <SFML/Graphics.hpp>
#include "scene.h"
#include "camera.h"

void camera::draw(Scene* scene, sf::RenderWindow* window) {

    window->clear();
    window->draw(scene->spaceShip.polygon());
    
    for (Planet planet : scene->planets) {
        window->draw(planet.getShape());
    }

    for (Astroid astroid :scene->astroids) {
        window->draw(astroid);
    }

}
