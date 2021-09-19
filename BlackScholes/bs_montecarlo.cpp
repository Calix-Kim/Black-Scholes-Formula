#include "bs_montecarlo.h"
#include <random>
#include <cmath>

double mcprice(double s, double k, double r, double  q, double  t, double sigma, OptionType type, unsigned int numSim) {
	std::mt19937_64 gen;
	std::normal_distribution<double> dist(0, 1);
	double sum = 0.;
	for (int i = 0; i < numSim; i++) {
		double e = dist(gen);
		double st = s * std::exp((r - q - 0.5 * sigma * sigma) * t + sigma * std::sqrt(t) * e);
		double payoff = MAX(type * (st - k), 0);
		sum += payoff;
	}
	double payoff_mean = sum / numSim;
	double price = std::exp(-r * t) * payoff_mean;

	return price;
}