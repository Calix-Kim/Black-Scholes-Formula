#pragma once

#include "date.h"
#include "gbm_process.h"

enum class OptionType { Call = 1, Put = -1 };
class Payoff;

// Abstract Class - can not generate an instance
class Option {
public:
	Option() :
		k_(0), mat_(Date()), type_(OptionType::Call), p_(GBMProcess()) {}
	Option(double k, Date mat, OptionType type, Payoff* po) :
		k_(k), mat_(mat), type_(type), p_(GBMProcess()), po_(po) {}
	virtual ~Option() { delete po_; }
	void setProcess(GBMProcess p) { p_ = p; }
	virtual double price() = 0;	// (pure) virtual function
	double mcprice(unsigned int numSim = 100000);
	double bntprice(unsigned int steps = 300);

protected:
	double get_d1(double sigma);
	double get_d2(double sigma);
	double get_ttm();
	double k_;
	Date mat_;
	OptionType type_;
	GBMProcess p_;
	Payoff* po_;
};