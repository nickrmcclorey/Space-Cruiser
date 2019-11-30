#include <SFML/Graphics.hpp>
#include "scene.h"
#include "camera.h"

void camera::draw(Scene* scene, sf::RenderWindow* window) {

    sf::Vector2f offset = scene->spaceShip.position;
    offset.x -= 960;
    offset.y -= 540;

    window->clear();
    sf::VertexArray spaceship = scene->spaceShip.polygon();
    for (int k = 0; k < spaceship.getVertexCount(); k++) {
        spaceship[k].position -= offset;
    }

    window->draw(spaceship);
    
    for (Planet planet : scene->planets) {
        sf::CircleShape shape(planet.radius);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(planet.position.x - planet.radius, planet.position.y - planet.radius);
        shape.setPosition(shape.getPosition() - offset);
        window->draw(shape);
    }

    window->display();
}
