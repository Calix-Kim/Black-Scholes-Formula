#pragma once
#include "option.h"

class BinaryOption : public Option {
public:
	BinaryOption(): Option(){}
	BinaryOption(double strike, Date mat, OptionType type):
		Option(strike, mat, type){}
	double price();
private:
	double binary_price(double s, double k, double r, double q, double t, double sigma, OptionType type);
};