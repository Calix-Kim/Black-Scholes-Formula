#pragma once
#include <string>

//OOP
//1. �߻�ȭ
//2. ĸ��ȭ - �������(�Ӽ�, ������) + ����Լ�(�޼ҵ�) + ��������
//3. ���
//4. ������

class Date {

public:
	//������: class->object ���� class�̸��� ������ �̸� �Լ�
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