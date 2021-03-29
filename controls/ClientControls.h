#pragma once
#include "IControls.h"

#define keyIsPressed(key) (sf::Keyboard::isKeyPressed(key))

class ClientControls : public IControls {
	public:
		bool forward();
		bool left();
		bool right();
		bool reset();
		bool pause();
};
