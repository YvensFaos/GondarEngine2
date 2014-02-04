#include "dgGameloop.h"


void dgGameloop::start() {
	GS_LOG("Starting game");

	frameCounter = 0;
}
void dgGameloop::end() {
	GS_LOG("Game ended");
}

bool dgGameloop::isRunning() {
	return (frameCounter < 60);
}

void dgGameloop::update() {
	frameCounter++;
	GS_LOG("Ran " << frameCounter << " of 60 frames");
}
void dgGameloop::draw() {
	// nothing
}