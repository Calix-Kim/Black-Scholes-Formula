#include "binaryoption.h"
#include "normal.h"
#include <cmath>

double BinaryOption::price() {
	double s = p_.getSpot();
	double r = p_.getRf();
	double q = p_.getDiv();
	double sigma = p_.getVol();
	double t = get_ttm();
	return binary_price(s, k_, r, q, t, sigma, type_);
}

double BinaryOption::binary_price(double s, double k, double r, double q, double t, double sigma, OptionType type) {
	double d2 = get_d2(sigma);
	double price = std::exp(-r * t) * normcdf(int(type) * d2);
	return price;
}