#include <iostream>
#include "cJednoslad.h"
using namespace std;

int main()
{
	cMotor* M1=new cMotor(60,300,15,"Kazek");
	M1->wypiszMotor();
	cGorski* R1 = new cGorski(24, 10, "Feniks", 3, 7);
	R1->wypiszGorski();
	cMotorower* MR1 = new cMotorower("turbo",68,200,13,"Moj",3,8);
	MR1->wypiszMotorower();

	cin.ignore();
	return 0;
}