#include <iostream>
#include "date.h"
#include "gbm_process.h"
#include "plainvanillaoption.h"
#include "binaryoption.h"

int main() {

	Date d1(2020, 10, 2);

	GBMProcess p1(100, 0.01, 0.01, 0.15);
	p1.setDate(d1);

	Option inst0(100, Date(2020, 12, 15), OptionType::Put);
	PlainVanillaOption inst1(100, Date(2020, 12, 15), OptionType::Put);
	BinaryOption inst2(100, Date(2020, 12, 15), OptionType::Call);
	inst0.setProcess(p1);
	inst1.setProcess(p1);
	inst2.setProcess(p1);

	for (int i = 0; i <= 40; ++i) {
		double spot = 80.0 + i;
		p1.setSpot(spot);
		inst0.setProcess(p1);
		inst1.setProcess(p1);
		inst2.setProcess(p1);
		//std::cout << spot << " : " << inst.price() << " | "
		//	<< inst.vega() << " | "
		//	<< inst.imp_vol(inst.price()) << std::endl;
		std::cout << spot << " : " << inst0.price() << " | "
			<< inst1.price() << " | "
			<< inst2.price() << std::endl;
	}

	return 0;
}