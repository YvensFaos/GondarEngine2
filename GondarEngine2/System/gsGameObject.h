#ifndef __GS_GAME_OBJECT__
#define __GS_GAME_OBJECT__

#include "gsConfig.h"
#include "gsMacros.h"
#include "Objects\gsTransform.h"

// Classe base de todos os objetos do jogo.
class GS_DLL gsGameObject {
protected:
	gsTransform transform; // Posi��o, tamanho e rota��o do objeto

	bool enabled;   // Se enabled for true, o objeto � atualizado todo frame
	bool visible;   // Se visible for true, o objeto � desenhado todo frame
	bool collident; // Se collident for true, o objeto � testado por colis�es

public:
	gsGameObject() {
		enabled = visible = collident = true;
	}
	virtual ~gsGameObject() {}

	virtual void update() = 0;
	virtual void draw() = 0;

	bool isEnabled() const { return enabled; }
	bool isVisible() const { return visible; }
	bool isCollident() const { return collident; }

	void setEnabled(bool value) { enabled = value; }
	void setVisible(bool value) { visible = value; }
	void setCollident(bool value) { collident = value; }

	gsTransform* getTransform() { return &transform; }
	const gsTransform* getTransform() const { return &transform; }
};

#endif