#include <SFML/Window/Keyboard.hpp>
#include "ClientControls.h"


bool ClientControls::forward() {
	return keyIsPressed(sf::Keyboard::W);		
}

bool ClientControls::left() {
	return keyIsPressed(sf::Keyboard::A);		
}

bool ClientControls::right() {
	return keyIsPressed(sf::Keyboard::D);		
}

bool ClientControls::reset() {
	return keyIsPressed(sf::Keyboard::R);		
}

bool ClientControls::pause() {
	return keyIsPressed(sf::Keyboard::Escape);
}

