#include "gsEngine.h"


#include "System\Subsystems\gsLogger.h"
#include "System\Subsystems\gsRandom.h"
#include "System\Subsystems\gsClock.h"
#include "System\Subsystems\Graphics\gsWindow.h"
#include "System\Subsystems\Graphics\gsGraphics.h"
#include "System\Subsystems\Event\gsEvent.h"
#include "System\Subsystems\Audio\gsAudio.h"
#include "System\Subsystems\Collision\gsCollision.h"
#include "System\Subsystems\Content\gsContent.h"

#include "System\gsGame.h"


void gsEngine::runGame() {
	initializeEngineSystems();

	game->start();
	while(game->isRunning()) {
		updateEngineSystems();

		game->update();

		gsGraphics::beginDraw();
			game->draw();
		gsGraphics::endDraw();
	}
	game->end();

	disposeEngineSystems();
}

void gsEngine::initializeEngineSystems() {
	gsLogger::init();
	gsWindow::init(GS_RESOLUTION_X, GS_RESOLUTION_Y);
	gsClock::init();
	gsRandom::init();
	gsAudio::init();
	gsGraphics::init(GS_RESOLUTION_X, GS_RESOLUTION_Y);
	gsEvent::init();
}
void gsEngine::updateEngineSystems() {
	gsClock::update();
	gsAudio::update();
	gsEvent::update();
}
void gsEngine::disposeEngineSystems() {
	gsGraphics::dispose();
	gsAudio::dispose();
	gsWindow::dispose();
}


