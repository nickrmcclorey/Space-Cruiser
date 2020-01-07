#include <SFML/Window/Keyboard.hpp>
#include "ClientControls.h"

bool ClientControls::forward() {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::N);		
}

bool ClientControls::left() {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::N);		
}

bool ClientControls::right() {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::N);		
}

bool ClientControls::reset() {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::N);		
}

bool ClientControls::pause() {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}

