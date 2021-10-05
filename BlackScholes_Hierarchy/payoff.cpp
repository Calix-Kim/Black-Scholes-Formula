#include "payoff.h"
#define MAX(x,y) (((x)>(y))?(x):(y))

double PlainVanillaPayoff::getPayoff(double st) {
	return MAX(int(type_) * (st - k_), 0);
}

double BinaryPayoff::getPayoff(double st) {
	return int(type_)*(st - k_) >= 0.0 ? 1.0 : 0.0;
}