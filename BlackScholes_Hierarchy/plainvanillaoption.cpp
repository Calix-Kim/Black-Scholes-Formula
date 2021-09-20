#include "plainvanillaoption.h"
#include "normal.h"
#include "cmath"

double PlainVanillaOption::bsprice(double s, double k, double r, double  q, double  t, double sigma, OptionType type) {	//call:type = +1 or put:type = -1
	double d1 = get_d1(sigma);
	double d2 = get_d2(sigma);
	double nd1 = normcdf(int(type) * d1);
	double nd2 = normcdf(int(type) * d2);

	double price = (int)type * (s * std::exp(-q * t) * nd1 - k * std::exp(-r * t) * nd2);

	return price;
}

double PlainVanillaOption::bsvega(double s, double k, double r, double  q, double  t, double sigma) {
	double d1 = get_d1(sigma);
	double pdf_d1 = normpdf(d1);
	double vega = s * std::exp(-q * t) * std::sqrt(t) * pdf_d1;

	return vega;
}

double PlainVanillaOption::imvol(double s, double k, double r, double q, double t, double price, OptionType type) {

	double x0 = 0.2;
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
	double t = get_ttm();
	double price = bsprice(p_.getSpot(), k_, p_.getRf(), p_.getDiv(), t, p_.getVol(), type_);
	return price;
}
double PlainVanillaOption::vega() {
	double t = get_ttm();
	double vega = bsvega(p_.getSpot(), k_, p_.getRf(), p_.getDiv(), t, p_.getVol());
	return vega;
}
double PlainVanillaOption::imp_vol(double mktPrice) {
	double t = get_ttm();
	double iv = imvol(p_.getSpot(), k_, p_.getRf(), p_.getDiv(), t, mktPrice, type_);
	return iv;
}
