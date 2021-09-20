#include <iostream>
#include "gbm_process.h"

GBMProcess::GBMProcess(double s, double r, double q, double sigma) :
	s_(s), r_(r), q_(q), sigma_(sigma), today_(Date()) {
	std::cout << "gbm process generated: " << s << std::endl;
}
double GBMProcess::getSpot() { return s_; }
double GBMProcess::getRf() { return r_; }
double GBMProcess::getDiv() { return q_; }
double GBMProcess::getVol() { return sigma_; }
void GBMProcess::setDate(Date d) { today_ = d; }