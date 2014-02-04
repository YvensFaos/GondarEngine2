#include "gsRandom.h"


#include <cstdlib>
#include <ctime>


void gsRandom::init() {
	srand(time(0));
}

bool gsRandom::nextBool() {
	bool value = (rand() % 2) == 0;
	return value;
}
int gsRandom::nextInt(int min, int max) {
	int value = rand() % ((max + 1) - min) + min;
	return value;
}
double gsRandom::nextDouble(double min, double max) {
	double value = rand() / (double)RAND_MAX;;
	value = value * ((max + 1) - min) + min;
	return value;
}

gsVector2 gsRandom::insideCircumference(double radius) {
	double angle = nextDouble(0, 2 * PI);
	return gsVector2(cos(angle), sin(angle)) * radius;
}
gsVector2 gsRandom::insideCircle(double radius) {
	double angle = nextDouble(0, 2 * PI);
	return gsVector2(cos(angle), sin(angle)) * nextDouble(0, radius);
}

gsColor gsRandom::nextColorRGB(float alpha) {
	return gsColor(nextDouble(), nextDouble(), nextDouble(), alpha);
}
gsColor gsRandom::nextColorRGBA() {
	return gsColor(nextDouble(), nextDouble(), nextDouble(), nextDouble());
}

bool gsRandom::chance(int chance) {
	if(chance > 100) return true;
	if(chance < 0) return false;

	int value = nextInt(0, 100);
	if(value < chance)
	{
		return true;
	}
	else
	{
		return false;
	}
}