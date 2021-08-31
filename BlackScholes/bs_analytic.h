#pragma once

enum OptionType { Call = 1, Put = -1 };

double bsprice(double s, double k, double r, double  q, double  t, double sigma, OptionType type);	
double bsvega(double s, double k, double r, double  q, double  t, double sigma);
double imivol(double s, double k, double r, double q, double t, double price, OptionType type);
