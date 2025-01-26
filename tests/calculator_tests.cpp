#include <gtest/gtest.h>
#include "../inc/calculator.h"

//constructor test

TEST(CalculatorTest, ConstructorTest) {
    Calculator calc;
    EXPECT_EQ(calc.getMode(), 0); 
    EXPECT_DOUBLE_EQ(calc.getAns(), 0.0);  
}

//mode setter getter test

TEST(CalculatorTest, modeTest) {
    Calculator calc;
    calc.setMode(1);
    EXPECT_EQ(calc.getMode(), 1);

    calc.setMode(2);
    EXPECT_EQ(calc.getMode(), 2);

    calc.setMode(3);
    EXPECT_EQ(calc.getMode(), 3);
}

//basic operations in decimal tests

TEST(CalculatorTest, decAddTest) {
    Calculator calc;
    calc.setMode(0);  
    calc.setNum1("10.5");
    calc.setNum2("20.5");
    EXPECT_DOUBLE_EQ(calc.add(), 31.0);
}


TEST(CalculatorTest, decSubTest) {
    Calculator calc;
    calc.setMode(0); 
    calc.setNum1("50.0");
    calc.setNum2("20.0");
    EXPECT_DOUBLE_EQ(calc.sub(), 30.0);
}


TEST(CalculatorTest, decMultiTest) {
    Calculator calc;
    calc.setMode(0); 
    calc.setNum1("5.0");
    calc.setNum2("4.0");
    EXPECT_DOUBLE_EQ(calc.multi(), 20.0);
}


TEST(CalculatorTest, decDivTest) {
    Calculator calc;
    calc.setMode(0); 
    calc.setNum1("10.0");
    calc.setNum2("2.0");
    EXPECT_DOUBLE_EQ(calc.div(), 5.0);

    calc.setNum2("0.0");
    EXPECT_DOUBLE_EQ(calc.div(), 0.0);  
}

//adding in bin, oct, hex tests

TEST(CalculatorTest, binAddTest) {
    Calculator calc;
    calc.setMode(1);  
    calc.setNum1("1010");  
    calc.setNum2("0101");  
    EXPECT_DOUBLE_EQ(calc.add(), 15.0);  
}


TEST(CalculatorTest, octAddTest) {
    Calculator calc;
    calc.setMode(2);  
    calc.setNum1("12");  
    calc.setNum2("7");  
    EXPECT_DOUBLE_EQ(calc.add(), 17.0); 
}

TEST(CalculatorTest, hexAddTest) {
    Calculator calc;
    calc.setMode(3);  
    calc.setNum1("A"); 
    calc.setNum2("5");  
    EXPECT_DOUBLE_EQ(calc.add(), 15.0);  
}
//convertion tests

TEST(CalculatorTest, dec2bin) {
    Calculator calc;
    std::string value = "10";
    int prevMode = 0;
    calc.setMode(1);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "1010");
}

TEST(CalculatorTest, dec2oct) {
    Calculator calc;
    std::string value = "10";
    int prevMode = 0;
    calc.setMode(2);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "12");
}

TEST(CalculatorTest, dec2hex) {
    Calculator calc;
    std::string value = "10";
    int prevMode = 0;
    calc.setMode(3);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "A");
}

TEST(CalculatorTest, bin2dec) {
    Calculator calc;
    std::string value = "1010";
    int prevMode = 1;
    calc.setMode(0);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "10");
}

TEST(CalculatorTest, bin2oct) {
    Calculator calc;
    std::string value = "1010";
    int prevMode = 1;
    calc.setMode(2);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "12");
}

TEST(CalculatorTest, bin2hex) {
    Calculator calc;
    std::string value = "1010";
    int prevMode = 1;
    calc.setMode(3);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "A");
}

TEST(CalculatorTest, oct2dec) {
    Calculator calc;
    std::string value = "12";
    int prevMode = 2;
    calc.setMode(0);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "10");
}

TEST(CalculatorTest, oct2bin) {
    Calculator calc;
    std::string value = "12";
    int prevMode = 2;
    calc.setMode(1);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "1010");
}

TEST(CalculatorTest, oct2hex) {
    Calculator calc;
    std::string value = "12";
    int prevMode = 2;
    calc.setMode(3);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "A");
}

TEST(CalculatorTest, hex2dec) {
    Calculator calc;
    std::string value = "A";
    int prevMode = 3;
    calc.setMode(0);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "10");
}

TEST(CalculatorTest, hex2bin) {
    Calculator calc;
    std::string value = "A";
    int prevMode = 3;
    calc.setMode(1);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "1010");
}

TEST(CalculatorTest, hex2oct) {
    Calculator calc;
    std::string value = "A";
    int prevMode = 3;
    calc.setMode(2);
    std::string result = calc.convert(value, prevMode);
    EXPECT_EQ(result, "12");
}
