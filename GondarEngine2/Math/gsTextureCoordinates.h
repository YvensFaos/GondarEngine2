#ifndef __GS_TEXTURE_COORDINATES_H__
#define __GS_TEXTURE_COORDINATES_H__

#include "gsConfig.h"
#include "gsMacros.h"
#include "gsVector2.h"

class GS_DLL gsTextureCoordinates {
private:
	gsVector2 coords[4];

public:
	gsTextureCoordinates() {}
	gsTextureCoordinates(gsVector2 c1, gsVector2 c2, gsVector2 c3, gsVector2 c4);
	gsTextureCoordinates(gsVector2 *data);

	gsVector2* getData() { return coords; }
	void setData(gsVector2 c1, gsVector2 c2, gsVector2 c3, gsVector2 c4);
	void setData(gsVector2 *data);

	static gsTextureCoordinates fullImage();
};


#endif