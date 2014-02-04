#ifndef __DG_GRAPHICS_H__
#define __DG_GRAPHICS_H__

#include "GondarEngine2\gsGondarEngine2.h"

class dgGraphics : public gsGame {
public:
	virtual void start();
	virtual void end();

	virtual bool isRunning();

	virtual void update();
	virtual void draw();
};

#endif
