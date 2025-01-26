#pragma once
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <sstream>

//this calculator class was created specifically for GUI application that ensures proper data entering
class Calculator {
private:
	double num1{}, num2{};
	double ans{};
	int mode{};			//0-decimal, 1-binary, 2-octal, 3-hex
			

public:
	Calculator();
	
	void setNum1(std::string value);
	
	void setNum2(std::string value);
	
	void setAns(double ans);
	
	void setMode(int mode);

	double getAns();

	int getMode();

	double add();

	double sub();

	double multi();

	double div();
	
	//bitwise functions
	double bor();
	
	double band();
	
	double bnor();

	double bnand();

	double bxor();

	double bxnor();

	//function for binary readability
	std::string fixBin(std::string bin);
	
	//function to format result of equation
	std::string result();

	//function for converting displayed value from one system to another
	std::string convert(std::string value, int prevMode);

};