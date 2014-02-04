#include "dgRandomAndClock.h"



void dgRandomAndClock::start() {
	for (int i = 0; i < 8; i++)
	{
		colors[i] = gsRandom::nextColorRGB();
		polygon[i] = gsRandom::insideCircle(150);
	}
	timer = 0.0f;
}
void dgRandomAndClock::end() {}

bool dgRandomAndClock::isRunning() {
	return true;
}

void dgRandomAndClock::update() {
	timer += gsClock::getDeltaTime();
	if (timer > 1.0f) {
		timer -= 1.0f;
		for (int i = 0; i < 8; i++)
		{
			colors[i] = gsRandom::nextColorRGB();
			polygon[i] = gsRandom::insideCircle(150);
		}
	}
}
void dgRandomAndClock::draw() {
	glTranslatef(480, 270, 0);

	glBegin(GL_LINE_STRIP);
	glColor3f(1, 1, 1);
	float angle = 0.0f;
	for (int i = 0; i <= 32; i++)
	{
		angle = ((float)i / 32.0f) * 2 * PI;
		glVertex3f(cos(angle) * 150, sin(angle) * 150, 0);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 8; i++)
	{
		colors[i].sendToOpenGL_Color();
		glVertex3f(polygon[i].x, polygon[i].y, 0);
	}
	glVertex3f(polygon[0].x, polygon[0].y, 0); // conectando o último com o primeiro
	glEnd();
}