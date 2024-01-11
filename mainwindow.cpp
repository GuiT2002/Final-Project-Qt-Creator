#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ui-> Result->setText( QString::number( ui->n1->value() - ui->n2->value()) );

unsigned long long factorial(int n, int range) {
    if (n == 0 || n == 1 || n <= range) {
        return 1;
    } else {
        return static_cast<unsigned long long>(n) * factorial(n - 1, range);
    }
}

QVector<double> generate_x_values(){
    QVector<double> x_values;

    for (double i=-5.00;i<7.00; i+=0.01){
        x_values.push_back(i);
    }

    return x_values;
}


QVector<double> y_sin(){
    QVector<double> y_values;

    for (size_t i=0;i<generate_x_values().size(); i++){
        y_values.push_back(sin(generate_x_values().at(i)));
    }

    return y_values;
}


QVector<double> y_cos(){
    QVector<double> y_values;

    for (size_t i=0;i<generate_x_values().size(); i++){
        y_values.push_back(cos(generate_x_values().at(i)));
    }

    return y_values;
}


QVector<double> y_tan(){
    QVector<double> y_values;

    for (size_t i=0;i<generate_x_values().size(); i++){
        y_values.push_back(tan(generate_x_values().at(i)));
    }

    return y_values;
}


QVector<double> y_ln(){
    QVector<double> y_values;

    for (size_t i=0;i<generate_x_values().size(); i++){
        y_values.push_back(log(generate_x_values().at(i)));
    }

    return y_values;
}


QVector<double> y_exp(){
    QVector<double> y_values;

    for (size_t i=0;i<generate_x_values().size(); i++){
        y_values.push_back(exp(generate_x_values().at(i)));
    }

    return y_values;
}


QVector<double> y_log(double base){
    QVector<double> y_values;

    for (size_t i=0;i<generate_x_values().size(); i++){
        y_values.push_back(log(generate_x_values().at(i))/log(base));
    }

    return y_values;
}


QVector<double> y_sqrroot(){
    QVector<double> y_values;

    for (size_t i=0;i<generate_x_values().size(); i++){
        y_values.push_back(pow(generate_x_values().at(i), 0.5));
    }

    return y_values;
}


QVector<double> y_nthroot(double n){
    QVector<double> y_values;

    for (size_t i=0;i<generate_x_values().size(); i++){
        y_values.push_back(pow(generate_x_values().at(i), 1/n));
    }

    return y_values;
}


QVector<double> y_power(double n){
    QVector<double> y_values;

    for (size_t i=0;i<generate_x_values().size(); i++){
        y_values.push_back(pow(generate_x_values().at(i), n));
    }

    return y_values;
}


void MainWindow::on_Sum_clicked()
{
    ui-> Result->setText( QString::number( ui->n1->value() + ui->n2->value()) );
}


void MainWindow::on_Subtraction_clicked()
{
    ui-> Result->setText( QString::number( ui->n1->value() - ui->n2->value()) );
}


void MainWindow::on_Multiplication_clicked()
{
    ui-> Result->setText( QString::number( ui->n1->value() * ui->n2->value()) );
}


void MainWindow::on_Division_clicked()
{
    if (ui->n2->value() != 0)
        ui->Result->setText( QString::number( ui->n1->value() / ui->n2->value()) );
    else
        ui->Result->setText("Undefined");
}


void MainWindow::on_Tangent_clicked()
{
    ui-> Result->setText( QString::number( tan(ui->n1->value()) ));
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(generate_x_values(), y_tan());
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(-2, 7);
    ui->customPlot->yAxis->setRange(-2, 7);
    ui->customPlot->replot();
}


void MainWindow::on_Cosine_clicked()
{
    ui-> Result->setText( QString::number( cos(ui->n1->value()) ));
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(generate_x_values(), y_cos());
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(-2, 7);
    ui->customPlot->yAxis->setRange(-2, 7);
    ui->customPlot->replot();
}


void MainWindow::on_Sine_clicked()
{
    ui-> Result->setText( QString::number( sin(ui->n1->value())));
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(generate_x_values(), y_sin());
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(-2, 7);
    ui->customPlot->yAxis->setRange(-2, 7);
    ui->customPlot->replot();
}


void MainWindow::on_Exp_clicked()
{
    ui-> Result->setText( QString::number( exp(ui->n1->value())));
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(generate_x_values(), y_exp());
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(-2, 7);
    ui->customPlot->yAxis->setRange(-2, 7);
    ui->customPlot->replot();
}

//log_b(a) = log_c(a)/log_c(b)
void MainWindow::on_Log_clicked()
{
    if (ui->n2->value() != 1){
        ui-> Result->setText( QString::number( log(ui->n1->value())/ log(ui->n2->value())));
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(generate_x_values(), y_log(ui->n2->value()));
        ui->customPlot->xAxis->setLabel("x");
        ui->customPlot->yAxis->setLabel("y");
        ui->customPlot->xAxis->setRange(-2, 7);
        ui->customPlot->yAxis->setRange(-2, 7);
        ui->customPlot->replot();
    }
    else ui-> Result->setText("Undefined");
}


void MainWindow::on_Ln_clicked()
{
    ui-> Result->setText( QString::number( log(ui->n1->value())) );
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(generate_x_values(), y_ln());
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(-2, 7);
    ui->customPlot->yAxis->setRange(-2, 7);
    ui->customPlot->replot();

}


void MainWindow::on_Factorial_clicked()
{
    if (ui->n1->value() < 0 || ui->n2->value() < 0) {
        ui->Result->setText("Invalid input: n and range must be non-negative.");
    }

    else ui-> Result->setText( QString::number( factorial(ui->n1->value(), ui->n2->value())) );
}


void MainWindow::on_Sqrt_clicked()
{
    ui-> Result->setText( QString::number( sqrt(ui->n1->value() + ui->n2->value())) );
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(generate_x_values(), y_sqrroot());
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(-2, 7);
    ui->customPlot->yAxis->setRange(-2, 7);
    ui->customPlot->replot();

}


void MainWindow::on_NthRoot_clicked()
{
    ui-> Result->setText( QString::number( pow(ui->n2->value(), 1.0/ui->n1->value())) );
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(generate_x_values(), y_nthroot(ui->n1->value()));
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(-2, 7);
    ui->customPlot->yAxis->setRange(-2, 7);
    ui->customPlot->replot();
}


void MainWindow::on_Power_clicked()
{
    ui-> Result->setText( QString::number( pow(ui->n1->value(), ui->n2->value())) );
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(generate_x_values(), y_power(ui->n2->value()));
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(-2, 7);
    ui->customPlot->yAxis->setRange(-2, 7);
    ui->customPlot->replot();
}

