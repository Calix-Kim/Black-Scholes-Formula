#pragma once

#include "option.h"

class PlainVanillaOption : public Option {
public:
	PlainVanillaOption(double k, Date mat, OptionType type):
		Option(k, mat, type){}
	PlainVanillaOption() : Option() {}
	double price();	//�������̵� Over-riding, �Լ� �����ε� Overloading
	double vega();
	double imp_vol(double mktPrice);
private:
	double bsprice(double s, double k, double r, double  q, double  t, double sigma, OptionType type);
	double bsvega(double s, double k, double r, double  q, double  t, double sigma);
	double imvol(double s, double k, double r, double q, double t, double price, OptionType type);
};
