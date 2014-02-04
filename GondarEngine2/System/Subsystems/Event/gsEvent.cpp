#include "gsEvent.h"


#include "Dependencies\sdl\SDL_events.h"

void gsEvent::init() {

}
void gsEvent::update() {
	SDL_Event e;

	while(SDL_PollEvent(&e)) {
		
	}
}