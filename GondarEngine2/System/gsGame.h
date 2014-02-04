#ifndef __GS_GAME_H__
#define __GS_GAME_H__

#include "gsConfig.h"
#include "gsMacros.h"


// Classe base para a definição de um jogo
class GS_DLL gsGame {
public:
	virtual ~gsGame() {}

	virtual void start() = 0; // Método chamado antes do primeiro update. Utilize-o para inicializar recursos
	virtual void end() = 0; // Método chamado após o último update. Utilize-o para liberar recursos

	virtual bool isRunning() = 0; // Retorna true se o jogo estiver rodando e false se ele tiver terminado

	virtual void update() = 0; // Método responsável por atualizar todos os objetos do jogo
	virtual void draw() = 0; // Método responsável por desenhar todos os objetos do jogo
};

#endif