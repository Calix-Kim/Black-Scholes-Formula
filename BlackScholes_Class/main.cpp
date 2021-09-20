#include <iostream>
#include "date.h"
#include "gbm_process.h"
#include "plainvanillaoption.h"

int main() {

	Date d1(2020, 10, 2);
	Date d2(2020, 11, 15);
	std::cout << d2.daysFrom(d1) << std::endl;

	GBMProcess p1(100, 0.01, 0.01, 0.15);
	p1.setDate(d1);

	PlainVanillaOption inst(100, Date(2020, 12, 15), OptionType::Put);
	inst.setProcess(p1);

	for (int i = 0; i <= 40; ++i) {
		double spot = 80.0 + i;
		p1.setSpot(spot);
		inst.setProcess(p1);
		std::cout << spot << " : " << inst.price() << " | "
			<< inst.vega() << " | "
			<< inst.imp_vol(inst.price()) << std::endl;
	}
	

	return 0;
}