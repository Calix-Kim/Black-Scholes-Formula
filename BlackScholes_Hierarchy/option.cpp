#include "option.h"
#include <cmath>
#include <random>
#include "payoff.h"

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

double Option::mcprice(unsigned int numSim) {
	double s = p_.getSpot(), r = p_.getRf(),
		q = p_.getDiv(), sigma = p_.getVol();
	double k = k_, t = get_ttm();
	OptionType type = type_;

	std::mt19937_64 gen;
	std::normal_distribution<double> dist(0, 1);
	double sum = 0.;
	for (int i = 0; i < numSim; i++) {
		double e = dist(gen);
		double st = s * std::exp((r - q - 0.5 * sigma * sigma) * t + sigma * std::sqrt(t) * e);
		double payoff = po_->getPayoff(st);
		sum += payoff;
	}
	double payoff_mean = sum / numSim;
	double price = std::exp(-r * t) * payoff_mean;

	return price;
}

double Option:: bntprice(unsigned int steps) {
	double s = p_.getSpot(), r = p_.getRf(),
		q = p_.getDiv(), sigma = p_.getVol();
	double k = k_, t = get_ttm();
	OptionType type = type_;

	double dt = t / steps;
	double u = std::exp(sigma * std::sqrt(dt));
	double d = 1.0 / u;
	double p = (std::exp((r - q) * dt) - d) / (u - d);
	std::vector<double> v(steps + 1, 0.0);

	for (int i = 0; i < v.size(); i++) {
		double st = s * std::pow(u, (steps - i)) * std::pow(d, i);
		v[i] = po_->getPayoff(st);
	}
	for (int k = steps; k > 0; --k) {
		for (int j = 0; j < k; ++j) {
			v[j] = std::exp(-r * dt) * (p * v[j] + (1 - p) * v[j + 1]);
		}
	}

	return v[0];
}