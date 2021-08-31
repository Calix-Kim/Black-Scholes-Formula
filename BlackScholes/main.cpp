#include <iostream>

//pdf, cdf
#include "normal.h"
#include "bs_analytic.h"



int main() {
	/*for (int i = 0; i <= 60; i++) {
		double x = i / 10.0 - 3.0;
		double pdf = normpdf(x);
		double cdf = normcdf(x);
		std::cout << x << "\t" << "pdf = " << pdf << "\t";
		std::cout << "cdf = " << cdf << std::endl;
	}*/

	double s = 100, k = 100, r = 0.015, q = 0.01, t = 0.1, sigma = 0.15;
	
	for (int i = 0; i <= 40; i++) {
		double vega = bsvega(i + 80, k, r, q, t, sigma);
		//double put = bsprice(i+80, k, r, q, t, sigma, Put);
		std::cout << "price = " << vega << std::endl;
	}

	return 0;
}