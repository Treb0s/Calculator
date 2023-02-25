#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "rechenAlgorithmus.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <locale>
#include "strtk.hpp"

struct Eingabewerte
{
    int commaAllowed;
    int commaInNumber;
    int numberAllowed;
    int operatorsAllowed;
    int minusSqRootAllowed;
    int leftBracketallowed;
    int rightBracketAllowed;
    int bracketControl;
};

std::vector<Eingabewerte> eingabewerte;

void resetEingabewerte()
{
    eingabewerte.clear();
    eingabewerte.push_back(Eingabewerte());
    eingabewerte[0].numberAllowed = 1;
    eingabewerte[0].commaInNumber = 0;
    eingabewerte[0].commaAllowed = 0;
    eingabewerte[0].operatorsAllowed = 0;
    eingabewerte[0].minusSqRootAllowed = 1;
    eingabewerte[0].leftBracketallowed = 1;
    eingabewerte[0].rightBracketAllowed = 0;
    eingabewerte[0].bracketControl = 0;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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



void NumberClicked()
{
    eingabewerte.push_back(Eingabewerte());
    eingabewerte[eingabewerte.size() - 1].numberAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].commaInNumber = eingabewerte[eingabewerte.size() - 2].commaInNumber;
    eingabewerte[eingabewerte.size() - 1].commaAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].operatorsAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].minusSqRootAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].leftBracketallowed = 0;
    eingabewerte[eingabewerte.size() - 1].rightBracketAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].bracketControl = eingabewerte[eingabewerte.size() - 2].bracketControl;
}

void OperatorClicked()
{
    eingabewerte.push_back(Eingabewerte());
    eingabewerte[eingabewerte.size() - 1].numberAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].commaInNumber = 0;
    eingabewerte[eingabewerte.size() - 1].commaAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].operatorsAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].minusSqRootAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].leftBracketallowed = 1;
    eingabewerte[eingabewerte.size() - 1].rightBracketAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].bracketControl = eingabewerte[eingabewerte.size() - 2].bracketControl;
}

void MainWindow::on_Button_0_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += "0";
    rechnungDisp += "0";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_1_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += "1";
    rechnungDisp += "1";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_2_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += "2";
    rechnungDisp += "2";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_3_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += "3";
    rechnungDisp += "3";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_4_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += "4";
    rechnungDisp += "4";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_5_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += "5";
    rechnungDisp += "5";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_6_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += "6";
    rechnungDisp += "6";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_7_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += "7";
    rechnungDisp += "7";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_8_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += "8";
    rechnungDisp += "8";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_9_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += "9";
    rechnungDisp += "9";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_leftbracket_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].leftBracketallowed == 0) return;
    eingabewerte.push_back(Eingabewerte());
    eingabewerte[eingabewerte.size() - 1].numberAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].commaInNumber = 0;
    eingabewerte[eingabewerte.size() - 1].commaAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].operatorsAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].minusSqRootAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].leftBracketallowed = 1;
    eingabewerte[eingabewerte.size() - 1].rightBracketAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].bracketControl = eingabewerte[eingabewerte.size() - 2].bracketControl + 1;
    rechnung += "(";
    rechnungDisp += "(";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_rightbracket_clicked()
{
    if(eingabewerte[eingabewerte.size() - 1].rightBracketAllowed == 0 || eingabewerte[eingabewerte.size() - 1].bracketControl == 0) return;
    eingabewerte.push_back(Eingabewerte());
    eingabewerte[eingabewerte.size() - 1].numberAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].commaInNumber = 0;
    eingabewerte[eingabewerte.size() - 1].commaAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].operatorsAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].minusSqRootAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].leftBracketallowed = 0;
    eingabewerte[eingabewerte.size() - 1].rightBracketAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].bracketControl = eingabewerte[eingabewerte.size() - 2].bracketControl - 1;
    rechnung += ")";
    rechnungDisp += ")";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_toThePowerOf_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].operatorsAllowed == 0) return;
    OperatorClicked();
    rechnung += "^";
    rechnungDisp += "^";
    ui->Rechenfenster->setText(rechnungDisp);
}


void MainWindow::on_Button_divide_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].operatorsAllowed == 0) return;
    OperatorClicked();
    rechnung += "/";
    rechnungDisp += "÷";
    ui->Rechenfenster->setText(rechnungDisp);
}


void MainWindow::on_Button_multiply_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].operatorsAllowed == 0) return;
    OperatorClicked();
    rechnung += "*";
    rechnungDisp += "·";
    ui->Rechenfenster->setText(rechnungDisp);

}


void MainWindow::on_Button_minus_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].minusSqRootAllowed == 0) return;
    OperatorClicked();
    rechnung += "-";
    rechnungDisp += "-";
    ui->Rechenfenster->setText(rechnungDisp);
}


void MainWindow::on_Button_plus_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].operatorsAllowed == 0) return;
    OperatorClicked();
    rechnung += "+";
    rechnungDisp += "+";
    ui->Rechenfenster->setText(rechnungDisp);
}


void MainWindow::on_Button_comma_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].commaAllowed == 0 || eingabewerte[eingabewerte.size() - 1].commaInNumber == 1) return;
    eingabewerte.push_back(Eingabewerte());
    eingabewerte[eingabewerte.size() - 1].numberAllowed = 1;
    eingabewerte[eingabewerte.size() - 1].commaInNumber = 1;
    eingabewerte[eingabewerte.size() - 1].commaAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].operatorsAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].minusSqRootAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].leftBracketallowed = 0;
    eingabewerte[eingabewerte.size() - 1].rightBracketAllowed = 0;
    eingabewerte[eingabewerte.size() - 1].bracketControl = eingabewerte[eingabewerte.size() - 2].bracketControl;
    rechnung += ",";
    rechnungDisp += ",";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_modulo_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].operatorsAllowed == 0) return;
    OperatorClicked();
    rechnung += "%";
    rechnungDisp += "%";
    ui->Rechenfenster->setText(rechnungDisp);
}


void MainWindow::on_Button_sqRoot_clicked()
{
    if ((eingabewerte[eingabewerte.size() - 1].numberAllowed == 0 || eingabewerte[eingabewerte.size() - 1].operatorsAllowed == 1) && !rechnung.empty()) return;
    OperatorClicked();
    rechnung += "w";
    rechnungDisp += "√";
    ui->Rechenfenster->setText(rechnungDisp);
}


void MainWindow::on_Button_pi_clicked()
{
    if (eingabewerte[eingabewerte.size() - 1].numberAllowed == 0) return;
    NumberClicked();
    rechnung += strtk::type_to_string<double>(M_PI);
    rechnungDisp += "π";
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_delete_clicked()
{
    if (rechnung.empty()) return;
    rechnung.pop_back();
    rechnungDisp.truncate(rechnungDisp.size()-1);
     eingabewerte.erase(eingabewerte.end() - 1);
    ui->Rechenfenster->setText(rechnungDisp);
}

void MainWindow::on_Button_AC_clicked()
{
    resetEingabewerte();
    rechnung = "";
    rechnungDisp = "";
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
        ui->Ergebnisfenster->setText("Fehler! Nicht alle Klammern wurden geschlossen");
        return;
    }
    ui->Ergebnisfenster->setText(QString::fromStdString(rechenAlgorithmus(rechnung)));
    ui->Ergebnisfenster->setAlignment(Qt::AlignRight);
}
