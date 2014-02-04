#ifndef __GS_LOGGER_H__
#define __GS_LOGGER_H__

#include "gsConfig.h"
#include "gsMacros.h"
#include <sstream>

// Subsistema responsável por postar mensagens no console. utilize o macro GS_LOG para postar
// uma mensagem.
// Ex: int a = 10; GS_LOG("O valor da variável a é: " << a << ", use o operador << como o + do java para concatenar coisas");
class GS_DLL gsLogger {
public:
	static void init();

	static void log(const std::stringstream& message);
};


#define GS_LOG(a) {       \
	std::stringstream ss; \
	ss << a << '\n';      \
	gsLogger::log(ss);    \
}

#endif