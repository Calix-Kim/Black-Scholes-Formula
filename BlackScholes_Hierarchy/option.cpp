#include "option.h"
#include <cmath>

double Option::get_d1(double sigma) {
	double s = p_.getSpot();
	double r = p_.getRf();
	double q = p_.getDiv();
	//double sigma = p_.getVol();
	double t = mat_.daysFrom(p_.getToday()) / 365.0;
	double d1 = (std::log(s / k_) + (r - q + 0.5 * sigma * sigma) * t) / (sigma * std::sqrt(t));

	return d1;
}

double Option::get_d2(double sigma) {
	//double sigma = p_.getVol();
	double t = mat_.daysFrom(p_.getToday()) / 365.0;
	double d2 = get_d1(sigma) - sigma * std::sqrt(t);
	return d2;
}

double Option::get_ttm() {
	double t = mat_.daysFrom(p_.getToday()) / 365.0;
	return t;
}

double Option::price() {
	return 0;
}