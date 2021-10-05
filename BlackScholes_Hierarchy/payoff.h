#pragma once
#include "option.h"

// Abstract class
class Payoff {
public:
	Payoff() : k_(0), type_(OptionType::Call) {}
	Payoff(double k, OptionType type) : k_(k), type_(type) {}
	virtual double getPayoff(double st) = 0;
protected:
	double k_;
	OptionType type_;
};

class PlainVanillaPayoff : public Payoff {
public:
	PlainVanillaPayoff() : Payoff() {}
	PlainVanillaPayoff(double k, OptionType type) :
		Payoff(k, type) {}
	virtual double getPayoff(double st);
};

class BinaryPayoff : public Payoff {
public:
	BinaryPayoff() : Payoff() {}
	BinaryPayoff(double k, OptionType type) :
		Payoff(k, type) {}
	virtual double getPayoff(double st);
};
