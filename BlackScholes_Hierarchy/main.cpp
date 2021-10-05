#include <iostream>
#include <vector>
#include "date.h"
#include "gbm_process.h"
#include "plainvanillaoption.h"
#include "binaryoption.h"

// Overloading 
//void printPrice(PlainVanillaOption inst) {
//	std::cout << "Vanilla Price = " << inst.price() << std::endl;	
//}
//
//void printPrice(Option inst) {
//	std::cout << "Option Price = " << inst.price() << std::endl;
//}
//
//void printPrice(BinaryOption inst) {
//	std::cout << "Binary Price = " << inst.price() << std::endl;
//}

void printPrice(Option* inst, std::string productType){
	std::cout << productType << " Price = " << 
		inst->price() << " | " <<
		inst->mcprice() << " | " <<
		inst->bntprice() << " | " <<
		std::endl;
}

int main() {

	Date d1(2020, 10, 2);

	GBMProcess p1(100, 0.01, 0.01, 0.15);
	p1.setDate(d1);
	std::vector<Option*> inst;
	inst.push_back(
		new PlainVanillaOption(100, Date(2020, 12, 15), OptionType::Put));
	inst.push_back(
		new BinaryOption(100, Date(2020, 12, 15), OptionType::Call));
	inst.push_back(
		new PlainVanillaOption(100, Date(2021, 1, 15), OptionType::Put));
	inst.push_back(
		new BinaryOption(100, Date(2021, 2, 15), OptionType::Call));
	inst.push_back(
		new PlainVanillaOption(100, Date(2021, 3, 15), OptionType::Put));
	inst.push_back(
		new BinaryOption(100, Date(2021, 4, 15), OptionType::Call));

	for (int i = 0; i <= 0; ++i) {
		double spot = 100;
		p1.setSpot(spot);
		for(int j=0; j<inst.size(); ++j)
			inst[j]->setProcess(p1);

		std::cout << spot << " : " << std::endl;
		for (int j = 0; j < inst.size(); ++j)
			printPrice(inst[j], "Option");

	}

	for (int j = 0; j < inst.size(); ++j)
		delete inst[j];

	return 0;
}