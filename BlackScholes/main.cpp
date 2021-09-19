#include <iostream>

//pdf, cdf
#include "normal.h"
#include "bs_analytic.h"
#include "bs_montecarlo.h"
#include "bs_binomialtree.h"


int main() {
	/*for (int i = 0; i <= 60; i++) {
		double x = i / 10.0 - 3.0;
		double pdf = normpdf(x);
		double cdf = normcdf(x);
		std::cout << x << "\t" << "pdf = " << pdf << "\t";
		std::cout << "cdf = " << cdf << std::endl;
	}*/
	
	double s = 100, k = 100, r = 0.015, q = 0.01, t = 0.1, sigma = 0.15;
	double price = 2; // bsprice(s, k, r, q, t, sigma, Call);
	double iv = imvol(s, k, r, q, t, price, Call);
	std::cout << "IV = " << iv << std::endl;

	double price1 = bsprice(s, k, r, q, t, iv, Call);
	std::cout << price << " | " << price1 << std::endl;

	double price2 = mcprice(s, k, r, q, t, iv, Call, 400000);
	std::cout << price2 << std::endl;

	for (int i = 0; i <= 20; ++i) {
		double s = 90 + i;
		double analytic = bsprice(s, k, r, q, t, sigma, Put);
		double mc = mcprice(s, k, r, q, t, sigma, Put);
		double bnt = bntprice(s, k, r, q, t, sigma, Put);
		std::cout << analytic << "|" << mc << "|" << bnt << std::endl;
	}

	return 0;
}