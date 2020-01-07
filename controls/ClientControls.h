#include "IControls.h"

class ClientControls : public IControls {
	public:
		bool forward();
		bool left();
		bool right();
		bool reset();
		bool pause();
};
