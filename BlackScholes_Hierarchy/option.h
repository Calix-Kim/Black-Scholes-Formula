#pragma once

#include "date.h"
#include "gbm_process.h"

enum class OptionType { Call = 1, Put = -1 };

class Option {
public:
	Option() :
		k_(0), mat_(Date()), type_(OptionType::Call), p_(GBMProcess()) {}
	Option(double k, Date mat, OptionType type) :
		k_(k), mat_(mat), type_(type), p_(GBMProcess()) {}
	void setProcess(GBMProcess p) { p_ = p; }
	double price();

protected:
	double get_d1(double sigma);
	double get_d2(double sigma);
	double get_ttm();
	double k_;
	Date mat_;
	OptionType type_;
	GBMProcess p_;
};