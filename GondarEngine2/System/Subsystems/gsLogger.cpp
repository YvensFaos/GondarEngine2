#include "gsLogger.h"


#include "Dependencies\sdl\SDL_log.h"
#include <iostream>

using namespace std;


void gsLogger::init() {
	// Any init code for SDL logging?
}

void gsLogger::log(const stringstream& message) {
	SDL_Log(message.str().c_str());
}