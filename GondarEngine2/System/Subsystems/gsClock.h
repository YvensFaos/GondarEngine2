#ifndef __GS_CLOCK_H__
#define __GS_CLOCK_H__

#include "gsConfig.h"
#include "gsMacros.h"

// Subsistema responsável pelo registro da passagem do tempo
class GS_DLL gsClock {
public:
	static void init();
	static void update();

	// Retorna o tempo total de execução do jogo desde que o relógio foi inicializado (em segundos)
	static double getTotalTime();
	// Retorna o tempo decorrido entre as duas últimas atualizações do relógio (em segundos)
	static double getDeltaTime();
};

#endif