#pragma once
#include <string>

//OOP
//1. 추상화
//2. 캡슐화 - 멤버변수(속성, 데이터) + 멤버함수(메소드) + 정보은닉
//3. 상속
//4. 다형성

class Date {

public:
	//생성자: class->object 생성 class이름과 동일한 이름 함수
	Date(): year_(0), month_(0), day_(0) {} //default constructor
	Date(unsigned int y, unsigned int m, unsigned int d);
	unsigned int year(); //Get function
	unsigned int month() { return month_;}
	unsigned int day() { return day_; }
	void setYear(unsigned int y){	//Set function
		year_ = y;
	}
	int daysFrom(Date d);
	std::string datestr();
	
private:
	unsigned int year_;
	unsigned int month_;
	unsigned int day_;

};