#ifndef __GS_ENGINE__
#define __GS_ENGINE__

#include "gsConfig.h"
#include "gsMacros.h"

// Classe base para a defini��o de um jogo
class gsGame;

// Classe base para a execu��o de jogos.
class GS_DLL gsEngine {
private:
	// O jogo que ser� executado.
	gsGame *game;

	// Inicializa todos os subsistemas da engine que precisam ser inicializados
	void initializeEngineSystems();
	// Atualiza todos os subsistemas da engine que precisam ser atualizados todo frame
	void updateEngineSystems();
	// Libera os recursos utilizados pelos subsistemas que possuem algum recurso
	void disposeEngineSystems();

public:
	// Inicializa a engine recebendo o jogo que ser� executado
	gsEngine(gsGame* gameToBeRun) { this->game = gameToBeRun; }
	~gsEngine() {}

	// Executa o jogo.
	void runGame();
};

#endif