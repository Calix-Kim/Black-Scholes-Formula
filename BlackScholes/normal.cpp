#define _USE_MATH_DEFINES
#include "normal.h"
#include <cmath>

double normpdf(double x, double mu, double sigma) {
	double value = 1. / (sigma * std::sqrt(2. * M_PI))
		* std::exp(-(x - mu) * (x - mu) / (2. * sigma * sigma) );

	return value;
}
double normcdf(double x, double mu, double sigma) {
	double v = (x - mu) / sigma;						// x 값의 표준화된 값.
	double value = 0.5 * std::erfc(-v * M_SQRT1_2);		// error function 사용
	return value;
}