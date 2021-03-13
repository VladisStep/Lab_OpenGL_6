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
    ui->widget->xAlpha = 0;
    ui->widget->yAlpha = 0;
    ui->widget->zAlpha = -8;
    ui->widget->paintGL();
    ui->widget->update();
}





void MainWindow::on_horizontalSlider_x_sliderMoved(int position)
{
    ui->widget->cam_x = position/10.0;
    ui->widget->paintGL();
    ui->widget->update();
}

void MainWindow::on_horizontalSlider_y_sliderMoved(int position)
{
    ui->widget->cam_y = position/10.0;
    ui->widget->paintGL();
    ui->widget->update();
}

void MainWindow::on_horizontalSlider_z_sliderMoved(int position)
{
    ui->widget->cam_z = position/10.0;
    ui->widget->paintGL();
    ui->widget->update();
}

void MainWindow::on_horizontalSlider_a_x_sliderMoved(int position)
{
    ui->widget->xAlpha = position;
    ui->widget->paintGL();
    ui->widget->update();
}

void MainWindow::on_horizontalSlider_a_y_sliderMoved(int position)
{
    ui->widget->yAlpha = position;
    ui->widget->paintGL();
    ui->widget->update();
}

void MainWindow::on_horizontalSlider_a_z_sliderMoved(int position)
{
    ui->widget->zAlpha = position;
    ui->widget->paintGL();
    ui->widget->update();
}

void MainWindow::on_horizontalSlider_melkost_sliderMoved(int position)
{
    ui->widget->fineness = position;
    ui->widget->paintGL();
    ui->widget->update();
}

void MainWindow::on_horizontalSlider_fig_xAlpha_sliderMoved(int position)
{
    ui->widget->fig_xAlpha = position;
    ui->widget->paintGL();
    ui->widget->update();
}

void MainWindow::on_horizontalSlider_fig_yAlpha_sliderMoved(int position)
{
    ui->widget->fig_yAlpha = position;
    ui->widget->paintGL();
    ui->widget->update();
}

void MainWindow::on_horizontalSlider_fig_zAlpha_sliderMoved(int position)
{
    ui->widget->fig_zAlpha = position;
    ui->widget->paintGL();
    ui->widget->update();
}

void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    ui->widget->test = position;
    ui->widget->paintGL();
    ui->widget->update();
}
