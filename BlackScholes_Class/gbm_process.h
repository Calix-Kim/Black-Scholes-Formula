#pragma once
#include "date.h"

class GBMProcess {
public:
	GBMProcess():
		s_(0), r_(0), q_(0), sigma_(0)	{}
	GBMProcess(double s, double r, double q, double sigma);
	void setDate(Date d);
	Date getToday() { return today_; }
	void setSpot(double s) { s_ = s; }
	double getSpot();
	double getRf();
	double getDiv();
	double getVol();
private:
	double s_, r_, q_, sigma_;
	Date today_;
};