#ifndef __GS_RANDOM_H__
#define __GS_RANDOM_H__

#include "gsConfig.h"
#include "gsMacros.h"
#include "Math\gsVector2.h"
#include "Math\gsColor.h"

// Subsistema responsável pela geração de números aleatórios
class GS_DLL gsRandom {
public:
	static void init();

	// retorna um valor booleano aleatório
	static bool nextBool();
	// retorna um valor inteiro aleatório no intervalo [min, max]
	static int nextInt(int min, int max);
	// retorna um valor decimal aleatório no intervalo [min, max]
	static double nextDouble(double min = 0, double max = 1);

	// Retorna um ponto aleatório na circunferência posicionado em (0, 0) e com o raio indicado
	static gsVector2 insideCircumference(double radius = 1.0f);
	// Retorna um ponto aleatório dentro do círculo posicionado em (0, 0) e com o raio indicado
	static gsVector2 insideCircle(double radius = 1.0f);

	// Retorna uma cor com R, G e B aleatórios e o A indicado
	static gsColor nextColorRGB(float alpha = 1.0f);
	// Retorna uma cor com R, G, B e A aleatórios
	static gsColor nextColorRGBA();

	// Retorna true caso o valor aleatório no intervalo [0, 100] seja maior que chance e false caso contrário
	static bool chance(int chance);
};

#endif