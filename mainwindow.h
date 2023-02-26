#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_0_clicked();

    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_6_clicked();

    void on_Button_7_clicked();

    void on_Button_8_clicked();

    void on_Button_9_clicked();

    void on_Button_AC_clicked();

    void on_Button_leftbracket_clicked();

    void on_Button_rightbracket_clicked();

    void on_Button_toThePowerOf_clicked();

    void on_Button_divide_clicked();

    void on_Button_multiply_clicked();

    void on_Button_minus_clicked();

    void on_Button_plus_clicked();

    void on_Button_comma_clicked();

    void on_Button_modulo_clicked();

    void on_Button_sqRoot_clicked();

    void on_Button_pi_clicked();

    void on_Button_equal_clicked();

    void on_Button_delete_clicked();

    void keyPressEvent(QKeyEvent *event);

    void NumberClicked(char number);

    void ParenthesesClicked(char brace);

    void OperatorClicked(char chOperator);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
