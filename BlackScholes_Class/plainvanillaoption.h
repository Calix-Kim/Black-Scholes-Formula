#pragma once
#include "date.h"
#include "gbm_process.h"

enum class OptionType { Call = 1, Put = -1 };

class PlainVanillaOption {
public:
	PlainVanillaOption():
		k_(0), mat_(Date()), type_(OptionType::Call), p_(GBMProcess()) {}
	PlainVanillaOption(double k, Date mat, OptionType type) :
		k_(k), mat_(mat), type_(type), p_(GBMProcess()) {}
	void setProcess(GBMProcess p) { p_ = p; }
	double price();
	double vega();
	double imp_vol(double mktPrice);
private:
	double bsprice(double s, double k, double r, double  q, double  t, double sigma, OptionType type);
	double bsvega(double s, double k, double r, double  q, double  t, double sigma);
	double imvol(double s, double k, double r, double q, double t, double price, OptionType type);
	double k_;
	Date mat_;
	OptionType type_;
	GBMProcess p_;
};