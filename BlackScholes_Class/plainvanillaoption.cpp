#include "plainvanillaoption.h"
#include "normal.h"
#include "cmath"

double PlainVanillaOption::bsprice(double s, double k, double r, double  q, double  t, double sigma, OptionType type) {	//call:type = +1 or put:type = -1
	double d1 = (std::log(s / k) + (r - q + 0.5 * sigma * sigma) * t) / (sigma * std::sqrt(t));
	double d2 = d1 - sigma * std::sqrt(t);
	double nd1 = normcdf(int(type) * d1);
	double nd2 = normcdf(int(type) * d2);

	double price = (int)type * (s * std::exp(-q * t) * nd1 - k * std::exp(-r * t) * nd2);

	return price;
}

double PlainVanillaOption::bsvega(double s, double k, double r, double  q, double  t, double sigma) {
	double d1 = (std::log(s / k) + (r - q + 0.5 * sigma * sigma) * t) / (sigma * std::sqrt(t));
	double pdf_d1 = normpdf(d1);
	double vega = s * std::exp(-q * t) * std::sqrt(t) * pdf_d1;

	return vega;
}

double PlainVanillaOption::imvol(double s, double k, double r, double q, double t, double price, OptionType type) {	

	double x0 = 0.1;
	double tol = 1e-8;
	double error = 100; 
	while (error > tol) {
		double x1 = x0 - (bsprice(s, k, r, q, t, x0, type) - price) / bsvega(s, k, r, q, t, x0);
		error = std::abs(bsprice(s, k, r, q, t, x1, type) - price);
		x0 = x1;
	}
	return x0;
}

double PlainVanillaOption::price() {
	double t = mat_.daysFrom(p_.getToday()) / 365.0;
	double price = bsprice(p_.getSpot(), k_, p_.getRf(), p_.getDiv(), t, p_.getVol(), type_);
	return price;
}
double PlainVanillaOption::vega() {
	double t = mat_.daysFrom(p_.getToday()) / 365.0;
	double vega = bsvega(p_.getSpot(), k_, p_.getRf(), p_.getDiv(), t, p_.getVol());
	return vega;
}
double PlainVanillaOption::imp_vol(double mktPrice) {
	double t = mat_.daysFrom(p_.getToday()) / 365.0;
	double iv = imvol(p_.getSpot(), k_, p_.getRf(), p_.getDiv(), t, mktPrice, type_);
	return iv;
}