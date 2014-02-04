#ifndef __GS_GAME_H__
#define __GS_GAME_H__

#include "gsConfig.h"
#include "gsMacros.h"


// Classe base para a defini��o de um jogo
class GS_DLL gsGame {
public:
	virtual ~gsGame() {}

	virtual void start() = 0; // M�todo chamado antes do primeiro update. Utilize-o para inicializar recursos
	virtual void end() = 0; // M�todo chamado ap�s o �ltimo update. Utilize-o para liberar recursos

	virtual bool isRunning() = 0; // Retorna true se o jogo estiver rodando e false se ele tiver terminado

	virtual void update() = 0; // M�todo respons�vel por atualizar todos os objetos do jogo
	virtual void draw() = 0; // M�todo respons�vel por desenhar todos os objetos do jogo
};

#endif