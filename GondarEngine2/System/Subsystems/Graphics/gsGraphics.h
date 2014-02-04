#ifndef __GS_GRAPHICS_H__
#define __GS_GRAPHICS_H__

#include "gsConfig.h"
#include "gsMacros.h"
#include "Objects\gsTransform.h"
#include "Data\gsArrayList.h"
#include "Data\gsHashmap.h"

// Subsistema responsável pelas rotinas de desenho na tela
class GS_DLL gsGraphics {
private:
	static gsArrayList<gsArrayList<gsTransform*>> objectGroupings;
	static gsHashMap<uint, int> nameToListHash;
	static int nextFreeSlot;

	static void drawQuad(gsTransform *transform);

public:
	static void init(int resX, int resY);
	static void dispose();

	static void beginDraw();
	static void endDraw();

	static void submit(gsTransform *object);
};

#endif