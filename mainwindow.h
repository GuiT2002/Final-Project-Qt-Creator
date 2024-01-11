#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_Sum_clicked();

    void on_Subtraction_clicked();

    void on_Multiplication_clicked();

    void on_Division_clicked();

    void on_Tangent_clicked();

    void on_Cosine_clicked();

    void on_Sine_clicked();

    void on_Exp_clicked();

    void on_Log_clicked();

    void on_Ln_clicked();

    void on_Factorial_clicked();

    void on_Sqrt_clicked();

    void on_NthRoot_clicked();

    void on_Power_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
