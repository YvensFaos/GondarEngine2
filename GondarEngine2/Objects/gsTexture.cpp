#include "gsTexture.h"


#include "System\Subsystems\gsOpenGL.h"

void gsTexture::sendToOpenGL_Texture() {
	glBindTexture(GL_TEXTURE_2D, handle);
}