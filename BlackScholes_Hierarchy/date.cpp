#include "date.h"
#include <ctime>

//클래스 멤버함수 정의
//std::cout
//Class::멤버

Date::Date(unsigned int y, unsigned int m, unsigned int d):
	year_(y), month_(m), day_(d){}

unsigned int Date::year() { return year_; } //Get function

int Date::daysFrom(Date d) {
	std::tm a = { 0, 0, 0, d.day(), d.month() - 1, d.year() - 1900 };
	std::tm b = { 0, 0, 0, day_, month_- 1, year_ - 1900 };
	std::time_t x = std::mktime(&a);
	std::time_t y = std::mktime(&b);
	int difference = (int)std::difftime(y, x) / (60 * 60 * 24);
	return difference;
	//return daysBetween(d, *this);
}

std::string Date::datestr() {
	return std::to_string(year_) + "/" + ((month_ < 10) ? "0" : "") + std::to_string(month_) + "/" + ((day_<10) ? "0":"") + std::to_string(day_);
}

int daysBetween(Date d1, Date d2) {
	return d2.daysFrom(d1);
	/*std::tm a = { 0, 0, 0, d1.day(), d1.month() - 1, d1.year() - 1900 };
	std::tm b = { 0, 0, 0, d2.day(), d2.month() - 1, d2.year() - 1900 };
	std::time_t x = std::mktime(&a);
	std::time_t y = std::mktime(&b);
	int difference = std::difftime(y, x) / (60 * 60 * 24);
	return difference;*/
}