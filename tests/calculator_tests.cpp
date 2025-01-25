#include <gtest/gtest.h>
#include "../inc/calculator.h"


TEST(CalculatorTest, ConstructorTest) {
    Calculator calc;
    EXPECT_EQ(calc.getMode(), 0); 
    EXPECT_DOUBLE_EQ(calc.getAns(), 0.0);  
}


TEST(CalculatorTest, modeTest) {
    Calculator calc;
    calc.setMode(1);
    EXPECT_EQ(calc.getMode(), 1);

    calc.setMode(2);
    EXPECT_EQ(calc.getMode(), 2);

    calc.setMode(3);
    EXPECT_EQ(calc.getMode(), 3);
}


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


TEST(CalculatorTest, SetAnswerTest) {
    Calculator calc;
    calc.setAns(42.0);
    EXPECT_DOUBLE_EQ(calc.getAns(), 42.0);
}
