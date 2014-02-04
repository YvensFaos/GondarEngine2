#ifndef __DG_RANDOM_AND_CLOCK_H__
#define __DG_RANDOM_AND_CLOCK_H__

#include "GondarEngine2\gsGondarEngine2.h"

class dgRandomAndClock : public gsGame {
private:
	gsColor colors[8];
	gsVector2 polygon[8];
	float timer;

public:
	virtual void start();
	virtual void end();

	virtual bool isRunning();

	virtual void update();
	virtual void draw();
};

#endif
