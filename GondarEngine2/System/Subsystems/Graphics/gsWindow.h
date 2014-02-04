#ifndef __GS_WINDOW_H__
#define __GS_WINDOW_H__

#include "gsConfig.h"
#include "gsMacros.h"

struct SDL_Window;

// Subsitema responsável pela criação da janela
class GS_DLL gsWindow {
public:
	static void init(int resX, int resY);
	static void dispose();

	// Retorna uma referência para a janela da aplicação
	static SDL_Window* getWindow();

	static const char* getWindowTitle();
	static void setWindowTitle(const char* title);

	static void setFullscreen(bool fullscreen);

	static int getWindowWidth();
	static int getWindowHeight();
	static void setWindowSize(int w, int h);
};

#endif