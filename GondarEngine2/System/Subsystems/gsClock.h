#ifndef __GS_CLOCK_H__
#define __GS_CLOCK_H__

#include "gsConfig.h"
#include "gsMacros.h"

// Subsistema respons�vel pelo registro da passagem do tempo
class GS_DLL gsClock {
public:
	static void init();
	static void update();

	// Retorna o tempo total de execu��o do jogo desde que o rel�gio foi inicializado (em segundos)
	static double getTotalTime();
	// Retorna o tempo decorrido entre as duas �ltimas atualiza��es do rel�gio (em segundos)
	static double getDeltaTime();
};

#endif