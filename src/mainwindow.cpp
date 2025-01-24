#include "../inc/mainwindow.h"
#include "../inc/calculator.h"


Calculator c;
//vector to hold operator values in order: '+','-','*','/','OR','AND','NOR','NAND','XOR','XNOR'
//idea to store operators as boolean based on Derek Banas QT tutorial
std::vector<bool> operators(10,false);

double value{};
bool newEquation = true;



mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //setting default button state
    changeButtonState(true, false, false, false);
    
    //below binding buttons to call functions
    //digit buttons
    connect(ui.Button0, SIGNAL(clicked()), this, SLOT(digitPressed()));
    connect(ui.Button1, SIGNAL(clicked()), this, SLOT(digitPressed()));
    connect(ui.Button2, SIGNAL(clicked()), this, SLOT(digitPressed()));
    connect(ui.Button3, SIGNAL(clicked()), this, SLOT(digitPressed()));
    connect(ui.Button4, SIGNAL(clicked()), this, SLOT(digitPressed()));
    connect(ui.Button5, SIGNAL(clicked()), this, SLOT(digitPressed()));
    connect(ui.Button6, SIGNAL(clicked()), this, SLOT(digitPressed()));
    connect(ui.Button7, SIGNAL(clicked()), this, SLOT(digitPressed()));
    connect(ui.Button8, SIGNAL(clicked()), this, SLOT(digitPressed()));
    connect(ui.Button9, SIGNAL(clicked()), this, SLOT(digitPressed()));
    //operator buttons
    connect(ui.ButtonPlus, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui.ButtonMinus, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui.ButtonMulti, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui.ButtonDiv, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui.ButtonOR, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui.ButtonAND, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui.ButtonNOR, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui.ButtonNAND, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    connect(ui.ButtonXOR, SIGNAL(clicked()), this, SLOT(operatorPressed()));
    
    //not button
    connect(ui.ButtonXNOR, SIGNAL(clicked()), this, SLOT(operatorPressed()));

    //A-F buttons
    connect(ui.ButtonA, SIGNAL(clicked()), this, SLOT(alphaPressed()));
    connect(ui.ButtonB, SIGNAL(clicked()), this, SLOT(alphaPressed()));
    connect(ui.ButtonC, SIGNAL(clicked()), this, SLOT(alphaPressed()));
    connect(ui.ButtonD, SIGNAL(clicked()), this, SLOT(alphaPressed()));
    connect(ui.ButtonE, SIGNAL(clicked()), this, SLOT(alphaPressed()));
    connect(ui.ButtonF, SIGNAL(clicked()), this, SLOT(alphaPressed()));

    //equal button
    connect(ui.ButtonEqual, SIGNAL(clicked()), this, SLOT(equalPressed()));
    //mode buttons
    connect(ui.ButtonDEC, SIGNAL(clicked()), this, SLOT(modePressed()));
    connect(ui.ButtonBIN, SIGNAL(clicked()), this, SLOT(modePressed()));
    connect(ui.ButtonOCT, SIGNAL(clicked()), this, SLOT(modePressed()));
    connect(ui.ButtonHEX, SIGNAL(clicked()), this, SLOT(modePressed()));
    //backspace button
    connect(ui.ButtonBack, SIGNAL(clicked()), this, SLOT(backPressed()));

    //CE button
    connect(ui.ButtonClean, SIGNAL(clicked()), this, SLOT(clearPressed()));

    //sign button
    connect(ui.ButtonSign, SIGNAL(clicked()), this, SLOT(signPressed()));

    //decimal point button
    connect(ui.ButtonDot, SIGNAL(clicked()), this, SLOT(dotPressed()));
    
    //anwser button
    connect(ui.ButtonAns, SIGNAL(clicked()), this, SLOT(answerPressed()));
}

mainWindow::~mainWindow()
{}
//function for pressing digit 
void mainWindow::digitPressed() {
    //sender will return pointer to pressed button 
    QPushButton* button = (QPushButton*)sender();
    
    //get value of digit on button
    QString digit = button->text();

    //get current value of display
    QString displayText = ui.Display->text();

    //checking numeral system dec/bin/oct/hex
    int nSystem = c.getMode();

    if (newEquation) {   //replace display text if its new equation
        ui.Display->setText(digit);
        newEquation = false;
    }
    else {
        if (nSystem == 0) {
            //converting string to double if in decimal mode
            value = (ui.Display->text() + digit).toDouble();
            // 'g' display will automatically switch to exponential notation after 12 digits
            displayText = QString::number(value, 'g', 12);
            //displaying displayText value on calculator display
            ui.Display->setText(displayText);
        }
        else {
            //adding digit to string on display
            displayText += digit;
            ui.Display->setText(displayText);
        }
    }

}

//function for pressing operator
void mainWindow::operatorPressed() {
    //loop setting all operator values to false
    for (int i = 0; i < operators.size();i++) {
        operators[i] = false;
    }

    QString displayText = ui.Display->text();
    
    //seting num1 in Calculator class 
    c.setNum1(displayText.toStdString());

    QPushButton* button = (QPushButton*)sender();

    //assigning button text to op variable
    QString op = button->text();

    //setting true on operation to be done
    if (op == "+") {
        operators[0] = true;
    }
    else if (op == "-") {
        operators[1] = true;
    }
    else if (op == "*") {
        operators[2] = true;
    }
    else if (op == "/") {
        operators[3] = true;
    }
    else if (op == "OR") {
        operators[4] = true;
    }
    else if (op == "AND") {
        operators[5] = true;
    }
    else if (op == "NOR") {
        operators[6] = true;
    }
    else if (op == "NAND") {
        operators[7] = true;
    }
    else if (op == "XOR") {
        operators[8] = true;
    }
    else if (op == "XNOR") {
        operators[9] = true;
    }
   
    ui.Display->setText("");
}

//function to get result of equation
void mainWindow::equalPressed() {
    double result=0.0;
    QString displayText = ui.Display->text();
 
    c.setNum2(displayText.toStdString());
    if (operators[0]) {
        result = c.add();
    }
    else if (operators[1]) {
        result = c.sub();
    }
    else if (operators[2]) {
        result = c.multi();
    }
    else if(operators[3]){
        result = c.div();
    }
    else if (operators[4]) {
        result = c.bor();
    }
    else if (operators[5]) {
        result = c.band();
    }
    else if (operators[6]) {
        result = c.bnor();
    }
    else if (operators[7]) {
        result = c.bnand();
    }
    else if (operators[8]) {
        result = c.bxor();
    }
    else if (operators[9]) {
        result = c.bxnor();
    }
    else {
        result = 0;
    }

    c.setAns(result);
    displayText = QString::fromStdString(c.result());
    ui.Display->setText(displayText);
    newEquation= true;
}

//function to remove last symbol from display
void mainWindow::backPressed() {
    QString displayText = ui.Display->text();
    displayText.removeLast();
    if (displayText == "") {
        displayText = "0";
    }
    ui.Display->setText(displayText);
    newEquation = false;
}

//function to clear display
void mainWindow::clearPressed() {
    c.setNum1("0");
    c.setNum2("0");
    ui.Display->setText("0");
    newEquation = true;
}

//function for inserting A-F to display
void mainWindow::alphaPressed() {
    QPushButton* button = (QPushButton*)sender();
    QString hexSymbol = button->text();
    QString displayText = ui.Display->text();

    //if its new equation replace displayed 0 else add symbol to the right
    if (newEquation) {
        ui.Display->setText(hexSymbol);
        newEquation = false;
    }
    else {
        displayText = ui.Display->text() + hexSymbol;
        
        ui.Display->setText(displayText);
    }
}

//function to negate current display value
void mainWindow::signPressed() {
    QString displayText = ui.Display->text();
    value = displayText.toDouble();
    value *= (-1);
    displayText= QString::number(value, 'g', 12);
    ui.Display->setText(displayText);

}

//function to enable/disable buttons based on currently selected numeral system
void mainWindow::changeButtonState(bool dMode, bool bMode, bool oMode, bool hMode) {
    
    ui.ButtonDot->setEnabled(dMode);

    ui.Button2->setEnabled(!bMode);
    ui.Button3->setEnabled(!bMode);
    ui.Button4->setEnabled(!bMode);
    ui.Button5->setEnabled(!bMode);
    ui.Button6->setEnabled(!bMode);
    ui.Button7->setEnabled(!bMode);
    ui.Button8->setDisabled(bMode || oMode);
    ui.Button9->setDisabled(bMode || oMode);

    ui.ButtonA->setEnabled(hMode);
    ui.ButtonB->setEnabled(hMode);
    ui.ButtonC->setEnabled(hMode);
    ui.ButtonD->setEnabled(hMode);
    ui.ButtonE->setEnabled(hMode);
    ui.ButtonF->setEnabled(hMode);

    ui.ButtonOR->setDisabled(dMode);
    ui.ButtonAND->setDisabled(dMode);
    ui.ButtonNOR->setDisabled(dMode);
    ui.ButtonNAND->setDisabled(dMode);
    ui.ButtonXOR->setDisabled(dMode);
    ui.ButtonXNOR->setDisabled(dMode);
    ui.ButtonSign->setEnabled(dMode);
}

//function for changing numeral system
void mainWindow::modePressed() {
    bool decMode = false;
    bool binMode = false;
    bool octMode = false;
    bool hexMode = false;
    int prevMode = c.getMode();
    newEquation = true;
    
    
    QPushButton* button = (QPushButton*)sender();
    QString displayText = ui.Display->text();          
    QString mode = button->text();
    std::string str;                //helper variable
    
    if (mode == "DEC") {
        decMode = true;
        c.setMode(0);
    }
    else if (mode == "BIN") {
        binMode = true;
        c.setMode(1);
    }
    else if (mode == "OCT") {
        octMode = true;
        c.setMode(2);
    }
    else if (mode == "HEX") {
        hexMode = true;
        c.setMode(3);
    }
    changeButtonState(decMode, binMode, octMode, hexMode);

    str = displayText.toStdString();
    str = c.convert(str,prevMode);
    displayText = QString::fromStdString(str);
    ui.Display->setText(displayText);
}

//function to insert decimal point to equation
void mainWindow::dotPressed() {
    
    QString displayText = ui.Display->text() + ".";
    ui.Display->setText(displayText);
}

//function to display previous result
void mainWindow::answerPressed() {
    QString displayText;
   
    displayText = QString::fromStdString(c.result());
    ui.Display->setText(displayText);
    newEquation = false;
}
