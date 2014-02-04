#ifndef __DG_GAMELOOP_H__
#define __DG_GAMELOOP_H__

#include "GondarEngine2\gsGondarEngine2.h"

class dgGameloop : public gsGame {
private:
	int frameCounter;

public:
	virtual void start();
	virtual void end();

	virtual bool isRunning();

	virtual void update();
	virtual void draw();
};

#endif
