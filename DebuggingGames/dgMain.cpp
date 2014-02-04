
#include "GondarEngine2\gsGondarEngine2.h"
#include "Gameloop\dgGameloop.h"
#include "Graphics\dgGraphics.h"
#include "RandomAndClock\dgRandomAndClock.h"


void main() {
	dgGraphics game;
	gsEngine engine(&game);

	engine.runGame();
}