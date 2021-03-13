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
    void on_pushButton_clicked();

    void on_horizontalSlider_x_sliderMoved(int position);

    void on_horizontalSlider_y_sliderMoved(int position);

    void on_horizontalSlider_z_sliderMoved(int position);

    void on_horizontalSlider_a_x_sliderMoved(int position);

    void on_horizontalSlider_a_y_sliderMoved(int position);

    void on_horizontalSlider_a_z_sliderMoved(int position);

    void on_horizontalSlider_melkost_sliderMoved(int position);

    void on_horizontalSlider_fig_xAlpha_sliderMoved(int position);

    void on_horizontalSlider_fig_yAlpha_sliderMoved(int position);

    void on_horizontalSlider_fig_zAlpha_sliderMoved(int position);

    void on_verticalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
