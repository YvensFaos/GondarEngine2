#ifndef __GS_TEXTURE_H__
#define __GS_TEXTURE_H__

#include "gsConfig.h"
#include "gsMacros.h"


class GS_DLL gsTexture  {
private:
	uint handle;

public:
	uint getHandle() { return handle; }
	void sendToOpenGL_Texture();
};

#endif