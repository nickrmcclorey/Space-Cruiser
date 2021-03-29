#pragma once

class IControls {
	public:
		virtual bool forward() = 0;
		virtual bool left() = 0;
		virtual bool right() = 0;
		virtual bool reset() = 0;
		virtual bool pause() = 0;	
};
