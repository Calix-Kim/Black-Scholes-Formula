#include "bs_binomialtree.h"
#include <vector>
#include <cmath>

// CRR tree: u=exp(sigma*sqrt(dt)), d = 1/u, q=(exp(r*dt)-d)/(u-d)
double bntprice(double s, double k, double r, double  q, double  t, double sigma, OptionType type, unsigned int steps) {

	double dt = t / steps;
	double u = std::exp(sigma * std::sqrt(dt));
	double d = 1.0 / u;
	double p = (std::exp((r-q) * dt) - d) / (u - d);
	std::vector<double> v(steps + 1, 0.0);
	//v[0] ~ v[steps]
	//i=0 : st = s0 * u^steps * d^0
	//i=1 : st = s0 * u^(steps-1) * d^1
	//i=1 : st = s0 * u^(stpes-2) * d^2
	//i=stpes : st = s0 * u^0 * d^steps

	for (int i = 0; i < v.size(); i++) {
		double st = s * std::pow(u, (steps - i)) * std::pow(d, i);
		v[i] = MAX(type * (st - k), 0);
	}
	for (int k = steps; k > 0; --k) {
		for (int j = 0; j < k; ++j) {
			v[j] = std::exp(-r * dt) * (p * v[j] + (1 - p) * v[j + 1]);
		}
	}

	return v[0];
}