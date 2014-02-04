#include "gsGraphics.h"

#include "Dependencies\sdl\SDL.h"
#include "System\Subsystems\gsOpenGL.h"
#include "gsWindow.h"


gsArrayList<gsArrayList<gsTransform*>> gsGraphics::objectGroupings;
gsHashMap<uint, int> gsGraphics::nameToListHash;
int gsGraphics::nextFreeSlot;
SDL_GLContext gGLContext;

void gsGraphics::init(int resX, int resY) {
	gGLContext = SDL_GL_CreateContext(gsWindow::getWindow());
	SDL_GL_MakeCurrent(gsWindow::getWindow(), gGLContext);
	SDL_GL_SetSwapInterval(1);

	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	nextFreeSlot = 1;
}

void gsGraphics::dispose() {
	nextFreeSlot = 1;
}

void gsGraphics::beginDraw() {
	int w = gsWindow::getWindowWidth();
	int h = gsWindow::getWindowHeight();
	glViewport(0, 0, w, h);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	glOrtho(0, w, h, 0, 0, 10);

	for (int i = 0; i < objectGroupings.getSize(); i++)
	{
		objectGroupings.get(i).clear();
	}

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void gsGraphics::endDraw() {
	for (int i = 0; i < objectGroupings.getSize(); i++)
	{
		if (objectGroupings.get(i).getSize() > 0) {
			gsArrayList<gsTransform*> group = objectGroupings.get(i);
			group.get(0)->texture->sendToOpenGL_Texture();
			glBegin(GL_QUADS);
			for (int j = 0; j < group.getSize(); j++)
			{
				drawQuad(group.get(j));
			}
			glEnd();
		}
	}
	SDL_GL_SwapWindow(gsWindow::getWindow());
}

void gsGraphics::submit(gsTransform *object) {
	if (object->texture == 0) {
		objectGroupings.get(0).add(object); // untextured
	} else {
		if (nameToListHash.contains(object->texture->getHandle())) {
			objectGroupings.get(nameToListHash.get(object->texture->getHandle())).add(object);
		} else {
			nameToListHash.add(object->texture->getHandle(), nextFreeSlot);
			objectGroupings.get(nextFreeSlot).add(object);

			nextFreeSlot++;
		}
	}
}

void gsGraphics::drawQuad(gsTransform *transform) {
	glPushMatrix();

	glTranslatef(transform->position.x + transform->offset.x, transform->position.y + transform->offset.y, transform->depth);
	glRotatef(transform->rotation, 0, 0, 1);
	glScalef(transform->scale, transform->scale, 0.0f);

	const gsVector2 halfExtents = transform->size / 2;
	const gsVector2 *coords = transform->textureCoordinates.getData();

	transform->tint.sendToOpenGL_Color();
	glTexCoord2f(coords[0].x, coords[0].y);
	glVertex3f(-halfExtents.x, -halfExtents.y, 0);
	glTexCoord2f(coords[1].x, coords[1].y);
	glVertex3f( halfExtents.x, -halfExtents.y, 0);
	glTexCoord2f(coords[2].x, coords[2].y);
	glVertex3f( halfExtents.x,  halfExtents.y, 0);
	glTexCoord2f(coords[3].x, coords[3].y);
	glVertex3f(-halfExtents.x,  halfExtents.y, 0);

	glPopMatrix();
}