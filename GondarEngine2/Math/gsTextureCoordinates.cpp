#include "gsTextureCoordinates.h"


gsTextureCoordinates::gsTextureCoordinates(gsVector2 c1, gsVector2 c2, gsVector2 c3, gsVector2 c4) {
	setData(c1, c2, c3, c4);
}
gsTextureCoordinates::gsTextureCoordinates(gsVector2 *data) {
	setData(data);
}

void gsTextureCoordinates::setData(gsVector2 c1, gsVector2 c2, gsVector2 c3, gsVector2 c4) {
	coords[0] = c1;
	coords[1] = c2;
	coords[2] = c3;
	coords[4] = c4;
}
void gsTextureCoordinates::setData(gsVector2 *data) {
	coords[0] = data[0];
	coords[1] = data[1];
	coords[2] = data[2];
	coords[4] = data[3];
}

gsTextureCoordinates gsTextureCoordinates::fullImage() {
	return gsTextureCoordinates(gsVector2(0, 1), gsVector2(1, 1), gsVector2(1, 0), gsVector2(0, 0));
}