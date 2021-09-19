#include <iostream>
#include <random>

int main() {
	std::mt19937_64 gen;
	std::normal_distribution<double> dist(0, 1);
	for (int i = 0; i < 100; i++) {
		double e = dist(gen);
		std::cout << e << std::endl;
	}

	return 0;
}