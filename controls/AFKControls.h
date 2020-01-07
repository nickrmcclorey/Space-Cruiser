#include "IControls.h"

class AFKControls : public IControls {
	public:
		bool forward();
		bool left();
		bool right();
		bool reset();
		bool pause();
};
