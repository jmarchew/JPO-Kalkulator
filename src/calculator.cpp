#include "../inc/calculator.h"
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <sstream>

Calculator::Calculator() {
	this->num1 = 0.0;
	this->num2 = 0.0;
	this->mode = 0;
}

void Calculator::setNum1(std::string value) {
	if (mode == 0) {

		this->num1 = stod(value, 0);
	}
	else if (mode == 1) {
		this->num1 = stoll(value, 0, 2);
	}
	else if (mode == 2) {
		this->num1 = stoll(value, 0, 8);
	}
	else if (mode == 3) {
		this->num1 = stoll(value, 0, 16);
	}
}

void Calculator::setNum2(std::string value) {
	if (mode == 0) {

        this->num2 = stod(value, 0);
	}
	else if (mode == 1) {
		this->num2 = stoll(value, 0, 2);
	}
	else if (mode == 2) {
		this->num2 = stoll(value, 0, 8);
	}
	else if (mode == 3) {
		this->num2 = stoll(value, 0, 16);
	}
}

void Calculator::setAns(double ans) {
	this->ans = ans;
}

void Calculator::setMode(int mode) {
	this->mode = mode;
}


int Calculator::getMode() {
	return mode;
}

double Calculator::getAns(){
		return ans;
}

double Calculator::add() {
	return num1 + num2;
}

double Calculator::sub() {
	return num1 - num2;
}

double Calculator::multi() {
	return num1 * num2;
}

double Calculator::div() {
    if (num2 != 0) {
        return num1 / num2;
    }
    else {
        return 0;
    }
}

double Calculator::bor() {
	return (int)num1 | (int)num2;
}

double Calculator::band() {
	return (int)num1 & (int)num2;
}

double Calculator::bnor() {
	return ~((int)num1 | (int)num2);
}

double Calculator::bnand() {
	return ~((int)num1 & (int)num2);
}	

double Calculator::bxor() {
	return (int)num1 ^ (int)num2;
}

double Calculator::bxnor() {
	return ~((int)num1 ^ (int)num2);
}

//function converting result stored in double ans to string for display purpouse
std::string Calculator::result() {
    std::string result;
	
    // Convert the number to decimal
    if (mode == 0) { 
        result = std::to_string(ans); 
        
        //removing unnecesary 0 at end of floating string
        while (result.back() == '0' && result.length()>4) {
            result.pop_back();
        }
        //making sure no result like 5. occurs
        if (result.back() == '.') {
            result.push_back('0');
        }
    }
    // Binary
    else if (mode == 1) {

        // Convert the number to 64 bit binary string
        std::string bin = std::bitset<64>(ans).to_string();
        
        //adjusting string to be more readable
        result = fixBin(bin);
    }
    //octal
    else if (mode == 2) {

        //creating string stream
        std::ostringstream oss; 

        // converting number to oct
        oss << std::oct << static_cast <long long > (ans);
        
        result = oss.str();
    }

    // Hexadecimal
    else if (mode == 3) { 
        //creating string stream
        std::ostringstream oss; 

        // converting number to hex
        oss << std::hex << static_cast <long long> (ans);

        result = oss.str(); 
    }
    //making A-F upper case for visual purpouse
	for (auto& x : result) {
		x = toupper(x);
	}

	return result;
}

//function making binary numbers more readable 
std::string Calculator::fixBin(std::string bin) {
    
    // removing octets with zeros only
    bin.erase(0, bin.find_first_not_of('0'));
    
    //base length=4 for displaying in octets
    int len = 4;
    while (bin.length() > len) {
        len += 4;
    }
    //adding 0 to bin string to full octet
    bin = std::string(len - bin.size(), '0') + bin;

    // Insert spaces every 4 characters for readability
    for (int i = 4; i < bin.size(); i += 5) {
        bin.insert(i, " ");
    }

    return bin; 

}

//function converting displayed value between numeral systems
std::string Calculator::convert(std::string value, int prevMode) {

    //variable to store value to convert
    long long num = 0; 
 
    std::string result; 
    
    // convertion from decimal
    if (prevMode == 0) { 
        //converting string to long long decimal number
        num = std::stoll(value, nullptr, 10);
    }
    // convertion from binary
    else if (prevMode == 1) { 
        // Remove spaces from the binary string added by fixBin()
        value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
   
        // Convert binary string to bitset
        std::bitset<64> bits(value);

       //converting 64 bit binary number to 64 bit integer
        num = bits.to_ullong();
    }
    //converting from octal
    else if (prevMode == 2) { 

        //converting octal string to unsigned long long
        num = std::stoull(value, nullptr, 8);
        
    }
    //converting from hex
    else if (prevMode == 3) {

        //converting hex string to unsigned long long
        num = std::stoull(value, nullptr, 16);

    }
    //Convert the number to the target numeral system
    //convert to string representing decimal number
    if (mode == 0) { 
        result = std::to_string(num); 
    }
    // Convert the number to a 64 bit binary string 
    else if (mode == 1) {
        std::string bin = std::bitset<64>(num).to_string();

        //making string more readable
        result=fixBin(bin);
    }
    //convert to string representing octal number
    else if (mode == 2) { // Octal
       
        std::ostringstream oss; 
        oss << std::oct << num; 
        result = oss.str(); 
    }
    //convert to string representing octal number
    else if (mode == 3) { 
        std::ostringstream oss; 
        oss << std::hex << num; 
        result = oss.str(); 
    }

    // Convert hexadecimal letters to uppercase (if any)
    for (auto& c : result) {
        c = std::toupper(c);
    }
    
    return result;
}