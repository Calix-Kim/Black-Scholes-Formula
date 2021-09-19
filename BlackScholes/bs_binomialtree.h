#pragma once
#include "bs_analytic.h"

double bntprice(double s, double k, double r, double  q, double  t, double sigma, OptionType type, unsigned int steps = 200);