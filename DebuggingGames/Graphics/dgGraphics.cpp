#include "dgGraphics.h"


void dgGraphics::start() {}
void dgGraphics::end() {}

bool dgGraphics::isRunning() {
	return true;
}

void dgGraphics::update() {
}
void dgGraphics::draw() {
	glTranslatef(75, 75, 0);
	glRotatef(gsClock::getTotalTime() * 64, 0, 0, 1);
	

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(-25, -25, 0);
	glVertex3f(25, -25, 0);
	glVertex3f(25, 25, 0);
	glVertex3f(-25, 25, 0);
	glEnd();
}

/*

glColor3f(1, 0, 0);
	glVertex3f(10, 10, 0);
	glColor3f(0, 1, 0);
	glVertex3f(GS_RESOLUTION_X - 10, 10, 0);
	glColor3f(0, 0, 1);
	glVertex3f(GS_RESOLUTION_X - 10, GS_RESOLUTION_Y - 10, 0);
	glColor3f(1, 1, 0);
	glVertex3f(10, GS_RESOLUTION_Y - 10, 0);
	*/