#pragma once
#include "bs_analytic.h"

double mcprice(double s, double k, double r, double  q, double  t, double sigma, OptionType type, unsigned int numSim=100000);