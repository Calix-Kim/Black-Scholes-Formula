#include "bs_analytic.h"
#include "normal.h"
#include <cmath>
#include <iostream>

double bsprice(double s, double k, double r, double  q, double  t, double sigma, OptionType type) {	//call:type = +1 or put:type = -1
	double d1 = (std::log(s / k) + (r - q + 0.5 * sigma * sigma) * t) / (sigma * std::sqrt(t));
	double d2 = d1 - sigma * std::sqrt(t);
	double nd1 = normcdf(type*d1);	
	double nd2 = normcdf(type*d2);

	double price = type * (s * std::exp(-q * t) * nd1 - k * std::exp(-r * t) * nd2);

	return price;
}

double bsvega(double s, double k, double r, double  q, double  t, double sigma) {
	double d1 = (std::log(s / k) + (r - q + 0.5 * sigma * sigma) * t) / (sigma * std::sqrt(t));
	double pdf_d1 = normpdf(d1);
	double vega = s * std::exp(-q * t) * std::sqrt(t) * pdf_d1;

	return vega;
}

double imvol(double s, double k, double r, double q, double t, double price, OptionType type) {	// imvol을 계산할 때 vega가 필요!!

	double x0 = 0.1;
	double tol = 1e-8;
	double error = 100; // std::abs(bsprice(s, k, r, q, t, x0, type) - price);
	while (error > tol) {
		double x1 = x0 - (bsprice(s, k, r, q, t, x0, type) - price) / bsvega(s, k, r, q, t, x0);
		error = std::abs(bsprice(s, k, r, q, t, x1, type) - price);
		x0 = x1;
	}
	return x0;
}