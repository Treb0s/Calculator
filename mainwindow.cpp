#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "rechenAlgorithmus.h"
#include <QKeyEvent>
#include <iostream>
#include <cmath>
#include <vector>
#include <locale>
#include "strtk.hpp"

struct Eingabewerte
{
    int numberAllowed;
    int commaAllowed;
    int commaInNumber;
    int operatorsAllowed;
    int minusAllowed;
    int sqRootAllowed;
    int leftParenAllowed;
    int rightParenAllowed;
    int bracketControl;
};

std::vector<Eingabewerte> eingabewerte;

void resetEingabewerte()
{
    eingabewerte.clear();
    eingabewerte.push_back(Eingabewerte());
    eingabewerte[0].numberAllowed = 1;
    eingabewerte[0].commaAllowed = 0;
    eingabewerte[0].commaInNumber = 0;
    eingabewerte[0].operatorsAllowed = 0;
    eingabewerte[0].minusAllowed = 1;
    eingabewerte[0].sqRootAllowed = 1;
    eingabewerte[0].leftParenAllowed = 1;
    eingabewerte[0].rightParenAllowed = 0;
    eingabewerte[0].bracketControl = 0;
}

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    resetEingabewerte();
    std::locale::global(std::locale("de_DE.utf8"));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string rechnung;
QString rechnungDisp;

void MainWindow::NumberClicked(char number)
{

    if (number == 'p' && eingabewerte[eingabewerte.size() - 1].numberAllowed == 1)
    {
        eingabewerte.push_back(Eingabewerte());
        eingabewerte[eingabewerte.size() - 1].numberAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].commaAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].sqRootAllowed = 0;
        rechnung += strtk::type_to_string<double>(M_PI);
        rechnungDisp += "π";
        //ui->Rechenfenster->setText(rechnungDisp);
    }
    else if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 1)
    {
        eingabewerte.push_back(Eingabewerte());
        eingabewerte[eingabewerte.size() - 1].numberAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].commaAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].sqRootAllowed = eingabewerte[eingabewerte.size() - 2].sqRootAllowed;
        rechnung += number;
        rechnungDisp += number;
    }
    else return;
    eingabewerte[eingabewerte.size() - 1].commaInNumber = eingabewerte[eingabewerte.size() - 2].commaInNumber;
    eingabewerte[eingabewerte.size() - 1].operatorsAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].minusAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].leftParenAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].rightParenAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].bracketControl = eingabewerte[eingabewerte.size() - 2].bracketControl;
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::OperatorClicked(char chOperator)
{

    if (chOperator == 'w' && eingabewerte[eingabewerte.size() - 1].sqRootAllowed == 1)
    {
        eingabewerte.push_back(Eingabewerte());
        eingabewerte[eingabewerte.size() - 1].sqRootAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].minusAllowed = 1;
        rechnungDisp += "√";
    }
    else if (chOperator == '-' && eingabewerte[eingabewerte.size() - 1].minusAllowed == 1)
    {
        eingabewerte.push_back(Eingabewerte());
        eingabewerte[eingabewerte.size() - 1].sqRootAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].minusAllowed = 0;
        rechnungDisp += chOperator;
    }
    else if (chOperator != 'w' && eingabewerte[eingabewerte.size() - 1].operatorsAllowed == 1)
    {
        eingabewerte.push_back(Eingabewerte());
        eingabewerte[eingabewerte.size() - 1].sqRootAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].minusAllowed = 0;

        if (chOperator == '/')
        {
            rechnungDisp += "÷";
        }
        else if (chOperator == '*')
        {
            rechnungDisp += "·";
        }

        else rechnungDisp += chOperator;
    }

    else return;
    rechnung += chOperator;
    eingabewerte[eingabewerte.size() - 1].numberAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].commaAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].commaInNumber = 0;
    eingabewerte[eingabewerte.size() - 1].operatorsAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].rightParenAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].leftParenAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].bracketControl = eingabewerte[eingabewerte.size() - 2].bracketControl;
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::ParenthesesClicked(char brace)
{

    if (brace == '(' && eingabewerte[eingabewerte.size() - 1].leftParenAllowed == 1)
    {
        eingabewerte.push_back(Eingabewerte());
        eingabewerte[eingabewerte.size() - 1].numberAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].operatorsAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].minusAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].sqRootAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].leftParenAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].rightParenAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].bracketControl = eingabewerte[eingabewerte.size() - 2].bracketControl + 1;
        rechnung += brace;
        rechnungDisp += brace;
        ui->Rechenfenster->setText(rechnungDisp);
    }

    else if (brace == ')' && eingabewerte[eingabewerte.size() - 1].rightParenAllowed == 1 && eingabewerte[eingabewerte.size() - 1].bracketControl != 0)
    {
        eingabewerte.push_back(Eingabewerte());
        eingabewerte[eingabewerte.size() - 1].numberAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].operatorsAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].minusAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].sqRootAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].leftParenAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].rightParenAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].bracketControl = eingabewerte[eingabewerte.size() - 2].bracketControl - 1;
        rechnung += brace;
        rechnungDisp += brace;
        ui->Rechenfenster->setText(rechnungDisp);
    }
    else return;
    eingabewerte[eingabewerte.size() - 1].commaAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].commaInNumber = 0;
}


void MainWindow::on_Button_0_clicked()
{
    NumberClicked('0');
}

void MainWindow::on_Button_1_clicked()
{
    NumberClicked('1');
}

void MainWindow::on_Button_2_clicked()
{
    NumberClicked('2');
}

void MainWindow::on_Button_3_clicked()
{
    NumberClicked('3');
}

void MainWindow::on_Button_4_clicked()
{
    NumberClicked('4');
}

void MainWindow::on_Button_5_clicked()
{
    NumberClicked('5');
}

void MainWindow::on_Button_6_clicked()
{
    NumberClicked('6');
}

void MainWindow::on_Button_7_clicked()
{
    NumberClicked('7');
}

void MainWindow::on_Button_8_clicked()
{
    NumberClicked('8');
}

void MainWindow::on_Button_9_clicked()
{
    NumberClicked('9');
}

void MainWindow::on_Button_pi_clicked()
{
        NumberClicked('p');
}

void MainWindow::on_Button_leftbracket_clicked()
{
    ParenthesesClicked('(');
}

void MainWindow::on_Button_rightbracket_clicked()
{
    ParenthesesClicked(')');
}

void MainWindow::on_Button_toThePowerOf_clicked()
{
    OperatorClicked('^');
}


void MainWindow::on_Button_divide_clicked()
{
    OperatorClicked('/');
}


void MainWindow::on_Button_multiply_clicked()
{
     OperatorClicked('*');
}


void MainWindow::on_Button_minus_clicked()
{
    OperatorClicked('-');
}


void MainWindow::on_Button_plus_clicked()
{
        OperatorClicked('+');
    }


void MainWindow::on_Button_modulo_clicked()
{
        OperatorClicked('%');
}


void MainWindow::on_Button_sqRoot_clicked()
{
    OperatorClicked('w');
}



void MainWindow::on_Button_comma_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].commaAllowed == 1 && eingabewerte[eingabewerte.size() - 1].commaInNumber == 0)
    {
        eingabewerte.push_back(Eingabewerte());
        eingabewerte[eingabewerte.size() - 1].numberAllowed = 1;
        eingabewerte[eingabewerte.size() - 1].commaAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].commaInNumber = 1;
        eingabewerte[eingabewerte.size() - 1].operatorsAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].minusAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].sqRootAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].leftParenAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].rightParenAllowed = 0;
        eingabewerte[eingabewerte.size() - 1].bracketControl = eingabewerte[eingabewerte.size() - 2].bracketControl;
        rechnung += ",";
        rechnungDisp += ",";
        ui->Rechenfenster->setText(rechnungDisp);
    }
}


void MainWindow::on_Button_delete_clicked()
{
    if (!rechnung.empty())
    {
        rechnung.pop_back();
        rechnungDisp.truncate(rechnungDisp.size()-1);
        eingabewerte.erase(eingabewerte.end() - 1);
        ui->Rechenfenster->setText(rechnungDisp);
    }
}

void MainWindow::on_Button_AC_clicked()
{
    resetEingabewerte();
    rechnung.clear();
    rechnungDisp.clear();
    ui->Ergebnisfenster->setText("");
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_equal_clicked()
{
    if (rechnung.empty())
    {
        ui->Ergebnisfenster->setText("Bitte gib etwas ein");
        return;
    }
    if (eingabewerte[eingabewerte.size() - 1].bracketControl != 0)
    {
        ui->Ergebnisfenster->setText("Fehler! Klammern nicht geschlossen");
        return;
    }
    ui->Ergebnisfenster->setText(QString::fromStdString(rechenAlgorithmus(rechnung)));
    ui->Ergebnisfenster->setAlignment(Qt::AlignRight);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_0)
    {
        NumberClicked('0');
    }

    if(event->key() == Qt::Key_1)
    {
        NumberClicked('1');
    }

    if(event->key() == Qt::Key_2)
    {
        NumberClicked('2');
    }

    if(event->key() == Qt::Key_3)
    {
        NumberClicked('3');
    }

    if(event->key() == Qt::Key_4)
    {
        NumberClicked('4');
    }

    if(event->key() == Qt::Key_5)
    {
        NumberClicked('5');
    }

    if(event->key() == Qt::Key_6)
    {
        NumberClicked('6');
    }

    if(event->key() == Qt::Key_7)
    {
        NumberClicked('7');
    }

    if(event->key() == Qt::Key_8)
    {
        NumberClicked('8');
    }

    if(event->key() == Qt::Key_9)
    {
        NumberClicked('9');
    }

    if(event->key() == Qt::Key_P)
    {
        NumberClicked('p');
    }

    if(event->key() == Qt::Key_Comma)
    {
        on_Button_comma_clicked();
    }

    if(event->key() == Qt::Key_Dead_Circumflex)
    {
        OperatorClicked('^');
    }

    if(event->key() == Qt::Key_W)
    {
        OperatorClicked('w');
    }

    if(event->key() == Qt::Key_Percent)
    {
        OperatorClicked('%');
    }

    if(event->key() == Qt::Key_Slash)
    {
        OperatorClicked('/');
    }

    if(event->key() == Qt::Key_Asterisk)
    {
        OperatorClicked('*');
    }

    if(event->key() == Qt::Key_Plus)
    {
        OperatorClicked('+');
    }

    if(event->key() == Qt::Key_Minus)
    {
        OperatorClicked('-');
    }

    if(event->key() == Qt::Key_Percent)
    {
        OperatorClicked('%');
    }

    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        on_Button_equal_clicked();
    }

    if(event->key() == Qt::Key_Backspace)
    {
        on_Button_delete_clicked();
    }

    if(event->key() == Qt::Key_Delete)
    {
        on_Button_AC_clicked();
    }

    if(event->key() == Qt::Key_ParenLeft)
    {
        ParenthesesClicked('(');
    }

    if(event->key() == Qt::Key_ParenRight)
    {
        ParenthesesClicked(')');
    }
}
