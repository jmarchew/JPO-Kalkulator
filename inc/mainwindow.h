#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <vector>
namespace Ui {
    class mainWindow;
}
class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget* parent = nullptr);
    ~mainWindow();

private:
    Ui::mainWindow ui;

private slots:
    void digitPressed();
    void alphaPressed();
    void signPressed();
    void equalPressed();
    void modePressed();
    void operatorPressed();
    void backPressed();
    void clearPressed();
    void dotPressed();
    void answerPressed();
    void changeButtonState(bool dMode, bool bMode, bool oMode, bool hMode);
};