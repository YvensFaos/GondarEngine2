#include "gsWindow.h"


#include "Dependencies\sdl\SDL.h"
#include "System\Subsystems\gsLogger.h"


#define gsAssertSDL(x) {if(!(x)) { GS_LOG("SDL Error: " << SDL_GetError()); gsAssert(0); } }

SDL_Window *gAppWindow;

void gsWindow::init(int resX, int resY) {
	gsAssertSDL(SDL_Init(SDL_INIT_EVERYTHING) == 0);

		gAppWindow = SDL_CreateWindow(
		"Untitled", 
		GS_WINDOW_POS_X, GS_WINDOW_POS_Y, 
		GS_RESOLUTION_X, GS_RESOLUTION_Y, 
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	gsAssertSDL(gAppWindow != 0);

	SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");

	SDL_DisableScreenSaver();
	
	GS_LOG("Current Video Driver: " << SDL_GetCurrentVideoDriver());
}
void gsWindow::dispose() {
	SDL_DestroyWindow(gAppWindow);
	SDL_EnableScreenSaver();

	SDL_Quit();
}

SDL_Window* gsWindow::getWindow() {
	return gAppWindow;
}


const char* gsWindow::getWindowTitle() {
	return SDL_GetWindowTitle(gAppWindow);
}
void gsWindow::setWindowTitle(const char* title) {
	SDL_SetWindowTitle(gAppWindow, title);
}

void gsWindow::setFullscreen(bool fullscreen) {
	SDL_SetWindowFullscreen(gAppWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

int gsWindow::getWindowWidth() {
	int w;
	SDL_GetWindowSize(gAppWindow, &w, 0);
	return w;
}
int gsWindow::getWindowHeight() {
	int h;
	SDL_GetWindowSize(gAppWindow, 0, &h);
	return h;
}
void gsWindow::setWindowSize(int w, int h) {
	gsAssert(w > 0);
	gsAssert(h > 0);
	SDL_SetWindowSize(gAppWindow, w, h);
}