#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    ui->widget->xAlpha = position;
    ui->widget->paintGL();
    ui->widget->update();
}



void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->widget->zAlpha = position;
    ui->widget->paintGL();
    ui->widget->update();
}
