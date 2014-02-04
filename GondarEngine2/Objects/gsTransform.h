#ifndef __GS_TRANSFORM_H__
#define __GS_TRANSFORM_H__

#include "gsConfig.h"
#include "gsMacros.h"
#include "gsTexture.h"
#include "Math\gsVector2.h"
#include "Math\gsColor.h"
#include "Math\gsTextureCoordinates.h"

// Classe que representa a posição, o tamanho e a orientação de um objeto do jogo.
class GS_DLL gsTransform  {
public:
	gsVector2 position; // A posição do objeto
	gsVector2 size;     // O tamanho do objeto
	gsVector2 speed;    // A velocidade do objeto
	float     rotation; // A orientação do objeto (em graus)
	float     depth;    // A profundidade que o objeto se encontra
	gsColor   tint;     // A cor do objeto

	gsTextureCoordinates textureCoordinates; //Coordenadas de textura

	gsTexture *texture;
	gsVector2 offset;
	float scale;

private:
	void _init(gsVector2 pos, gsVector2 siz, gsVector2 spd, float rotation, gsTextureCoordinates* texCoords, gsColor col);

public:
	gsTransform() {}

	gsTransform(gsVector2 pos, gsVector2 siz) {
		_init(pos, siz, gsVector2::zero(), 0, 0, gsColor::white());
	}

	void applySpeed();

	bool touchedScreenEdges();
	bool leftTheSceen();

	void bounceAtScreenEdges();
	void collideWithScreenEdges();

	void setTextureCoordinates(gsTextureCoordinates* coords);
};

#endif