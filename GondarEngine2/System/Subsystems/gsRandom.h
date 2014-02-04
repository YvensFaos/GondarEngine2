#ifndef __GS_RANDOM_H__
#define __GS_RANDOM_H__

#include "gsConfig.h"
#include "gsMacros.h"
#include "Math\gsVector2.h"
#include "Math\gsColor.h"

// Subsistema respons�vel pela gera��o de n�meros aleat�rios
class GS_DLL gsRandom {
public:
	static void init();

	// retorna um valor booleano aleat�rio
	static bool nextBool();
	// retorna um valor inteiro aleat�rio no intervalo [min, max]
	static int nextInt(int min, int max);
	// retorna um valor decimal aleat�rio no intervalo [min, max]
	static double nextDouble(double min = 0, double max = 1);

	// Retorna um ponto aleat�rio na circunfer�ncia posicionado em (0, 0) e com o raio indicado
	static gsVector2 insideCircumference(double radius = 1.0f);
	// Retorna um ponto aleat�rio dentro do c�rculo posicionado em (0, 0) e com o raio indicado
	static gsVector2 insideCircle(double radius = 1.0f);

	// Retorna uma cor com R, G e B aleat�rios e o A indicado
	static gsColor nextColorRGB(float alpha = 1.0f);
	// Retorna uma cor com R, G, B e A aleat�rios
	static gsColor nextColorRGBA();

	// Retorna true caso o valor aleat�rio no intervalo [0, 100] seja maior que chance e false caso contr�rio
	static bool chance(int chance);
};

#endif